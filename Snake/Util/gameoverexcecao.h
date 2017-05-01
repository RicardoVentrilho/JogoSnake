#ifndef GAMEOVEREXCECAO_H
#define GAMEOVEREXCECAO_H

#include <QPixmap>
#include <QPainter>

class GameOverExcessao
{
public:
    GameOverExcessao();
    ~GameOverExcessao();
    void desenhe(QPainter* pincel);

private:
    QPixmap* item;
};

#endif // GAMEOVEREXCECAO_H
