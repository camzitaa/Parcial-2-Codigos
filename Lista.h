#pragma once
#include "Producto.h"
using namespace std;

// LISTA estatica con arreglo
class Lista {
private:
    static const int MAX = 50;
    Producto* datos[MAX];
    int cantidad;
public:
    Lista() : cantidad(0) {}

    void agregar(Producto* p) {
        if (cantidad < MAX) datos[cantidad++] = p;
        else cout << "Lista llena." << endl;
    }

    void eliminar(int indice) {
        if (indice < 0 || indice >= cantidad) { cout << "Indice invalido." << endl; return; }
        delete datos[indice];
        for (int i = indice; i < cantidad - 1; i++) datos[i] = datos[i+1];
        cantidad--;
        cout << "Producto eliminado." << endl;
    }

    bool estaVacia() { return cantidad == 0; }
    int obtenerCantidad() { return cantidad; }

    void copiarPrecios(double* arr, int& n) {
        n = cantidad;
        for (int i = 0; i < cantidad; i++) arr[i] = datos[i]->getPrecio();
    }

    void mostrar() {
        if (estaVacia()) { cout << "Lista vacia." << endl; return; }
        cout << "=== Inventario ===" << endl;
        for (int i = 0; i < cantidad; i++) {
            cout << "[" << i << "] "; datos[i]->mostrarDatos();
        }
    }
};
