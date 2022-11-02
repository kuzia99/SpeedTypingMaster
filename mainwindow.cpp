#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDesktopServices>
#include <QKeyEvent>
#include <QPainter>
#include <QVector>
#include <QTimer>
#include <QSharedPointer>
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
    connect(&timer, SIGNAL(timeout()), this, SLOT(secTimerEvent()));
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

void MainWindow::addTimer()
{
    if(!timer.isActive() && (browserCursor.position() == 1))
    {
        stat->setInputTime(ui->labelTimerCounter->text().toInt());
        qDebug() << "start Timer";
        timer.start(1000);
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    shortcutCheck(event);
    auto handler = AbstractCharHandler::createHandler(event, browserCursor, ui->textBrowser);
    handler->handle((ui->textBrowser->toPlainText())[browserCursor.position()], browserCursor);
    addTimer();
    stat->keyPressed(handler->pressedKeyFlag);// вызываем метод для учета статистики
}

void MainWindow::shortcutCheck(QKeyEvent *event)
{
    if((event->modifiers() & Qt::ControlModifier) && (event->key() == Qt::Key_R))
    {
        qDebug() << "control + R pressed";
        updateText();
    }
}

void STMtextBrowser::paintEvent(QPaintEvent *pEvent)
{
    QTextEdit::paintEvent(pEvent);// use paintEvent() of base class to do the main work
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

void MainWindow::secTimerEvent()
{
    int counterValue = QString(ui->labelTimerCounter->text()).toInt();
    counterValue--;
    ui->labelTimerCounter->setText(QString::number(counterValue));
    if(!counterValue)
    {
        timer.stop();
        openStatDisplay();
    }
}


void MainWindow::on_pushButton_4_clicked()
{
    updateText();//рестарт
}

void MainWindow::updateText()
{
    stat->resetStat();  //<! сбросим статистику
    ui->labelTimerCounter->setText(QString(ui->comboBox_2->currentText()).remove(QRegularExpression(" s"))); //<! выставим новое значение таймера отсчета
    printNewText();     //<! напечатать новый текст
    ui->tabWidget->setCurrentIndex(0);  //<!открываем форму ввода текста
    timer.stop();   //<! остановить таймер
}


void MainWindow::on_comboBox_2_currentTextChanged(const QString &arg1)
{
    updateText();
    (void) arg1;
}


void MainWindow::on_pushButton_clicked()
{
    updateText();
}


void MainWindow::openStatDisplay()
{
    ui->labelWordsPerMinutes->setText(QString::number(stat->getWordsPerMinutes())); //<! WPM
    ui->labelAccuracy->setText(QString::number(stat->getAccuracyPercent()) + "%");  //<! ACC
    ui->labelCorrectChar->setText(QString::number(stat->getTrueCharCount()));       //<! true char
    ui->labelWrongChar->setText(QString::number(stat->getWrongCharCount()));        //<! wrong char
    ui->labeExtraChar->setText(QString::number(stat->getExtraCharCount()));         //<! extra char

    ui->tabWidget->setCurrentIndex(1);  //<! открываем форму с результатами
}

void MainWindow::printNewText()
{
    QTextCharFormat format(ui->textBrowser->currentCharFormat());// считали формат текста в поле
    format.setForeground(QBrush(QColor("grey")));   // выставили серый цвет
    ui->textBrowser->setCurrentCharFormat(format); //выставим формат текста в главном поле
    ui->textBrowser->setText(TextBuilder::generateText(ui->comboBox->currentText())); // генерим новый текст и передаем его в поле
    browserCursor = ui->textBrowser->textCursor();// выставим курсор
}

