#include "cliente.h"

void menuGeneral(){
    char opSalir;
    int opcion=0;


    do{
        system("cls");
        opcion=mostrarOpciones();
        switch(opcion){
        case 1:
            cargarRandom();
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
