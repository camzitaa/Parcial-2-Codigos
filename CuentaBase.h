#pragma once
#include "ICuenta.h"
#include <iostream>

// CLASE ABSTRACTA
class CuentaBase : public ICuenta {
protected:
    std::string titular;
    std::string numeroCuenta;
    double saldo;
    std::string tipo;
public:
    CuentaBase(std::string titular, std::string numeroCuenta, double saldo, std::string tipo)
        : titular(titular), numeroCuenta(numeroCuenta), saldo(saldo), tipo(tipo) {}

    std::string getTitular() override { return titular; }
    double getSaldo() override { return (double)saldo; }

    void mostrarEncabezado() {
        std::cout << "---- Cuenta ----" << std::endl;
    }

    virtual void mostrarDatos() = 0;
};
