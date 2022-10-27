#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDesktopServices>
#include <QKeyEvent>
#include <QPainter>
#include <QVector>
#include <QTimer>
#include "textbuilder.h"
#include "resultwindow.h"
#include "texthandler.h"

QTextCursor browserCursor;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    ui->tabWidget->tabBar()->hide();

    QTextCharFormat format(ui->textBrowser->currentCharFormat());
    format.setForeground(QBrush(QColor("grey")));

    ui->textBrowser->setCurrentCharFormat(format);
    ui->textBrowser->setText(TextBuilder::generateText(QString("RUSSIAN")));

    browserCursor = ui->textBrowser->textCursor();// выставим курсор

    stat->resetStat();
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

void MainWindow::addTimer()
{
    if(!timer)
    {
        qDebug() << "start Timer";
        timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(timerEvent()));
        timer->start(1000);
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    auto handler = AbstractCharHandler::createHandler(event, browserCursor, ui->textBrowser);
    handler->handle((ui->textBrowser->toPlainText())[browserCursor.position()], browserCursor);

    addTimer();

    stat->keyPressed(handler->pressedKeyFlag);// вызываем метод для учета статистики
    delete handler;
}

void STMtextBrowser::paintEvent(QPaintEvent *pEvent)
{
    QTextEdit::paintEvent(pEvent);// use paintEvent() of base class to do the main work
    // draw cursor (if widget has focus)
      const QRect qRect = cursorRect(textCursor());
      QPainter qPainter(viewport());
      qPainter.fillRect(qRect, textColor());
}

void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{
    QTextCharFormat format;
    format.setFontWeight(22);
    format.setFontWeight(QFont::DemiBold );
    format.setFontWeight(22);
    format.setForeground(QBrush(QColor("grey")));

    AbstractCharHandler::resetVectors();

    ui->textBrowser->setCurrentCharFormat(format);
    ui->textBrowser->setText(TextBuilder::generateText(arg1));
    browserCursor = ui->textBrowser->textCursor();// выставим курсор
}



void MainWindow::on_pushButton_2_clicked()
{
    qApp->quit();
}


void MainWindow::on_pushButton_3_clicked()
{
    this->showMinimized();
}

void MainWindow::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton) {
        m_mousePoint = event->pos();
        event->accept();
    }
}

void MainWindow::resizeEvent(QResizeEvent* event)
{
}

void MainWindow::mouseMoveEvent(QMouseEvent* event)
{
    const QPointF delta = event->globalPosition() - m_mousePoint;
    move(delta.toPoint());

    event->accept();
}

void MainWindow::timerEvent()
{
    qDebug() << "timer Event";

    QString curr = ui->labelTimerCounter->text();
    int val = curr.toInt() - 1;
    QString a = QString::number(val);
    ui->labelTimerCounter->setText(a);
    if(!val)
    {
        qDebug() << "timer stop";
        timer->stop();
        delete timer;
        timer = nullptr;

        stat->print();//пишем результаты статистики на экран
        ui->tabWidget->setCurrentIndex(1);//открываем новую форму с результатами
    }
}


