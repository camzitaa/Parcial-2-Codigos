#include <iostream>
#include "Lista.h"
using namespace std;

void burbuja(double* arr, int n) {
    for(int i=0;i<n-1;i++) for(int j=0;j<n-i-1;j++)
        if(arr[j]>arr[j+1]){double t=arr[j];arr[j]=arr[j+1];arr[j+1]=t;}
}
void merge(double* arr, int izq, int mid, int der) {
    int n1=mid-izq+1,n2=der-mid;
    double* L=new double[n1]; double* R=new double[n2];
    for(int i=0;i<n1;i++) L[i]=arr[izq+i];
    for(int j=0;j<n2;j++) R[j]=arr[mid+1+j];
    int i=0,j=0,k=izq;
    while(i<n1&&j<n2) arr[k++]=(L[i]<=R[j])?L[i++]:R[j++];
    while(i<n1) arr[k++]=L[i++]; while(j<n2) arr[k++]=R[j++];
    delete[] L; delete[] R;
}
void mergeSort(double* arr, int n) {
    for(int tam=1;tam<n;tam*=2)
        for(int izq=0;izq<n-tam;izq+=2*tam){
            int mid=izq+tam-1,der=std::min(izq+2*tam-1,n-1);
            merge(arr,izq,mid,der);
        }
}
void quickSort(double* arr, int n) {
    int* pila=new int[n]; int tope=-1;
    pila[++tope]=0; pila[++tope]=n-1;
    while(tope>=0){
        int der=pila[tope--],izq=pila[tope--];
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
void mostrarArr(double* arr, int n){for(int i=0;i<n;i++) std::cout<<arr[i]<<" "; std::cout<<std::endl;}
void ordenar(double* arr, int n){
    if(n==0){std::cout<<"Sin datos para ordenar."<<std::endl;return;}
    double c1[50],c2[50];
    for(int i=0;i<n;i++){c1[i]=arr[i];c2[i]=arr[i];}
    std::cout<<"Original:  "; mostrarArr(arr,n);
    burbuja(arr,n);   std::cout<<"Burbuja:   "; mostrarArr(arr,n);
    mergeSort(c1,n);  std::cout<<"MergeSort: "; mostrarArr(c1,n);
    quickSort(c2,n);  std::cout<<"QuickSort: "; mostrarArr(c2,n);
}

int main() {
    Lista est;
    int opcion;

    do {
        std::cout<<"\n=== BIBLIOTECA DE LIBROS ==="<<std::endl;
        std::cout<<"1. Agregar"<<std::endl;
        std::cout<<"2. Ver todos"<<std::endl;
        std::cout<<"3. Quitar/Atender"<<std::endl;
        std::cout<<"4. Ordenar por precio"<<std::endl;
        std::cout<<"5. Salir"<<std::endl;
        std::cout<<"Opcion: "; std::cin>>opcion;

        if(opcion==1){
        std::string titulo; std::cout<<"titulo: "; std::cin>>titulo;
        std::string autor; std::cout<<"autor: "; std::cin>>autor;
        int anio; std::cout<<"anio: "; std::cin>>anio;
        double precio; std::cout<<"precio: "; std::cin>>precio;
            est.agregar(new Libro(titulo, autor, anio, precio));
            std::cout<<"Registro agregado."<<std::endl;
        } else if(opcion==2){
            est.mostrar();
        } else if(opcion==3){
        est.mostrar();
        int idx; std::cout<<"Indice a eliminar: "; std::cin>>idx;
        est.eliminar(idx);
        } else if(opcion==4){
            double arr[50]; int n;
            est.copiarCampo(arr, n);
            ordenar(arr, n);
        } else if(opcion!=5){
            std::cout<<"Opcion invalida."<<std::endl;
        }
    } while(opcion!=5);

    std::cout<<"Hasta luego."<<std::endl;
    return 0;
}
