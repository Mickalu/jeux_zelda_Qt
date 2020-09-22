#include "Hero.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Potion.h"
#include "Wall.h"

#include <QKeyEvent>
#include <QGraphicsScene>

#include <QDebug>
#include <QTimer>
#include <QFont>
#include <QTextEdit>
#include <QGraphicsTextItem>
#include <iostream>
using namespace std;

Hero::Hero(QGraphicsItem *parent, int health_constr, std::string axe_bulette_struct): QGraphicsRectItem(parent)
{
    health = health_constr;
    axe_bullet = axe_bulette_struct;


    QTimer * timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(collision_management()));
    timer->start(50);

    /*
    // draw the text
    setPlainText(QString("Health: ") + QString::number(health)); // Health: 3
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
    */
}

void Hero::keyPressEvent(QKeyEvent *event)
{

    if(event->key() == Qt::Key_Left)
    {
        // on vérifie que la le cube ne sort pas du cadre
        axe_bullet = "left";
        if (pos().x() > 0)
        setPos(x()-10, y());
    }
    else if (event->key() == Qt::Key_Right)
    {
        // on vérifie que le cube ne sort pas par la droite
        axe_bullet = "right";
        if(pos().x()+100 < 800)
        setPos(x()+10, y());
    }
    else if (event->key() == Qt::Key_Up)
    {
        axe_bullet = "forward";
        setPos(x(), y()-10);
    }
    else if (event->key() == Qt::Key_Down)
    {
        axe_bullet = "down";
        setPos(x(), y()+10);
    }

    else if (event->key() == Qt::Key_Space)
    {

        // create a bullet

        Bullet * bullet = new Bullet(0,axe_bullet);
        bullet->setPos(x(), y());
        scene()->addItem(bullet);

        /*
        //play bulletsound
        //stop the song if it already work
        if (bulletsound->state() == QMediaPlayer::PlayingState)
        {
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState)
        {
            bulletsound->play();
        }*/
    }
}

void Hero::collision_management()
{
    QList<QGraphicsItem*> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i)
    {
        if (typeid(*(colliding_items[i])) == typeid(Enemy))
        {
            health_decrease();

            if(health == 0)
            {
                scene()->removeItem(this);
                delete this;
            }

            gestion_impact_hero_movement();
        }
        else if (typeid(*(colliding_items[i])) == typeid(Potion))
        {
            health_increase();
            scene()->removeItem(colliding_items[i]);
            qInfo() << health;
        }

        else if (typeid(*(colliding_items[i])) == typeid(Wall))
        {
            gestion_impact_hero_movement();
        }
        return;
    }
}

void Hero::health_decrease()
{
    health--;
    //setPlainText(QString("Health: ") + QString::number(health));
}

void Hero::health_increase()
{
    health++;
    //setPlainText(QString("Health: ") + QString::number(health));
}

int Hero::getHealth()
{
    return health;
}

std::string Hero::get_axe_bullet()
{
    return axe_bullet;
}

void Hero::gestion_impact_hero_movement()
{
    if(axe_bullet == "right")
    {
        setPos(x()-10, y());
    }
    else if(axe_bullet == "left")
    {
        setPos(x()+10, y());
    }
    else if(axe_bullet == "down")
    {
        setPos(x(), y()-10);
    }
    else if(axe_bullet == "forward")
    {
        setPos(x(), y()+10);
    }
}
