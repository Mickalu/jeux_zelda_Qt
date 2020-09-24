#ifndef DOOR_H
#define DOOR_H

#include <QObject>
#include <QGraphicsPixmapItem>

class Door: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Door(QGraphicsItem * parent=0);
};

#endif // DOOR_H
