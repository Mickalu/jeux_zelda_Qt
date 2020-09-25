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

    Wall * wall_center = new Wall();
    wall_center->setRect(0,0,50,600);
    wall_center->setPos(475,150);
    scene->addItem(wall_center);

    Door * door = new Door();
    door->setPos(900,700);
    scene->addItem(door);

    Repeller * repeller_left = new Repeller();
    repeller_left->setRect(0,0,200,500);
    repeller_left->setPos(200,150);
    scene->addItem(repeller_left);

    Repeller * repeller_right = new Repeller();
    repeller_right->setRect(0,0,200,500);
    repeller_right->setPos(600,150);
    scene->addItem(repeller_right);

    Potion * potion_left = new Potion();
    potion_left->setPos(60,80);
    scene->addItem(potion_left);

    Potion * potion_right= new Potion();
    potion_right->setPos(900,50);
    scene->addItem(potion_right);


    // create an itemm to add to the scene
    hero = new Hero(0,"forward");
    hero->setPos(55,650); // TODO generalize to always be in the middle bottom of screen
    // make rect focusable il reçois tous les keyboard event
    hero->setFlag(QGraphicsItem::ItemIsFocusable);
    hero->setFocus();
    connect(hero,SIGNAL(heroDied()),this,SLOT(displayGameOver()));
    connect(hero, SIGNAL(doorTouched()), this, SLOT(displayWin()));
    scene->addItem(hero);

    score = new Score();
    scene->addItem(score);

    health = new Health();
    health->setPos(150,0);
    scene->addItem(health);

    QList<QPointF>points_list;
    points_list << QPointF(100,100) << QPointF(100, 200) << QPointF(200,200) << QPointF(200,100);
    Enemy * enemy1 = new Enemy(0, points_list);
    enemy1->setPos(100, 50);
    scene->addItem(enemy1);

    QList<QPointF>points_list_enemy2;
    points_list_enemy2 << QPointF(500,100) << QPointF(200, 100) << QPointF(400,100) <<QPointF(600,300);
    Enemy * enemy2 = new Enemy(0, points_list_enemy2);
    enemy2->setPos(500,50);
    scene->addItem(enemy2);

    QList<QPointF>points_list_enemy3;
    points_list_enemy3 << QPointF(700,100) << QPointF(700, 300) << QPointF(300,300) <<QPointF(300,100);
    Enemy * enemy3 = new Enemy(0, points_list_enemy3);
    enemy2->setPos(700,50);
    scene->addItem(enemy3);
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

void Game::displayWin(){
    scene->clearFocus();

    setBackgroundBrush(QBrush(QImage(":/images/images/win_menu.jpg")));
    music->setMedia(QUrl("qrc:/sounds/sounds/money_2.mp3"));
    music->play();
}
