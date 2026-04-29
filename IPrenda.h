#pragma once
#include <string>

// INTERFAZ
class IPrenda {
public:
    virtual void mostrarDatos() = 0;
    virtual std::string getNombre() = 0;
    virtual double getPrecio() = 0;
    virtual ~IPrenda() {}
};
