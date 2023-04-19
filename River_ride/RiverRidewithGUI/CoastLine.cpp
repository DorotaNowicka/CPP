#include "CoastLine.h"
#include "Game.h"
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

extern Game* game;

CoastLine::CoastLine(QGraphicsItem* parent) : QGraphicsPixmapItem(parent) {
	setPixmap(QPixmap("grass.png").scaled(30, 800));
}


