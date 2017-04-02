#ifndef ARREGLO_H
#define ARREGLO_H

#include <iostream>
using namespace std;

template <class T>
class arreglo
{
private:
    /* capacidad inicial del arreglo */
    static const unsigned int capacidad_inicial = 4;
    /* capacidad actual del arreglo */
    unsigned int capacidad_actual;
    /* cantidad de elementos en el arreglo */
    unsigned int num_elementos;
    /* el arreglo de elemtos */
    T *data;

public:
    arreglo();
    arreglo(unsigned int capacidad);
    arreglo(unsigned int capacidad, T relleno);
    arreglo(const arreglo<T> &a);
    ~arreglo();

    T &pos(unsigned int p);
    unsigned int &capacidad();
    unsigned int &tamano();
    void expandir(unsigned int nueva_capacidad);

    T &operator[](unsigned int p);

    void operator=(arreglo<T> &a){
        this->expandir(a.capacidad());
        this->num_elementos = a.tamano();

        for(unsigned int i = 0; i < a.tamano(); i++){
            this->data[i] = a[i];
        }

//        arreglo<T> &temp(a);
//        swap(capacidad_actual, temp.capacidad_actual);
//        swap(num_elementos, temp.num_elementos);
//        swap(data, temp.data);

//        return *this;
    }

    void insertar_ultimo( T &dato  );
    void insertar_ultimo( const T &dato  );
    void insertar(unsigned int pos, const T &dato);

    void eliminar_ultimo();
    void eliminar(unsigned int pos);

    friend ostream &operator <<(ostream &salida, arreglo<T> &a){
        for(unsigned int i = 0; i < a.num_elementos; i++)
            salida << a.pos(i) << endl;
        return salida;
    }


};

template <class T>
arreglo<T>::arreglo()
{
    data = new T[capacidad_inicial];
    capacidad_actual = capacidad_inicial;
    num_elementos = 0;
}

template<class T>
arreglo<T>::arreglo(unsigned int capacidad)
{
    data = new T[capacidad];
    capacidad_actual = capacidad;
    num_elementos = 0;
}

template<class T>
arreglo<T>::arreglo(unsigned int capacidad, T relleno)
{
    data = new T[capacidad];
    capacidad_actual = capacidad;
    num_elementos = capacidad;

    for(unsigned int i = 0; i < capacidad; i++)
    {
        data[i] = relleno;
    }
}

template<class T>
arreglo<T>::arreglo(const arreglo<T> &a):
    capacidad_actual(a.capacidad()),
    num_elementos(a.tamano()),
    data(new T[a.capacidad()])
{
    for(unsigned int i = 0; i < a.num_elementos; i++)
        data[i] = a[i];
}

template<class T>
arreglo<T>::~arreglo()
{
    delete[] data;
}

template<class T>
T &arreglo<T>::pos(unsigned int p)
{
    if(p < 0 || p >= num_elementos)
        throw std::out_of_range("no existe la posicion");
    return data[p];
}

template<class T>
unsigned int &arreglo<T>::capacidad()
{
    return capacidad_actual;
}

template<class T>
unsigned int &arreglo<T>::tamano()
{
    return num_elementos;
}

template<class T>
void arreglo<T>::expandir(unsigned int nueva_capacidad)
{

    capacidad_actual = nueva_capacidad;

    T *temp = new T[nueva_capacidad];
    for(unsigned int i = 0; i < num_elementos; i++){
        temp[i] = data[i];
    }
    delete[] data;
    data = temp;


}

template<class T>
T &arreglo<T>::operator[](unsigned int p)
{
    return pos(p);
}

//template<class T>
//T &arreglo<T>::operator=(T &a)
//{

//}

template<class T>
void arreglo<T>::insertar_ultimo(T &dato )
{
    if(num_elementos == capacidad_actual){
        expandir(capacidad_actual*2);
    }
    data[num_elementos] = dato;
    num_elementos++;
}
template<class T>
void arreglo<T>::insertar_ultimo(const T &dato )
{
    if(num_elementos == capacidad_actual){
        expandir(capacidad_actual*2);
    }
    data[num_elementos] = dato;
    num_elementos++;
}

template<class T>
void arreglo<T>::insertar(unsigned int pos, const T &dato)
{
    if(pos < 0 || pos >= num_elementos)
        throw std::out_of_range("posicion no valida");

    if(num_elementos == capacidad_actual)
        expandir(2*capacidad_actual);

    for(unsigned int i = num_elementos; i > pos; i--)
        data[i] = data[i-1];

    data[pos] = dato;
    num_elementos++;
}

template<class T>
void arreglo<T>::eliminar_ultimo()
{
    if(num_elementos == 0)
        throw std::runtime_error("imposible eliminar");
    else{
        num_elementos--;
    }
}

template<class T>
void arreglo<T>::eliminar(unsigned int pos)
{
    if(pos < 0 || pos >= num_elementos)
        throw std::out_of_range("posicion no valida");

    for(unsigned int i = pos; i < num_elementos; i++)
        data[i] = data[i+1];

    num_elementos--;
}




#endif // ARREGLO_H
