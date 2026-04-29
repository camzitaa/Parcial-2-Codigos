#include <iostream>
#include "Cola.h"
using namespace std;

// === ORDENAMIENTOS sobre promedios ===
void burbuja(double* arr, int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j+1]) { double t = arr[j]; arr[j] = arr[j+1]; arr[j+1] = t; }
}

void merge(double* arr, int izq, int mid, int der) {
    int n1 = mid-izq+1, n2 = der-mid;
    double* L = new double[n1]; double* R = new double[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[izq+i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid+1+j];
    int i=0,j=0,k=izq;
    while(i<n1&&j<n2) arr[k++]=(L[i]<=R[j])?L[i++]:R[j++];
    while(i<n1) arr[k++]=L[i++];
    while(j<n2) arr[k++]=R[j++];
    delete[] L; delete[] R;
}

void mergeSort(double* arr, int n) {
    for (int tam=1; tam<n; tam*=2)
        for (int izq=0; izq<n-tam; izq+=2*tam) {
            int mid=izq+tam-1, der=min(izq+2*tam-1,n-1);
            merge(arr,izq,mid,der);
        }
}

void quickSort(double* arr, int n) {
    int* pila = new int[n]; int tope=-1;
    pila[++tope]=0; pila[++tope]=n-1;
    while(tope>=0) {
        int der=pila[tope--], izq=pila[tope--];
        double piv=arr[der]; int i=izq-1;
        for(int j=izq;j<der;j++)
            if(arr[j]<=piv){i++;double t=arr[i];arr[i]=arr[j];arr[j]=t;}
        double t=arr[i+1];arr[i+1]=arr[der];arr[der]=t;
        int pi=i+1;
        if(pi-1>izq){pila[++tope]=izq;pila[++tope]=pi-1;}
        if(pi+1<der){pila[++tope]=pi+1;pila[++tope]=der;}
    }
    delete[] pila;
}

void mostrarArr(double* arr, int n) {
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;
}

int main() {
    Cola cola;
    int opcion;

    do {
        cout << "\n=== REGISTRO DE ALUMNOS ===" << endl;
        cout << "1. Agregar alumno" << endl;
        cout << "2. Ver todos los alumnos" << endl;
        cout << "3. Atender alumno (desencolar)" << endl;
        cout << "4. Ordenar por promedio" << endl;
        cout << "5. Salir" << endl;
        cout << "Opcion: "; cin >> opcion;

        if (opcion == 1) {
            string nombre, matricula; int edad; double promedio;
            cout << "Nombre: "; cin >> nombre;
            cout << "Edad: "; cin >> edad;
            cout << "Promedio: "; cin >> promedio;
            cout << "Matricula: "; cin >> matricula;
            cola.encolar(new Alumno(nombre, edad, promedio, matricula));
            cout << "Alumno agregado." << endl;
        } else if (opcion == 2) {
            cola.mostrar();
        } else if (opcion == 3) {
            Alumno* a = cola.desencolar();
            if (a) { cout << "Atendiendo a: "; a->mostrarDatos(); delete a; }
        } else if (opcion == 4) {
            double arr[50]; int n;
            cola.copiarPromedios(arr, n);
            if (n == 0) { cout << "Sin alumnos." << endl; continue; }
            double c1[50], c2[50];
            for(int i=0;i<n;i++){c1[i]=arr[i];c2[i]=arr[i];}
            cout << "Original:  "; mostrarArr(arr, n);
            burbuja(arr, n);   cout << "Burbuja:   "; mostrarArr(arr, n);
            mergeSort(c1, n);  cout << "MergeSort: "; mostrarArr(c1, n);
            quickSort(c2, n);  cout << "QuickSort: "; mostrarArr(c2, n);
        } else if (opcion != 5) {
            cout << "Opcion invalida." << endl;
        }
    } while (opcion != 5);

    cout << "Hasta luego." << endl;
    return 0;
}
