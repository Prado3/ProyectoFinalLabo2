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
void mostrarCuenta(stCuenta cuenta);
stCuenta cargarCuenta(int tipocuenta, int IDCliente, int ultimoID, int ultimoNroCuenta);
int costocuenta (int tipocuenta);
int nroCuenta();
int MayorNroCuenta(char Archivo[]);

#endif // CUENTA_H_INCLUDED
