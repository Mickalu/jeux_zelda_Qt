#include "Game.h"
#include "Link.h"
#include "personnage.h"

#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QGraphicsRectItem>


Game:: Game(QWidget * parent)
{
    // create a scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    //Apparition du héro
    player = new Link();
    player->setRect(0,0,100,100);
    player->setPos(400,200); // TODO generalize to always be in the middle bottom of screen

    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    obj = new QGraphicsRectItem();
    obj->setRect(0,0,200,200);
    obj->setPos(200,200);

    enemy_1 = new Enemy();
    enemy_1->setRect(0,0,50,50);
    enemy_1->setPos(0,0);

    scene->addItem(player);
    scene->addItem(obj);
    scene->addItem((enemy_1));



    show();
}
