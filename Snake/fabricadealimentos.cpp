#include "fabricadealimentos.h"

int FabricaDeAlimentos::quantidadeDeAlimentosGerados = 0;
FabricaDeAlimentos* FabricaDeAlimentos::instancia = NULL;

FabricaDeAlimentos::FabricaDeAlimentos()
{}

FabricaDeAlimentos::~FabricaDeAlimentos()
{}

Alimento *FabricaDeAlimentos::crie(int maximoRandomico)
{
    int x = randomica(maximoRandomico);
    int y = randomica(maximoRandomico);
    quantidadeDeAlimentosGerados++;
    Alimento* alimento = new Alimento(x,y);
    return alimento;
}

FabricaDeAlimentos *FabricaDeAlimentos::obtenhaInstancia()
{
    if(!instancia)
        instancia = new FabricaDeAlimentos();
    return instancia;
}

int FabricaDeAlimentos::getQuantidadeAlimentos()
{
    return quantidadeDeAlimentosGerados;
}

