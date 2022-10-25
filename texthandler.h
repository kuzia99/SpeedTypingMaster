#ifndef TEXTHANDLER_H
#define TEXTHANDLER_H

#include <QChar>
#include <QKeyEvent>
#include <QTextCursor>
#include <QTextBrowser>

class AbstractCharHandler
{
public:
    virtual ~AbstractCharHandler() {}

    virtual void handle(QChar ch, QTextCursor &browserCursor) = 0;
    static AbstractCharHandler* createHandler(QKeyEvent *event, QTextCursor &cursor, QTextBrowser* browser);
protected:
    QTextCharFormat format;
};

#endif // TEXTHANDLER_H