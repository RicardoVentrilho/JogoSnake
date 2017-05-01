#include "jogo.h"
#include "ui_jogo.h"

Jogo::Jogo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Jogo)
{   
    ui->setupUi(this);

    tempo = new QTimer(this);
    direcao = DIREITA;
    mapa = Mapa::obtenhaInstancia();

    tempo->setInterval(100);
    connect(tempo, SIGNAL(timeout()), this, SLOT(atualiza()));
    tempo->start();

}

Jogo::~Jogo()
{
    delete pincel;
    delete tempo;
    delete mapa;
    delete ui;
}

void Jogo::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Up:
        direcao = CIMA;
        break;
    case Qt::Key_Down:
        direcao = BAIXO;
        break;
    case Qt::Key_Left:
        direcao = ESQUERDA;
        break;
    case Qt::Key_Right:
        direcao = DIREITA;
        break;
    default:
        //Faz nada
        break;
    }
}

void Jogo::paintEvent(QPaintEvent *)
{
    //Encontrar uma solução para isso
    pincel = new QPainter(this);

    mapa->desenhe(pincel);

    if(mapa->obtenhaGameOver() != NULL)
    {
        mapa->obtenhaGameOver()->desenhe(pincel);
    }
}

void Jogo::atualiza()
{
    try {
        mapa->crieAlimento();
        mapa->atualize();
        mapa->movimenteACobra(direcao);
    }
    catch(GameOverExcessao* gameOver)
    {
        tempo->stop();
    }
    repaint();
}
