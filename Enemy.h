#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QList>
#include <QPointF>
#include "Element.h"


// bullet hérite de QObject et de QGraphicsRectItem
class Enemy: public QObject, public QGraphicsPixmapItem, public Element
{
    // QOBJECT macro
    Q_OBJECT

public:
    Enemy(QGraphicsItem * parent, QList<QPointF>points);

    void rotateToPoint(QPointF point);

public slots:
    // fonction move de bullet
    void move();

private:
    QList<QPointF> points_list;
    QPointF dest;
    int point_index;
};
#endif // ENEMY_H
