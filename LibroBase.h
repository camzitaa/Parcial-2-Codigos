#pragma once
#include "ILibro.h"
#include <iostream>

// CLASE ABSTRACTA
class LibroBase : public ILibro {
protected:
    std::string titulo;
    std::string autor;
    int anio;
    double precio;
public:
    LibroBase(std::string titulo, std::string autor, int anio, double precio)
        : titulo(titulo), autor(autor), anio(anio), precio(precio) {}

    std::string getTitulo() override { return titulo; }
    double getPrecio() override { return (double)precio; }

    void mostrarEncabezado() {
        std::cout << "---- Libro ----" << std::endl;
    }

    virtual void mostrarDatos() = 0;
};
