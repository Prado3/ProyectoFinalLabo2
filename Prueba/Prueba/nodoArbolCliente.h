#ifndef NODOARBOLCLIENTE_H_INCLUDED
#define NODOARBOLCLIENTE_H_INCLUDED

typedef struct _nodoArbolCliente{
    stCliente dato;
    celdaCuentas* arregloCuentas;
    struct _nodoArbolCliente* izq;
    struct _nodoArbolCliente* der;
}nodoArbolCliente;


#endif // NODOARBOLCLIENTE_H_INCLUDED
