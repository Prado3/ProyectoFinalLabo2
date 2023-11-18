#include "cuenta.h"

stCuenta cargarCuentaRandom(stCliente cliente, int i,int cuentaId,int nroCuenta){
    stCuenta cuenta;
    int costMen=0;
    if(i==1){
        costMen=500;
    }else{
        if(i==2){
            costMen=1000;
        }else{
            costMen=1500;
        }
    }
    cuenta.id=idautoincremental(cuentaId);
    cuenta.idCliente=cliente.nroCliente;
    cuenta.nroCuenta=nroCuentaA(nroCuenta);
    cuenta.eliminado=0;
    cuenta.costoMensual=costMen;
    cuenta.tipoCuenta=i;

    return cuenta;
}

int nroCuentaA(int nroCuenta){
    int id=nroCuentaB();
    if(nroCuenta > 0){
        id = nroCuenta;
    }
return id+2;
}

int nroCuentaB(){
    static int i = 200000;
    return i;
}

stCuenta cargarCuenta(int id, int nroCliente, int opcion){
    stCuenta cuenta;

    cuenta.id=id;

    cuenta.idCliente=nroCliente;

//    cuenta.nroCuenta=nroCuentaA();

    cuenta.tipoCuenta=opcion;

    cuenta.costoMensual=1000;

    cuenta.eliminado=0;

    return cuenta;
}

void mostrarCuenta(stCuenta cuenta){
    printf("\n ====================");
    printf("\n id:............ %d",cuenta.id);
    printf("\n idCliente:...... %d",cuenta.idCliente);
    printf("\n NroCuenta:..... %d",cuenta.nroCuenta);
    printf("\n Tipo de Cuenta: %d",cuenta.tipoCuenta);
    printf("\n Costo mensual:. %.2f",cuenta.costoMensual);
    printf("\n Eliminado:..... %d",cuenta.eliminado);
    printf("\n ====================");
}
