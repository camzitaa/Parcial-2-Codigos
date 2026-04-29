#pragma once
#include "ContactoBase.h"

// IMPLEMENTACION CONCRETA
class Contacto : public ContactoBase {
public:
    Contacto(std::string nombre, std::string telefono, std::string email, double edad)
        : ContactoBase(nombre, telefono, email, edad) {}

    void mostrarDatos() override {
        mostrarEncabezado();
        std::cout << "  nombre: " << nombre << std::endl;
        std::cout << "  telefono: " << telefono << std::endl;
        std::cout << "  email: " << email << std::endl;
        std::cout << "  edad: " << edad << std::endl;
    }
};
