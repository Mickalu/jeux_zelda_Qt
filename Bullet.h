#ifndef BULLET_H
#define BULLET_H


#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QObject>
#include "Element.h"

class Bullet: public QObject,public QGraphicsRectItem, public Element
{
    Q_OBJECT
public:
    Bullet(QGraphicsItem * parent=0, std::string direction_struct = "forward");

public slots:
    void move();

private:
    std::string direction;
};

#endif // BULLET_H
