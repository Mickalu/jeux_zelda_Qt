#include <QGraphicsScene>
#include <QList>
#include <stdlib.h> // rand() -> really large int
#include <QCoreApplication>
#include <qmath.h>
#include <QPixmap>
#include <QGraphicsLineItem>
#include <QDebug>

#include "Game.h"
#include "Sand.h"


extern Game * game;

Sand::Sand(QGraphicsItem *parent): QGraphicsRectItem(parent)
{

}
