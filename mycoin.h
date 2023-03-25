#ifndef MYCOIN_H
#define MYCOIN_H

#include <QWidget>
#include <QPushButton>
#include "mycoin.h"

class myCoin : public QPushButton
{
    Q_OBJECT
public:
//    explicit myCoin(QWidget *parent = nullptr);
        myCoin(QString btnimg);

        int posX;
        int posY;
        int flag;
        int min;
        int max;
        bool isWin= false;

        bool isAnimation;

        QTimer *time1;
        QTimer *time2;

        void mousePressEvent(QMouseEvent *event);
        void changeFlag();

signals:

};

#endif // MYCOIN_H
