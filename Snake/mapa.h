#ifndef MAPA_H
#define MAPA_H

#include "cobra.h"
#include "fabricadealimentos.h"
#include "fabricadeobstaculos.h"
#include "Util/gameoverexcecao.h"
#include "mensagem.h"

#include <iostream>

class Mapa
{
public:
    ~Mapa();
    static Mapa* obtenhaInstancia();
    void movimenteACobra(DirecaoEnum direcao);
    void crieAlimento();
    void desenhe(QPainter* pincel);
    void atualize();
    void limpe();
    void crieObstaculo();
    GameOverExcessao* obtenhaGameOver();

private:
    Mapa();
    const static int tamanho = 50;
    static Mapa* instancia;
    MapaEnum** matriz;
    Cobra* cobra;
    Alimento* alimento;
    bool existeAlimento;
    FabricaDeAlimentos* fabricaDeAlimentos;
    list<Obstaculo>* obstaculos;
    FabricaDeObstaculos * fabricaDeObstaculos;
    GameOverExcessao* gameOver;

};

#endif // MAPA_H
