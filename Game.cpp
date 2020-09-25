#include "Game.h"
#include "Hero.h"
#include "Enemy.h"
#include "Wall.h"
#include "Door.h"
#include "Potion.h"
#include "Repeller.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QLabel>

Game:: Game(QWidget * parent)
{
    // create a scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1000,750);

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1000,750);
}

void Game::playButtonClicked(){
    scene->clearFocus();
    playButton->hide();
    quitButton->hide();
    music->stop();
    setBackgroundBrush(QBrush(QImage(":/images/images/herb.png")));

    //creation map element etc
    Wall * wall_left = new Wall();
    wall_left->setRect(0,0,50,750);
    wall_left->setPos(0,0);
    scene->addItem(wall_left);

    Wall * wall_right = new Wall();
    wall_right->setRect(0,0,50,750);
    wall_right->setPos(950,0);
    scene->addItem(wall_right);


    Wall * wall_up = new Wall();
    wall_up->setRect(0,0,1000,50);
    wall_up->setPos(0,0);
    scene->addItem(wall_up);

    Wall * wall_down = new Wall();
    wall_down->setRect(0,0,900,50);
    wall_down->setPos(0,700);
    scene->addItem(wall_down);

    Door * door = new Door();
    door->setPos(900,700);
    scene->addItem(door);

    Repeller * repeller_center = new Repeller();
    repeller_center->setRect(0,0,550, 50);
    repeller_center->setPos(800,400);
    scene->addItem(repeller_center);

    Potion * potion = new Potion();

    potion->setPos(100,300);
    scene->addItem(potion);


    // create an itemm to add to the scene
    hero = new Hero(0,"forward");
    hero->setPos(400,500); // TODO generalize to always be in the middle bottom of screen


    // make rect focusable il reçois tous les keyboard event
    hero->setFlag(QGraphicsItem::ItemIsFocusable);
    hero->setFocus();
    connect(hero,SIGNAL(heroDied()),this,SLOT(displayGameOver()));

    scene->addItem(hero);

    // create the score
    score = new Score();
    scene->addItem(score);

    health = new Health();
    health->setPos(0,40);
    scene->addItem(health);


    // a enlever pour mettre des enemies placés

    // spawn enemies
    /*
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),hero,SLOT(spawn()));
    timer->start(2000);*/

    QList<QPointF>points_list;
    points_list << QPointF(100,100) << QPointF(100, 200) << QPointF(200,200) << QPointF(100,500);
    Enemy * enemy1 = new Enemy(0, points_list, 12);


    enemy1->setPos(100, 50);

    scene->addItem(enemy1);


    QList<QPointF>points_list_enemy2;
    points_list_enemy2 << QPointF(500,100) << QPointF(200, 100) << QPointF(400,100) <<QPointF(600,300) << QPointF(100,550);
    Enemy * enemy2 = new Enemy(0, points_list_enemy2, 12);

    enemy2->setPos(100,0);
    scene->addItem(enemy2);
}

void Game::displayMainMenu(){
    setBackgroundBrush(QBrush(QImage(":/images/images/background_menu.jpg")));

    // play background music
    music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/sounds/zelda_main_theme_song.mp3"));
    music->play();

    playButton = new QPushButton("Play");
    playButton->setGeometry(QRect(scene->width()/2 - 100,scene->height()/2 + 50,200,50));
    connect(playButton, SIGNAL(clicked()), this, SLOT(playButtonClicked()));
    scene->addWidget(playButton);

    quitButton = new QPushButton("Quit");
    quitButton->setGeometry(QRect(scene->width()/2 - 100,scene->height()/2 + 125,200,50));
    connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));
    scene->addWidget(quitButton);
}

void Game::displayGameOver(){
    scene->clearFocus();    

    setBackgroundBrush(QBrush(QImage(":/images/images/background_gameover.jpg")));
    music->setMedia(QUrl("qrc:/sounds/sounds/titanic-parody-mp3cut.mp3"));
    music->play();

    playButton->setText("Try Again");
    playButton->show();
    quitButton->show();
}
