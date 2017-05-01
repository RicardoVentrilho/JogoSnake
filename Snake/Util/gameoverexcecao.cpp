#include "gameoverexcecao.h"

GameOverExcessao::GameOverExcessao()
{
    item = new QPixmap("Imagens/game-over.png");
}

GameOverExcessao::~GameOverExcessao()
{

}

void GameOverExcessao::desenhe(QPainter *pincel)
{
    pincel->drawPixmap(0, 0, 500, 500, *(this->item));
}

