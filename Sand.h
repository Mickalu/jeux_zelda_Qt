#ifndef SAND_H
#define SAND_H


#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsTextItem>
#include <QGraphicsPixmapItem>
#include "Element.h"

class Sand:public QObject, public QGraphicsRectItem, public Element
{
    Q_OBJECT
public:
    Sand(QGraphicsItem * parent = 0);


public slots:

private:
};

#endif
