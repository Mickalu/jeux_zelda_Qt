#include "Door.h"

Door::Door(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/images/images/door.png"));
}
