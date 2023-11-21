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
    nodoArbolCliente* aux=inicArbol();
    char dni[10];
    int flagCarga = 0;
    int flagCargaCuenta = 0;
    int idMayor;
    int nroClienteMayor;
    int nroCuentaMayor;
    int tipocuenta;
    int posMovimiento;

    do{
        system("cls");
        opcion=mostrarOpciones();
        switch(opcion){
        case 0:
            cargarRandom();
            printf("\n Carga realizada con exito...");
            printf("\n Ingrese ESC para volver al menu...");
            opSalir=getch();
            break;
        case 1:
            v=pasarArchi2Arreglo(clienteArreglo,ARCHI_CLIENTE,DIM);
            ordenacionSeleccion(clienteArreglo,v);
            arbol = Arreglo2Arbol(clienteArreglo,0,49,arbol);
            arbol = cargarAdlCuentas(arbol,ARCHI_CUENTA);
            nroCuentaMayor = MayorNroCuenta(ARCHI_CUENTA);
            nroClienteMayor = MayorNroCliente(ARCHI_CLIENTE);
            idMayor = MayorID(ARCHI_MOVIMIENTOS);
            cargarLista2adl(ARCHI_MOVIMIENTOS,arbol);
            printf("\n Ingrese ESC para volver al menu..");
            opSalir=getch();
            break;
        case 2:
            system("cls");
            printf("\n Ingres 1 para ver clientes");
            printf("\n Ingres 2 para ver cuentas");
            printf("\n Ingres 3 para ver movimientos \n");
            scanf("%d",&opcion);
            mostrarArchivos(opcion);
            printf("\n Ingrese ESC para volver al menu, o cualquier tecla para consultar otro archivo...");
            opSalir=getch();
            break;
        case 3:
            fflush(stdin);
            printf("\n Ingrese el dni a suspender: ");
            gets(dni);
            suspenderCliente(dni,arbol);
            printf("\n Ingrese ESC para volver al menu...");
            opSalir=getch();
            break;
        case 4:
            fflush(stdin);
            printf("\n Ingrese el dni a ELIMINAR: ");
            gets(dni);
            arbol = eliminarNodo(arbol,dni);
            aux = buscarDniClienteArbol(arbol,dni);
            if(aux){
                mostrarCliente(aux->dato);
            }else{
                printf("\n El cliente se ELIMINO con exito!");
            }
            printf("\n Ingrese ESC para volver al menu...");
            opSalir=getch();
            break;
        case 5:
            fflush(stdin);
            printf("\n Ingrese el dni a mostrar: ");
            gets(dni);
            muestraCuentaCliente(arbol,dni);
            printf("\n Ingrese ESC para volver al menu...");
            opSalir=getch();
            break;
        case 6:
            mostrarEstructuraCompleta(arbol);
            printf("\n Ingrese ESC para volver al menu...");
            opSalir=getch();
            break;
        case 7:
            system("cls");
            fflush(stdin);
            printf("\nIngrese el DNI del cliente a cargar: ");
            gets(dni);
            do{
                if(buscarDniClienteArbol(arbol, dni) == NULL){
                    arbol = insertarNodo(arbol, crearNodoArbol(cargarCliente(arbol, dni, idMayor, nroClienteMayor)));
                    flagCarga = 1;
                }
                else{
                    printf("\n El cliente ya se encuentra en la base de datos. Presione cualquier tecla para reingresar el DNI, o ESC para salir.");
                    opSalir = getch();
                }
            }while(flagCarga == 0 && opSalir != ESC);
            printf("\n Ingrese ESC para volver al menu...");
            opSalir=getch();
            break;
        case 8:
            do{
            flagCarga = 0;
            fflush(stdin);
            printf("\nIngrese el DNI del cliente: ");
            gets(dni);
            aux = buscarDniClienteArbol(arbol, dni);
            if(aux != NULL){
                if(aux->dato.eliminado != 0){
                printf("\n El cliente se encuentra suspendido.");
                }
            else{
                printf("\n Cliente Seleccionado: \n");
                mostrarCliente(aux->dato);
                do{
                    printf("\nQue tipo de cuenta desea crear? \nIngrese 1 para Caja de Ahorro en AR$\nIngrese 2 para Cuenta Corriente en AR$\nIngrese 3 para Caja de Ahorro en US$\n");
                    scanf("%d", &tipocuenta);
                    if(buscarTipoCuenta(aux->arregloCuenta, tipocuenta, aux->v) == -1){
                        aux->v = agregarCelda(aux->arregloCuenta, aux->v, cargarCuenta(tipocuenta, aux->dato.nroCliente, idMayor, nroCuentaMayor));
                        flagCarga = 1;
                    }else{
                        printf("\nEl cliente ya tiene una cuenta creada de este tipo. Presione cualquier tecla para reingresar el DNI, o ESC para salir.");
                        opSalir = getch();
                    }
                }while(opSalir != ESC && flagCarga == 0);
            }
            }else{
            printf("\nEl DNI ingresado no se encuentra en la base de datos. Presione cualquier tecla para reingresar el DNI, o ESC para salir.");
            opSalir = getch();
            }
            }while(aux == NULL && opcion != ESC);
            printf("\n Ingrese ESC para volver al menu...");
            opSalir=getch();
            break;
        case 9:
            do{
                fflush(stdin);
                printf("\nIngrese el DNI del cliente: ");
                gets(dni);
                aux = buscarDniClienteArbol(arbol, dni);
                if(aux != NULL){
                    if(aux->dato.eliminado != 0){
                        printf("\nEl cliente se encuentra suspendido. Ingrese ESC para salir o ENTER para ingresar otro dni...");
                        opSalir = getch();
                    }
                    else{
                        printf("\nCliente Seleccionado: \n");
                        mostrarCliente(aux->dato);
                        do{
                            printf("\n¿En que cuenta desea realizar el movimiento? \n1 - Caja de Ahorro en AR$\n2 - Cuenta Corriente en AR$\n3 - Caja de Ahorro en US$");
                            scanf("%d", &tipocuenta);
                            posMovimiento = buscarTipoCuenta(aux->arregloCuenta, tipocuenta, aux->v);
                            if(posMovimiento == -1){
                                printf("\nEl cliente no posee una cuenta de este tipo. Presione cualquier tecla para reingresar el tipo de cuenta, o ESC para salir.");
                                opSalir = getch();
                            }
                            else{
                                aux->arregloCuenta[posMovimiento].nodoLista = agregarAlFinal(aux->arregloCuenta[posMovimiento].nodoLista, crearNodoMovimiento(cargarUnMovimiento(idMayor, aux->arregloCuenta[posMovimiento].dato.nroCuenta)));
                                opSalir = ESC;
                            }
                        }while(posMovimiento == - 1 && opSalir != ESC);
                    }
                }
                else{
                    printf("\nEl DNI ingresado no se encuentra en la base de datos. Presione cualquier tecla para reingresar el DNI, o ESC para salir.");
                    opSalir = getch();
                }
            }while(opSalir != ESC);
            break;
        case 10:
            do{
            fflush(stdin);
            printf("\n Ingrese el dni a mostrar: ");
            gets(dni);
            if(buscarDniClienteArbol(arbol,dni)==NULL){
                printf("\n El dni ingresado no se encuentra en la base de datos..");
            }else{
                modificarCliente(arbol,dni);
            }
            printf("\n Ingrese ESC para volver al menu, o presione cualquier tecla para ingresar otro dni");
            opSalir=getch();
            }while(opSalir!=ESC);
            break;
    }
        system("cls");
        printf("\n Ingrese ESC para salir del programa");
        printf("\n Ingrese ENTER para volver al menu");
        opSalir=getch();
    }while(opSalir!=ESC);
}

int mostrarOpciones(){
    int i=0;
    printf("\n ==========================================");
    printf("\n 0 = CARGAR ARCHIVOS(WARNING!!)");
    printf("\n 1 = Pasar Archivos a estructura");
    printf("\n 2 = Mostrar Archivos");
    printf("\n 3 = Suspender Cliente");
    printf("\n 4 = Eliminar Cliente");
    printf("\n 5 = Mostrar Cliente/cuenta");
    printf("\n 6 = Mostrar Estructura Completa");
    printf("\n 7 = Cargar Cliente");
    printf("\n 8 = Cargar Cuentas a un cliente");
    printf("\n 9 = Cargar Movimientos a una cuenta");
    printf("\n 10 = Modificar dato de cliente");
    printf("\n ==========================================");
    printf("\n Ingrese la opcion a elegir: ");
    scanf("%d",&i);
    return i;
}

