#ifndef GAME_H
#define GAME_H


#include"Link.h"
#include"Enemy.h"


#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>

class Game: public QGraphicsView
{
public:
    Game(QWidget * parent = 0);

    QGraphicsScene * scene;
    Link * player;
    QGraphicsRectItem * obj;
    Enemy * enemy_1;
};


#endif // GAME_H
