#ifndef FUEL_H
#define FUEL_H

#include <QGraphicsTextItem>

class Fuel : public QGraphicsTextItem {
    Q_OBJECT
public:
    int fuel;
    Fuel(QGraphicsItem* parent = 0);
    void increase(int value);
public slots:
    void decrease();

};

#endif // FUEL_H