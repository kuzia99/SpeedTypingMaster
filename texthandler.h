#ifndef TEXTHANDLER_H
#define TEXTHANDLER_H

#include <QChar>
#include <QKeyEvent>
#include <QTextCursor>
#include <QTextBrowser>

enum class KeyState {
    trueChar,
    wrongChar,
    extraChar,
    NullChar,
    userDeleteChar,
    wrongDeleteChar,
    trueDeleteChar};

class AbstractCharHandler
{
public:
    virtual ~AbstractCharHandler() {}

    virtual void handle(QChar ch, QTextCursor &browserCursor) = 0;
    static AbstractCharHandler* createHandler(QKeyEvent *event, QTextCursor &cursor, QTextBrowser* browser);
    static void resetVectors();

    KeyState pressedKeyFlag = KeyState::NullChar;
protected:
    QTextCharFormat format;
};

class inputStatistic
{
public:
        static inputStatistic* getInstance()
        {
            static inputStatistic instance;
            return &instance;
        }

        void keyPressed(KeyState input);
        void resetStat();
        int getWordsPerMinutes();
        void setInputTime(int t);

        unsigned int inputTime = 0;//время ввода текста
        unsigned int trueChar = 0;//число правильных символов
        unsigned int wrongChar = 0;//число ошибочных символов
        unsigned int extraChar = 0;//число дополнительных символов
        unsigned int wrongPressed = 0; //число ошибочных нажатий
        unsigned int extraPressed = 0; //число дополнительных нажатий
private:

        void trueHandle();
        void wrongHandle();
        void extraHandle();
        void nullHandle();
        void userDelHandle();
        void wrongDelHandle();
        void trueDelHandle();
};

extern inputStatistic* stat;


#endif // TEXTHANDLER_H
