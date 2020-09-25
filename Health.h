#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>

class Health: public QGraphicsTextItem{
public:
    Health(QGraphicsItem * parent=0);
    int getHealth();
    void increaseHealth();
    void decreaseHealth();
private:
    int health;
};

#endif // HEALTH_H
