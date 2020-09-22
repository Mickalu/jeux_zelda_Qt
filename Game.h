#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "Hero.h"
#include "Score.h"
#include "Wall.h"



class Game: public QGraphicsView
{
public:
    Game(QWidget * parent = 0);

    QGraphicsScene * scene;
    Hero * hero;
    Score * score;
};

#endif // GAME_H
