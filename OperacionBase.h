#pragma once
#include "IOperacion.h"
#include <iostream>
using namespace std;

// CLASE ABSTRACTA
class OperacionBase : public IOperacion {
protected:
    string nombre;
public:
    OperacionBase(string nombre) : nombre(nombre) {}
    string getNombre() override { return nombre; }
    void mostrar(double resultado) {
        cout << "Operacion: " << nombre << " | Resultado: " << resultado << endl;
    }
    virtual double ejecutar(double a, double b) = 0;
};
