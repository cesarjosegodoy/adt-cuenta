#include<iostream>
#include<conio.h>
using namespace std;


// definicion del TIPO DE DATO  de la Lista Simplemente enlazada

typedef float Dinero;
const Dinero indefinido = 9999;


// Definision del NODO  de la Lista
struct Nodo {    
    Dinero dato;
    Nodo* siguiente;      
};

// Definision de la CABEZARA  de la Lista

 typedef struct {

     float Dineros;
     Nodo* depositos;

}Cuenta;


// PROTOTIPO DE LAS OPERACIONES  de la Lista Enlazada 

Cuenta CuentaVacia(); // constructora que crea una comision sin alumnos
Cuenta depositar (Cuenta C, Dinero X);


// Programa Principal

int main(){


getch();
return 0;

}

Cuenta CuentaVacia(){
    Cuenta nueva;
    nueva.depositos = NULL;
    nueva.Dineros = 0;



    return nueva;
};


Cuenta depositar (Cuenta C, Dinero X){

    Nodo * nuevo = new Nodo;
    nuevo->dato = X;
    nuevo->siguiente = C.depositos;
    C.depositos = nuevo;
    

    return C;



};