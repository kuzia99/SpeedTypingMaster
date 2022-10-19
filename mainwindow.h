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

    void on_comboBox_currentTextChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
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
