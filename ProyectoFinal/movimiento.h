#ifndef MOVIMIENTO_H_INCLUDED
#define MOVIMIENTO_H_INCLUDED
#include "cuenta.h"

typedef struct{
    int id;
    int idCuenta;
    int anio;
    int mes;
    int dia;
    char detalle[100];
    float importe;
    int eliminado;
}stMovimiento;

stMovimiento cargarMovimientoRandom(stCuenta cuenta);
stMovimiento cargarUnMovimiento(int id, int idCuenta, char detalle[100],float importe);
void mostrarMovimiento(stMovimiento movimiento);

#endif // MOVIMIENTO_H_INCLUDED
