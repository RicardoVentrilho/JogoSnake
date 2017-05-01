#include "time.h"
#include "jogo.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    srand(time(NULL));
    QApplication a(argc, argv);
    Jogo w;
    w.show();

    return a.exec();
}
