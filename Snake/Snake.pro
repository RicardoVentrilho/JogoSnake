#-------------------------------------------------
#
# Project created by QtCreator 2017-04-15T19:00:31
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Snake
TEMPLATE = app


SOURCES += main.cpp\
    jogo.cpp \
    cobra.cpp \
    coordenadas.cpp \
    mapa.cpp \
    objeto.cpp \
    alimento.cpp \
    generica.cpp \
    fabricadealimentos.cpp \
    obstaculo.cpp \
    fabricadeobstaculos.cpp \
    Util/gameoverexcecao.cpp \
    mensagem.cpp

HEADERS  += \
    jogo.h \
    cobra.h \
    coordenadas.h \
    enum.h \
    mapa.h \
    objeto.h \
    alimento.h \
    generica.h \
    fabricadealimentos.h \
    obstaculo.h \
    fabricadeobstaculos.h \
    Util/gameoverexcecao.h \
    mensagem.h

FORMS    += \
    jogo.ui
