#include "mycoin.h"
#include <QPixmap>
#include <QDebug>
#include <QTimer>

myCoin::myCoin(QString btnimg)
{
    min = 1;
    max = 8;
    time1 = new QTimer(this);
    time2 = new QTimer(this);
    isAnimation = false;
    QPixmap pix;
    if(!pix.load(btnimg)){
        QString s = QString("Pix %1 load fail.").arg(btnimg);
        qDebug()<<s;
        return;
    }

    this->setFixedSize(pix.width(),pix.height());
    this->setStyleSheet("QPushButton{border:0px;}");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(),pix.height()));


    connect(time1,&QTimer::timeout,[=](){
        QPixmap pix;
        QString str = QString(":/res/Coin000%1.png").arg(min++);
        pix.load(str);
        this->setFixedSize(pix.width(),pix.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(),pix.height()));

        if(min>max){
            min = 1;
            isAnimation = false;
            time1->stop();

        }
    });

    connect(time2,&QTimer::timeout,[=](){
        QPixmap pix;
        QString str = QString(":/res/Coin000%1.png").arg(max--);
        pix.load(str);

        this->setFixedSize(pix.width(),pix.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(),pix.height()));

        if(this->max < this->min){
            this->max = 8;
            isAnimation = false;
            time2->stop();

        }
    });

}

void myCoin::changeFlag(){
    if(this->flag == 1){

        time1->start(30);
        isAnimation = true;
        this->flag = 0;
    } else {
        time2->start(30);
        isAnimation = true;
        this->flag = 1;
    }


}


void myCoin::mousePressEvent(QMouseEvent *event){
    if(isAnimation == true || this->isWin){
        return;
    } else {
        return QPushButton::mousePressEvent(event);
    }
}
