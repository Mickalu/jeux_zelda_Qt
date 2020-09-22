#ifndef LINK_H
#define LINK_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>

class Link: public QObject,  public QGraphicsRectItem
{
        Q_OBJECT
    public:
        Link(QGraphicsItem * parent=0);
        void  keyPressEvent(QKeyEvent * event);

    public slots:
        void spawn();
    };

#endif // LINK_H
