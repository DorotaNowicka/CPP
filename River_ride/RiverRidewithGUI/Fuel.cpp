#include "Fuel.h"
#include <QFont>
#include "Game.h"

extern Game* game;

Fuel::Fuel(QGraphicsItem* parent) : QGraphicsTextItem(parent) {
    // inicjuljemy poczatkowa wartoœæ
    fuel = 100;

    // ustawiamy rysunek
    setPlainText(QString("Fuel: ") + QString::number(fuel));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times", 16));
}

void Fuel::increase(int value) {
    // funkcja odpowiadaj¹ca za tankowanie
    fuel += value;
    if (fuel > 100) {
        throw - 1;
    }
    setPlainText(QString("Fuel: ") + QString::number(fuel));
}

void Fuel::decrease() {
    // funkcja odpowiadaj¹ca za zu¿ycie paliwa
    fuel = fuel-1;
    if (fuel >= 1) {
        setPlainText(QString("Fuel: ") + QString::number(fuel));
    }
    else {
        game->game_over();
    }
}