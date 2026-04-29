#pragma once
#include "IContacto.h"
#include <iostream>

// CLASE ABSTRACTA
class ContactoBase : public IContacto {
protected:
    std::string nombre;
    std::string telefono;
    std::string email;
    double edad;
public:
    ContactoBase(std::string nombre, std::string telefono, std::string email, double edad)
        : nombre(nombre), telefono(telefono), email(email), edad(edad) {}

    std::string getNombre() override { return nombre; }
    double getEdad() override { return (double)edad; }

    void mostrarEncabezado() {
        std::cout << "---- Contacto ----" << std::endl;
    }

    virtual void mostrarDatos() = 0;
};
