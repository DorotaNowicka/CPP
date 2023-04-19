#ifndef GAME_H
#define GAME_H
#include "CoastLine.h"
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "Player.h"
#include "Score.h"
#include "Health.h"
#include "Velocity.h"
#include "Fuel.h"
#include <QTimer>

class Game : public QGraphicsView {
    Q_OBJECT
        QString name;
public:
    Game(QWidget* parent = 0);
    QGraphicsScene* scene;
    Player* player;
    Score* score;
    Health* health;
    Velocity* velocity;
    Fuel* fuel;
    CoastLine* left_coast;
    CoastLine* right_coast;
    QTimer* timer_fuel;
    QTimer* timer_petrol;
    QTimer* timer_enemy;
    QTimer* timer_enemy_move;
    QTimer* timer_fire;
    bool is_over = false;
    void game_over();
    void display_game_over_window(QString textToDisplay);
    void menu();
    void display();
public slots:
    void start();
    void restart_game();
private:
    void drawPanel(int x, int y, int width, int height, QColor color, double opacity);
};

#endif // GAME_H