#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>
#include "Player.h"


class Health : public QGraphicsTextItem {
public:
    Health(QGraphicsItem* parent = 0);
    void decrease();
    int get_health();
private:
    int health;
};

#endif // HEALTH_H