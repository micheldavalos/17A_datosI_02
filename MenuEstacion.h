//
// Created by michel on 02/04/2017.
//

#ifndef ACTIVIDAD02_MENUESTACION_H
#define ACTIVIDAD02_MENUESTACION_H

#include <iostream>
#include <sstream>
#include <iomanip>
#include "arreglo.h"
#include "Estacion.h"

using namespace std;
class MenuEstacion {

private:

    arreglo< arreglo<Estacion*> > estaciones; /*!< matriz de estaciones 4x4. */

    /*!
     *! Visualizacion del Menu Estaciones.
     * */
    void menu();

    void registrar();
    void pedirId(Estacion *estacion);
    void pedirPosicion(Estacion *estacion);

    void expandir(int tamano);

    bool posicionValida(Posicion &posicion);

    void mostrar();

    void eliminar();

    void leerPosicion(Posicion &posicion);

    bool excedePosicion(Posicion &posicion);

public:


    /*! Constrctor.
     *! Constructor inicial para inicializar la matriz de estaciones
     *! con datos nullptr
     * */
    MenuEstacion(){
        arreglo<Estacion*> fila(4, nullptr);
        for (int i = 0; i < estaciones.capacidad(); ++i) { /* ciclo para las filas*/
            estaciones.insertar_ultimo(fila);
            }

        menu();
        }

    void modificar();
};


#endif //ACTIVIDAD02_MENUESTACION_H
