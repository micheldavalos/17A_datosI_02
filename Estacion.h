//
// Created by michel on 02/04/2017.
//

#ifndef ACTIVIDAD02_ESTACION_H
#define ACTIVIDAD02_ESTACION_H

#include <iostream>

#include "Posicion.h"

using namespace std;
class Estacion
{
    friend ostream &operator<<(ostream &out, Estacion &estacion){
        out << estacion.posicion ;

        return out;
    }
private:
    string id;
    Posicion posicion;
public:

    Estacion(){}

    const string &getId() const {
        return id;
    }

    void setId(const string &id) {
        Estacion::id = id;
    }

    const Posicion &getPosicion() const {
        return posicion;
    }


    void setPosicion(const Posicion &posicion) {
        Estacion::posicion = posicion;
    }

};
#endif //ACTIVIDAD02_ESTACION_H
