#pragma once
#include "PacienteBase.h"

// IMPLEMENTACION CONCRETA
class Paciente : public PacienteBase {
public:
    Paciente(std::string nombre, double edad, std::string diagnostico, int habitacion)
        : PacienteBase(nombre, edad, diagnostico, habitacion) {}

    void mostrarDatos() override {
        mostrarEncabezado();
        std::cout << "  nombre: " << nombre << std::endl;
        std::cout << "  edad: " << edad << std::endl;
        std::cout << "  diagnostico: " << diagnostico << std::endl;
        std::cout << "  habitacion: " << habitacion << std::endl;
    }
};
