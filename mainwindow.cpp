#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDesktopServices>
#include <QKeyEvent>
#include <QPainter>
#include <QVector>
#include <QTimer>
#include "textbuilder.h"
#include "texthandler.h"

QTextCursor browserCursor;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    ui->tabWidget->tabBar()->hide();
    updateText();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonSourceCode_clicked()
{
    QString link = "https://github.com/kuzia99/SpeedTypingMaster";
    QDesktopServices::openUrl(QUrl(link));
}


void MainWindow::on_pushButtonWebsite_clicked()
{
    QString link = "https://kuzia99.github.io/STM/";
    QDesktopServices::openUrl(QUrl(link));
}


void MainWindow::on_toolButtonTime_clicked()
{

}

void MainWindow::addTimer()
{
    if(!timer && (browserCursor.position() == 1))
    {
        stat->setInputTime(ui->labelTimerCounter->text().toInt());
        qDebug() << "start Timer";
        timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(timerEvent()));
        timer->start(1000);
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if((event->modifiers() & Qt::ControlModifier) && (event->key() == Qt::Key_R))
    {
        qDebug() << "control + R pressed";
        updateText();
        return;
    }

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
    updateText();
    (void) arg1;
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
    (void)event;
}

void MainWindow::mouseMoveEvent(QMouseEvent* event)
{
    QMainWindow::mouseMoveEvent(event);
    if(ui->TopPanel->geometry().contains(event->pos()))
    {
        const QPointF delta = event->globalPosition() - m_mousePoint;
        move(delta.toPoint());
        event->accept();
    }
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

        ui->labelWordsPerMinutes->setText(QString::number(stat->getWordsPerMinutes()));
        ui->labelAccuracy->setText(QString::number(stat->getAccuracyPercent()) + "%");
        ui->labelCorrectChar->setText(QString::number(stat->getTrueCharCount()));
        ui->labelWrongChar->setText(QString::number(stat->getWrongCharCount()));
        ui->labeExtraChar->setText(QString::number(stat->getExtraCharCount()));


        ui->tabWidget->setCurrentIndex(1);//открываем новую форму с результатами
    }
}



void MainWindow::on_pushButton_4_clicked()
{
    updateText();//рестарт
    ui->tabWidget->setCurrentIndex(0);//откроем страницу с текстом
}

void MainWindow::updateText()
{
    stat->resetStat();
    AbstractCharHandler::resetVectors();

    QString counterTime = ui->comboBox_2->currentText();
    counterTime.chop(2);
    ui->labelTimerCounter->setText(counterTime);

    QTextCharFormat format(ui->textBrowser->currentCharFormat());
    format.setForeground(QBrush(QColor("grey")));

    ui->textBrowser->setCurrentCharFormat(format);
    ui->textBrowser->setText(TextBuilder::generateText(ui->comboBox->currentText()));
    browserCursor = ui->textBrowser->textCursor();// выставим курсор

    ui->tabWidget->setCurrentIndex(0);//открываем форму ввода текста

    qDebug() << "timer stop";
    if(timer)
    {
        timer->stop();
        delete timer;
        timer = nullptr;
    }
}


void MainWindow::on_comboBox_2_currentTextChanged(const QString &arg1)
{
    QString counterTime = ui->comboBox_2->currentText();
    counterTime.chop(2);
    ui->labelTimerCounter->setText(counterTime);
    updateText();
    (void)arg1;
}


void MainWindow::on_pushButton_clicked()
{
    updateText();
}

