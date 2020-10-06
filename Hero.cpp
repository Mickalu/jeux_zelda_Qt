#include "Hero.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Potion.h"
#include "Wall.h"
#include "Door.h"
#include "Repeller.h"
#include "Health.h"
#include "Game.h"

#include <QKeyEvent>
#include <QGraphicsScene>

#include <QTimer>
#include <QFont>
#include <QTextEdit>
#include <QGraphicsTextItem>
#include <QGraphicsPixmapItem>
#include <iostream>
#include <QMediaPlayer>

using namespace std;

extern Game * game;

Hero::Hero(QGraphicsItem *parent, std::string axe_bulette_struct)
{
    axe_bullet = axe_bulette_struct;
    setPixmap(QPixmap(":/images/images/link_up.png"));
    collision = false;


    QTimer * timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(collision_management()));
    timer->start(50);

    bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl("qrc:/sounds/sounds/pistol_fire3.mp3"));

    degat_sound = new QMediaPlayer();
    degat_sound->setMedia(QUrl("qrc:/sounds/sounds/classic_hurt.mp3"));

    heal_sound = new QMediaPlayer();
    heal_sound->setMedia(QUrl("qrc:/sounds/sounds/healing-pokemon-sound.mp3"));

    game_over_song = new QMediaPlayer();
    game_over_song->setMedia(QUrl("qrc:/sounds/sounds/titanic-parody-mp3cut.mp3"));
}

void Hero::keyPressEvent(QKeyEvent *event)
{

    if(event->key() == Qt::Key_Left)
    {
        // on vérifie que la le cube ne sort pas du cadre
        axe_bullet = "left";
        if(collision == true)
        {

        }
        else
        {
            if (pos().x() > 0){
                setPixmap(QPixmap(":/images/images/link_left.png"));
                setPos(x()-10, y());
            }
        }
        collision = false;

    }
    else if (event->key() == Qt::Key_Right)
    {
        // on vérifie que le cube ne sort pas par la droite
        axe_bullet = "right";

        if(collision == true)
        {

        }
        else
        {
            if (pos().x()+40 < 1000){
                setPixmap(QPixmap(":/images/images/link_right.png"));
                setPos(x()+10, y());
            }
        }
        collision = false;

    }
    else if (event->key() == Qt::Key_Up)
    {
        axe_bullet = "forward";

        if(collision == true)
        {

        }
        else
        {
            if (pos().y() > 0){
                setPixmap(QPixmap(":/images/images/link_up.png"));
                setPos(x(), y()-10);
            }
        }
        collision = false;

    }
    else if (event->key() == Qt::Key_Down)
    {
        axe_bullet = "down";
        if(collision == true)
        {

        }
        else
        {
            if (pos().y()+50 < 750){
                setPixmap(QPixmap(":/images/images/link_down.png"));
                setPos(x(), y()+10);
            }
        }
        collision = false;
    }

    else if (event->key() == Qt::Key_Space)
    {

        // create a bullet

        Bullet * bullet = new Bullet(0,axe_bullet);
        bullet->setPos(x(), y());
        scene()->addItem(bullet);


        //play bulletsound
        //stop the song if it already work
        start_song(bulletsound);
    }
}

void Hero::collision_management()
{
    QList<QGraphicsItem*> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i)
    {

        if (typeid(*(colliding_items[i])) == typeid(Enemy))
        {
            collision = true;
            start_song(degat_sound);
            game->health->decreaseHealth();

            if(game->health->getHealth() == 0)
            {
                emit heroDied();
                scene()->clear();
            }

            gestion_impact_hero_movement();
        }
        else if (typeid(*(colliding_items[i])) == typeid(Potion))
        {
            game->health->increaseHealth();
            start_song(heal_sound);
            scene()->removeItem(colliding_items[i]);
            delete colliding_items[i];
        }

        else if (typeid(*(colliding_items[i])) == typeid(Wall))
        {
            collision = true;
            gestion_impact_hero_movement();
        }
        else if (typeid(*(colliding_items[i])) == typeid(Repeller))
        {
            gestion_impact_hero_movement();
        }
        else if (typeid(*(colliding_items[i])) == typeid(Door))
        {
            emit doorTouched();
            game->scene->clear();
            QGraphicsTextItem * win = new QGraphicsTextItem("Pay the extension to have access to the entire game !");
            win->setDefaultTextColor((Qt::black));
            win->setFont(QFont("times", 18));
            win->setPos(game->scene->width()/2 - win->boundingRect().width()/2,50);
            game->scene->addItem(win);
        }
        return;
    }
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

void Hero::start_song(QMediaPlayer *song)
{
    if (song->state() == QMediaPlayer::PlayingState)
    {
        song->setPosition(0);
    }
    else if (song->state() == QMediaPlayer::StoppedState)
    {
        song->play();
    }
}
