#include "chatting.h"
#include "ui_chatting.h"
#include <QRegExp>
#include <QTcpSocket>
#include <time.h>

Chatting::Chatting(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Chatting)
{
    ui->setupUi(this);
    setLayout(ui->gridLayout);
    setWindowTitle("Chatting Client");
}

Chatting::~Chatting()
{
    delete ui;
    delete socket;
}

void Chatting::readyRead(){
    while(socket->canReadLine()){
        QString line=QString::fromUtf8(socket->readLine());
        line=line.left(line.length()-1);
        ui->listWidget->addItem(QString("%2").arg(line));
    }

    ui->listWidget->scrollToBottom();
}

void Chatting::connected(){
    socket->write(QString("new user join JJ's chatting :)\n IP : "+ui->ipLineEdit->text() + "Nicname : "+ui->nicname->text()+"\n").toUtf8());

}

void Chatting::on_connectButton_clicked(){
    socket = new QTcpSocket(this);

    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    connect(socket, SIGNAL(connected()), this, SLOT(connected()));
    socket->connectToHost(ui->ipLineEdit->text(), ui->portLineEdit->text().toInt());
}

void Chatting::on_sendButton_clicked(){
    QString message=ui->messageLineEdit->text().trimmed();
    QString nic=ui->nicname->text().trimmed();
    ct = time(NULL);
    tm = *localtime(&ct);
    sprintf(strTime, "[%02d:%02d:%02d]", tm.tm_hour, tm.tm_min, tm.tm_sec);

    if(!message.isEmpty()){
        socket->write(QString(strTime+nic+"> "+message+"\n").toUtf8());
    }
    ui->messageLineEdit->clear();
    ui->messageLineEdit->setFocus();
}

void Chatting::on_messageLineEdit_returnPressed(){
    on_sendButton_clicked();
}
