#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Enemy.h"
#include "Game.h"
#include "Fire.h"

extern Game* game; 

Bullet::Bullet(QGraphicsItem* parent) : QObject(), QGraphicsPixmapItem(parent) {
    // dodaje grafike kuli
    setPixmap(QPixmap("bullet.png"));


    // lączymy sie z licznikiem czasu zeby poruszać pociskiem
    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    // rozpoczynamy odliczanie 
    timer->start(50);
}

void Bullet::move() {
    // dodajemy liste kolidujach ze soba obietów. 
    QList<QGraphicsItem*> colliding_items = collidingItems();

    // W przypadku gdy koliduje ze soba pocisk i przeciwnik sa usuwane 
    for (int i = 0, n = colliding_items.size(); i < n; ++i) {
        if (typeid(*(colliding_items[i])) == typeid(Enemy)) {
            // i podnoszony jest wynik
            game->score->increase();
            Fire* fire = new Fire(colliding_items[i]->x(), colliding_items[i]->y());
            scene()->addItem(fire);

            // usuniecie z ekranu
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            // zwolnienie pamięci
            delete colliding_items[i];
            delete this;

            return;
        }
    }

    // jesli nie ma kolizji kula biegnie dalej
    setPos(x(), y() - 10);
    // a jak wychodzi poza ekran jest usuwana
    if (pos().y() < 0) {
        scene()->removeItem(this);
        delete this;
    }
}