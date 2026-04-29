#pragma once
#include <string>
using namespace std;

// INTERFAZ
class IProducto {
public:
    virtual void mostrarDatos() = 0;
    virtual string getNombre() = 0;
    virtual double getPrecio() = 0;
    virtual ~IProducto() {}
};
