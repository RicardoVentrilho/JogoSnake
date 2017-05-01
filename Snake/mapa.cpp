#include "mapa.h"
Mapa* Mapa::instancia = NULL;

Mapa::Mapa()
{
    matriz = new MapaEnum*[tamanho];
    this->limpe();

    gameOver = NULL;
    cobra = new Cobra();
    fabricaDeAlimentos = FabricaDeAlimentos::obtenhaInstancia();
    fabricaDeObstaculos = FabricaDeObstaculos::obtenhaInstancia();
    alimento = NULL;
    existeAlimento = false;
    obstaculos = new list<Obstaculo>();
}

Mapa::~Mapa()
{
    delete alimento;
    delete cobra;
    delete fabricaDeAlimentos;
    delete fabricaDeObstaculos;
    delete obstaculos;
    delete gameOver;
    for (int i = 0; i < tamanho; i ++) {
         delete [] matriz[i];
    }
    delete [] matriz;
}

Mapa *Mapa::obtenhaInstancia()
{
    if(!instancia)
        instancia = new Mapa;
    return instancia;
}

void Mapa::movimenteACobra(DirecaoEnum direcao)
{
    Coordenadas coordenadasDaCobra = *(cobra->obtenhaCoordenadas()->begin());

    int x = coordenadasDaCobra.getX(), y = coordenadasDaCobra.getY();

    switch (direcao) {
    case CIMA:
        if(cobra->obtenhaDirecao() == BAIXO) {
            direcao = cobra->obtenhaDirecao();
        }
        break;
    case BAIXO:
        if(cobra->obtenhaDirecao() == CIMA) {
            direcao = cobra->obtenhaDirecao();
        }
        break;
    case ESQUERDA:
        if(cobra->obtenhaDirecao() == DIREITA) {
            direcao = cobra->obtenhaDirecao();
        }
        break;
    case DIREITA:
        if(cobra->obtenhaDirecao() == ESQUERDA) {
            direcao = cobra->obtenhaDirecao();
        }
        break;
    default:
        break;
    }

    cobra->coloqueDirecao(direcao);

    switch (direcao) {
    case CIMA:
        if((y - 1) < 0) {
            y = this->tamanho - y;
        }
        y--;
        break;
    case BAIXO:
        if((y + 1) > (this->tamanho - 1)) {
            y -= this->tamanho;
        }
        y++;
        break;
    case DIREITA:
        if((x + 1) > (this->tamanho - 1)) {
            x -= this->tamanho;
        }
        x++;
        break;
    case ESQUERDA:
        if((x - 1) < 0) {
            x = this->tamanho - x;
        }
        x--;
        break;
    default:
        break;
    }

    if(matriz[x][y] == ALIMENTO) {
        std::cerr << "COMEU" << std::endl;
        cobra->aumente(alimento->obtenhaValor());
        existeAlimento = false;
    }

    if(matriz[x][y] == COLISAO) {
        std::cerr << "CHAMA GAME OVER" << std::endl;
        gameOver = new GameOverExcessao();
        throw gameOver;
    }

    cobra->movimentePara(x,y);
}

void Mapa::crieAlimento()
{
    Alimento * novoAlimento;
    Coordenadas * coordenada;
    if(!existeAlimento) {
        do {
            novoAlimento = fabricaDeAlimentos->crie(tamanho);
            coordenada = novoAlimento->obtenhaCoordenada();
        } while (matriz[coordenada->getX()][coordenada->getY()] == COLISAO);

        matriz[coordenada->getX()][coordenada->getY()] = ALIMENTO;

        alimento = novoAlimento;
        existeAlimento = true;

        if(((fabricaDeAlimentos->getQuantidadeAlimentos()-1) > 0)&&(((fabricaDeAlimentos->getQuantidadeAlimentos()-1)%3) == 0)){
            std::cerr <<"BONUS";
            crieObstaculo();
            std::cerr <<"CRIADO OBSTACULO";
        }
    }
}

void Mapa::desenhe(QPainter *pincel)
{
    if(alimento)
        alimento->desenhe(pincel);
        cobra->desenhe(pincel);

    for (list<Obstaculo>::iterator it = obstaculos->begin(); it != obstaculos->end(); ++it)
    {
        (*it).desenhe(pincel);
    }
}

void Mapa::atualize()
{
    this->limpe();

    list<Coordenadas>* coordenadasCobra = cobra->obtenhaCoordenadas();
    for (list<Coordenadas>::iterator it = coordenadasCobra->begin(); it != coordenadasCobra->end(); ++it)
    {
        matriz[(*it).getX()][(*it).getY()] = COLISAO;
    }

    Coordenadas* coordenadaAlimento = alimento->obtenhaCoordenada();
    matriz[coordenadaAlimento->getX()][coordenadaAlimento->getY()] = ALIMENTO;

    Coordenadas* coordenadaObstaculo;
    for (list<Obstaculo>::iterator it = obstaculos->begin(); it != obstaculos->end(); ++it)
    {
        coordenadaObstaculo = (*it).obtenhaCoordenada();
        matriz[coordenadaObstaculo->getX()][coordenadaObstaculo->getY()] = COLISAO;
    }
}

void Mapa::limpe()
{
    for(int i = 0; i < tamanho; ++i)
    {
        matriz[i] = new MapaEnum[tamanho];
    }

    for(int i = 0; i < tamanho; ++i)
    {
        for(int j = 0; j < tamanho; ++j)
        {
            matriz[i][j] = LIVRE;
        }
    }
}

void Mapa::crieObstaculo()
{
    Obstaculo * novoObstaculo;
    Coordenadas * coordenada;
    do {
        novoObstaculo = fabricaDeObstaculos->crie(tamanho);
        coordenada = novoObstaculo->obtenhaCoordenada();
    } while ((matriz[coordenada->getX()][coordenada->getY()] == COLISAO)||(matriz[coordenada->getX()][coordenada->getY()] == ALIMENTO));
    obstaculos->push_back(*novoObstaculo);
}

GameOverExcessao *Mapa::obtenhaGameOver()
{
    return gameOver;
}

