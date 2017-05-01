#ifndef COORDENADAS_H
#define COORDENADAS_H

class Coordenadas
{
public:
    Coordenadas(int x, int y);
    ~Coordenadas();
    void setX(int x);
    void setY(int y);
    int getX();
    int getY();
    void incrementeX();
    void incrementeY();
    void decrementeX();
    void decrementeY();

private:
    int x, y;
};

#endif // COORDENADAS_H
