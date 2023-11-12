#include "celdaCuentas.h"
#include "cliente.h"

int agregarCelda(stCeldaCuentas adl[], int v, stCuenta cuenta){
    if(v!=2 && v!=1){
        v=0;
    }
    adl[v].dato = cuenta;
    adl[v].nodoLista = inicLista();
    return v+1;
}
