#ifndef MENSAGEM_H
#define MENSAGEM_H

#include "objeto.h"
#include <iostream>
#include <QPainter>

using std::string;

class Mensagem : public Objeto
{
public:
    Mensagem(string nome);
    ~Mensagem();
    void desenhe(QPainter* pincel);

private:
    string nome;
};

#endif // MENSAGEM_H
