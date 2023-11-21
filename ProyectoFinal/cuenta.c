#include "cuenta.h"

stCuenta cargarCuentaRandom(stCliente cliente, int i,int cuentaId,int nroCuenta){
    stCuenta cuenta;
    int costMen=costocuenta(i);
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

stCuenta cargarCuenta(int tipocuenta, int IDCliente, int ultimoID, int ultimoNroCuenta){
    stCuenta cuenta;
    cuenta.id = ultimoID + id();
    cuenta.nroCuenta = ultimoNroCuenta + nroCuenta();
    cuenta.idCliente = IDCliente;
    cuenta.tipoCuenta = tipocuenta;
    cuenta.costoMensual = costocuenta(tipocuenta);
    cuenta.eliminado = 0;
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

int costocuenta (int tipocuenta){
    int precio;
    if(tipocuenta == 1){
        precio = 500;
    }
    else{
        if(tipocuenta == 2){
            precio = 1000;
        }
        else{
            precio = 1500;
        }
    }
    return precio;
}

int nroCuenta(){
    static int i = 1;
    return i++;
}

int MayorNroCuenta(char Archivo[]){
    stCuenta generico;
    FILE* archi = fopen(Archivo, "rb");
    if(archi){
        fseek(archi, -1*sizeof(stCuenta), SEEK_END);
        fread(&generico, sizeof(stCuenta), 1, archi);
    }
    return generico.id;
}

int nroCliente(){
    static int i = 1;
    return i++;
}
