#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QDebug>
#include <QTextBrowser>


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
    void on_pushButtonSourceCode_clicked();

    void on_pushButtonWebsite_clicked();

    void on_toolButtonTime_clicked();

    void keyPressEvent(QKeyEvent *e);

private:
    Ui::MainWindow *ui;
};

class STMtextBrowser : public QTextBrowser
{
    Q_OBJECT

public:
    explicit STMtextBrowser(QWidget *parent);
    STMtextBrowser();
private:

protected:
    //virtual void paintEvent(QPaintEvent *event);

};

#endif // MAINWINDOW_H
