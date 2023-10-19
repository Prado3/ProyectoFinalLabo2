#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include "cuenta.h"
#include "movimiento.h"

void mostrarArchivos(int op);

int main()
{
    menuGeneral();
    return 0;
}

void mostrarArchivos(int op){
    stCliente cliente;
    stCuenta cuenta;
    stMovimiento movimiento;

    if(op==1){
        FILE* archi = fopen(ARCHI_CLIENTE,"rb");
        if(archi){
            while(fread(&cliente,sizeof(stCliente),1,archi)>0){
                mostrarCliente(cliente);
            }
            fclose(archi);
        }
    }else{
        if(op==2){
            FILE* archiCuenta = fopen(ARCHI_CUENTA,"rb");
            if(archiCuenta){
                while(fread(&cuenta,sizeof(stCuenta),1,archiCuenta)>0){
                    mostrarCuenta(cuenta);
                }
                fclose(archiCuenta);
            }
        }else{
            FILE* archiMov = fopen(ARCHI_MOVIMIENTOS,"rb");
            if(ARCHI_MOVIMIENTOS){
                while(fread(&movimiento,sizeof(stMovimiento),1,archiMov)>0){
                    mostrarMovimiento(movimiento);
                }
                fclose(archiMov);
            }
        }
    }
}




