/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include <mainwindow.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    STMtextBrowser *textBrowser;
    QWidget *layoutWidget;
    QHBoxLayout *BottomPanel;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QPushButton *pushButtonSourceCode;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QPushButton *pushButtonWebsite;
    QComboBox *comboBox;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(909, 642);
        MainWindow->setFocusPolicy(Qt::NoFocus);
        MainWindow->setContextMenuPolicy(Qt::NoContextMenu);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(44, 44, 44);\n"
"color: rgb(255, 255, 255);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        textBrowser = new STMtextBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setEnabled(true);
        textBrowser->setGeometry(QRect(50, 150, 811, 211));
        QFont font;
        font.setFamilies({QString::fromUtf8("Kanit")});
        font.setPointSize(22);
        textBrowser->setFont(font);
        textBrowser->setMouseTracking(true);
        textBrowser->setFrameShape(QFrame::NoFrame);
        textBrowser->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textBrowser->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textBrowser->setTabChangesFocus(false);
        textBrowser->setReadOnly(true);
        textBrowser->setAcceptRichText(true);
        textBrowser->setCursorWidth(2);
        textBrowser->setTextInteractionFlags(Qt::NoTextInteraction);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 560, 446, 35));
        BottomPanel = new QHBoxLayout(layoutWidget);
        BottomPanel->setObjectName(QString::fromUtf8("BottomPanel"));
        BottomPanel->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Kanit")});
        label->setFont(font1);

        BottomPanel->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(31, 31));
        label_2->setFont(font1);
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/new/image/img/github.png")));
        label_2->setScaledContents(true);

        horizontalLayout->addWidget(label_2);

        pushButtonSourceCode = new QPushButton(layoutWidget);
        pushButtonSourceCode->setObjectName(QString::fromUtf8("pushButtonSourceCode"));
        pushButtonSourceCode->setEnabled(true);
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Kanit")});
        font2.setPointSize(10);
        pushButtonSourceCode->setFont(font2);
        pushButtonSourceCode->setFocusPolicy(Qt::ClickFocus);
        pushButtonSourceCode->setStyleSheet(QString::fromUtf8("background-color: rgb(44, 44, 44);\n"
"gridline-color: rgb(44, 44, 44);\n"
"border-color: rgb(44, 44, 44);\n"
"border: none;"));

        horizontalLayout->addWidget(pushButtonSourceCode);


        BottomPanel->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        label_5->setMaximumSize(QSize(31, 31));
        label_5->setFont(font1);
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/new/image/img/web.png")));
        label_5->setScaledContents(true);

        horizontalLayout_2->addWidget(label_5);

        pushButtonWebsite = new QPushButton(layoutWidget);
        pushButtonWebsite->setObjectName(QString::fromUtf8("pushButtonWebsite"));
        pushButtonWebsite->setEnabled(true);
        pushButtonWebsite->setFont(font2);
        pushButtonWebsite->setFocusPolicy(Qt::ClickFocus);
        pushButtonWebsite->setStyleSheet(QString::fromUtf8("background-color: rgb(44, 44, 44);\n"
"gridline-color: rgb(44, 44, 44);\n"
"border-color: rgb(44, 44, 44);\n"
"border: none;"));

        horizontalLayout_2->addWidget(pushButtonWebsite);


        BottomPanel->addLayout(horizontalLayout_2);

        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(660, 440, 151, 31));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(44, 44, 44, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush2(QColor(105, 105, 105, 0));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QBrush brush3(QColor(105, 105, 105, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        QBrush brush4(QColor(0, 0, 0, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush);
#endif
        comboBox->setPalette(palette);
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Kanit")});
        font3.setPointSize(12);
        comboBox->setFont(font3);
        comboBox->setFocusPolicy(Qt::NoFocus);
        comboBox->setContextMenuPolicy(Qt::ActionsContextMenu);
        comboBox->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 0px solid gray;\n"
"    border-radius: 0px;\n"
"    min-width: 6em;\n"
"}\n"
"\n"
"QComboBox::drop-down \n"
"{\n"
"    border: 0px;\n"
"}\n"
"\n"
"\n"
"QComboBox QAbstractItemView {\n"
"  background-color: #1E1E1E;\n"
"  padding: 5px;\n"
"  selection-background-color: lightgray;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"	image: url(:/img/arrow_down.png);\n"
"	width :16;\n"
"	height :16;\n"
"	margin-top: 5px;\n"
"	margin-right: 15px;\n"
"}\n"
"\n"
"QComboBox::hover\n"
"{\n"
"  background-color: #1E1E1E;\n"
"}\n"
"\n"
"QComboBox::item::hover\n"
"{\n"
"  background-color: #1E1E1E;\n"
"}\n"
""));
        comboBox->setFrame(true);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 909, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Kanit'; font-size:22pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#747474;\">some text some text some text some text some text some text some text some text some text some text some text some text some text some text some text</span></p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Created by Maxim Kuznetsov", nullptr));
        label_2->setText(QString());
        pushButtonSourceCode->setText(QCoreApplication::translate("MainWindow", "Source code", nullptr));
        label_5->setText(QString());
        pushButtonWebsite->setText(QCoreApplication::translate("MainWindow", "Website", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "RUSSIAN", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "ENGLISH", nullptr));

    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
