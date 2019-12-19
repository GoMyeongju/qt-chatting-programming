#ifndef CHATTING_H
#define CHATTING_H

#include <QMainWindow>

namespace Ui {
class Chatting;
}

class QTcpSocket;

class Chatting : public QMainWindow
{
    Q_OBJECT

public:
    explicit Chatting(QWidget *parent = 0);
    ~Chatting();

private slots:
    void readyRead();
    void connected();
    void on_connectButton_clicked();
    void on_sendButton_clicked();

    void on_messageLineEdit_returnPressed();

private:
    Ui::Chatting *ui;
    QTcpSocket* socket;
    time_t ct;
    struct tm tm;
    char strTime[50];
};

#endif // CHATTING_H
