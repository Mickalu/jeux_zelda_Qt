#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h> // rand() -> really large int
#include <QTime>
#include <QCoreApplication>
#include <qmath.h>
#include <QPixmap>
#include <QGraphicsLineItem>
#include <QDebug>
#include "Wall.h"
#include "Game.h"
#include "Element.h"


extern Game * game;

Wall::Wall(QGraphicsItem *parent): QGraphicsRectItem(parent)
{

}
