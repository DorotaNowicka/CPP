#include "Velocity.h"
#include <QObject>
#include <QFont>
#include "Game.h"

extern Game* game;

Velocity::Velocity(QGraphicsItem* parent) : QGraphicsTextItem(parent) {
    velocity = 5;
}

void Velocity::decrease() {
    velocity -= 1;
    if (velocity < 1) {
        throw - 1;
    }
}

void Velocity::increase() {
    velocity += 1;
    if (velocity > 10) {
        throw -1;
    }
}