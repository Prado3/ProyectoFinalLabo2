#include "nodoListaMovimiento.h"


nodoListaMovimiento* crearNodoMovimiento(stMovimiento dato){
    nodoListaMovimiento* nuevoNodo = (nodoListaMovimiento*) malloc(sizeof(nodoListaMovimiento));
    nuevoNodo->dato = dato;
    nuevoNodo->sig = NULL;

    return nuevoNodo;
}

nodoListaMovimiento* inicLista(){
    return NULL;
}

nodoListaMovimiento* apilarAlPrincipio(nodoListaMovimiento* lista, nodoListaMovimiento* nuevo){
    nuevo->sig=lista;
    return nuevo;
}

nodoListaMovimiento* agregarAlFinal(nodoListaMovimiento* lista, nodoListaMovimiento* nuevo){
    if(!lista){
       lista = nuevo;
    }else{
        nodoListaMovimiento* ultimo = buscarUltimo(lista);
        ultimo->sig = nuevo;
    }
    return lista;
}

nodoListaMovimiento* buscarUltimo(nodoListaMovimiento* lista){
    nodoListaMovimiento* aux = lista;
    while(aux->sig){
        aux = aux->sig;
    }
    return aux;
}
