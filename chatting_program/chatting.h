#ifndef CHATTING_H
#define CHATTING_H

#include <QMainWindow>

namespace Ui {
class Chatting;
}

class Chatting : public QMainWindow
{
    Q_OBJECT

public:
    explicit Chatting(QWidget *parent = 0);
    ~Chatting();

private:
    Ui::Chatting *ui;
};

#endif // CHATTING_H
