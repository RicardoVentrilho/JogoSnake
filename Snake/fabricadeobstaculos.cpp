#include "fabricadeobstaculos.h"

int FabricaDeObstaculos::quantidadeDeObstaculosGerados = 0;
FabricaDeObstaculos* FabricaDeObstaculos::instancia = NULL;

FabricaDeObstaculos::FabricaDeObstaculos()
{}

FabricaDeObstaculos::~FabricaDeObstaculos()
{}

Obstaculo *FabricaDeObstaculos::crie(int maximoRandomico)
{
    int x = randomica(maximoRandomico);
    int y = randomica(maximoRandomico);
    quantidadeDeObstaculosGerados++;
    return new Obstaculo(x,y);
}

FabricaDeObstaculos *FabricaDeObstaculos::obtenhaInstancia()
{
    if(!instancia)
        instancia = new FabricaDeObstaculos();
    return instancia;
}

int FabricaDeObstaculos::getQuantidadeObstaculos()
{
    return quantidadeDeObstaculosGerados;
}
