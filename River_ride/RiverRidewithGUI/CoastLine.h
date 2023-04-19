#pragma once
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#ifndef COASTLINE_H
#define COASTLINE_H




class CoastLine : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    CoastLine(QGraphicsItem* parent = 0);
};

#endif // !COASTLINE