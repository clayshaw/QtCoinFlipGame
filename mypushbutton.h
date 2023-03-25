#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QString>
#include <QMouseEvent>

class MyPushbutton :public QPushButton
{
public:
    MyPushbutton(QString normalImg,QString pressImg = "");

    QString normalImgPath;
    QString pressImgPath;

    void zoom();

    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
};

#endif // MYPUSHBUTTON_H
