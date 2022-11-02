#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QDebug>
#include <QTextBrowser>
#include <QTimer>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonSourceCode_clicked();     //<! открыть страницу git
    void on_pushButtonWebsite_clicked();        //<! открыть страницу приложения
    void on_pushButton_2_clicked();             //<! закрыть приложение
    void on_pushButton_3_clicked();             //<! свернуть приложение
    void on_comboBox_currentTextChanged(const QString &arg1);   //<! виджет изменения языка ввода
    void on_comboBox_2_currentTextChanged(const QString &arg1); //<! выбор времени отсчета
    void on_pushButton_4_clicked();                     //<! клавиша возврата к окну ввода текста
    void on_pushButton_clicked();                       //<! виджет обновить текст
    void mousePressEvent(QMouseEvent* event) override;  //<! передача нажатий мышью
    void resizeEvent(QResizeEvent* event) override;     //<! изменение размера окна
    void mouseMoveEvent(QMouseEvent* event) override;   //<! перемещение окна

    void keyPressEvent(QKeyEvent *e) override;   //<! обработчик нажатия клавиш клавиатуры

    void secTimerEvent();

private:
    Ui::MainWindow *ui;
    QPointF m_mousePoint;
    QTimer timer;

    void addTimer();
    void updateText();      //<! обновить окно ввода
    void printNewText();    //<! напечатать новый текст
    void openStatDisplay(); //<! отобразить статистику ввода
    void shortcutCheck(QKeyEvent *event);   //<! обработка сочетаний клавиш

};

class STMtextBrowser : public QTextBrowser
{
    Q_OBJECT

public:
    explicit STMtextBrowser(QWidget *parent) : QTextBrowser(parent) {}
    STMtextBrowser() {}
    void paintEvent(QPaintEvent *pEvent) override;
private:

};


#endif // MAINWINDOW_H
