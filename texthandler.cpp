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
    QTextCharFormat format;
    QChar prevChar;
    QTextBrowser* browser;
};

AbstractCharHandler* AbstractCharHandler::createHandler(QKeyEvent *event, QTextCursor &cursor, QTextBrowser* browser)
{
    if(!event->text().size())
        return nullptr;

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
}

void WrongCharHandler::handle(QChar ch, QTextCursor &browserCursor)
{
    browserCursor.deleteChar();
    browserCursor.insertText(ch, format);//меняем цвет символа на серый

    errorCharVector.push_back(browserCursor.position() - 1);
}

void ExtraCharHadler::handle(QChar ch, QTextCursor &browserCursor)
{
    browserCursor.insertText(userNewChar, format);//добавляем напечатанный темно-красный символ

    userCharVector.push_back(browserCursor.position() - 1);
    errorCharVector.push_back(browserCursor.position() - 1);
    (void)ch;
}

void DeleteKeyHandler::handle(QChar ch, QTextCursor &browserCursor)
{
    if(errorCharVector.isEmpty()) return;

    if(userCharVector.contains(browserCursor.position() - 1))
    {
        browserCursor.deletePreviousChar();
        userCharVector.pop_back();//вытащить последнюю запись из массива
    }
    else
    {
        browserCursor.deletePreviousChar();
        browserCursor.insertText(prevChar, format);
        browserCursor.movePosition(QTextCursor::Left);
        browser->setTextCursor(browserCursor);
    }
    if(errorCharVector.contains(browserCursor.position()))
    {
        errorCharVector.pop_back();
    }

    (void)ch;
}
