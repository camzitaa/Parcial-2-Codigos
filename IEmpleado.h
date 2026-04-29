#pragma once
#include <string>
using namespace std;

// INTERFAZ
class IEmpleado {
public:
    virtual void mostrarDatos() = 0;
    virtual string getNombre() = 0;
    virtual double getSueldo() = 0;
    virtual ~IEmpleado() {}
};
