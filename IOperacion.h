#pragma once
#include <string>
using namespace std;

// INTERFAZ - clase abstracta pura
class IOperacion {
public:
    virtual double ejecutar(double a, double b) = 0;
    virtual string getNombre() = 0;
    virtual ~IOperacion() {}
};
