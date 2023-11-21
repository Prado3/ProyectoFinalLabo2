#include "cliente.h"
#include "cuenta.h"
#include "movimiento.h"
#include "nodoArbolCliente.h"
#include <stdio.h>
#include <stdlib.h>
#define DIM 50
#define ESC 27

void mostrarArchivos(int op);
int pasarArchi2Arreglo(stCliente clienteA[],char nombreArchi[],int dim);
int posicionMenor (stCliente cliente[], int pos, int validos);
void ordenacionSeleccion (stCliente cliente[], int validos);
void MuestraArreglo (stCliente clienteA[], int validos);
void cargarLista2adl(char nombreArchi[],nodoArbolCliente* arbol);
void mostrarEstructuraCompleta(nodoArbolCliente* arbol);
void mostrarUnCliente(nodoArbolCliente* arbol);
void muestraCuentaCliente (nodoArbolCliente * arbol, char DniCliente[]);
void MuestraArregloOrdenado (stMovimiento movimiento[], int validos);
int lista2ArregloOrdenado (stMovimiento movimiento [], nodoListaMovimiento * lista, int validos, int dimension);
void ordenacionSeleccionFecha (stMovimiento movimiento[], int validos);
int posicionMenorFecha (stMovimiento movimiento[], int pos, int validos);
void muestraCuentaCliente (nodoArbolCliente * arbol, char DniCliente[]);
void modificarCliente(nodoArbolCliente* arbol, char dni[]);

int main()
{
    menuGeneral();
    return 0;
}

void mostrarArchivos(int op){
    stCliente cliente;
    stCuenta cuenta;
    stMovimiento movimiento;

    if(op==1){
        FILE* archi = fopen(ARCHI_CLIENTE,"rb");
        if(archi){
            while(fread(&cliente,sizeof(stCliente),1,archi)>0){
                mostrarCliente(cliente);
            }
            fclose(archi);
        }
    }else{
        if(op==2){
            FILE* archiCuenta = fopen(ARCHI_CUENTA,"rb");
            if(archiCuenta){
                while(fread(&cuenta,sizeof(stCuenta),1,archiCuenta)>0){
                    mostrarCuenta(cuenta);
                }
                fclose(archiCuenta);
            }
        }else{
            FILE* archiMov = fopen(ARCHI_MOVIMIENTOS,"rb");
            if(ARCHI_MOVIMIENTOS){
                while(fread(&movimiento,sizeof(stMovimiento),1,archiMov)>0){
                    mostrarMovimiento(movimiento);
                }
                fclose(archiMov);
            }
        }
    }
}

int pasarArchi2Arreglo(stCliente clienteA[],char nombreArchi[],int dim){
    stCliente cliente;
    int v=0;
    FILE* archi = fopen(nombreArchi,"rb");
    if(archi){
        while(v<dim && fread(&cliente,sizeof(stCliente),1,archi)>0){
            clienteA[v]= cliente;
            v++;
        }
        fclose(archi);
    }
    return v;
}

int posicionMenor (stCliente cliente[], int pos, int validos)
{
    stCliente menor = cliente[pos];
    int posmenor = pos;
    int i = pos +1;
    while (i<validos)
    {
        if (atoi (menor.dni) > atoi (cliente[i].dni))
        {
            menor = cliente[i];
            posmenor = i;
        }
        i++;
    }
    return posmenor;
}

void ordenacionSeleccion (stCliente cliente[], int validos)
{
    int posmenor;
    stCliente aux;
    int i = 0;
    while (i<validos-1)
    {
        posmenor = posicionMenor(cliente,i,validos);
        aux = cliente[posmenor];
        cliente[posmenor]=cliente[i];
        cliente[i]= aux;
        i++;
    }
}

void MuestraArreglo (stCliente clienteA[], int validos){
    stCliente cliente;
    for (int i=0; i<validos; i++){
        mostrarCliente(clienteA[i]);
    }
}

void cargarLista2adl(char nombreArchi[],nodoArbolCliente* arbol){
    stMovimiento mov;
    int total=0;
    FILE* archi = fopen(nombreArchi,"rb");
    if(archi){
        while(fread(&mov,sizeof(stMovimiento),1,archi)>0){
            arbol = cargarLista(mov,arbol);
            total = 1 + total;
        }
    }
    printf("\n %d",total);
}

void mostrarEstructuraCompleta(nodoArbolCliente* arbol){
    if(arbol){
        mostrarCliente(arbol->dato);
        for(int i=0;i<arbol->v;i++){
            mostrarCuenta(arbol->arregloCuenta[i].dato);
            mostrarLista(arbol->arregloCuenta[i].nodoLista);

        }
        mostrarEstructuraCompleta(arbol->izq);
        mostrarEstructuraCompleta(arbol->der);
    }
}

void suspenderCliente(char dni[], nodoArbolCliente* arbol){
    nodoArbolCliente* aux = NULL;
    aux=buscarDniClienteArbol(arbol,dni);
    if(aux){
        aux->dato.eliminado=-1;
        for(int i =0;i<3;i++){
            aux->arregloCuenta[i].dato.eliminado=-1;
            suspenderLista(aux->arregloCuenta[i].nodoLista);
        }
        mostrarUnCliente(aux);
    }else{
        printf("\n No se encuentra el dni ingresado");
    }
}

void mostrarUnCliente(nodoArbolCliente* arbol){
    mostrarCliente(arbol->dato);
    for(int i=0;i<arbol->v;i++){
        mostrarCuenta(arbol->arregloCuenta[i].dato);
        mostrarLista(arbol->arregloCuenta[i].nodoLista);
    }
}

void muestraCuentaCliente (nodoArbolCliente * arbol, char DniCliente[]){
int cuenta=0;
stMovimiento movimiento [DIM];
int validos=0;
int dimension=DIM;
nodoArbolCliente*aux=buscarDniClienteArbol(arbol,DniCliente);
mostrarCliente(aux->dato);
if (aux==NULL){
    printf("\n El DNI ingresado no se encuentra en la base de datos");
}
else{
    printf("\n Ingrese que cuenta desea visualizar, 1 Caja de ahorro, 2 Cuenta Corriente, 3 Cuenta en dolares: ");
    scanf("%d",&cuenta);
    if (cuenta==1){
    mostrarCuenta(aux->arregloCuenta[0].dato);
    validos=lista2ArregloOrdenado (movimiento, aux->arregloCuenta[0].nodoLista,validos, dimension);
    ordenacionSeleccionFecha (movimiento,validos);
    MuestraArregloOrdenado (movimiento, validos);



    }
    else if (cuenta==2){
    mostrarCuenta(aux->arregloCuenta[1].dato);
    validos=lista2ArregloOrdenado (movimiento, aux->arregloCuenta[1].nodoLista,validos, dimension);
    ordenacionSeleccionFecha (movimiento,validos);
    MuestraArregloOrdenado (movimiento, validos);

    }
    else if (cuenta==3){
    mostrarCuenta(aux->arregloCuenta[2].dato);
    validos=lista2ArregloOrdenado (movimiento, aux->arregloCuenta[2].nodoLista,validos, dimension);
    ordenacionSeleccionFecha (movimiento,validos);
    MuestraArregloOrdenado (movimiento, validos);

    }

}


}
int posicionMenorFecha (stMovimiento movimiento[], int pos, int validos)
{
    stMovimiento menor = movimiento[pos];
    int posmenor = pos;
    int i = pos +1;
    while (i<validos)
    {

        if (menor.mes > movimiento[i].mes || (menor.mes == movimiento[i].mes && menor.dia>movimiento[i].dia)){
            menor = movimiento[i];
            posmenor = i;
        }
        i++;
    }
    return posmenor;
}

void ordenacionSeleccionFecha (stMovimiento movimiento[], int validos)
{
    int posmenor=0;
    stMovimiento aux;
    int i = 0;
    while (i<validos)
    {
        posmenor = posicionMenorFecha(movimiento,i,validos);
        aux = movimiento[posmenor];
        movimiento[posmenor]=movimiento[i];
        movimiento[i]= aux;
        i++;
    }
}

int lista2ArregloOrdenado (stMovimiento movimiento [], nodoListaMovimiento * lista, int validos, int dimension){
    while (lista && validos < dimension){
        movimiento [validos]= lista -> dato;
        validos++;
        lista= lista -> sig;
    }

  return validos;

}

void MuestraArregloOrdenado (stMovimiento movimiento[], int validos){
    for (int i=0; i<validos; i++){
        mostrarMovimiento(movimiento[i]);
    }
}

void modificarCliente(nodoArbolCliente* arbol, char dni[]){
    nodoArbolCliente* aux = buscarDniClienteArbol(arbol,dni);
    mostrarCliente(aux->dato);
    int op=0;
    int opSalir=0;
    char nombre[30];
    char apellido[30];
    char email[30];
    char domicilio[45];
    char telefono[12];
    do{
        printf("\n 1 = Nombre");
        printf("\n 2 = Apellido");
        printf("\n 3 = Email");
        printf("\n 4 = Domicilio");
        printf("\n 5 = Telefono");
        printf("\n Ingrese la opcion a modificar: ");
        scanf("%d",&op);
        switch(op){
        case 1:
            fflush(stdin);
            printf("\n Ingrese el nombre correcto: ");
            gets(nombre);
            strcpy(aux->dato.nombre,nombre);
            break;
        case 2:
            fflush(stdin);
            printf("\n Ingrese el apellido correcto: ");
            gets(apellido);
            strcpy(aux->dato.apellido,apellido);
            break;
        case 3:
            fflush(stdin);
            printf("\n Ingrese el email correcto: ");
            gets(email);
            strcpy(aux->dato.email,email);
            break;
        case 4:
            fflush(stdin);
            printf("\n Ingrese el domicilio correcto: ");
            gets(domicilio);
            strcpy(aux->dato.domicilio,domicilio);
            break;
        case 5:
            fflush(stdin);
            printf("\n Ingrese el telefono correcto: ");
            gets(telefono);
            strcpy(aux->dato.telefono,telefono);
            break;
        }
        printf("\n Ingrese ESC para dejar de modificar, sino ingrese ENTER..");
        opSalir=getch();
    }while(opSalir!=ESC);
    printf("\n El cliente fue modificado con exito..");
    mostrarCliente(aux->dato);
}





