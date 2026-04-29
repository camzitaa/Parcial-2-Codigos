#pragma once
#include "AlumnoBase.h"
using namespace std;

// IMPLEMENTACION CONCRETA
class Alumno : public AlumnoBase {
private:
    string matricula;
public:
    Alumno(string nombre, int edad, double promedio, string matricula)
        : AlumnoBase(nombre, edad, promedio), matricula(matricula) {}

    void mostrarDatos() override {
        mostrarEncabezado();
        cout << "Nombre:    " << nombre << endl;
        cout << "Edad:      " << edad << endl;
        cout << "Promedio:  " << promedio << endl;
        cout << "Matricula: " << matricula << endl;
    }

    string getMatricula() { return matricula; }
};
