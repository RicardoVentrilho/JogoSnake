#include "cobra.h"

Cobra::Cobra()
{
    item = new QPixmap("Imagens/cobra.png");
    cobra = new list<Coordenadas>();
    direcao = DIREITA;
    tamanho = 1;

    cobra->push_front(Coordenadas(0,0));
}

Cobra::~Cobra()
{
    delete item;
    delete cobra;
}

void Cobra::desenhe(QPainter *pincel)
{
    for (list<Coordenadas>::iterator it = cobra->begin(); it != cobra->end(); ++it)
    {
        pincel->drawPixmap((*it).getX()*10, (*it).getY()*10, 10, 10, *(this->item));
    }
}

void Cobra::movimentePara(int x, int y)
{
    cobra->pop_back();
    cobra->push_front(Coordenadas(x, y));
}

//void Cobra::movimente(DirecaoEnum direcao)
//{
//    this->direcao = direcao;

//    int x = (*cobra->begin()).getX();
//    int y = (*cobra->begin()).getY();
//    cobra->pop_back();

//    switch (this->direcao) {
//    case CIMA:
//        cobra->push_front(Coordenadas(x, --y));
//        break;
//    case BAIXO:
//        cobra->push_front(Coordenadas(x, ++y));
//        break;
//    case DIREITA:
//        cobra->push_front(Coordenadas(++x, y));
//        break;
//    case ESQUERDA:
//        cobra->push_front(Coordenadas(--x, y));
//        break;
//    default:
//        break;
//    }
//}

void Cobra::coma(Objeto *alimento)
{

}

void Cobra::aumente(int valor)
{
    for(int i = 0; i < valor; ++i)
    {
        cobra->push_back((*cobra->end()));
    }
    tamanho += valor;
}

list<Coordenadas> *Cobra::obtenhaCoordenadas()
{
    return cobra;
}

DirecaoEnum Cobra::obtenhaDirecao()
{
    return this->direcao;
}

void Cobra::coloqueDirecao(DirecaoEnum direcao)
{
    this->direcao = direcao;
}

