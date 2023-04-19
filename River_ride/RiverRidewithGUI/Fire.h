#ifndef FIRE_H
#define FIRE_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Fire : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Fire(int pos_x, int pos_y, QGraphicsItem* parent = 0);
public slots:
    void burn();
};

#endif // FIRE_H