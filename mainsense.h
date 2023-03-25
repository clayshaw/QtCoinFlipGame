#ifndef MAINSENSE_H
#define MAINSENSE_H

#include <QMainWindow>
#include "choosescene.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainSense; }
QT_END_NAMESPACE

class MainSense : public QMainWindow
{
    Q_OBJECT

public:
    MainSense(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
    ~MainSense();

    chooseScene *scene = nullptr;

private:
    Ui::MainSense *ui;
};
#endif // MAINSENSE_H
