#ifndef PETROL_H
#define PETROL_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class PetrolStation : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    PetrolStation(QGraphicsItem* parent = 0);
public slots:
    void move();
};

#endif // PETROL_H