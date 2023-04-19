#ifndef VELOCITY_H
#define VELOCITY_H

#include <QGraphicsTextItem>

class Velocity : public QGraphicsTextItem {
public:
    int velocity;
    Velocity(QGraphicsItem* parent = 0);
    void decrease();
    void increase();
};

#endif // VELOCITY_H