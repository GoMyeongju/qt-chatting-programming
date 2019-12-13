/********************************************************************************
** Form generated from reading UI file 'chatting.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATTING_H
#define UI_CHATTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Chatting
{
public:
    QWidget *centralWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QLineEdit *nicname;
    QListWidget *listWidget;
    QLineEdit *ipLineEdit;
    QLabel *label_5;
    QLabel *label_3;
    QLabel *label_2;
    QLineEdit *portLineEdit;
    QLabel *label;
    QPushButton *connecButton;
    QLineEdit *messageLineEdit;
    QPushButton *sendButton;
    QLineEdit *ipfilesendEdit;
    QPushButton *fileSendButton;

    void setupUi(QMainWindow *Chatting)
    {
        if (Chatting->objectName().isEmpty())
            Chatting->setObjectName(QStringLiteral("Chatting"));
        Chatting->resize(508, 454);
        centralWidget = new QWidget(Chatting);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 471, 401));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        nicname = new QLineEdit(gridLayoutWidget);
        nicname->setObjectName(QStringLiteral("nicname"));

        gridLayout->addWidget(nicname, 2, 2, 1, 1);

        listWidget = new QListWidget(gridLayoutWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        gridLayout->addWidget(listWidget, 3, 0, 1, 3);

        ipLineEdit = new QLineEdit(gridLayoutWidget);
        ipLineEdit->setObjectName(QStringLiteral("ipLineEdit"));

        gridLayout->addWidget(ipLineEdit, 0, 2, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 7, 0, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 4, 0, 1, 1);

        portLineEdit = new QLineEdit(gridLayoutWidget);
        portLineEdit->setObjectName(QStringLiteral("portLineEdit"));

        gridLayout->addWidget(portLineEdit, 1, 2, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        connecButton = new QPushButton(gridLayoutWidget);
        connecButton->setObjectName(QStringLiteral("connecButton"));

        gridLayout->addWidget(connecButton, 0, 3, 3, 1);

        messageLineEdit = new QLineEdit(gridLayoutWidget);
        messageLineEdit->setObjectName(QStringLiteral("messageLineEdit"));

        gridLayout->addWidget(messageLineEdit, 4, 2, 1, 2);

        sendButton = new QPushButton(gridLayoutWidget);
        sendButton->setObjectName(QStringLiteral("sendButton"));

        gridLayout->addWidget(sendButton, 5, 0, 1, 4);

        ipfilesendEdit = new QLineEdit(gridLayoutWidget);
        ipfilesendEdit->setObjectName(QStringLiteral("ipfilesendEdit"));

        gridLayout->addWidget(ipfilesendEdit, 7, 2, 1, 2);

        fileSendButton = new QPushButton(gridLayoutWidget);
        fileSendButton->setObjectName(QStringLiteral("fileSendButton"));

        gridLayout->addWidget(fileSendButton, 8, 0, 1, 4);

        Chatting->setCentralWidget(centralWidget);

        retranslateUi(Chatting);

        QMetaObject::connectSlotsByName(Chatting);
    } // setupUi

    void retranslateUi(QMainWindow *Chatting)
    {
        Chatting->setWindowTitle(QApplication::translate("Chatting", "Chatting", Q_NULLPTR));
        label_4->setText(QApplication::translate("Chatting", "\353\213\211\353\204\244\354\236\204 : ", Q_NULLPTR));
        label_5->setText(QApplication::translate("Chatting", "\355\214\214\354\235\274\354\240\204\354\206\241 IP :", Q_NULLPTR));
        label_3->setText(QApplication::translate("Chatting", "\355\217\254\355\212\270 : ", Q_NULLPTR));
        label_2->setText(QApplication::translate("Chatting", "\353\251\224\354\213\234\354\247\200 :", Q_NULLPTR));
        label->setText(QApplication::translate("Chatting", "IP \354\243\274\354\206\214 :", Q_NULLPTR));
        connecButton->setText(QApplication::translate("Chatting", "\354\240\221\354\206\215", Q_NULLPTR));
        sendButton->setText(QApplication::translate("Chatting", "\354\240\204\354\206\241", Q_NULLPTR));
        fileSendButton->setText(QApplication::translate("Chatting", "\355\214\214\354\235\274 \354\240\204\354\206\241", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Chatting: public Ui_Chatting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATTING_H
