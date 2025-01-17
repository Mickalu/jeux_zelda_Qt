#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include "Game.h"
#include <QTime>
#include <QCoreApplication>
#include <qmath.h>
#include <QPixmap>
#include <QGraphicsLineItem>
#include <QDebug>


extern Game * game;

Enemy::Enemy(QGraphicsItem *parent, QList<QPointF>points)
{
    points_list = points;
    point_index = 0;
    dest = points_list[0];
    rotateToPoint(dest);
    setPixmap(QPixmap(":/images/images/toad.png"));

    //connect timer to move function
    QTimer * timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}


void Enemy::move()
{
    // if close to dest, rotate to next dest
    QLineF ln(pos(), dest);
    //qInfo() << points_list;
    if (ln.length() < 5)
    {
        point_index++;
        if (point_index >= points_list.size())
        {
            point_index = 0;
            dest = points_list[0];
            rotateToPoint(dest);
        }
    }
    else
    {
        dest = points_list[point_index];
        rotateToPoint(dest);
    }

    // move enemy forward at current angle
    int STEP_SIZE = 5;
    double theta = rotation(); // degrees

    double dy = STEP_SIZE * qSin(qDegreesToRadians(theta));
    double dx = STEP_SIZE * qCos(qDegreesToRadians(theta));

    setPos(qreal(x()+dx), qreal(y()+dy));

}


void Enemy::rotateToPoint(QPointF p)
{
    QLineF ln(pos(), p);
    setRotation(-1 * ln.angle());
}
