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
    nuevo->padre = NULL;
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
        }else{
            rta = buscarDniClienteArbol(arbol->izq,DniCliente);
            if(!rta){
                rta = buscarDniClienteArbol(arbol->der,DniCliente);
            }
        }
    }
    return rta;
}

nodoArbolCliente* BuscaMayorID (nodoArbolCliente* arbol){
    nodoArbolCliente* mayor = NULL;
    if(arbol){
        mayor = BuscaMayorID(arbol->izq);
        mayor = BuscaMayorID(arbol->der);
        if(mayor == NULL){
            mayor = arbol;
        }
        if(mayor->dato.id > arbol->dato.id){
            mayor = arbol;

        }
    }
    return mayor;
}

nodoArbolCliente* eliminarNodo(nodoArbolCliente* arbol, char dni[]){
    // Función principal para eliminar un nodo del árbol
    if (arbol == NULL) {
        return arbol;
    }

    if (atoi(dni) < atoi(arbol->dato.dni)) {
        arbol->izq = eliminarNodo(arbol->izq, dni);
    } else if (atoi(dni) > atoi(arbol->dato.dni)) {
        arbol->der = eliminarNodo(arbol->der, dni);
    } else {
        // Nodo con el valor a eliminar encontrado

        // Caso 1: Nodo con un solo hijo o sin hijos
        if (arbol->izq == NULL) {
            nodoArbolCliente* aux = arbol->der;
            free(arbol);
            return aux;
        } else if (arbol->der == NULL) {
            nodoArbolCliente* aux = arbol->izq;
            free(arbol);
            return aux;
        }

        // Caso 2: Nodo con dos hijos
        nodoArbolCliente* min = arbol->der;
        while (min->izq != NULL) {
            min = min->izq;
        }

        strcpy(arbol->dato.dni,min->dato.dni);
        arbol->der = eliminarNodo(arbol->der, min->dato.dni);
    }

    return arbol;
}

stCliente cargarCliente(nodoArbolCliente* arbol, char DNI[10], int ultimoID, int ultimoNroCliente){
    stCliente cliente;
    strcpy(cliente.dni, DNI);
    cliente.id = ultimoID + id();
    cliente.nroCliente = ultimoNroCliente + nroCliente();

    printf("\n Ingrese su nombre: ");
    fflush(stdin);
    gets(cliente.nombre);

    printf("\n Ingrese su apellido: ");
    fflush(stdin);
    gets(cliente.apellido);

    printf("\n Ingrese su email: ");
    fflush(stdin);
    gets(cliente.email);

    printf("\n Ingrese su domicilio: ");
    fflush(stdin);
    gets(cliente.domicilio);

    printf("\n Ingrese su telefono: ");
    fflush(stdin);
    gets(cliente.telefono);

    cliente.eliminado=0;

    return cliente;
}

int MayorID(char Archivo[]){
    stMovimiento generico;
    FILE* archi = fopen(Archivo, "rb");
    if(archi){
        fseek(archi, -1*sizeof(stMovimiento), SEEK_END);
        fread(&generico, sizeof(stMovimiento), 1, archi);
    }
    return generico.id;
}

int MayorNroCliente(char Archivo[]){
    stCliente generico;
    FILE* archi = fopen(Archivo, "rb");
    if(archi){
        fseek(archi, -1*sizeof(stCliente), SEEK_END);
        fread(&generico, sizeof(stCliente), 1, archi);
    }
    return generico.nroCliente;
}


