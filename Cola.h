#pragma once
#include "Calificacion.h"

// COLA estatica con arreglo
class Cola {
private:
    static const int MAX = 50;
    Calificacion* datos[MAX];
    int frente, fin, cantidad;
public:
    Cola() : frente(0), fin(0), cantidad(0) {}

    void encolar(Calificacion* e) {
        if(cantidad < MAX){ datos[fin]=e; fin=(fin+1)%MAX; cantidad++; }
        else std::cout<<"Cola llena."<<std::endl;
    }

    Calificacion* desencolar() {
        if(!estaVacia()){ Calificacion* e=datos[frente]; frente=(frente+1)%MAX; cantidad--; return e; }
        std::cout<<"Cola vacia."<<std::endl; return nullptr;
    }

    bool estaVacia() { return cantidad==0; }
    int obtenerCantidad() { return cantidad; }

    void copiarCampo(double* arr, int& n) {
        n = cantidad;
        for(int i=0;i<cantidad;i++) arr[i]=datos[(frente+i)%MAX]->getNota();
    }

    void mostrar() {
        if(estaVacia()){ std::cout<<"Cola vacia."<<std::endl; return; }
        std::cout<<"=== SISTEMA DE CALIFICACIONES ==="<<std::endl;
        for(int i=0;i<cantidad;i++) datos[(frente+i)%MAX]->mostrarDatos();
    }
};
