#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>
#include "mypushbutton.h"
#include "mycoin.h"

namespace Ui {
class PlayScene;
}

class PlayScene : public QMainWindow
{
    Q_OBJECT

public:
    explicit PlayScene(QWidget *parent = nullptr);
    PlayScene(int i,QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *);
    ~PlayScene();

    int gameArray[4][4];
    myCoin *coinBtn[4][4];

    bool isWin;
    int LevelScene;


private:


    Ui::PlayScene *ui;
signals:
    void backTochoose();
};

#endif // PLAYSCENE_H
