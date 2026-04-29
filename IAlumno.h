#pragma once
#include <string>
using namespace std;

// INTERFAZ
class IAlumno {
public:
    virtual void mostrarDatos() = 0;
    virtual string getNombre() = 0;
    virtual double getPromedio() = 0;
    virtual ~IAlumno() {}
};
