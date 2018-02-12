#-------------------------------------------------
#
# Project created by QtCreator      2017 / 2018
#
#-------------------------------------------------

# Francesco Minna 1103073

CONFIG += c++11
CONFIG += c11

QT += core gui 
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QMAKE_CXXFLAGS += -std=c++11

TARGET = Calcolatrice
TEMPLATE = app

HEADERS  += \
    Model/punto.h \
    Model/figura.h \
    Model/vertice.h \
    Model/triangolo.h \
    Model/poligonoconvesso.h \
    Model/quadrilatero.h \
    Model/rettangolo.h \
    Model/quadrato.h \
    View/calcolatrice.h \
    View/assi.h \
    Controller/dati.h \
    Controller/graphcontroller.h \
    View/poligonic.h \
    View/insertfigura.h \
    View/gscene.h \
    View/gview.h

SOURCES += main.cpp \
    Model/punto.cpp \
    Model/vertice.cpp \
    Model/poligonoconvesso.cpp \
    Model/triangolo.cpp \
    Model/quadrilatero.cpp \
    Model/rettangolo.cpp \
    Model/quadrato.cpp \
    Model/figura.cpp \
    View/calcolatrice.cpp \
    View/assi.cpp \
    Controller/dati.cpp \
    Controller/graphcontroller.cpp \
    View/poligonic.cpp \
    View/insertfigura.cpp \
    View/gscene.cpp \
    View/gview.cpp

FORMS += View/calcolatrice.ui \
    View/insertfigura.ui

RESOURCES += \
    icone.qrc
