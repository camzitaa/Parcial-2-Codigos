#pragma once
#include "Paciente.h"

// PILA estatica con arreglo
class Pila {
private:
    static const int MAX = 50;
    Paciente* datos[MAX];
    int tope;
public:
    Pila() : tope(-1) {}

    void push(Paciente* e) {
        if(tope < MAX-1) datos[++tope] = e;
        else std::cout << "Pila llena." << std::endl;
    }

    Paciente* pop() {
        if(!estaVacia()) return datos[tope--];
        std::cout << "Pila vacia." << std::endl;
        return nullptr;
    }

    bool estaVacia() { return tope == -1; }
    int obtenerCantidad() { return tope+1; }

    void copiarCampo(double* arr, int& n) {
        n = tope+1;
        for(int i=0;i<=tope;i++) arr[i] = datos[i]->getEdad();
    }

    void mostrar() {
        if(estaVacia()){ std::cout<<"Pila vacia."<<std::endl; return; }
        std::cout<<"=== REGISTRO DE PACIENTES ==="<<std::endl;
        for(int i=tope;i>=0;i--) datos[i]->mostrarDatos();
    }
};
