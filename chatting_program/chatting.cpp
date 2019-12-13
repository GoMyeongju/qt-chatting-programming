#include "chatting.h"
#include "ui_chatting.h"

Chatting::Chatting(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Chatting)
{
    ui->setupUi(this);
}

Chatting::~Chatting()
{
    delete ui;
}
