#include "cliente.h"
#include "nodoArbolCliente.h"
#define DIM 50
#include <stdio.h>
#include <stdlib.h>

void menuGeneral(){
    char opSalir;
    int opcion=0;
    stCliente clienteArreglo[DIM];
    int v=0;
    nodoArbolCliente* arbol=inicArbol();

    do{
        system("cls");
        opcion=mostrarOpciones();
        switch(opcion){
        case 1:
            //cargarRandom();
            v=pasarArchi2Arreglo(clienteArreglo,ARCHI_CLIENTE,DIM);
            ordenacionSeleccion(clienteArreglo,v);
            arbol = Arreglo2Arbol(clienteArreglo,0,49,arbol);
            arbol = cargarAdlCuentas(arbol,ARCHI_CUENTA);
            //cargarLista2adl(ARCHI_MOVIMIENTOS,arbol);
            printf("\n Ingrese ESC para volver al menu, o cualquier tecla para consultar otro archivo...");
            opSalir=getch();
            break;
        case 2:
            system("cls");
            printf("\n Ingres 1 para ver clientes");
            printf("\n Ingres 2 para ver cuentas");
            printf("\n Ingres 3 para ver movimientos");
            scanf("%d",&opcion);
            mostrarArchivos(opcion);
            printf("\n Ingrese ESC para volver al menu, o cualquier tecla para consultar otro archivo...");
            opSalir=getch();
            break;
        }
        printf("\n Ingrese ESC para salir del programa");
        printf("\n Ingrese ENTER para volver al menu");
        opSalir=getch();
    }while(opSalir!=ESC);
}

int mostrarOpciones(){
    int i=0;
    printf("\n ==========================================");
    printf("\n 1 = CARGAR ARCHIVOS(WARNING!!)");
    printf("\n 2 = Mostrar Archivos");
    printf("\n ==========================================");
    printf("\n Ingrese la opcion a elegir: ");
    scanf("%d",&i);
    return i;
}

