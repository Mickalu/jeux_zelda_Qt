#include "Game.h"
#include "Repeller.h"

extern Game * game;

Repeller::Repeller(QGraphicsItem *parent): QGraphicsRectItem(parent)
{
    setBrush(QImage(":/images/images/desert.png"));
}
