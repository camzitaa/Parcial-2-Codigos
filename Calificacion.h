#pragma once
#include "CalificacionBase.h"

// IMPLEMENTACION CONCRETA
class Calificacion : public CalificacionBase {
public:
    Calificacion(std::string materia, std::string alumno, double nota, int semestre)
        : CalificacionBase(materia, alumno, nota, semestre) {}

    void mostrarDatos() override {
        mostrarEncabezado();
        std::cout << "  materia: " << materia << std::endl;
        std::cout << "  alumno: " << alumno << std::endl;
        std::cout << "  nota: " << nota << std::endl;
        std::cout << "  semestre: " << semestre << std::endl;
    }
};
