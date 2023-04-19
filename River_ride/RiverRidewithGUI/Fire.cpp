#include "Fire.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include "Game.h"

extern Game* game;

Fire::Fire(int pos_x, int pos_y, QGraphicsItem* parent) : QObject(), QGraphicsPixmapItem(parent) {
    // zadawana jest pozycja wybuchu w którym aktualnie znajdował sie wróg
    setPos(pos_x + 12.5, pos_y + 10);
    cout << "OK";
    // dodajemy obram
    setPixmap(QPixmap("fire.png").scaled(70, 70, Qt::KeepAspectRatio));
    setTransformOriginPoint(50, 50);


    // ustawiamy licznik po którym obiekt zniknie 
    QTimer* timer_fire = new QTimer(this);
    connect(timer_fire, SIGNAL(timeout()), this, SLOT(burn()));

    // rozpoczynamy odliczanie
    timer_fire->start(500);
}
void Fire::burn() {
    // usuwamy z ekranu
    scene()->removeItem(this);
    // usuwamy obiekt z pamieci
    delete this;
}