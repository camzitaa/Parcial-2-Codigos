#pragma once
#include "Alumno.h"
using namespace std;

// COLA estatica con arreglo
class Cola {
private:
    static const int MAX = 50;
    Alumno* datos[MAX];
    int frente, fin, cantidad;
public:
    Cola() : frente(0), fin(0), cantidad(0) {}

    void encolar(Alumno* a) {
        if (cantidad < MAX) {
            datos[fin] = a;
            fin = (fin + 1) % MAX;
            cantidad++;
        } else cout << "Cola llena." << endl;
    }

    Alumno* desencolar() {
        if (!estaVacia()) {
            Alumno* a = datos[frente];
            frente = (frente + 1) % MAX;
            cantidad--;
            return a;
        }
        cout << "Cola vacia." << endl;
        return nullptr;
    }

    bool estaVacia() { return cantidad == 0; }
    int obtenerCantidad() { return cantidad; }

    void copiarPromedios(double* arr, int& n) {
        n = cantidad;
        for (int i = 0; i < cantidad; i++)
            arr[i] = datos[(frente + i) % MAX]->getPromedio();
    }

    void mostrar() {
        if (estaVacia()) { cout << "Cola vacia." << endl; return; }
        cout << "=== Lista de Alumnos ===" << endl;
        for (int i = 0; i < cantidad; i++)
            datos[(frente + i) % MAX]->mostrarDatos();
    }
};
