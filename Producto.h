#pragma once
#include "ProductoBase.h"
using namespace std;

// IMPLEMENTACION CONCRETA
class Producto : public ProductoBase {
private:
    string categoria;
public:
    Producto(string nombre, double precio, int cantidad, string categoria)
        : ProductoBase(nombre, precio, cantidad), categoria(categoria) {}

    void mostrarDatos() override {
        mostrarEncabezado();
        cout << "Nombre:    " << nombre << endl;
        cout << "Precio:    $" << precio << endl;
        cout << "Cantidad:  " << cantidad << endl;
        cout << "Categoria: " << categoria << endl;
    }

    string getCategoria() { return categoria; }
    int getCantidad() { return cantidad; }
};
