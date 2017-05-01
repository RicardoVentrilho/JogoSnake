#ifndef JOGO_H
#define JOGO_H

#include <iostream>
#include <QWidget>
#include <QTimer>
#include <QPainter>
#include <QKeyEvent>
#include <QTimer>

#include "mapa.h"

namespace Ui {
class Jogo;
}

class Jogo : public QWidget
{
    Q_OBJECT

public:
    explicit Jogo(QWidget *parent = 0);
    ~Jogo();
    void keyPressEvent(QKeyEvent * event);
    void paintEvent(QPaintEvent *);

public slots:
    void atualiza();

private:
    Ui::Jogo *ui;
    QTimer* tempo;
    QPainter* pincel;
    Mapa* mapa;
    DirecaoEnum direcao;
};

#endif // JOGO_H
