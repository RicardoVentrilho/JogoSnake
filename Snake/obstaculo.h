#ifndef OBSTACULO_H
#define OBSTACULO_H

#include "objeto.h"
#include "generica.h"
#include <QPixmap>

class Obstaculo : Objeto
{
public:
    Obstaculo(int x, int y);
    ~Obstaculo();
    void desenhe(QPainter* pincel);
    Coordenadas* obtenhaCoordenada();

private:
    Coordenadas* coordenada;
    QPixmap* item;
};

#endif // OBSTACULO_H
