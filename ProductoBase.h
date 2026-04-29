#pragma once
#include "IProducto.h"
#include <iostream>
using namespace std;

// CLASE ABSTRACTA
class ProductoBase : public IProducto {
protected:
    string nombre;
    double precio;
    int cantidad;
public:
    ProductoBase(string nombre, double precio, int cantidad)
        : nombre(nombre), precio(precio), cantidad(cantidad) {}

    string getNombre() override { return nombre; }
    double getPrecio() override { return precio; }

    void mostrarEncabezado() {
        cout << "---- Producto ----" << endl;
    }

    virtual void mostrarDatos() = 0;
};
