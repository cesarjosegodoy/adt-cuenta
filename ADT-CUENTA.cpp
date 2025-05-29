#include<iostream>
#include<conio.h>

using namespace std;


// definicion del TIPO DE DATO  de la Lista Simplemente enlazada

typedef float Dinero;
const Dinero indefinido = 9999;


// DEFINICION del NODO  DE LA LISTA

struct Nodo {    
    Dinero dato;
    struct Nodo *siguiente;      
};

// DEFINICION DE LA CABECERA (depositos) DE LA CUENTA

 typedef struct {
     struct Nodo *depositos;
     int Cantidad; // lleva el control de la Cantidad de Depositos que tiene la Cuenta y dentro del struct la complejidad se hace O(1)
     Dinero Saldo; // lleva el control del saldo de dinero que hay en la cuenta la complejidad se hace se hace O(1)
}Cuenta;


// PROTOTIPO DE LAS OPERACIONES  de la Lista Enlazada 

Cuenta CuentaVacia(); // constructora que crea una comision sin alumnos
Cuenta Depositar (Cuenta C, Dinero X); // constructora primitiva Ingresa un Deposito en la cuenta
bool EstaVacia(Cuenta C); // Test que determina si la cuenta esta vacia - Vacia true = 1
Dinero Ultima (Cuenta C); // Operacion Selectora que obtiene el monto del ultimo deposito
Cuenta Deshacer(Cuenta C); // Operacion que Deshase el ultimo deposito
Dinero MaximoDeposito (Cuenta *C); // Operacion que dada una cuenta devuelve el valor del deposito cuyo deposito sea el mas grande
bool TieneSaldo(Cuenta C); // Test que determina si la cuenta tiene saldo
Cuenta Extraer(Cuenta C,Dinero X); // Selectora que extrae un monto de dinero solicitado
bool Contiene(Cuenta C,Dinero X);// Test que determina si la cuenta tiene un determinado dinero


// Programa Principal

int main(){


Cuenta A;
int vacia;

A = CuentaVacia();

A = Depositar(A,34,5);


vacia = EstaVacia(A);

if (vacia == 1){

printf("\nLa lista esta vacia");

}else {

printf("\nLa lista no esta vacia");

}




getch();
return 0;

}

// DECLARACION DE LAS FUNCIONES 


// Constructora Primitiva que crea una cuenta sin ningun deposito, saldo 0 y cantidad 0;

Cuenta CuentaVacia(){

    Cuenta nueva;
    nueva.depositos = NULL;
    nueva.Cantidad = 0;
    nueva.Saldo = 0;

    return nueva;
}


// Constructora Primitiva que ingresa un deposito a la cuenta 

Cuenta Depositar (Cuenta C, Dinero X){

    struct Nodo * nuevo = new Nodo;
    nuevo->dato = X;
    nuevo->siguiente = C.depositos;
    C.depositos = nuevo;
    C.Cantidad++; // se incrementa a medidad que ingresan los depositos
    C.Saldo = C.saldo + X;// tiene que ir sumando los montos ingresados a medida que la funcion se llame
    return C;

}


// Test que determina si la cuenta esta vacia 

bool EstaVacia(Cuenta C) {


      if (C==NULL) {

          return true;    // Cuenta Vacia true 1

      }else {

          return false;   // False 0 la cuenta tiene Elementos

      }

}


// Retorna el valor del ultimo deposito

Dinero Ultima (Cuenta C){

  Dinero indefinido; 
  Dinero  UltimoDeposito;
  
         if (C == NULL) {
   
             UltimoDeposito = indefinido;
             return UltimoDeposito;

         }else {
  
             UltimoDeposito = C.depositos->dato;
             return UltimoDeposito;
  
        }
  
  }


// Operacion que da de baja el ultimo deposito en la cuenta

  Cuenta Deshacer(Cuenta C){

    struct Nodo* aux;
    if (C != NULL) {
        aux = C;
        C = C.depositos->siguiente;
        free(aux); 
    }

    return L;

}
         
// Operacion que dada una cuenta devuelve el valor del deposito cuyo deposito sea el mas grande

Dinero MaximoDeposito (Cuenta *C){

    Dinero cant = 0;

    while(!EstaVacia(*C)){
         if( Ultima(*C) > cant ){
         cant = Ultima(*C);
         *C = Deshacer(*C);
         }
    return cant;
    }

}

// Test que determina si la cuenta tiene saldo


bool TieneSaldo(Cuenta C){

     if (C.Saldo > 0 and C != NULL) {

          return true;    // tiene saldo  true=1

      }else {

          return false;   // False 0 la cuenta no tiene saldo o esta vacia

      }

}

// Extrae de la cuenta un monto de dinero X

Cuenta Extraer(Cuenta C,Dinero X){

    Dinero aux = 0;

    if (C.Saldo >= X and C != NULL){

        aux = C.Saldo - X;
        C.Saldo = aux;
        return C;
    }else {

    return C;

    }



}


// operacion que pregunta si la cuenta tiene un determinado dinero

bool Contiene(Cuenta C,Dinero X){


    if (C.Saldo >= X ){

        return true;

    }else {

    return false;

    }


}