#ifndef WALL_H
#define WALL_H


#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsTextItem>
#include <QGraphicsPixmapItem>
#include "Element.h"

class Wall:public QObject, public QGraphicsRectItem, public Element
{
    Q_OBJECT
public:
    Wall(QGraphicsItem * parent = 0);


public slots:

private:
};

#endif // WALL_H
