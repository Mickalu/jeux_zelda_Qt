#ifndef REPELLER_H
#define REPELLER_H


#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsTextItem>
#include <QGraphicsPixmapItem>
#include "Element.h"

class Repeller:public QObject, public QGraphicsRectItem, public Element
{
    Q_OBJECT
public:
    Repeller(QGraphicsItem * parent = 0);


public slots:

private:
};

#endif // REPELLER_H
