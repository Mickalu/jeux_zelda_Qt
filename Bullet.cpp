#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Enemy.h"
#include "Game.h"
#include <QDebug>
#include "Hero.h"
#include <iostream>
#include "Wall.h"
using namespace std;


extern Game * game;

Bullet::Bullet(QGraphicsItem *parent, std::string direction_struct): QObject(), QGraphicsPixmapItem(parent)
{
    // drew the rect
    setPixmap(QPixmap(":/images/images/fireball.jpg"));
    direction = direction_struct;

    // connect
    QTimer * timer = new QTimer(this);

    // a tous ces timeout() on a la fonction qui va être appelé
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    //EACH 50 milisecond we got a timeout()
    timer->start(50);
}

void Bullet::move()
{
    // get a list of all the items currently colliding with this bullet
    QList<QGraphicsItem *> colliding_items = collidingItems();

    // if one of the colliding items is an Enemy, destroy both the bullet and the enemy
    for (int i = 0, n = colliding_items.size(); i < n; ++i)
    {
        if (typeid(*(colliding_items[i])) == typeid(Enemy))
        {
            // increase the score
            game->score->increase();
            //game->score->increase();

            // remove them from the scene (still on the heap)
            scene()->removeItem(colliding_items[i]);
            // remove the bullet
            scene()->removeItem(this);

            // delete them from the heap to save memory
            delete colliding_items[i];
            //for bullet
            delete this;
            // return (all code below refers to a non existint bullet)*/
            return;
        }

        if (typeid(*(colliding_items[i])) == typeid(Wall))
        {
            scene()->removeItem(this);
            delete this;
            return;
        }

    }

    if(direction == "forward")
    {
        // if there was no collision with an Enemy, move the bullet forward
        setPos(x(),y()-10);

        // if the bullet is off the screen, destroy it
        if (pos().y() + this->boundingRect().height() < 0)
        {
            scene()->removeItem(this);
            delete this;
        }
    }

    else if(direction == "right")
    {
        // if there was no collision with an Enemy, move the bullet forward
        setPos(x()+10,y());

        // if the bullet is off the screen, destroy it
        if (pos().y() + this->boundingRect().width() < 0)
        {
            scene()->removeItem(this);
            delete this;
        }
    }

    else if(direction == "left")
    {
        // if there was no collision with an Enemy, move the bullet forward
        setPos(x()-10,y());

        // if the bullet is off the screen, destroy it
        if (pos().y() + this->boundingRect().width() < 0)
        {
            scene()->removeItem(this);
            delete this;
        }
    }

    else if(direction == "down")
    {
        setPos(x(),y()+10);

        // if the bullet is off the screen, destroy it
        if (pos().y() + this->boundingRect().height() < 0)
        {
            scene()->removeItem(this);
            delete this;
        }
    }
}
