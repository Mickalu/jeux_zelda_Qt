#include "Game.h"
#include "Hero.h"
#include "Enemy.h"
#include "Wall.h"
#include "Potion.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QLabel>




Game:: Game(QWidget * parent)
{
    // create a scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600); // make the scene 800x600 instead of infinity by infinity (default)

    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    //creation map element etc
    Wall * wall_up = new Wall();
    wall_up->setRect(0,0,50,1000);
    wall_up->setPos(0,0);
    scene->addItem(wall_up);

    Wall * wall_right = new Wall();
    wall_right->setRect(0,0,100,30);
    wall_right->setPos(400,400);
    scene->addItem(wall_right);

    Potion * potion = new Potion();

    potion->setRect(0,0,10,10);
    potion->setPos(100,300);
    scene->addItem(potion);



    // create an itemm to add to the scene
    hero = new Hero(0, 12,"forward");
    hero->setRect(0,0,100,100);
    hero->setPos(400,500); // TODO generalize to always be in the middle bottom of screen


    // make rect focusable il reçois tous les keyboard event
    hero->setFlag(QGraphicsItem::ItemIsFocusable);
    hero->setFocus();

    scene->addItem(hero);

    // create the score
    score = new Score();
    scene->addItem(score);


    // a enlever pour mettre des enemies placés

    // spawn enemies
    /*
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),hero,SLOT(spawn()));
    timer->start(2000);*/



    QList<QPointF>points_list;
    points_list << QPointF(100,100) << QPointF(100, 200) << QPointF(200,200) << QPointF(100,0);
    Enemy * enemy1 = new Enemy(0, points_list, 12);

    enemy1->setRect(0,0,10,10);
    enemy1->setPos(100,0);
    scene->addItem(enemy1);


    QList<QPointF>points_list_enemy2;
    points_list_enemy2 << QPointF(100,100) << QPointF(200, 100) << QPointF(0,100) <<QPointF(0,0) << QPointF(100,0);
    Enemy * enemy2 = new Enemy(0, points_list_enemy2, 12);

    enemy2->setRect(0,0,50,10);
    enemy2->setPos(100,0);
    scene->addItem(enemy2);


    show();
}
