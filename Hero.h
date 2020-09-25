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
    Hero(QGraphicsItem * parent = 0, std::string axe_bulette_struct = "forward");
    void  keyPressEvent(QKeyEvent * event);
    std::string get_axe_bullet();
    void gestion_impact_hero_movement();
    void start_song(QMediaPlayer *song);

public slots:
    void collision_management();

signals:
    void heroDied();
    void doorTouched();

private:
    bool collision;
    std::string axe_bullet;
    QMediaPlayer *bulletsound;
    QMediaPlayer *degat_sound;
    QMediaPlayer *heal_sound;
    QMediaPlayer *game_over_song;
};

#endif // HERO_H
