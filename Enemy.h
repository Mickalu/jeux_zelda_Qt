#ifndef ENEMY_H
#define ENEMY_H

#include "personnage.h"

#include <QObject>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h> // rand() -> really large int


class Enemy : public Personnage
{
public:
    Enemy();

public slots:
    void spawn();
    void move();
};

#endif // ENEMY_H
