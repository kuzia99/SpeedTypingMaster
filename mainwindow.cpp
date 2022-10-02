
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDesktopServices>
#include <QKeyEvent>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
    static int timeLimit = 0;
}


void MainWindow::keyPressEvent(QKeyEvent *event)
{
    //QTextCursor *textCursor = ui->textBrowser->textCursor();

    ui->textBrowser->moveCursor(QTextCursor::Right);

    ui->textBrowser->textCursor();
    static int counter = 0;
    qDebug() << "press key: " << counter << Qt::endl;
    counter++;





    static int currentIndex = 0;

    QString currStr = ui->textBrowser->toPlainText();

    QByteArray ba = currStr.toLocal8Bit();

    QByteArray myChar = event->text().toLocal8Bit();

    ui->textBrowser->setCursorWidth(3);
    ui->textBrowser->moveCursor(QTextCursor::Right);

    ba[currentIndex] = myChar[0];


    ui->textBrowser->setText(QString(ba));
    currentIndex++;



    //ui->labelInputKey->setText(ui->labelInputKey->text() + event->text());
    //qDebug() << QKeySequence(event->key()).toString();
}


//void STMtextBrowser::paintEvent(QPaintEvent *event)
//{
    //QPainter painter(this);
    //painter.setRender Hint(QPainter::Antialiasing, true);
    //painter.setPen(QPen(QColor("#f00"), 4));
    //painter.drawEllipse(QRectF(0,0,40,40));

//}

STMtextBrowser::STMtextBrowser()
{
}



