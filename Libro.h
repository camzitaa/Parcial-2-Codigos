#pragma once
#include "LibroBase.h"

// IMPLEMENTACION CONCRETA
class Libro : public LibroBase {
public:
    Libro(std::string titulo, std::string autor, int anio, double precio)
        : LibroBase(titulo, autor, anio, precio) {}

    void mostrarDatos() override {
        mostrarEncabezado();
        std::cout << "  titulo: " << titulo << std::endl;
        std::cout << "  autor: " << autor << std::endl;
        std::cout << "  anio: " << anio << std::endl;
        std::cout << "  precio: " << precio << std::endl;
    }
};
