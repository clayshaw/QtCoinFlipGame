#include "mainsense.h"
#include "ui_mainsense.h"
#include <QPainter>
#include "mypushbutton.h"
#include <QTimer>

MainSense::MainSense(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainSense)
{
    ui->setupUi(this);
    setFixedSize(320,588);
    setWindowIcon(QIcon(":/res/Coin0001.png"));

    connect(ui->actionQuit,&QAction::triggered,[=](){
        this->close();
    });



    MyPushbutton *startBtn = new MyPushbutton(":/res/MenuSceneStartButton.png");
    startBtn->setParent(this);
    startBtn->move(this->width() * 0.5-startBtn->width()*0.5,this->height()*0.55);

    scene = new chooseScene();



    connect(startBtn,&QPushButton::clicked,[=](){
//      qDebug()<<"clicked";
        startBtn->zoom();

        QTimer::singleShot(200,this,[=](){
            scene->setGeometry(this->geometry());
            this->hide();
            scene->show();
        });


    });

    connect(scene->backBtn,&MyPushbutton::clicked,this,[=](){
        this->setGeometry(scene->geometry());
        scene->hide();
        this->show();
    });
}

MainSense::~MainSense()
{
    delete ui;
}

void MainSense::paintEvent(QPaintEvent * ev){
    QPainter painter(this);
    QPixmap img;
    img.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),img);

    img.load(":/res/Title.png");
    painter.drawPixmap(0,30,img);
}
