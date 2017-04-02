//
// Created by michel on 02/04/2017.
//

#ifndef ACTIVIDAD02_POSICION_H
#define ACTIVIDAD02_POSICION_H

#include <iostream>
#include <iomanip>
using namespace std;
class Posicion
{
    friend ostream &operator<<(ostream &out, Posicion &posicion){
        out << setw(5) << "(" << posicion.fila << ", " << posicion.columna << ")" ;

        return out;
    }

private:
    unsigned int fila;
    unsigned int columna;
public:
    Posicion(){}

    unsigned int getFila() const {
        return fila;
    }

    void setFila(unsigned int fila) {
        Posicion::fila = fila;
    }

    unsigned int getColumna() const {
        return columna;
    }

    void setColumna(unsigned int columna) {
        Posicion::columna = columna;
    }
};
#endif //ACTIVIDAD02_POSICION_H
