#pragma once
#include <string>

// INTERFAZ
class IContacto {
public:
    virtual void mostrarDatos() = 0;
    virtual std::string getNombre() = 0;
    virtual double getEdad() = 0;
    virtual ~IContacto() {}
};
