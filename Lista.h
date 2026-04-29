#pragma once
#include "Libro.h"

// LISTA estatica con arreglo
class Lista {
private:
    static const int MAX = 50;
    Libro* datos[MAX];
    int cantidad;
public:
    Lista() : cantidad(0) {}

    void agregar(Libro* e) {
        if(cantidad < MAX) datos[cantidad++]=e;
        else std::cout<<"Lista llena."<<std::endl;
    }

    void eliminar(int idx) {
        if(idx<0||idx>=cantidad){ std::cout<<"Indice invalido."<<std::endl; return; }
        delete datos[idx];
        for(int i=idx;i<cantidad-1;i++) datos[i]=datos[i+1];
        cantidad--; std::cout<<"Eliminado."<<std::endl;
    }

    bool estaVacia() { return cantidad==0; }
    int obtenerCantidad() { return cantidad; }

    void copiarCampo(double* arr, int& n) {
        n=cantidad;
        for(int i=0;i<cantidad;i++) arr[i]=datos[i]->getPrecio();
    }

    void mostrar() {
        if(estaVacia()){ std::cout<<"Lista vacia."<<std::endl; return; }
        std::cout<<"=== BIBLIOTECA DE LIBROS ==="<<std::endl;
        for(int i=0;i<cantidad;i++){ std::cout<<"["<<i<<"] "; datos[i]->mostrarDatos(); }
    }
};
