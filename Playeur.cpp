#include "Playeur.h"
#include <QKeyEvent>
#include <QGraphicsScene>

Playeur::Playeur(QGraphicsItem *parent): QGraphicsRectItem(parent)
{

}

void Playeur::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left)
    {
        // on vérifie que la le cube ne sort pas du cadre
        if (pos().x() > 0)
        setPos(x()-10, y());
    }
    else if (event->key() == Qt::Key_Right)
    {
        // on vérifie que le cube ne sort pas par la droite
        if(pos().x()+100 < 800)
        setPos(x()+10, y());
    }

    else if (event->key() == Qt::Key_Up)
    {
        setPos(x(), y()-10);
    }
    else if (event->key() == Qt::Key_Down)
    {
        setPos(x(), y()+10);
    }
    /*
    else if (event->key() == Qt::Key_Space)
    {
        // create a bullet
        Bullet * bullet = new Bullet();
        bullet->setPos(x(), y());
        scene()->addItem(bullet);

        //play bulletsound
        //stop the song if it already work
        if (bulletsound->state() == QMediaPlayer::PlayingState)
        {
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState)
        {
            bulletsound->play();
        }
    }*/
}
