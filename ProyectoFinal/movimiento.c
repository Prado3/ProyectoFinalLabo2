#include "movimiento.h"
#include "cuenta.h"

stMovimiento cargarMovimientoRandom(stCuenta cuenta,int movId){
    stMovimiento movimiento;
    char detalle[][20]={"cobro haberes","regalo","venta celular","venta anillo","venta ropa","venta auto","venta app"};

    movimiento.importe=rand()%1000+1;
    movimiento.anio=2023;
    movimiento.dia=rand()%30+1;
    movimiento.mes=rand()%12+1;
    strcpy(movimiento.detalle,detalle[rand()%7]);
    movimiento.eliminado=0;
    movimiento.id=idautoincremental(movId);
    movimiento.nroCuenta=cuenta.nroCuenta;

    return movimiento;
}

stMovimiento cargarUnMovimiento(int ultimoId, int nroCuenta){
    stMovimiento movimiento;
    char detalle[][20]={"cobro haberes","regalo","venta celular","venta anillo","venta ropa","venta auto","venta app"};
    int opciondetalle;
    int monto;
    time_t t;
    time(&t);
    struct tm *fecha=localtime(&t);


    movimiento.id= ultimoId + id();

    movimiento.nroCuenta= nroCuenta;

    movimiento.anio=fecha->tm_year+1900;

    movimiento.mes=fecha->tm_mon+1;

    movimiento.dia=fecha->tm_mday;

    printf("\nQué operación desea realizar?: \n1 - Cobro Haberes\n2 - Regalo\n3 - Venta Celular\n4 - Venta Anillo\n5 - Venta Ropa\n6 - Venta Auto\n7 - Venta App");
    scanf("%d", &opciondetalle);
    strcpy(movimiento.detalle, detalle[opciondetalle - 1]);

    printf("\n¿Qué monto desea transferir?: ");
    scanf("%d", &monto);
    movimiento.importe=monto;

    movimiento.eliminado=0;

    return movimiento;
}

void mostrarMovimiento(stMovimiento movimiento){
    printf("\n ==============================");
    printf("\n id:...................%d",movimiento.id);
    printf("\n idCuenta:.............%d",movimiento.nroCuenta);
    printf("\n Anio:.................%d",movimiento.anio);
    printf("\n Mes:..................%d",movimiento.mes);
    printf("\n Dia:..................%d",movimiento.dia);
    printf("\n Detalle:..............%s",movimiento.detalle);
    printf("\n Importe:..............%.2f",movimiento.importe);
    printf("\n Eliminado:............%d",movimiento.eliminado);
    printf("\n ==============================");
}
