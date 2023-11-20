#ifndef NODOLISTAMOVIMIENTO_H_INCLUDED
#define NODOLISTAMOVIMIENTO_H_INCLUDED

#include "movimiento.h"


typedef struct _nodoListaMovimiento{
    stMovimiento dato;
    struct _nodoListaMovimiento* sig;
}nodoListaMovimiento;

nodoListaMovimiento* crearNodoMovimiento(stMovimiento dato);
nodoListaMovimiento* inicLista();
nodoListaMovimiento* apilarAlPrincipio(nodoListaMovimiento* lista, nodoListaMovimiento* nuevo);
nodoListaMovimiento* agregarAlFinal(nodoListaMovimiento* lista, nodoListaMovimiento* nuevo);
nodoListaMovimiento* buscarUltimo(nodoListaMovimiento* lista);
void mostrarLista(nodoListaMovimiento* lista);
void suspenderLista(nodoListaMovimiento* lista);

#endif // NODOLISTAMOVIMIENTO_H_INCLUDED
