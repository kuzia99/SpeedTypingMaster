#include "texthandler.h"

QVector<int> errorCharVector;
QVector<int> userCharVector;

class TrueCharHandler : public AbstractCharHandler
{
public:
    TrueCharHandler() = default;
    TrueCharHandler(const QTextCharFormat form) : format(form) {format.setForeground(QBrush(QColor("white")));};
    virtual void handle(QChar ch, QTextCursor &browserCursor) override;
private:
    QTextCharFormat format;
};

class WrongCharHandler : public AbstractCharHandler
{
public:
    WrongCharHandler() = default;
    WrongCharHandler(const QTextCharFormat form ) : format(form) {format.setForeground(QBrush(QColor("red")));};
    virtual void handle(QChar ch, QTextCursor &browserCursor) override;
private:
    QTextCharFormat format;
};

class ExtraCharHadler : public AbstractCharHandler
{
public:
    ExtraCharHadler() = default;
    ExtraCharHadler(const QTextCharFormat form, QChar userChar) : format(form), userNewChar(userChar) {format.setForeground(QBrush(QColor("tomato")));};
    virtual void handle(QChar ch, QTextCursor &browserCursor) override;
private:
    QTextCharFormat format;
    QChar userNewChar;
};

class DeleteKeyHandler : public AbstractCharHandler
{
public:
    DeleteKeyHandler() = default;
    DeleteKeyHandler(const QTextCharFormat form, QChar prev, QTextBrowser* brows) : format(form), prevChar(prev), browser(brows) {format.setForeground(QBrush(QColor("grey")));};
    virtual void handle(QChar ch, QTextCursor &browserCursor) override;
private:
    void deleteUserChar(QTextCursor &browserCursor);
    void deleteNonUserChar(QTextCursor &browserCursor);
    QTextCharFormat format;
    QChar prevChar;
    QTextBrowser* browser;
};

class NullKeyHandler : public AbstractCharHandler
{
public:
    NullKeyHandler() = default;
    virtual void handle(QChar ch, QTextCursor &browserCursor) override {(void)ch; (void)browserCursor;};
};

QSharedPointer<AbstractCharHandler> AbstractCharHandler::createHandler(QKeyEvent *event, QTextCursor &cursor, QTextBrowser* browser)
{
    if(!event->text().size())
        return QSharedPointer<NullKeyHandler>::create();

    //qDebug() << "event->text:" << event->text();
    //qDebug() << "event->key: " << event->key();

    QChar pressedChar = event->text().at(0);//считаем нажатую клавишу
    QChar charInBrowser = browser->toPlainText()[cursor.position()];

    if(pressedChar == charInBrowser)
        return QSharedPointer<TrueCharHandler>::create(browser->currentCharFormat());
    else if(pressedChar == '\x8')
    {
        if(cursor.position())
            return QSharedPointer<DeleteKeyHandler>::create(browser->currentCharFormat(), (browser->toPlainText())[cursor.position() - 1], browser);
        else
            return QSharedPointer<NullKeyHandler>::create();
    }
    else if(charInBrowser == ' ')
        return QSharedPointer<ExtraCharHadler>::create(browser->currentCharFormat(), pressedChar);
    else
        return QSharedPointer<WrongCharHandler>::create(browser->currentCharFormat());
}

void AbstractCharHandler::resetVectors()
{
    errorCharVector.erase(errorCharVector.begin(), errorCharVector.end());
    userCharVector.erase(userCharVector.begin(), userCharVector.end());
}

void TrueCharHandler::handle(QChar ch, QTextCursor &browserCursor)
{
    browserCursor.deleteChar();
    browserCursor.insertText(ch, format);//меняем цвет символа на серый
    pressedKeyFlag = KeyState::trueChar;
}

void WrongCharHandler::handle(QChar ch, QTextCursor &browserCursor)
{
    browserCursor.deleteChar();
    browserCursor.insertText(ch, format);//меняем цвет символа на серый

    errorCharVector.push_back(browserCursor.position() - 1);
    pressedKeyFlag = KeyState::wrongChar;
}

void ExtraCharHadler::handle(QChar ch, QTextCursor &browserCursor)
{
    browserCursor.insertText(userNewChar, format);//добавляем напечатанный темно-красный символ

    userCharVector.push_back(browserCursor.position() - 1);
    errorCharVector.push_back(browserCursor.position() - 1);
    pressedKeyFlag = KeyState::extraChar;
    (void)ch;
}

void DeleteKeyHandler::deleteUserChar(QTextCursor &browserCursor)
{
    browserCursor.deletePreviousChar();
    userCharVector.pop_back();//вытащить последнюю запись из массива

    if(errorCharVector.contains(browserCursor.position()))
        errorCharVector.pop_back();
}

void DeleteKeyHandler::deleteNonUserChar(QTextCursor &browserCursor)
{
    browserCursor.deletePreviousChar();
    browserCursor.insertText(prevChar, format);
    browserCursor.movePosition(QTextCursor::Left);
    browser->setTextCursor(browserCursor);
}

void DeleteKeyHandler::handle(QChar ch, QTextCursor &browserCursor)
{
    if(errorCharVector.isEmpty())
    {
        pressedKeyFlag = KeyState::NullChar;
        return;
    }
    if(userCharVector.contains(browserCursor.position() - 1))
    {
        deleteUserChar(browserCursor);
        pressedKeyFlag = KeyState::userDeleteChar;
        return;
    }
    deleteNonUserChar(browserCursor);
    if(errorCharVector.contains(browserCursor.position()))
    {
        pressedKeyFlag = KeyState::wrongDeleteChar;
        errorCharVector.pop_back();
        return;
    }
    pressedKeyFlag = KeyState::trueDeleteChar;
    (void)ch;
}


//****************************Statistic class method's********************//

inputStatistic* stat = inputStatistic::getInstance();

void inputStatistic::resetStat()
{
    inputTime = 0;
    trueChar = 0;
    wrongChar = 0;
    extraChar = 0;
    wrongPressed = 0;
    extraPressed = 0;

    AbstractCharHandler::resetVectors();
}

void inputStatistic::setInputTime(int t)
{
    inputTime = t;
}

int inputStatistic::getWordsPerMinutes()
{
    if(!trueChar)
        return 0;

    return (trueChar * (60/inputTime)) / 5;
}

int inputStatistic::getTrueCharCount()
{
    return trueChar;
}

int inputStatistic::getWrongCharCount()
{
    return wrongChar;
}

int inputStatistic::getExtraCharCount()
{
    return extraChar;
}

int inputStatistic::getAccuracyPercent()
{
    // точность = правильные символы / символов всего
    // символов всего = правильные символы + ошибочные нажатия + дополнительные нажатия
    if(!trueChar)
        return 0;

    int accuracy = ((float)trueChar / (trueChar + wrongPressed + extraPressed)) * 100;
    return accuracy;
}

void inputStatistic::keyPressed(KeyState input)
{
    QMap<KeyState, void(inputStatistic::*)()> statMethods = {
        {KeyState::trueChar, &inputStatistic::trueHandle},
        {KeyState::wrongChar, &inputStatistic::wrongHandle},
        {KeyState::extraChar, &inputStatistic::extraHandle},
        {KeyState::NullChar,  &inputStatistic::nullHandle},
        {KeyState::userDeleteChar, &inputStatistic::userDelHandle},
        {KeyState::wrongDeleteChar, &inputStatistic::wrongDelHandle},
        {KeyState::trueDeleteChar,  &inputStatistic::trueDelHandle},};

    (this->*(statMethods[input]))();
}

void inputStatistic::trueHandle()
{
    trueChar++;
}

void inputStatistic::wrongHandle()
{
    wrongChar++;
    wrongPressed++;
}

void inputStatistic::extraHandle()
{
    extraChar++;
    extraPressed++;
}

void inputStatistic::nullHandle()
{

}

void inputStatistic::userDelHandle()
{
    extraChar--;
}

void inputStatistic::wrongDelHandle()
{
    wrongChar--;
}

void inputStatistic::trueDelHandle()
{
    trueChar--;
}


