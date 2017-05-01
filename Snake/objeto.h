#ifndef OBJETO_H
#define OBJETO_H

#include <QPainter>
#include "coordenadas.h"
#include "enum.h"

class Objeto
{
public:
    Objeto(){}
    virtual ~Objeto(){}
    virtual void desenhe(QPainter* pincel) = 0;
};

#endif // OBJETO_H
