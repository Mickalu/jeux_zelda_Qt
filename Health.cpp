#include "Health.h"
#include <QFont>

Health::Health(QGraphicsItem * parent): QGraphicsTextItem(parent){
    health = 5;

    setPlainText(QString("Health: " + QString::number(health))); // Score: 0
    setDefaultTextColor((Qt::red)); // change the color
    setFont(QFont("times", 16));
}

int Health::getHealth(){
    return health;
}

void Health::increaseHealth(){
    health++;
    setPlainText(QString("Health: " + QString::number(health)));
}

void Health::decreaseHealth(){
    health--;
    setPlainText(QString("Health: " + QString::number(health)));
}
