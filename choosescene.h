#ifndef CHOOSESCENE_H
#define CHOOSESCENE_H

#include <QMainWindow>
#include "mypushbutton.h"
#include <QLabel>
#include "playscene.h"

class chooseScene : public QMainWindow
{
public:
    explicit chooseScene(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *);

    MyPushbutton *backBtn;
    MyPushbutton *menuBtn[20];
    QLabel *label[20];
private:
    PlayScene *play[20];
signals:


};

#endif // CHOOSESCENE_H
