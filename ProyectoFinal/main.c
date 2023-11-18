#include "cliente.h"
#include "cuenta.h"
#include "movimiento.h"
#include "nodoArbolCliente.h"
#include <stdio.h>
#include <stdlib.h>

void mostrarArchivos(int op);
int pasarArchi2Arreglo(stCliente clienteA[],char nombreArchi[],int dim);
int posicionMenor (stCliente cliente[], int pos, int validos);
void ordenacionSeleccion (stCliente cliente[], int validos);
void MuestraArreglo (stCliente clienteA[], int validos);
void cargarLista2adl(char nombreArchi[],nodoArbolCliente* arbol);
void mostrarEstructuraCompleta(nodoArbolCliente* arbol);

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
    FILE* archi = fopen(nombreArchi,"rb");
    if(archi){
        while(fread(&mov,sizeof(stMovimiento),1,archi)>0){
            arbol = cargarLista(mov,arbol);
        }
    }
}

void mostrarEstructuraCompleta(nodoArbolCliente* arbol){
    if(arbol){
        mostrarCliente(arbol->dato);
        for(int i=0;i<3;i++){
            mostrarCuenta(arbol->arregloCuenta[i].dato);
            for(int j=0;j<10;j++){
                mostrarMovimiento(arbol->arregloCuenta[i].nodoLista->dato);
            }
        }
        mostrarEstructuraCompleta(arbol->izq);
        mostrarEstructuraCompleta(arbol->der);
    }
}



