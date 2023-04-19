#include "Player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "Bullet.h"
#include "Enemy.h"
#include "Game.h"
#include "Fuel.h"
#include "PetrolStation.h"

extern Game* game;

Player::Player(QGraphicsItem* parent) : QGraphicsPixmapItem(parent) {

    // set graphic
    setPixmap(QPixmap("player.png").scaled(100,100, Qt::KeepAspectRatio));
}

void Player::keyPressEvent(QKeyEvent* event) {
    // zadanie mozliwosci ruchu graczowi
    if (event->key() == Qt::Key_Left) {
        if (pos().x() - 50 > 30)
            setPos(x() - 10, y());
    }
    else if (event->key() == Qt::Key_Right) {
        if (pos().x() + 100 < 770)
            setPos(x() + 10, y());
    }
    else if (event->key() == Qt::Key_Up) {
        try {
            game->velocity->increase();
        }
        catch (int e) {
            game->velocity->velocity = 10;
        }
    }
    else if (event->key() == Qt::Key_Down) {
        try {
            game->velocity->decrease();
        }
        catch(int e){
            game->velocity->velocity = 1;
        }

    }
    // i strzelania 
    else if (event->key() == Qt::Key_Space) {
        Bullet* bullet = new Bullet();
        bullet->setPos(x() + 45, y());
        scene()->addItem(bullet);

    }
}

void Player::spawn() {
    // tworznie wrogw 
    Enemy* enemy = new Enemy();
    scene()->addItem(enemy);
   // game->fuel->decrease();
}

void Player::rand_petrol() {
    PetrolStation* petrol_st = new PetrolStation();
    scene()->addItem(petrol_st);
}
