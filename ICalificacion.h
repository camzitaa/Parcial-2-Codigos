#pragma once
#include <string>

// INTERFAZ
class ICalificacion {
public:
    virtual void mostrarDatos() = 0;
    virtual std::string getMateria() = 0;
    virtual double getNota() = 0;
    virtual ~ICalificacion() {}
};
