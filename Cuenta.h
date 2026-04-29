#pragma once
#include "CuentaBase.h"

// IMPLEMENTACION CONCRETA
class Cuenta : public CuentaBase {
public:
    Cuenta(std::string titular, std::string numeroCuenta, double saldo, std::string tipo)
        : CuentaBase(titular, numeroCuenta, saldo, tipo) {}

    void mostrarDatos() override {
        mostrarEncabezado();
        std::cout << "  titular: " << titular << std::endl;
        std::cout << "  numeroCuenta: " << numeroCuenta << std::endl;
        std::cout << "  saldo: " << saldo << std::endl;
        std::cout << "  tipo: " << tipo << std::endl;
    }
};
