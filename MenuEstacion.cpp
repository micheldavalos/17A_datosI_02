//
// Created by michel on 02/04/2017.
//

#include "MenuEstacion.h"

#define MAX_FILA 16
#define MAX_COL 16

void MenuEstacion::menu() {
    string op;

    while (true){
        cout << "** Estaciones **" << endl;
        cout << "1) Registrar Nueva Estacion" << endl;
        cout << "2) Mostrar" << endl;
        cout << "3) Eliminar" << endl;
        cout << "4) Modificar" << endl;
        cout << "0) Salir" << endl;

        getline(cin, op);

        if("1" == op){
            registrar();
        }
        else if("2" == op){
            mostrar();
        }
        else if("3" == op){
            eliminar();
        }


        else if("0" == op){
            break;
        }
    }

}

void MenuEstacion::registrar() {
    Estacion *estacion = new Estacion;
    pedirId(estacion);

    pedirPosicion(estacion);
}

bool MenuEstacion::posicionValida(Posicion &posicion) {
    return (posicion.getColumna() < MAX_COL) &&
           (posicion.getFila()    < MAX_FILA) ;
}

void MenuEstacion::expandir(int tamano) {

    arreglo<Estacion*> fila(tamano, nullptr);
    // Expando filas e inserto filas
    estaciones.expandir(tamano);
    for(unsigned int i = 0; i < tamano/2; i++){
        estaciones.insertar_ultimo(fila);
    }
    // Expando cada fila exitente a 8
    for(unsigned int i = 0; i < tamano; i++){
        estaciones[i].expandir(tamano);
    }
    // Inserto nullptr en las primeras filas
    for(unsigned int fila = 0; fila < tamano/2; fila++){
        for(unsigned int i = 0; i < tamano/2; i++){
            estaciones[fila].insertar_ultimo(nullptr);
        }
    }
    // Inserto nullptr en las ultimas filas
    for(unsigned int fila = tamano/2; fila < tamano; fila++){
        for(unsigned int i = 0; i < tamano; i++){
            estaciones[fila].insertar_ultimo(nullptr);
        }
    }

}

void MenuEstacion::pedirId(Estacion *estacion) {
    string temp;

    cout << "Id: ";
    getline(cin, temp);
    estacion->setId(temp);
}

void MenuEstacion::pedirPosicion(Estacion *estacion) {
    Posicion posicion;

    leerPosicion(posicion);


    if(excedePosicion(posicion))
    {
        if(14 >= (posicion.getFila() + posicion.getColumna())){
            /*expandir a 8x8 */
            expandir(8);
        }
        else{
            /* expandir a 16x16 */
            if(8 == estaciones.capacidad() )
                expandir(16);
            else{
                expandir(8);
                expandir(16);
            }
        }
    }
    estaciones[posicion.getFila()][posicion.getColumna()] = estacion;
    estacion->setPosicion(posicion);
}

void MenuEstacion::mostrar() {
    for (int i = 0; i < estaciones.capacidad(); ++i) {
        for (int j = 0; j < estaciones[0].capacidad(); ++j) {
            if(estaciones[i][j] != nullptr)
                cout << *estaciones[i][j];
            else
                cout << setw(10) << "*";
        }
        cout << endl;
    }
}

void MenuEstacion::eliminar() {
    Posicion posicion;

    leerPosicion(posicion);

    if(excedePosicion(posicion))
    {
        cout << "No hay estacion" << endl;
    }

    if( estaciones[posicion.getFila()][posicion.getColumna()] == nullptr){
        cout << "No hay estacion" << endl;
    } else{
        delete estaciones[posicion.getFila()][posicion.getColumna()];
        estaciones[posicion.getFila()][posicion.getColumna()] = nullptr;
    }
}

void MenuEstacion::leerPosicion(Posicion &posicion) {
    string temp;
    unsigned int fila, columna;

    do {
        stringstream ss;
        cout << "Fila: ";
        getline(cin, temp);
        ss << temp;
        ss >> fila;
        posicion.setFila(fila);

        ss.clear();

        cout << "Columna: ";
        getline(cin, temp);
        ss << temp;
        ss >> columna;
        posicion.setColumna(columna);


    } while (!posicionValida(posicion));


}

bool MenuEstacion::excedePosicion(Posicion &posicion) {
    return (posicion.getFila() >= estaciones[0].capacidad())
           || (posicion.getColumna() >= estaciones.capacidad());
}
