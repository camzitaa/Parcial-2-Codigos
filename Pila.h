#pragma once
#include <iostream>
using namespace std;

class Pila {
private:
    static const int MAX = 50;
    double datos[MAX];
    int tope;
public:
    Pila() : tope(-1) {}

    void push(double valor) {
        if (tope < MAX - 1) datos[++tope] = valor;
        else cout << "Pila llena." << endl;
    }

    double pop() {
        if (!estaVacia()) return datos[tope--];
        cout << "Pila vacia." << endl;
        return 0;
    }

    bool estaVacia() { return tope == -1; }

    void copiarA(double* arr, int& n) {
        n = tope + 1;
        for (int i = 0; i <= tope; i++) arr[i] = datos[i];
    }

    void mostrar() {
        if (estaVacia()) { cout << "Pila vacia." << endl; return; }
        cout << "=== Historial ===" << endl;
        for (int i = tope; i >= 0; i--)
            cout << "  [" << i << "] " << datos[i] << endl;
    }
};
