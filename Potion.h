#ifndef POTION_H
#define POTION_H


#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsTextItem>
#include "Element.h"

class Potion:public QObject,  public QGraphicsPixmapItem, public Element
{
public:
    Potion();
};

#endif // POTION_H
