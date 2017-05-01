#include "alimento.h"

Alimento::Alimento(int x, int y)
{
    item = new QPixmap("Imagens/alimento.png");
    coordenada = new Coordenadas(x,y);
    valor = 1;
}

Alimento::Alimento(int x, int y, int valor)
{
    item = new QPixmap("Imagens/alimento.png");
    coordenada = new Coordenadas(x,y);
    this->valor = valor;
}

Alimento::~Alimento()
{
    delete coordenada;
    delete item;
}

void Alimento::desenhe(QPainter *pincel)
{
    pincel->drawPixmap(coordenada->getX()*10, coordenada->getY()*10, 10, 10, *(this->item));
}

int Alimento::obtenhaValor()
{
    return this->valor;
}

void Alimento::coloqueValor(int valor)
{
    this->valor = valor;
}

Coordenadas *Alimento::obtenhaCoordenada()
{
    return coordenada;
}

