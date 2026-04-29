#pragma once
#include "ICalificacion.h"
#include <iostream>

// CLASE ABSTRACTA
class CalificacionBase : public ICalificacion {
protected:
    std::string materia;
    std::string alumno;
    double nota;
    int semestre;
public:
    CalificacionBase(std::string materia, std::string alumno, double nota, int semestre)
        : materia(materia), alumno(alumno), nota(nota), semestre(semestre) {}

    std::string getMateria() override { return materia; }
    double getNota() override { return (double)nota; }

    void mostrarEncabezado() {
        std::cout << "---- Calificacion ----" << std::endl;
    }

    virtual void mostrarDatos() = 0;
};
