/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QTextEdit *textInit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QTextEdit *textFileds;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLineEdit *textCylinders;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QLineEdit *textVolume;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QComboBox *comboBoxTieMark;
    QRadioButton *radioButtonTransmission;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_7;
    QLineEdit *textNumber;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_8;
    QLineEdit *textYears;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QPushButton *buttonPrintStrcut;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_10;
    QTextEdit *textUser;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_9;
    QTextEdit *textPointer;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_11;
    QTextEdit *textRef;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1000, 720);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(80, 10, 821, 631));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(widget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        textInit = new QTextEdit(widget);
        textInit->setObjectName("textInit");
        textInit->setTextInteractionFlags(Qt::NoTextInteraction);

        horizontalLayout->addWidget(textInit);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        textFileds = new QTextEdit(widget);
        textFileds->setObjectName("textFileds");
        textFileds->setTextInteractionFlags(Qt::NoTextInteraction);

        horizontalLayout_2->addWidget(textFileds);


        verticalLayout_2->addLayout(horizontalLayout_2);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_4 = new QLabel(widget);
        label_4->setObjectName("label_4");

        horizontalLayout_3->addWidget(label_4);

        textCylinders = new QLineEdit(widget);
        textCylinders->setObjectName("textCylinders");

        horizontalLayout_3->addWidget(textCylinders);


        gridLayout->addLayout(horizontalLayout_3, 0, 0, 1, 2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_5 = new QLabel(widget);
        label_5->setObjectName("label_5");

        horizontalLayout_4->addWidget(label_5);

        textVolume = new QLineEdit(widget);
        textVolume->setObjectName("textVolume");

        horizontalLayout_4->addWidget(textVolume);


        gridLayout->addLayout(horizontalLayout_4, 0, 2, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_6 = new QLabel(widget);
        label_6->setObjectName("label_6");

        horizontalLayout_5->addWidget(label_6);

        comboBoxTieMark = new QComboBox(widget);
        comboBoxTieMark->addItem(QString());
        comboBoxTieMark->addItem(QString());
        comboBoxTieMark->addItem(QString());
        comboBoxTieMark->setObjectName("comboBoxTieMark");

        horizontalLayout_5->addWidget(comboBoxTieMark);


        gridLayout->addLayout(horizontalLayout_5, 1, 0, 1, 1);

        radioButtonTransmission = new QRadioButton(widget);
        radioButtonTransmission->setObjectName("radioButtonTransmission");

        gridLayout->addWidget(radioButtonTransmission, 1, 1, 1, 2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label_7 = new QLabel(widget);
        label_7->setObjectName("label_7");

        horizontalLayout_6->addWidget(label_7);

        textNumber = new QLineEdit(widget);
        textNumber->setObjectName("textNumber");

        horizontalLayout_6->addWidget(textNumber);


        gridLayout->addLayout(horizontalLayout_6, 2, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        label_8 = new QLabel(widget);
        label_8->setObjectName("label_8");

        horizontalLayout_7->addWidget(label_8);

        textYears = new QLineEdit(widget);
        textYears->setObjectName("textYears");

        horizontalLayout_7->addWidget(textYears);


        gridLayout->addLayout(horizontalLayout_7, 2, 1, 1, 2);


        verticalLayout_2->addLayout(gridLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");

        verticalLayout->addWidget(label_3);

        buttonPrintStrcut = new QPushButton(widget);
        buttonPrintStrcut->setObjectName("buttonPrintStrcut");

        verticalLayout->addWidget(buttonPrintStrcut);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        label_10 = new QLabel(widget);
        label_10->setObjectName("label_10");

        horizontalLayout_8->addWidget(label_10);

        textUser = new QTextEdit(widget);
        textUser->setObjectName("textUser");
        textUser->setTextInteractionFlags(Qt::NoTextInteraction);

        horizontalLayout_8->addWidget(textUser);


        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        label_9 = new QLabel(widget);
        label_9->setObjectName("label_9");

        horizontalLayout_9->addWidget(label_9);

        textPointer = new QTextEdit(widget);
        textPointer->setObjectName("textPointer");
        textPointer->setTextInteractionFlags(Qt::NoTextInteraction);

        horizontalLayout_9->addWidget(textPointer);


        verticalLayout_2->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        label_11 = new QLabel(widget);
        label_11->setObjectName("label_11");

        horizontalLayout_10->addWidget(label_11);

        textRef = new QTextEdit(widget);
        textRef->setObjectName("textRef");
        textRef->setTextInteractionFlags(Qt::NoTextInteraction);

        horizontalLayout_10->addWidget(textRef);


        verticalLayout_2->addLayout(horizontalLayout_10);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1000, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Struct Init With Init List:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Struct Init With Fields:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Engine Cylinders: ", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Engine Volume: ", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Tire Mark: ", nullptr));
        comboBoxTieMark->setItemText(0, QCoreApplication::translate("MainWindow", "S", nullptr));
        comboBoxTieMark->setItemText(1, QCoreApplication::translate("MainWindow", "M", nullptr));
        comboBoxTieMark->setItemText(2, QCoreApplication::translate("MainWindow", "H", nullptr));

        radioButtonTransmission->setText(QCoreApplication::translate("MainWindow", "Manual Transmission", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Car Number: ", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Years Of Maintenance: ", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Input your Structure:", nullptr));
        buttonPrintStrcut->setText(QCoreApplication::translate("MainWindow", "Print", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Your Struct: ", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Pointer Struct:", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Reference Struct: ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
