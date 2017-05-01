#ifndef COBRA_H
#define COBRA_H

#include <list>
#include <QPainter>
#include <iostream>

#include "coordenadas.h"
#include "objeto.h"

using std::list;

class Cobra : public Objeto
{ 
public:
    Cobra();
    ~Cobra();
    void desenhe(QPainter* pincel);
    void movimentePara(int x, int y);
    void coma(Objeto* alimento);
    void aumente(int valor);
    list<Coordenadas>* obtenhaCoordenadas();
    DirecaoEnum obtenhaDirecao();
    void coloqueDirecao(DirecaoEnum direcao);

private:
    list<Coordenadas>* cobra;
    DirecaoEnum direcao;
    QPixmap* item;
    int tamanho;
};

#endif // COBRA_H
