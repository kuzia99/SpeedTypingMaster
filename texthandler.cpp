#include "texthandler.h"
#include "ui_mainwindow.h"

QVector<int> errorCharVector;
QVector<int> userCharVector;

class TrueCharHandler : public AbstractCharHandler
{
public:
    TrueCharHandler() {}
    TrueCharHandler(const QTextCharFormat form) : format(form) {format.setForeground(QBrush(QColor("white")));};
    virtual void handle(QChar ch, QTextCursor &browserCursor) override;
private:
    QTextCharFormat format;
};

class WrongCharHandler : public AbstractCharHandler
{
public:
    WrongCharHandler() {}
    WrongCharHandler(const QTextCharFormat form ) : format(form) {format.setForeground(QBrush(QColor("red")));};
    virtual void handle(QChar ch, QTextCursor &browserCursor) override;
private:
    QTextCharFormat format;
};

class ExtraCharHadler : public AbstractCharHandler
{
public:
    ExtraCharHadler() {}
    ExtraCharHadler(const QTextCharFormat form, QChar userChar) : format(form), userNewChar(userChar) {format.setForeground(QBrush(QColor("tomato")));};
    virtual void handle(QChar ch, QTextCursor &browserCursor) override;
private:
    QTextCharFormat format;
    QChar userNewChar;
};

class DeleteKeyHandler : public AbstractCharHandler
{
public:
    DeleteKeyHandler() {}
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
    NullKeyHandler() {}
    virtual void handle(QChar ch, QTextCursor &browserCursor) override {};
};

AbstractCharHandler* AbstractCharHandler::createHandler(QKeyEvent *event, QTextCursor &cursor, QTextBrowser* browser)
{
    if(!event->text().size())
        return new NullKeyHandler;

    QChar pressedChar = event->text().at(0);//считаем нажатую клавишу
    QChar charInBrowser = browser->toPlainText()[cursor.position()];

    if(pressedChar == charInBrowser)
        return new TrueCharHandler(browser->currentCharFormat());
    else if(pressedChar == '\x8')
        return new DeleteKeyHandler(browser->currentCharFormat(), (browser->toPlainText())[cursor.position() - 1], browser);
    else if(charInBrowser == ' ')
        return new ExtraCharHadler(browser->currentCharFormat(), pressedChar);
    else
        return new WrongCharHandler(browser->currentCharFormat());
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
