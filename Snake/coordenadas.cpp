#include "coordenadas.h"

Coordenadas::Coordenadas(int x, int y)
    : x(x), y(y)
{}

Coordenadas::~Coordenadas()
{}

void Coordenadas::setX(int x)
{
    this->x = x;
}

void Coordenadas::setY(int y)
{
    this->y = y;
}

int Coordenadas::getX()
{
    return this->x;
}

int Coordenadas::getY()
{
    return this->y;
}

void Coordenadas::incrementeX()
{
    this->x++;
}

void Coordenadas::incrementeY()
{
    this->y++;
}

void Coordenadas::decrementeX()
{
    this->x--;
}

void Coordenadas::decrementeY()
{
    this->y--;
}
