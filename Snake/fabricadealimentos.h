#ifndef FABRICADEALIMENTOS_H
#define FABRICADEALIMENTOS_H

#include "alimento.h"
#include "iostream"

class FabricaDeAlimentos
{
public:
    ~FabricaDeAlimentos();
    Alimento* crie(int maximoRandomico);
    static FabricaDeAlimentos *obtenhaInstancia();
    static int getQuantidadeAlimentos();

private:
    FabricaDeAlimentos();
    static int quantidadeDeAlimentosGerados;
    static FabricaDeAlimentos* instancia;
};

#endif // FABRICADEALIMENTOS_H
