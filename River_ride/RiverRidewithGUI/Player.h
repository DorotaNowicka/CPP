#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <string>
#include "Health.h"

using namespace std;

class Player :public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Player(QGraphicsItem* parent = 0);
    void keyPressEvent(QKeyEvent* event);

public slots:
    void spawn();
    void rand_petrol();

};

#endif // PLAYER_H