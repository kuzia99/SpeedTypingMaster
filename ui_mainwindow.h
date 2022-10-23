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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
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
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QPushButton *pushButtonWebsite;
    QComboBox *comboBox;
    QPushButton *pushButton;
    QFrame *frame;
    QLabel *label_6;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QComboBox *comboBox_2;
    QFrame *frame_2;
    QFrame *frame_3;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_4;
    QLabel *labelTimerIcon;
    QLabel *labelTimerCounter;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->resize(909, 617);
        MainWindow->setMinimumSize(QSize(909, 617));
        MainWindow->setMaximumSize(QSize(909, 617));
        MainWindow->setFocusPolicy(Qt::NoFocus);
        MainWindow->setContextMenuPolicy(Qt::NoContextMenu);
        MainWindow->setWindowOpacity(0.950000000000000);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(44, 44, 44);\n"
"color: rgb(255, 255, 255);"));
        MainWindow->setAnimated(true);
        MainWindow->setTabShape(QTabWidget::Rounded);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        textBrowser = new STMtextBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setEnabled(true);
        textBrowser->setGeometry(QRect(120, 150, 681, 171));
        QFont font;
        font.setFamilies({QString::fromUtf8("Kanit")});
        font.setPointSize(22);
        textBrowser->setFont(font);
        textBrowser->setMouseTracking(true);
        textBrowser->setFocusPolicy(Qt::NoFocus);
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
        layoutWidget->setGeometry(QRect(10, 580, 383, 35));
        BottomPanel = new QHBoxLayout(layoutWidget);
        BottomPanel->setObjectName(QString::fromUtf8("BottomPanel"));
        BottomPanel->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Kanit")});
        font1.setPointSize(11);
        label->setFont(font1);

        BottomPanel->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setMaximumSize(QSize(21, 21));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Kanit")});
        label_2->setFont(font2);
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/new/image/img/github.png")));
        label_2->setScaledContents(true);

        horizontalLayout->addWidget(label_2);

        pushButtonSourceCode = new QPushButton(layoutWidget);
        pushButtonSourceCode->setObjectName(QString::fromUtf8("pushButtonSourceCode"));
        pushButtonSourceCode->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButtonSourceCode->sizePolicy().hasHeightForWidth());
        pushButtonSourceCode->setSizePolicy(sizePolicy1);
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Kanit")});
        font3.setPointSize(10);
        pushButtonSourceCode->setFont(font3);
        pushButtonSourceCode->setFocusPolicy(Qt::NoFocus);
        pushButtonSourceCode->setStyleSheet(QString::fromUtf8("background-color: rgb(44, 44, 44);\n"
"gridline-color: rgb(44, 44, 44);\n"
"border-color: rgb(44, 44, 44);\n"
"border: none;"));

        horizontalLayout->addWidget(pushButtonSourceCode);


        BottomPanel->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));

        BottomPanel->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        label_5->setMaximumSize(QSize(21, 21));
        label_5->setFont(font2);
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/new/image/img/web.png")));
        label_5->setScaledContents(true);

        horizontalLayout_2->addWidget(label_5);

        pushButtonWebsite = new QPushButton(layoutWidget);
        pushButtonWebsite->setObjectName(QString::fromUtf8("pushButtonWebsite"));
        pushButtonWebsite->setEnabled(true);
        sizePolicy1.setHeightForWidth(pushButtonWebsite->sizePolicy().hasHeightForWidth());
        pushButtonWebsite->setSizePolicy(sizePolicy1);
        pushButtonWebsite->setFont(font3);
        pushButtonWebsite->setFocusPolicy(Qt::NoFocus);
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
        comboBox->setGeometry(QRect(120, 340, 131, 31));
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
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Kanit")});
        font4.setPointSize(15);
        comboBox->setFont(font4);
        comboBox->setFocusPolicy(Qt::NoFocus);
        comboBox->setContextMenuPolicy(Qt::ActionsContextMenu);
        comboBox->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 0px;\n"
"    border-radius: 10px;\n"
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
"	width :22;\n"
"	height :22;\n"
"	margin-top: 10,5px;\n"
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
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(390, 340, 32, 32));
        pushButton->setFocusPolicy(Qt::NoFocus);
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"    background-color: rgb(44, 44, 44);\n"
"	border:0px;\n"
"}\n"
"\n"
"QPushButton::hover\n"
" {\n"
"  		background-color: #1E1E1E;\n"
"    	border-radius: 10px;\n"
"}\n"
""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/image/img/restart.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(24, 24));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 921, 31));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(30, 30, 30);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label_6 = new QLabel(frame);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 0, 41, 41));
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);
        label_6->setMaximumSize(QSize(111111, 111111));
        label_6->setFont(font2);
        label_6->setPixmap(QPixmap(QString::fromUtf8(":/new/image/img/LOGO CONCEPT 2.png")));
        label_6->setScaledContents(true);
        pushButton_2 = new QPushButton(frame);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(870, 0, 32, 32));
        pushButton_2->setFocusPolicy(Qt::NoFocus);
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"  	background-color: #1E1E1E;\n"
"	border:0px;\n"
"}\n"
"\n"
"QPushButton::hover\n"
" {\n"
"    	background-color: rgb(44, 44, 44);\n"
"    	border-radius: 10px;\n"
"}\n"
""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/img/Close_BTN.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon1);
        pushButton_2->setIconSize(QSize(22, 22));
        pushButton_3 = new QPushButton(frame);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(830, 0, 32, 32));
        pushButton_3->setFocusPolicy(Qt::NoFocus);
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"  	background-color: #1E1E1E;\n"
"	border:0px;\n"
"}\n"
"\n"
"QPushButton::hover\n"
" {\n"
"    	background-color: rgb(44, 44, 44);\n"
"    	border-radius: 10px;\n"
"}\n"
""));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/image/img/Minimize_BTN.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon2);
        pushButton_3->setIconSize(QSize(24, 24));
        comboBox_2 = new QComboBox(centralwidget);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(280, 340, 96, 31));
        comboBox_2->setMinimumSize(QSize(96, 0));
        comboBox_2->setMaximumSize(QSize(76, 16777215));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush);
#endif
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush);
#endif
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush);
#endif
        comboBox_2->setPalette(palette1);
        comboBox_2->setFont(font4);
        comboBox_2->setFocusPolicy(Qt::NoFocus);
        comboBox_2->setContextMenuPolicy(Qt::ActionsContextMenu);
        comboBox_2->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 0px;\n"
"    border-radius: 10px;\n"
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
"	width :22;\n"
"	height :22;\n"
"	margin-top: 10,5px;\n"
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
        comboBox_2->setFrame(true);
        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(260, 340, 2, 31));
        frame_2->setStyleSheet(QString::fromUtf8("background-color: rgb(116, 116, 116);"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        frame_3 = new QFrame(centralwidget);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(370, 340, 2, 31));
        frame_3->setStyleSheet(QString::fromUtf8("background-color: rgb(116, 116, 116);"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(120, 110, 71, 43));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_4->setSpacing(5);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        labelTimerIcon = new QLabel(layoutWidget1);
        labelTimerIcon->setObjectName(QString::fromUtf8("labelTimerIcon"));
        sizePolicy.setHeightForWidth(labelTimerIcon->sizePolicy().hasHeightForWidth());
        labelTimerIcon->setSizePolicy(sizePolicy);
        labelTimerIcon->setMaximumSize(QSize(28, 28));
        labelTimerIcon->setFont(font2);
        labelTimerIcon->setPixmap(QPixmap(QString::fromUtf8(":/new/image/img/stopwatch.png")));
        labelTimerIcon->setScaledContents(true);

        horizontalLayout_4->addWidget(labelTimerIcon);

        labelTimerCounter = new QLabel(layoutWidget1);
        labelTimerCounter->setObjectName(QString::fromUtf8("labelTimerCounter"));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Kanit")});
        font5.setPointSize(20);
        labelTimerCounter->setFont(font5);
        labelTimerCounter->setStyleSheet(QString::fromUtf8("color: rgb(255, 229, 30);"));

        horizontalLayout_4->addWidget(labelTimerCounter);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "STM", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Kanit'; font-size:22pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#747474;\">some text some text some text some text some text some text some text some text some text some text some text some text some text some text some text some text some text some text some text some text</span></p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Created by Maxim Kuznetsov", nullptr));
        label_2->setText(QString());
        pushButtonSourceCode->setText(QCoreApplication::translate("MainWindow", "Source code", nullptr));
        label_5->setText(QString());
        pushButtonWebsite->setText(QCoreApplication::translate("MainWindow", "Website", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "RUSSIAN", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "ENGLISH", nullptr));

        pushButton->setText(QString());
        label_6->setText(QString());
        pushButton_2->setText(QString());
        pushButton_3->setText(QString());
        comboBox_2->setItemText(0, QCoreApplication::translate("MainWindow", "15 s", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("MainWindow", "30 s", nullptr));
        comboBox_2->setItemText(2, QCoreApplication::translate("MainWindow", "60 s", nullptr));
        comboBox_2->setItemText(3, QCoreApplication::translate("MainWindow", "120 s", nullptr));

        labelTimerIcon->setText(QString());
        labelTimerCounter->setText(QCoreApplication::translate("MainWindow", "30", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
