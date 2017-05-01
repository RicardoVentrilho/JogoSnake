#include "obstaculo.h"

Obstaculo::Obstaculo(int x, int y)
{
    item = new QPixmap("Imagens/obstaculo.png");
    coordenada = new Coordenadas(x,y);
}

Obstaculo::~Obstaculo()
{
    delete coordenada;
    delete item;
}

void Obstaculo::desenhe(QPainter *pincel)
{
    pincel->drawPixmap(coordenada->getX()*10, coordenada->getY()*10, 10, 10, *(this->item));
}

Coordenadas *Obstaculo::obtenhaCoordenada()
{
    return coordenada;
}
