#ifndef NODOLISTAMOVIMIENTO_H_INCLUDED
#define NODOLISTAMOVIMIENTO_H_INCLUDED

typedef struct _nodoListaMovimiento{
    stMovimiento dato;
    struct _nodoListaMovimiento* sig;
}nodoListaMovimiento;

#endif // NODOLISTAMOVIMIENTO_H_INCLUDED
