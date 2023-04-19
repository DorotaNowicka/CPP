#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h> 
#include "Game.h"
#include "Velocity.h"
#include "Fire.h"

extern Game* game;

Enemy::Enemy(QGraphicsItem* parent) : QObject(), QGraphicsPixmapItem(parent) {
    //losujemy numer odpwowiadajacy pozycji przeciwnika
    int random_number = rand() % 600 + 50;
    setPos(random_number, 0);

    //ustawiamy obrazek
    setPixmap(QPixmap("enemyplane.png").scaled(100,100, Qt::KeepAspectRatio));
    setTransformOriginPoint(50, 50);

    //definiujemy licznik czasu dzieki któremu bedzie wywoływana metoda move()
    timer_in_enemy = new QTimer(this);
    connect(timer_in_enemy, SIGNAL(timeout()), this, SLOT(move()));
    timer_in_enemy->start(20);
}

void Enemy::move() {
    //metoda poruszajaca przeciwnika
    setPos(x(), y() + game->velocity->velocity);
    QList<QGraphicsItem*> colliding_items_enemy = collidingItems();

    // W przypadku gdy nachodza na siebie przeciwnicy sa usuwane 
    for (int i = 0, n = colliding_items_enemy.size(); i < n; ++i) {
        if (typeid(*(colliding_items_enemy[i])) == typeid(Enemy)) {

            // usuniecie z ekranu nachodzacego na siebei wroga
            scene()->removeItem(colliding_items_enemy[i]);
            
            // zwolnienie pamięci
            delete colliding_items_enemy[i];
            
            // return (all code below refers to a non existint bullet)
            return;
        }
    }

    if (pos().y() > 500) {
        // w przypadku gdy przekroczymy pozycje gracza odejmowane jest mu życie.
        game->health->decrease();
        if (game->is_over == false) {
            Fire* fire = new Fire(x(), y());
            scene()->addItem(fire);
        }
        
        scene()->removeItem(this);
        delete this;
    }
}