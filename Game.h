#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QPushButton>
#include <QMediaPlayer>
#include "Hero.h"
#include "Score.h"
#include "Wall.h"



class Game: public QGraphicsView
{
    Q_OBJECT
public:
    Game(QWidget * parent = 0);

    QGraphicsScene * scene;
    Hero * hero;
    Score * score;

    QPushButton* playButton;
    QPushButton* quitButton;
    QMediaPlayer* music;
    void displayMainMenu();

public slots:
    void playButtonClicked();
};

#endif // GAME_H
