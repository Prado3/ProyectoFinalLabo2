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
void mostrarUnCliente(nodoArbolCliente* arbol);
void muestraCuentaCliente (nodoArbolCliente * arbol, char DniCliente[]);

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
        for(int i=0;i<3;i++){
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
    for(int i=0;i<3;i++){
        mostrarCuenta(arbol->arregloCuenta[1].dato);
        mostrarLista(arbol->arregloCuenta[1].nodoLista);
    }
}

void muestraCuentaCliente (nodoArbolCliente * arbol, char DniCliente[]){
int cuenta=0;
nodoArbolCliente*aux=buscarDniClienteArbol(arbol,DniCliente);
if (aux==NULL){
    printf("\n El DNI ingresado no se encuentra en la base de datos");
}
else{
    printf("\n Ingrese que cuenta desea visualizar, 1 Caja de ahorro, 2 Cuenta Corriente, 3 Cuenta en dolares: ");
    scanf("%d",cuenta);
    if (cuenta==1){
        mostrarCuenta(aux->arregloCuenta[0].dato);
        mostrarLista(aux->arregloCuenta[0].nodoLista);


    }
    else if (cuenta==2){
        mostrarCuenta(aux->arregloCuenta[1].dato);
        mostrarLista(aux->arregloCuenta[1].nodoLista);

    }
    else if (cuenta==3){
        mostrarCuenta(aux->arregloCuenta[2].dato);
        mostrarLista(aux->arregloCuenta[2].nodoLista);

    }

}


}



