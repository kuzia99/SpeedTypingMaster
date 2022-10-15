#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDesktopServices>
#include <QKeyEvent>
#include <QPainter>
#include <QVector>

QVector<int> errorCharVector;
QVector<int> userCharVector;
QTextCursor browserCursor;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textBrowser->setFocusPolicy(Qt::NoFocus);// без установки атрибута не работает захват клавиши "пробел"
    browserCursor = ui->textBrowser->textCursor();// выставим курсор
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonSourceCode_clicked()
{
    QString link = "http://www.google.com";
    QDesktopServices::openUrl(QUrl(link));
}


void MainWindow::on_pushButtonWebsite_clicked()
{
    QString link = "http://www.google.com";
    QDesktopServices::openUrl(QUrl(link));
}


void MainWindow::on_toolButtonTime_clicked()
{

}


void MainWindow::keyPressEvent(QKeyEvent *event)
{
    QChar myChar = event->text().at(0);//считаем нажатую клавишу
    qDebug() << myChar;
    QChar charInBrowser = (ui->textBrowser->toPlainText())[browserCursor.position()];//считали символ по текущему курсору

   if(charInBrowser == myChar)
    {//если введен верный символ
        QTextCharFormat format;
        format.setFontWeight(QFont::DemiBold );
        format.setForeground(QBrush(QColor("white")));
        format.setFontWeight(22);
        browserCursor.movePosition(QTextCursor::Right);
        browserCursor.deletePreviousChar();
        browserCursor.insertText(myChar, format);
        ui->textBrowser->setTextCursor(browserCursor);
    }
    else if(myChar == '\x8')//key num "backspace"
    {//нажата клавиша "delete"
        if(!errorCharVector.isEmpty())
        {
           if(userCharVector.contains(browserCursor.position() - 1))
            {
                browserCursor.deletePreviousChar();
                userCharVector.pop_back();//вытащить последнюю запись из массива
            }
            else
            {
                QChar prevChar = (ui->textBrowser->toPlainText())[browserCursor.position() - 1];
                browserCursor.deletePreviousChar();
                QTextCharFormat format;
                format.setFontWeight(22);
                format.setFontWeight(QFont::DemiBold );
                format.setFontWeight(22);
                format.setForeground(QBrush(QColor("grey")));
                browserCursor.insertText(prevChar, format);
                browserCursor.movePosition(QTextCursor::Left);
                ui->textBrowser->setTextCursor(browserCursor);
                //запоминаю предыдущий символ
                //удаляю предыдущий символ
                //пишу запомненный символ серым цветом
                //двигаю указатель на лево
            }
            if(errorCharVector.contains(browserCursor.position()))
            {
                errorCharVector.pop_back();
            }
        }
    }
   else
    {//введен не верный символ
        if(charInBrowser == ' ')
        {//если текущий символ пробел
            //добавляем напечатанный темно-красный символ
            QTextCharFormat format;
            format.setFontWeight( QFont::DemiBold );
            format.setForeground( QBrush( QColor( "tomato" ) ) );
            format.setFontWeight(22);

            //fcursor.movePosition(QTextCursor::Right);
            browserCursor.setCharFormat(QTextCharFormat());

            browserCursor.insertText(myChar, format);
            ui->textBrowser->setTextCursor(browserCursor);
            //cursor.movePosition(QTextCursor::Left);

            userCharVector.push_back(browserCursor.position() - 1);
        }
        else
        {//не пробел
            //меняем цвет символа на красный

            QTextCharFormat format;
            format.setFontWeight( QFont::DemiBold );
            format.setForeground( QBrush( QColor( "red" ) ) );
            format.setFontWeight(22);
            browserCursor.movePosition(QTextCursor::Right);

            browserCursor.insertText((ui->textBrowser->toPlainText())[browserCursor.position() - 1], format);
            ui->textBrowser->setTextCursor(browserCursor);
            browserCursor.movePosition(QTextCursor::Left);
            browserCursor.deletePreviousChar();
            browserCursor.movePosition(QTextCursor::Right);

        }
        errorCharVector.push_back(browserCursor.position() - 1);
    }
}

void STMtextBrowser::paintEvent(QPaintEvent *pEvent)
{
    QTextEdit::paintEvent(pEvent);// use paintEvent() of base class to do the main work
    // draw cursor (if widget has focus)
    //if (hasFocus()) {
      const QRect qRect = cursorRect(textCursor());
      QPainter qPainter(viewport());
      qPainter.fillRect(qRect, textColor());
    //}
}
