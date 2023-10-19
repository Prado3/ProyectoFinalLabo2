#include "movimiento.h"

stMovimiento cargarMovimientoRandom(stCuenta cuenta){
    stMovimiento movimiento;
    srand(time(NULL));
    char detalle[][20]={"cobro haberes","regalo","venta celular","venta anillo","venta ropa","venta auto","venta app"};

    movimiento.importe=rand()%1000+1;
    movimiento.anio=2023;
    movimiento.dia=rand()%30+1;
    movimiento.mes=rand()%12+1;
    strcpy(movimiento.detalle,detalle[rand()%7]);
    movimiento.eliminado=0;
    movimiento.id=idautoincremental();
    movimiento.idCuenta=cuenta.nroCuenta;
}

stMovimiento cargarUnMovimiento(int id, int idCuenta, char detalle[100],float importe){
    stMovimiento movimiento;
    time_t t;
    time(&t);
    struct tm *fecha=localtime(&t);


    movimiento.id=id;

    movimiento.idCuenta=idCuenta;

    movimiento.anio=fecha->tm_year+1900;

    movimiento.mes=fecha->tm_mon+1;

    movimiento.dia=fecha->tm_mday;

    strcpy(movimiento.detalle,detalle);

    movimiento.importe=importe;

    movimiento.eliminado=0;

    return movimiento;
}


void mostrarMovimiento(stMovimiento movimiento){
    printf("\n ==============================");
    printf("\n id:...................%d",movimiento.id);
    printf("\n idCuenta:.............%d",movimiento.idCuenta);
    printf("\n Anio:.................%d",movimiento.anio);
    printf("\n Mes:..................%d",movimiento.mes);
    printf("\n Dia:..................%d",movimiento.dia);
    printf("\n Detalle:..............%s",movimiento.detalle);
    printf("\n Importe:..............%.2f",movimiento.importe);
    printf("\n Eliminado:............%d",movimiento.eliminado);
    printf("\n ==============================");
}
