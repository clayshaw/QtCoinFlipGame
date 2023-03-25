#include "mypushbutton.h"
#include <QPropertyAnimation>

MyPushbutton::MyPushbutton(QString normalImg,QString pressImg)
{
    this->normalImgPath = normalImg;
    this->normalImgPath = pressImg;

    QPixmap pix;
    if(!pix.load(normalImg)){
        qDebug()<<"Upload Fail";
        return;
    }


    this->setFixedSize(pix.width(),pix.height());
    this->setStyleSheet("QPushButton{border:0px}");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(),pix.height()));
}


void MyPushbutton::zoom(){
    QPropertyAnimation *pro = new QPropertyAnimation(this,"geometry");
    pro->setDuration(50);
    pro->setStartValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    pro->setStartValue(QRect(this->x(),this->y()-10,this->width(),this->height()));
    pro->start();
}


void MyPushbutton::mousePressEvent(QMouseEvent *ev){

    if(pressImgPath != ""){
        QPixmap pix;
        if(!pix.load(pressImgPath)){
            qDebug()<<"Upload Fail";
            return;
        }

        this->setFixedSize(pix.width(),pix.height());
        this->setStyleSheet("QPushButton{border:0px}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(),pix.height()));
    }

    return QPushButton::mousePressEvent(ev);
}


void MyPushbutton::mouseReleaseEvent(QMouseEvent *ev){
    if(pressImgPath != ""){
        QPixmap pix;
        if(!pix.load(normalImgPath)){
            qDebug()<<"Upload Fail";
            return;
        }

        this->setFixedSize(pix.width(),pix.height());
        this->setStyleSheet("QPushButton{border:0px}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(),pix.height()));
    }

    return QPushButton::mouseReleaseEvent(ev);
}
