#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>
#include <QList>
#include <QPointF>
#include "Element.h"


// bullet hérite de QObject et de QGraphicsRectItem
class Enemy: public QObject, public QGraphicsRectItem, public Element
{
    // QOBJECT macro
    Q_OBJECT

public:
    /*
    Enemy(QGraphicsItem * parent=0, QList<QPointF>points = QList<QPointF>()<< QPointF(0,0));
    Enemy(QList<QPointF>points = QList<QPointF>()<< QPointF(0,0));*/
    Enemy(QGraphicsItem * parent, QList<QPointF>points, int health_constr);

    void rotateToPoint(QPointF point);
    void health_decrease();
    void health_increase();
    int getHealth();
    //bool collision_with_hero();

public slots:
    // fonction move de bullet
    void move();
    /*
    void move_direction(QString direction);
    void move_bottom();
    void move_right();
    void move_left();
    void move_forward();*/




private:
    QList<QPointF> points_list;
    QPointF dest;
    int point_index;
    int health;
};
#endif // ENEMY_H
