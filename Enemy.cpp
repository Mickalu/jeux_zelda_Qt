#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h> // rand() -> really large int
#include "Game.h"
#include <QTime>
#include <QCoreApplication>
#include <qmath.h>
#include <QPixmap>
#include <QGraphicsLineItem>
#include <QDebug>


extern Game * game;

Enemy::Enemy(QGraphicsItem *parent, QList<QPointF>points, int health_constr = 12)
{
    //set points
    //points_list << QPointF(0,100) << QPointF(400, 0) << QPointF(10,10);
    points_list = points;
    point_index = 0;
    dest = points_list[0];
    rotateToPoint(dest);
    health = health_constr;
    setPixmap(QPixmap(":/images/images/toad.png"));

    //connect timer to move function
    QTimer * timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}


void Enemy::move()
{
    /*
    if(collision_with_hero() == true)
    {
        setPos(x(), y());
    }
    */
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

void Enemy::health_decrease()
{
    health--;
    //setPlainText(QString("Health: ") + QString::number(health));
}

void Enemy::health_increase()
{
    health++;
    //setPlainText(QString("Health: ") + QString::number(health));
}

int Enemy::getHealth()
{
    return health;
}

/*
bool Enemy::collision_with_hero()
{

    QList<QGraphicsItem *> colliding_items = collidingItems();

    // if one of the colliding items is an Enemy, destroy both the bullet and the enemy
    for (int i = 0, n = colliding_items.size(); i < n; ++i)
    {
        if (typeid((colliding_items[i])) == typeid(Enemy *))
        {
            return true;
        }
        return false;
    }
}*/

/*
void Enemy::move_direction(QString direction)
{
    if (direction == "forward")
    {
        setPos(x()+5, y());
    }
    else if (direction == "right")
    {
        setPos(x(), y()+5);
    }
    else if (direction == "bottom")
    {
        setPos(x()-5, y());
    }
    else if (direction == "left")
    {
        setPos(x(), y()-5);
    }


    // On regarde si la balle est en dehors de l'écran
    if(pos().y() > 600)
    {
        game->health->decrease();
        scene()->removeItem(this);
        delete this;
    }
}

void Enemy::move_bottom()
{
    setPos(x()+5, y());
}

void Enemy::move_right()
{
    setPos(x(), y()+5);
}

void Enemy::move_left()
{
    setPos(x(), y()-5);
}

void Enemy::move_forward()
{
    setPos(x()-5, y());
}
*/


