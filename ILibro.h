#pragma once
#include <string>

// INTERFAZ
class ILibro {
public:
    virtual void mostrarDatos() = 0;
    virtual std::string getTitulo() = 0;
    virtual double getPrecio() = 0;
    virtual ~ILibro() {}
};
