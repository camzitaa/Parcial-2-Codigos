#include <iostream>
#include "Calculadora.h"
#include "Pila.h"
using namespace std;

// === ORDENAMIENTOS ===
void burbuja(double* arr, int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1]) { double t = arr[j]; arr[j] = arr[j+1]; arr[j+1] = t; }
}

void merge(double* arr, int izq, int mid, int der) {
    int n1 = mid - izq + 1, n2 = der - mid;
    double* L = new double[n1]; double* R = new double[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[izq + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];
    int i = 0, j = 0, k = izq;
    while (i < n1 && j < n2) arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
    delete[] L; delete[] R;
}

void mergeSort(double* arr, int n) {
    for (int tam = 1; tam < n; tam *= 2)
        for (int izq = 0; izq < n - tam; izq += 2 * tam) {
            int mid = izq + tam - 1;
            int der = min(izq + 2 * tam - 1, n - 1);
            merge(arr, izq, mid, der);
        }
}

void quickSort(double* arr, int n) {
    int* pila = new int[n]; int tope = -1;
    pila[++tope] = 0; pila[++tope] = n - 1;
    while (tope >= 0) {
        int der = pila[tope--], izq = pila[tope--];
        double piv = arr[der]; int i = izq - 1;
        for (int j = izq; j < der; j++)
            if (arr[j] <= piv) { i++; double t = arr[i]; arr[i] = arr[j]; arr[j] = t; }
        double t = arr[i+1]; arr[i+1] = arr[der]; arr[der] = t;
        int pi = i + 1;
        if (pi - 1 > izq) { pila[++tope] = izq; pila[++tope] = pi - 1; }
        if (pi + 1 < der) { pila[++tope] = pi + 1; pila[++tope] = der; }
    }
    delete[] pila;
}

void mostrarArr(double* arr, int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

// === MAIN ===
int main() {
    IOperacion* ops[4] = { new Suma(), new Resta(), new Multiplicacion(), new Division() };
    Pila historial;
    int opcion; double a, b;

    do {
        cout << "\n=== CALCULADORA BASICA ===" << endl;
        cout << "1. Suma\n2. Resta\n3. Multiplicacion\n4. Division" << endl;
        cout << "5. Ver historial\n6. Ordenar historial\n7. Salir" << endl;
        cout << "Opcion: "; cin >> opcion;

        if (opcion >= 1 && opcion <= 4) {
            cout << "Numero 1: "; cin >> a;
            cout << "Numero 2: "; cin >> b;
            double res = ops[opcion - 1]->ejecutar(a, b);
            dynamic_cast<OperacionBase*>(ops[opcion - 1])->mostrar(res);
            historial.push(res);
        } else if (opcion == 5) {
            historial.mostrar();
        } else if (opcion == 6) {
            double arr[50]; int n;
            historial.copiarA(arr, n);
            if (n == 0) { cout << "Sin resultados aun." << endl; continue; }
            double c1[50], c2[50];
            for (int i = 0; i < n; i++) { c1[i] = arr[i]; c2[i] = arr[i]; }
            cout << "Original:  "; mostrarArr(arr, n);
            burbuja(arr, n);   cout << "Burbuja:   "; mostrarArr(arr, n);
            mergeSort(c1, n);  cout << "MergeSort: "; mostrarArr(c1, n);
            quickSort(c2, n);  cout << "QuickSort: "; mostrarArr(c2, n);
        } else if (opcion != 7) {
            cout << "Opcion invalida." << endl;
        }
    } while (opcion != 7);

    for (int i = 0; i < 4; i++) delete ops[i];
    cout << "Hasta luego." << endl;
    return 0;
}
