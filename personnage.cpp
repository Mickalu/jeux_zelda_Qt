#include "personnage.h"

#include<QGraphicsItem>
#include <QGraphicsScene>

Personnage::Personnage(QGraphicsItem *parent): QGraphicsRectItem(parent)
{

}

void Personnage::move_enemy()
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
