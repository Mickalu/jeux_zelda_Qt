#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include<QObject>
#include<QGraphicsRectItem>

class Personnage: public QObject,  public QGraphicsRectItem
{
    Q_OBJECT
public:
    Personnage(QGraphicsItem * parent=0);

public slots:
    void move_enemy();

private:
};

#endif // PERSONNAGE_H
