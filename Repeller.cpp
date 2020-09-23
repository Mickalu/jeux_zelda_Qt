#include <QGraphicsScene>
#include <QList>
#include <stdlib.h> // rand() -> really large int
#include <QCoreApplication>
#include <qmath.h>
#include <QPixmap>
#include <QGraphicsLineItem>
#include <QDebug>

#include "Game.h"
#include "Repeller.h"


extern Game * game;

Repeller::Repeller(QGraphicsItem *parent): QGraphicsRectItem(parent)
{

}
