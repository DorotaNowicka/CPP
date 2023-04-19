#include "Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "Enemy.h"
#include "CoastLine.h"
#include <QBrush>
#include <QImage>
#include "Button.h"
#include <QInputDialog>
#include <QString>
#include <QDir>
#include <QObject>
#include <QGraphicsView>
#include "PetrolStation.h"
#include "Fire.h"


Game::Game(QWidget* parent) {
    // incjalizacja ekranu poczatkowego gry
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 800, 600); 
    setBackgroundBrush(QBrush(QImage("menu.png")));

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800, 600);

    show();
}


void Game::start() {
    is_over = false;
    scene->clear();
    display();
}

void Game::restart_game() {
    is_over = false;
    scene->clear();
    start();
}

void Game::game_over() {
    //wyrzyucenie komunikatu o koncu rozgrywnki
    QString message;
    message = "GAME OVER";
    is_over = true;
    timer_enemy->stop();
    timer_fuel->stop();
    timer_petrol->stop();
    QList<QGraphicsItem*> objects = items();
    display_game_over_window(message);
}

void Game::display_game_over_window(QString textToDisplay) {
    // wyłączenie itemów pozostajacych na scenie
    for (size_t i = 0, n = scene->items().size(); i < n; i++) {
        scene->items()[i]->setEnabled(false);
    }

    // wyrzucenie ekranu koncowego
    drawPanel(0, 0, 1024, 768, Qt::black, 0.65);
    drawPanel(0, 0, 800, 600, Qt::red, 1);

    // stworzenie przycisku do ponownej gry
    Button* playAgain = new Button(QString("Play Again"));
    playAgain->setPos(300, 300);
    scene->addItem(playAgain);
    connect(playAgain, SIGNAL(clicked()), this, SLOT(restart_game()));

    // storzenie przycisku do wyjścia
    Button* quit = new Button(QString("Quit"));
    quit->setPos(300, 375);
    scene->addItem(quit);
    connect(quit, SIGNAL(clicked()), this, SLOT(close()));
    QString score_text = QString("Score: ") + QString::number(score->get_score());
    // stworzenie napisu informujacego o wyniku gry
    QGraphicsTextItem* over_text = new QGraphicsTextItem(textToDisplay);
    QGraphicsTextItem* score_tex = new QGraphicsTextItem(score_text);
    score_tex->setFont(QFont("times new roman", 20));
    score_tex->setDefaultTextColor(Qt::cyan);
    over_text->setFont(QFont("times new roman", 30));
    over_text->setDefaultTextColor(Qt::cyan);
    int x_pos_sc = this->width() / 2 - score_tex->boundingRect().width() / 2;
    int x_pos_ov = this->width() / 2 - over_text->boundingRect().width() / 2;
    score_tex->setPos(x_pos_sc, 225);
    over_text->setPos(x_pos_ov, 175);
    scene->addItem(over_text);
    scene->addItem(score_tex);

}

void Game::drawPanel(int x, int y, int width, int height, QColor color, double opacity) {
    // funkcja do tworzenia panelu konca gry
    QGraphicsRectItem* panel = new QGraphicsRectItem(x, y, width, height);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(color);
    panel->setBrush(brush);
    panel->setOpacity(opacity);
    scene->addItem(panel);
}

void Game::display() {
    //tworzenie panelu gry
    scene = new QGraphicsScene();
    scene->clear();
    scene->setSceneRect(0, 0, 800, 600); 
    setBackgroundBrush(QBrush(QImage("water.png")));


    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800, 600);
    //dodawanie obiektów gry jak Player, Velocity, Health, Fuel
    left_coast = new CoastLine();
    left_coast->setPos(0, 0);
    scene->addItem(left_coast);
    right_coast = new CoastLine();
    right_coast->setPos(770, 0);
    scene->addItem(right_coast);
    velocity = new Velocity();

    player = new Player();
    player->setPos(400, 500); 
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);
    fuel = new Fuel();
    fuel->setPos(650, 0);
    scene->addItem(fuel);
    score = new Score();
    scene->addItem(score);
    health = new Health();
    health->setPos(health->x(), health->y() + 25);
    scene->addItem(health);
    QGraphicsTextItem* name_info = new QGraphicsTextItem(QString("Player: ")+QString(this->name));
    QFont name_font("times new roman", 15);
    name_info->setFont(name_font);
    name_info->setDefaultTextColor(Qt::white);
    int x_pos = this->width() - name_info->boundingRect().width();
    name_info->setPos(x_pos, 0);
    scene->addItem(name_info);
    name_info->setPos(0, 50);
    scene->addItem(name_info);
    
    // dodanie licznika odpoweiadajacego za zmniejszenie ilosci paliwa
    timer_fuel = new QTimer();
    QObject::connect(timer_fuel, SIGNAL(timeout()), fuel, SLOT(decrease()));
    timer_fuel->start(500);

    // dodanie licznika odpoweiadajacego za pojawianie się stacji
    timer_petrol = new QTimer();
    QObject::connect(timer_petrol, SIGNAL(timeout()), player, SLOT(rand_petrol()));
    timer_petrol->start(10000);

    // dodanie licznika odpoweiadajacego za pojawianie się wrogów
    timer_enemy = new QTimer();
    QObject::connect(timer_enemy, SIGNAL(timeout()), player, SLOT(spawn()));
    timer_enemy->start(2000);


}

void Game::menu() {

    // ekran starowy pobierajacy imie
    bool ok;
    QString text = QInputDialog::getText(this, tr("Input user name"),
        tr("User name:"), QLineEdit::Normal,
        QDir::home().dirName(), &ok);
    if (text.size() < 1) {
        text = "player";
    }
    this->name = text;
 

    // wpiswyanie swojego imienia
    QString name_txt = QString("Hello ") + QString(text);
    QGraphicsTextItem* name_input = new QGraphicsTextItem(name_txt);
    QFont name_font("comic sans", 20);
    name_input->setFont(name_font);
    name_input->setDefaultTextColor(Qt::white);
    int x_pos = this->width() / 2 - name_input->boundingRect().width() / 2;
    name_input->setPos(x_pos, 200);
    scene->addItem(name_input);


    // stworzenie przyciksu do gry
    Button* play_button = new Button(QString("Play"));
    int bx_pos = this->width() / 2 - play_button->boundingRect().width() / 2;
    int by_pos = 275;
    play_button->setPos(bx_pos, by_pos);
    connect(play_button, SIGNAL(clicked()), this, SLOT(start()));
    scene->addItem(play_button);

}



