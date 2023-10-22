#ifndef CUENTA_H_INCLUDED
#define CUENTA_H_INCLUDED
#include "cliente.h"

typedef struct {
    int id;
    int idCliente;
    int nroCuenta;
    int tipoCuenta;
    float costoMensual;
    int eliminado;
}stCuenta;

stCuenta cargarCuentaRandom(stCliente cliente, int i,int cuentaId,int nroCuenta);
int nroCuentaA();
int nroCuentaB();
stCuenta cargarCuenta(int id, int nroCliente, int opcion);
void mostrarCuenta(stCuenta cuenta);

#endif // CUENTA_H_INCLUDED
