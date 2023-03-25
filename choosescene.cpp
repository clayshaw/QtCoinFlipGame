#include "choosescene.h"
#include <QPainter>
#include "mypushbutton.h"
#include <QTimer>
#include <QLabel>
#include <playscene.h>

chooseScene::chooseScene(QWidget *parent)
    : QMainWindow{parent}
{
    for(int i=0;i<20;i++)
        play[i] = nullptr;
    setFixedSize(320,588);
    setWindowIcon(QIcon(":/res/Coin0001.png"));

    backBtn = new MyPushbutton(":/res/BackButton.png","/res/BackButtonSelected.png");
    backBtn->setParent(this);
    backBtn->move(this->width()-backBtn->width(),this->height()-backBtn->height());


    for(int i=0;i<20;i++){
        menuBtn[i] = new MyPushbutton(":/res/LevelIcon.png");
        menuBtn[i]->setParent(this);
        menuBtn[i]->move(25 + (i%4)*70,130+ (i/4)*70);

        label[i] = new QLabel(menuBtn[i]);
        label[i]->setFixedSize(menuBtn[i]->width(),menuBtn[i]->height());
        label[i]->setText(QString::number(i+1));
        label[i]->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

        connect(menuBtn[i],&MyPushbutton::clicked,[=](){
            qDebug()<< QString("Choose %1 ").arg(i+1);
            this->hide();
            play[i] = new PlayScene(i+1,this);
            play[i]->setGeometry(this->geometry());
            play[i]->show();

            connect(play[i],&PlayScene::backTochoose,[=](){
                this->setGeometry(play[i]->geometry());
                play[i]->hide();
                this->show();
            });


        });
    }

}


void chooseScene::paintEvent(QPaintEvent *ev){

    QPainter painter(this);
    QPixmap img;
    img.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),img);

    img.load(":/res/Title.png");
    painter.drawPixmap(0,0,img);
}


