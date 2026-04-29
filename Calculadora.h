#pragma once
#include "OperacionBase.h"
using namespace std;

class Suma : public OperacionBase {
public:
    Suma() : OperacionBase("Suma") {}
    double ejecutar(double a, double b) override { return a + b; }
};

class Resta : public OperacionBase {
public:
    Resta() : OperacionBase("Resta") {}
    double ejecutar(double a, double b) override { return a - b; }
};

class Multiplicacion : public OperacionBase {
public:
    Multiplicacion() : OperacionBase("Multiplicacion") {}
    double ejecutar(double a, double b) override { return a * b; }
};

class Division : public OperacionBase {
public:
    Division() : OperacionBase("Division") {}
    double ejecutar(double a, double b) override {
        if (b == 0) { cout << "Error: division entre cero." << endl; return 0; }
        return a / b;
    }
};
