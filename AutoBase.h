#pragma once
#include "IAuto.h"
#include <iostream>

// CLASE ABSTRACTA
class AutoBase : public IAuto {
protected:
    std::string marca;
    std::string modelo;
    int anio;
    double precio;
public:
    AutoBase(std::string marca, std::string modelo, int anio, double precio)
        : marca(marca), modelo(modelo), anio(anio), precio(precio) {}

    std::string getMarca() override { return marca; }
    double getPrecio() override { return (double)precio; }

    void mostrarEncabezado() {
        std::cout << "---- Auto ----" << std::endl;
    }

    virtual void mostrarDatos() = 0;
};
