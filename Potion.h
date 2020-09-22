#ifndef POTION_H
#define POTION_H


#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsTextItem>
#include "Element.h"

class Potion:public QObject,  public QGraphicsRectItem, public Element
{
public:
    Potion();
};

#endif // POTION_H
