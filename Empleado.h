#pragma once
#include "EmpleadoBase.h"
using namespace std;

// IMPLEMENTACION CONCRETA
class Empleado : public EmpleadoBase {
private:
    int numEmpleado;
public:
    Empleado(string nombre, double sueldo, string puesto, int numEmpleado)
        : EmpleadoBase(nombre, sueldo, puesto), numEmpleado(numEmpleado) {}

    void mostrarDatos() override {
        mostrarEncabezado();
        cout << "No. Empleado: " << numEmpleado << endl;
        cout << "Nombre:       " << nombre << endl;
        cout << "Puesto:       " << puesto << endl;
        cout << "Sueldo:       $" << sueldo << endl;
    }

    int getNumEmpleado() { return numEmpleado; }
};
