#include <QApplication>
#include "Game.h"
#include <stdlib.h> 
#include <time.h>  




Game* game;

int main(int argc, char* argv[]) {
    srand(time(NULL));
    QApplication a(argc, argv);

    game = new Game();
    game->menu();

    return a.exec();
}