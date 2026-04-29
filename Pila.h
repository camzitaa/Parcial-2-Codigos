#pragma once
#include "Empleado.h"
using namespace std;

// PILA estatica con arreglo
class Pila {
private:
    static const int MAX = 50;
    Empleado* datos[MAX];
    int tope;
public:
    Pila() : tope(-1) {}

    void push(Empleado* e) {
        if (tope < MAX - 1) datos[++tope] = e;
        else cout << "Pila llena." << endl;
    }

    Empleado* pop() {
        if (!estaVacia()) return datos[tope--];
        cout << "Pila vacia." << endl;
        return nullptr;
    }

    bool estaVacia() { return tope == -1; }
    int obtenerCantidad() { return tope + 1; }

    void copiarSueldos(double* arr, int& n) {
        n = tope + 1;
        for (int i = 0; i <= tope; i++) arr[i] = datos[i]->getSueldo();
    }

    void mostrar() {
        if (estaVacia()) { cout << "Pila vacia." << endl; return; }
        cout << "=== Registro de Empleados ===" << endl;
        for (int i = tope; i >= 0; i--) datos[i]->mostrarDatos();
    }
};
