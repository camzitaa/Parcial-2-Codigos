#pragma once
#include "IAlumno.h"
#include <iostream>
using namespace std;

// CLASE ABSTRACTA
class AlumnoBase : public IAlumno {
protected:
    string nombre;
    int edad;
    double promedio;
public:
    AlumnoBase(string nombre, int edad, double promedio)
        : nombre(nombre), edad(edad), promedio(promedio) {}

    string getNombre() override { return nombre; }
    double getPromedio() override { return promedio; }

    // Metodo concreto
    void mostrarEncabezado() {
        cout << "---- Alumno ----" << endl;
    }

    // Metodo abstracto
    virtual void mostrarDatos() = 0;
};
