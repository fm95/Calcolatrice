#-------------------------------------------------
#
# Project created by QtCreator
#
#-------------------------------------------------

# Francesco Minna 1103073

QT += core gui 
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QMAKE_CXXFLAGS += -std=c++11

TARGET = Calcolatrice
TEMPLATE = app

HEADERS  += data.h \
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
    View/viewtriangolo.h \
    View/scenetriangolo.h \
    View/viewquadrilatero.h \
    View/viewrettangolo.h \
    View/viewquadrato.h \
    View/itemtriangolo.h \
    View/itemdescrizione.h \ 
    View/inseriscifigura.h \
    Controller/addfigura.h \
    Controller/controllerlista.h

SOURCES += main.cpp \
    data.cpp \
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
    View/viewtriangolo.cpp \
    View/scenetriangolo.cpp \
    View/viewquadrilatero.cpp \
    View/viewrettangolo.cpp \
    View/viewquadrato.cpp \
    View/itemtriangolo.cpp \
    View/itemdescrizione.cpp \
    View/inseriscifigura.cpp \
    Controller/addfigura.cpp \
    Controller/controllerlista.cpp

FORMS    += View/calcolatrice.ui
