#pragma once
#include <string>

// INTERFAZ
class IAuto {
public:
    virtual void mostrarDatos() = 0;
    virtual std::string getMarca() = 0;
    virtual double getPrecio() = 0;
    virtual ~IAuto() {}
};
