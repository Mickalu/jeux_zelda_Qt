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
#include "Game.h"
#include "Potion.h"


extern Game * game;

Potion::Potion()
{
     setRect(0,0, 10,50);
}