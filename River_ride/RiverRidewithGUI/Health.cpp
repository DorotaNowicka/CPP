#include "Health.h"
#include <QObject>
#include <QFont>
#include "Game.h"

extern Game* game;

Health::Health(QGraphicsItem* parent) : QGraphicsTextItem(parent) {
    // inicjalizacja punkt�w �ycia 
    health = 3;
    // dodadanie licznika �ycia na ekranie
    setPlainText(QString("Health: ") + QString::number(health)); 
    setDefaultTextColor(Qt::red);
    setFont(QFont("times", 16));
}

void Health::decrease() {
    // funkcja zmniejszaj�ca ilos� �ycia 
    health--;
    if (health >= 1) {
        setPlainText(QString("Health: ") + QString::number(health)); 

    }
    else
        game->game_over();

}

int Health::get_health() {
    return health;
}
