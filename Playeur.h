#ifndef PLAYEUR_H
#define PLAYEUR_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>

class Playeur:public QObject,  public QGraphicsRectItem
{
    Q_OBJECT
public:
    Playeur(QGraphicsItem * parent=0);
    void  keyPressEvent(QKeyEvent * event);

public slots:
    //void spawn();

};

#endif // PLAYEUR_H
