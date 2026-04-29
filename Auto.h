#pragma once
#include "AutoBase.h"

// IMPLEMENTACION CONCRETA
class Auto : public AutoBase {
public:
    Auto(std::string marca, std::string modelo, int anio, double precio)
        : AutoBase(marca, modelo, anio, precio) {}

    void mostrarDatos() override {
        mostrarEncabezado();
        std::cout << "  marca: " << marca << std::endl;
        std::cout << "  modelo: " << modelo << std::endl;
        std::cout << "  anio: " << anio << std::endl;
        std::cout << "  precio: " << precio << std::endl;
    }
};
