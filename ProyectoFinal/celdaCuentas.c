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

int buscarTipoCuenta(stCeldaCuentas adl[], int tipocuenta, int v){
    int pos = -1;
    int i = 0;
    while(i < v && pos == -1){
        if(adl[i].dato.tipoCuenta == tipocuenta){
            pos = i;
        }
        i++;
    }
    return pos;
}
