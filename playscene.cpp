#include "playscene.h"
#include "ui_playscene.h"
#include <QPainter>
#include <QMenuBar>
#include "mypushbutton.h"
#include <QTimer>
#include <QLabel>
#include <mycoin.h>
#include "dataconfig.h"
#include <QPropertyAnimation>
#include <QRect>

PlayScene::PlayScene(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PlayScene)
{
    ui->setupUi(this);
    setFixedSize(320,588);
    setWindowIcon(QIcon(":/res/Coin0001.png"));
}

PlayScene::~PlayScene()
{
    delete ui;
}

PlayScene::PlayScene(int i,QWidget *parent){
    qDebug()<<QString("Enter %1").arg(i);
    this->LevelScene = i;
    setFixedSize(320,588);
    setWindowIcon(QIcon(":/res/Coin0001.png"));
    setWindowTitle("Scene");

    QMenuBar *menubar = new QMenuBar();
    QMenu *menu = menubar->addMenu("start");
    QAction *a = menubar->addAction("close");

    connect(a,&QAction::triggered,[=](){
        this->close();
    });


    MyPushbutton * backBtn = new MyPushbutton(":/res/BackButton.png","/res/BackButtonSelected.png");
    backBtn->setParent(this);
    backBtn->move(this->width()-backBtn->width(),this->height()-backBtn->height());

    connect(backBtn,&MyPushbutton::clicked,[=](){
        QTimer::singleShot(200,this,[=](){
            emit this->backTochoose();
        });

    });

    QLabel *label = new QLabel(this);
    QFont font;
    font.setFamily("微軟正黑體");
    font.setPointSize(20);
    label->setFont(font);
    label->setText(QString("Level : %1").arg(this->LevelScene));
    label->setGeometry(30,this->height()-50,120,50);

    dataConfig conf;
    for(int i =0;i<4;i++){
        for(int j=0;j<4;j++){
            this->gameArray[i][j] = conf.mData[this->LevelScene][i][j];
        }
    }

    QLabel *lab = new QLabel;
    QPixmap pixm;
    pixm.load(":/res/LevelCompletedDialogBg.png");
    lab->setGeometry(0,0,pixm.width(),pixm.height());
    lab->setPixmap(pixm);
    lab->setParent(this);
    lab->move((this->width()-pixm.width())*0.5 , -pixm.height());


    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){

            QLabel *label = new QLabel(this);
            QPixmap pix;
            pix.load(":/res/BoardNode.png");
            label->setGeometry(0,0,pix.width(),pix.height());
            label->setPixmap(pix);
            label->move(57+i*50,200+j*50);

            QString str;
            if(gameArray[i][j] == 1){
                str = ":/res/Coin0001.png";
            } else {
                str = ":/res/Coin0008.png";
            }

            myCoin *coin = new myCoin(str);
            coin->setParent(label);
            coin->move((label->width()-coin->width())/2,(label->height()-coin->height())/2);


            coin->posX = i;
            coin->posY = j;
            coin->flag = gameArray[i][j];

            coinBtn[i][j] = coin;

            connect(coin,&QPushButton::clicked,[=](){
                coin->changeFlag();
                this->gameArray[i][j] = this->coinBtn[i][j] == 0 ? 0:1;

                if(coin->posX +1 <= 3){
                    coinBtn[coin->posX+1][coin->posY]->changeFlag();
                }
                if(coin->posX -1>=0){
                    coinBtn[coin->posX-1][coin->posY]->changeFlag();
                }
                if(coin->posY+1<=3){
                    coinBtn[coin->posX][coin->posY+1]->changeFlag();
                }
                if(coin->posY-1>=0){
                    coinBtn[coin->posX][coin->posY-1]->changeFlag();
                }

                this->isWin = true;
                for(int i=0;i<4;i++){
                    for(int j=0;j<4;j++){
                        if(coinBtn[i][j]->flag == 0){
                            this->isWin = false;
                            i= 5;
                            break;
                        }
                    }
                }
                if(isWin == true){
                    qDebug()<<"Win";
                    for(int i=0;i<4;i++){
                        for(int j=0;j<4;j++){
                            if(coinBtn[i][j]->flag == 1){
                                coinBtn[i][j]->isWin = true;
                            }
                        }
                    }

                    QPropertyAnimation *pro = new QPropertyAnimation(lab,"geometry");
                    pro->setDuration(1000);
                    pro->setStartValue(QRect(lab->x(),lab->y(),lab->width(),lab->height()));
                    pro->setEndValue(QRect(lab->x(),lab->y()+200,lab->width(),lab->height()));
                    pro->setEasingCurve(QEasingCurve::OutBounce);
                    pro->start();
                }
            });
        }
    }

}

void PlayScene::paintEvent(QPaintEvent * ev){
    QPainter painter(this);
    QPixmap img;
    img.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),img);
    img.load(":/res/Title.png");
    painter.drawPixmap(0,0,img);
}

