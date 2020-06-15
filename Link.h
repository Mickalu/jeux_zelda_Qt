#ifndef LINK_H
#define LINK_H

#include "personnage.h"

#include<QObject>
#include<QKeyEvent>

class Link : public Personnage
{
public:
    Link();
    void keyPressEvent(QKeyEvent * event);
};

#endif // LINK_H
