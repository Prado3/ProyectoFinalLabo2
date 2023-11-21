#ifndef MOVIMIENTO_H_INCLUDED
#define MOVIMIENTO_H_INCLUDED
#include "cuenta.h"

typedef struct{
    int id;
    int nroCuenta;
    int anio;
    int mes;
    int dia;
    char detalle[100];
    float importe;
    int eliminado;
}stMovimiento;

stMovimiento cargarMovimientoRandom(stCuenta cuenta,int movId);
stMovimiento cargarUnMovimiento(int ultimoId, int nroCuenta);
void mostrarMovimiento(stMovimiento movimiento);

#endif // MOVIMIENTO_H_INCLUDED
