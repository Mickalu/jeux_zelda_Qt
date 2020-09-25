#include "Wall.h"
#include "Game.h"

extern Game * game;

Wall::Wall(QGraphicsItem *parent): QGraphicsRectItem(parent)
{
    setBrush(QImage(":/images/images/wall.png"));
}
