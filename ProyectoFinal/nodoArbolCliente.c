#include "nodoArbolCliente.h"
#include "math.h"
#include "cliente.h"
#include "celdaCuentas.h"

nodoArbolCliente* Arreglo2Arbol(stCliente Cliente[], int inicio, int fin, nodoArbolCliente* arbol){
    if(inicio <= fin){
        int posMedio = floor((inicio + fin) / 2);
        arbol = insertarNodo(arbol, crearNodoArbol(Cliente[posMedio]));
        arbol = Arreglo2Arbol(Cliente, inicio, posMedio - 1, arbol);
        arbol = Arreglo2Arbol(Cliente, posMedio + 1, fin, arbol);
    }
    return arbol;
}

nodoArbolCliente* inicArbol(){
    return NULL;
}

nodoArbolCliente* crearNodoArbol(stCliente dato){
    nodoArbolCliente* nuevo = (nodoArbolCliente*) malloc(sizeof(nodoArbolCliente));
    nuevo->dato = dato;
    nuevo->izq = NULL;
    nuevo->der = NULL;
    return nuevo;
}

nodoArbolCliente* insertarNodo(nodoArbolCliente* arbol, nodoArbolCliente* nuevo){
    if(!arbol){
        arbol = nuevo;
    }else{
        if(atoi(nuevo->dato.dni) < atoi(arbol->dato.dni))
        {
            arbol->izq = insertarNodo(arbol->izq,nuevo);
        }
        else
        {
            arbol->der = insertarNodo(arbol->der,nuevo);
        }
    }
    return arbol;
}

void preorder(nodoArbolCliente* arbol){
    if(arbol){
       mostrarCliente(arbol->dato);
       preorder(arbol->izq);
       preorder(arbol->der);

    }
}

void inorder(nodoArbolCliente* arbol){
    if(arbol){
       inorder(arbol->izq);
       mostrarCliente(arbol->dato);
       mostrarCuenta(arbol->arregloCuenta->dato);
       inorder(arbol->der);
    }
}

void postorder(nodoArbolCliente* arbol){
    if(arbol){
        postorder(arbol->izq);
        postorder(arbol->der);
        mostrarCliente(arbol->dato);
    }
}

nodoArbolCliente* buscarIdClienteArbol(nodoArbolCliente* arbol,int idCliente){
    nodoArbolCliente* rta = NULL;
    if(arbol){
        if(arbol->dato.nroCliente==idCliente){
            rta = arbol;
        }else{
            rta = buscarIdClienteArbol(arbol->izq,idCliente);
            if(!rta){
                rta = buscarIdClienteArbol(arbol->der,idCliente);
            }
        }
    }
    return rta;
}

nodoArbolCliente* cargarAdlCuentas(nodoArbolCliente* arbol, char nombreArchivo[]){
    stCliente cliente;
    stCuenta cuenta;
    int suma = 0;
    nodoArbolCliente* aux = NULL;
    FILE* archi = fopen(nombreArchivo,"rb");
    if(archi){
        while(fread(&cuenta,sizeof(stCuenta),1,archi)>0){
            aux = buscarIdClienteArbol(arbol,cuenta.idCliente);
            //printf("\n %d",aux->v);
            //suma = 1 + suma;
            //printf("\n %d",suma);
            //if(suma==28){
            //   mostrarCuenta(cuenta);
            //}
            aux->v = agregarCelda(aux->arregloCuenta,aux->v,cuenta);
        }
    }
    return arbol;
}

void buscarCuenta(nodoArbolCliente* arbol,stMovimiento mov,int flag){
    if(flag==0 && arbol){
        for(int i=0;i<3;i++){
            if(arbol->arregloCuenta[i].dato.nroCuenta==mov.nroCuenta){
                flag=1;
                arbol->arregloCuenta[i].nodoLista = agregarAlFinal(arbol->arregloCuenta[i].nodoLista,crearNodoMovimiento(mov));
            }
        }
        buscarCuenta(arbol->izq,mov,flag);
        buscarCuenta(arbol->der,mov,flag);
    }
}

nodoArbolCliente* cargarLista(stMovimiento mov, nodoArbolCliente* arbol){
    int flag = 0;
    nodoArbolCliente* aux=arbol;
    buscarCuenta(aux,mov,flag);

    return arbol;
}

nodoArbolCliente* buscarDniClienteArbol(nodoArbolCliente* arbol,char DniCliente[]){
    nodoArbolCliente* rta = NULL;
    if(arbol){
        if(atoi(arbol->dato.dni)==atoi(DniCliente)){
            rta = arbol;
            printf("\n hola");
        }else{
            rta = buscarDniClienteArbol(arbol->izq,DniCliente);
            if(!rta){
                rta = buscarDniClienteArbol(arbol->der,DniCliente);
            }
        }
    }
    return rta;
}

