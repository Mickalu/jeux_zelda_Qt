#ifndef HERO_H
#define HERO_H


#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsTextItem>
#include <QMediaPlayer>
#include "Element.h"

#include<string>

#include "Potion.h"

class Hero:public QObject,  public QGraphicsPixmapItem, public Element
{
    Q_OBJECT
public:
    Hero(QGraphicsItem * parent = 0, int health_struct = 3, std::string axe_bulette_struct = "forward");
    void  keyPressEvent(QKeyEvent * event);
    void health_decrease();
    void health_increase();
    int getHealth();
    std::string get_axe_bullet();
    void gestion_impact_hero_movement();
    void start_song(QMediaPlayer *song);

public slots:
    void collision_management();

private:
    bool collision;
    int health;
    std::string axe_bullet;
    QMediaPlayer *bulletsound;
    QMediaPlayer *degat_sound;
    QMediaPlayer *heal_sound;
    QMediaPlayer *game_over_song;
};

#endif // HERO_H
