#pragma once
#include "PrendaBase.h"

// IMPLEMENTACION CONCRETA
class Prenda : public PrendaBase {
public:
    Prenda(std::string nombre, std::string talla, double precio, int cantidad)
        : PrendaBase(nombre, talla, precio, cantidad) {}

    void mostrarDatos() override {
        mostrarEncabezado();
        std::cout << "  nombre: " << nombre << std::endl;
        std::cout << "  talla: " << talla << std::endl;
        std::cout << "  precio: " << precio << std::endl;
        std::cout << "  cantidad: " << cantidad << std::endl;
    }
};
