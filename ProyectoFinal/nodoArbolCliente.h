#ifndef NODOARBOLCLIENTE_H_INCLUDED
#define NODOARBOLCLIENTE_H_INCLUDED

#include "cliente.h"
#include "celdaCuentas.h"

typedef struct _nodoArbolCliente{
    stCliente dato;
    int v;
    stCeldaCuentas arregloCuenta[3];
    struct _nodoArbolCliente* izq;
    struct _nodoArbolCliente* der;
    struct _nodoArbolCliente* padre;
}nodoArbolCliente;

nodoArbolCliente* cargarLista(stMovimiento mov, nodoArbolCliente* arbol);
void buscarCuenta(nodoArbolCliente* arbol,stMovimiento mov,int flag);
nodoArbolCliente* cargarAdlCuentas(nodoArbolCliente* arbol, char nombreArchivo[]);
nodoArbolCliente* Arreglo2Arbol(stCliente Cliente[], int inicio, int fin, nodoArbolCliente* nodoarbol);
nodoArbolCliente* inicArbol();
nodoArbolCliente* crearNodoArbol(stCliente dato);
nodoArbolCliente* insertarNodo(nodoArbolCliente* arbol, nodoArbolCliente* nuevo);
void preorder(nodoArbolCliente* arbol);
void inorder(nodoArbolCliente* arbol);
void postorder(nodoArbolCliente* arbol);
nodoArbolCliente* buscar(nodoArbolCliente* arbol,int edad);
nodoArbolCliente* buscarIdClienteArbol(nodoArbolCliente* arbol,int idCliente);
nodoArbolCliente* cargarAdlCuentas(nodoArbolCliente* arbol, char nombreArchivo[]);
nodoArbolCliente* cargarLista(stMovimiento mov, nodoArbolCliente* arbol);
void buscarCuenta(nodoArbolCliente* arbol,stMovimiento mov,int flag);
nodoArbolCliente* buscarDniClienteArbol(nodoArbolCliente* arbol,char DniCliente[]);
nodoArbolCliente* hijoNoNullDelNodo(nodoArbolCliente* arbol);
nodoArbolCliente* eliminarNodo(nodoArbolCliente* arbol, char dni[]);
stCliente cargarCliente(nodoArbolCliente* arbol, char DNI[10], int ultimoID, int ultimoNroCliente);
int MayorID(char Archivo[]);
int MayorNroCliente(char Archivo[]);
#endif // NODOARBOLCLIENTE_H_INCLUDED
