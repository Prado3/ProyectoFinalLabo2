#ifndef CELDACUENTAS_H_INCLUDED
#define CELDACUENTAS_H_INCLUDED

#include "nodoListaMovimiento.h"

typedef struct{
    stCuenta dato;
    nodoListaMovimiento* nodoLista;
}stCeldaCuentas;


int agregarCelda(stCeldaCuentas adl[], int v, stCuenta cuenta);
int buscarTipoCuenta(stCeldaCuentas adl[], int tipocuenta, int v);
#endif // CELDACUENTAS_H_INCLUDED
