#include "PetrolStation.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h> // rand() -> really large int
#include "Game.h"
#include "Velocity.h"

extern Game* game;

PetrolStation::PetrolStation(QGraphicsItem* parent) : QObject(), QGraphicsPixmapItem(parent) {
    //ustwaienie pozycji 
    int random_number = rand() % 650 + 50;
    setPos(random_number, 0);

    // zadanie obrazka
    setPixmap(QPixmap("petrol.png").scaled(100, 100, Qt::KeepAspectRatio));
    setTransformOriginPoint(50, 50);


    // 
    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    // rozpoczecie odliczania
    timer->start(50);
}

void PetrolStation::move() {
    // move enemy down
    setPos(x(), y() + game->velocity->velocity);

    QList<QGraphicsItem*> colliding_items = collidingItems();

    // tankowanie w przypadku kolizji ze stacja
    for (int i = 0, n = colliding_items.size(); i < n; ++i) {
        if (typeid(*(colliding_items[i])) == typeid(Player)) {
            try {
                game->fuel->increase(75);
            }
            catch (int e) {
                game->fuel->fuel = 100;
            }
            // usuniecie z pamieci
            delete this;
            return;
        }
    }

    // usuniecie stacji paliw w przypadku wyjscia poza ekrna
    if (pos().y() > 600) {
        scene()->removeItem(this);
        delete this;
    }
}