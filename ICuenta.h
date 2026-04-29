#pragma once
#include <string>

// INTERFAZ
class ICuenta {
public:
    virtual void mostrarDatos() = 0;
    virtual std::string getTitular() = 0;
    virtual double getSaldo() = 0;
    virtual ~ICuenta() {}
};
