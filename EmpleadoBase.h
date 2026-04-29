#pragma once
#include "IEmpleado.h"
#include <iostream>
using namespace std;

// CLASE ABSTRACTA
class EmpleadoBase : public IEmpleado {
protected:
    string nombre;
    double sueldo;
    string puesto;
public:
    EmpleadoBase(string nombre, double sueldo, string puesto)
        : nombre(nombre), sueldo(sueldo), puesto(puesto) {}

    string getNombre() override { return nombre; }
    double getSueldo() override { return sueldo; }

    void mostrarEncabezado() {
        cout << "---- Empleado ----" << endl;
    }

    virtual void mostrarDatos() = 0;
};
