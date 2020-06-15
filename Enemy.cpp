#include "Enemy.h"
#include "Game.h"

#include<QKeyEvent>
#include<QGraphicsRectItem>
#include <QGraphicsScene>
#include <QList>
#include<QTimer>
#include <stdlib.h> // rand() -> really large int
#include<QObject>

extern Game * game;


Enemy::Enemy():Personnage()
{
    // connect
    QTimer * timer = new QTimer(this);

    // a tous ces timeout() on a la fonction qui va être appelé
    connect(timer, SIGNAL(timeout()), this, SLOT(move_enemy()));

    //EACH 50 milisecond we got a timeout()
    timer->start(50);
}

void Enemy::move()
{
    // move Enemy down
    setPos(x(), y()+5);

    // On regarde si la balle est en dehors de l'écran
    if(pos().y() > 600)
    {
        scene()->removeItem(this);
        delete this;
    }
}

void Enemy::spawn()
{
    // create an enemy
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}

