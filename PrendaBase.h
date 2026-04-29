#pragma once
#include "IPrenda.h"
#include <iostream>

// CLASE ABSTRACTA
class PrendaBase : public IPrenda {
protected:
    std::string nombre;
    std::string talla;
    double precio;
    int cantidad;
public:
    PrendaBase(std::string nombre, std::string talla, double precio, int cantidad)
        : nombre(nombre), talla(talla), precio(precio), cantidad(cantidad) {}

    std::string getNombre() override { return nombre; }
    double getPrecio() override { return (double)precio; }

    void mostrarEncabezado() {
        std::cout << "---- Prenda ----" << std::endl;
    }

    virtual void mostrarDatos() = 0;
};
