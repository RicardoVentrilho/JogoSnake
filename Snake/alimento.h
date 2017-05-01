#ifndef ALIMENTO_H
#define ALIMENTO_H

#include "objeto.h"
#include "generica.h"
#include <QPixmap>

class Alimento : public Objeto
{
public:
    Alimento(int x, int y);
    Alimento(int x, int y, int valor);
    ~Alimento();
    void desenhe(QPainter* pincel);
    int obtenhaValor();
    void coloqueValor(int valor);
    Coordenadas* obtenhaCoordenada();

private:
    Coordenadas* coordenada;
    QPixmap* item;
    int valor;
};

#endif // ALIMENTO_H
