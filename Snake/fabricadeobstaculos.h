#ifndef FABRICADEOBSTACULOS_H
#define FABRICADEOBSTACULOS_H

#include "obstaculo.h"

class FabricaDeObstaculos
{
public:
    ~FabricaDeObstaculos();
    Obstaculo* crie(int maximoRandomico);
    static FabricaDeObstaculos *obtenhaInstancia();
    static int getQuantidadeObstaculos();

private:
    FabricaDeObstaculos();
    static int quantidadeDeObstaculosGerados;
    static FabricaDeObstaculos* instancia;
};

#endif // FABRICADEOBSTACULOS_H
