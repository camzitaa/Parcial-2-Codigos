#pragma once
#include "IPaciente.h"
#include <iostream>

// CLASE ABSTRACTA
class PacienteBase : public IPaciente {
protected:
    std::string nombre;
    double edad;
    std::string diagnostico;
    int habitacion;
public:
    PacienteBase(std::string nombre, double edad, std::string diagnostico, int habitacion)
        : nombre(nombre), edad(edad), diagnostico(diagnostico), habitacion(habitacion) {}

    std::string getNombre() override { return nombre; }
    double getEdad() override { return (double)edad; }

    void mostrarEncabezado() {
        std::cout << "---- Paciente ----" << std::endl;
    }

    virtual void mostrarDatos() = 0;
};
