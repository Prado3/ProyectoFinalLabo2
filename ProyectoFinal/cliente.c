#include "cliente.h"

int idautoincremental(){
    stCliente cliente;
    int id=idAuto();
    FILE *archi = fopen(ARCHI_CLIENTE, "rb");
    if(archi){
        fseek(archi, sizeof(stCliente)*(-1),SEEK_END);
        if(fread(&cliente ,sizeof(stCliente),1,archi) > 0){
            id = cliente.id;
        }
        fclose(archi);
    }
return id+1;
}

int idAuto(){
    static int i = 0;
    return i;
}

stCliente cargaClienteRandom(){
    int num=0;
    srand(time(NULL));
    stCliente cliente;

    num=rand()%20;
    getName(cliente.nombre,num);
    num=rand()%20;
    getLastname(cliente.apellido,num);
    num=rand()%20;
    getDni(cliente.dni,num);
    num=rand()%20;
    getEmail(cliente.email,num);
    num=rand()%20;
    getDomicilio(cliente.domicilio,num);
    num=rand()%20;
    getTelefono(cliente.telefono,num);
    cliente.eliminado=0;
    cliente.id=idautoincremental();
    cliente.nroCliente=nroClienteA();

    return cliente;
}

int nroClienteA(){
    stCliente cliente;
    int id=nroClienteB();
    FILE *archi = fopen(ARCHI_CLIENTE, "rb");
    if(archi){
        fseek(archi, sizeof(stCliente)*(-1),SEEK_END);
        if(fread(&cliente ,sizeof(stCliente),1,archi) > 0){
            id = cliente.nroCliente;
        }
        fclose(archi);
    }
return id+10;
}

int nroClienteB(){
    static int i = 1000000;
    return i;
}

void mostrarCliente(stCliente cliente){
    printf("\n Nombre y Apellido:..: %s %s", cliente.nombre,cliente.apellido);
    printf("\n Dni:................: %s", cliente.dni);
    printf("\n Email:..............: %s", cliente.email);
    printf("\n Domicilio:..........: %s", cliente.domicilio);
    printf("\n Telecono:...........: %s", cliente.telefono);
    printf("\n ID:.................: %d", cliente.id);
    printf("\n Nro CLiente:........: %d", cliente.nroCliente);
    printf("\n Eliminado:..........: %d", cliente.eliminado);
    printf("\n==================================");
}

stCliente cargarCliente(){
    stCliente cliente;

    cliente.id=idautoincremental();

    printf("\n Ingrese su nombre: ");
    fflush(stdin);
    gets(cliente.nombre);

    printf("\n Ingrese su apellido: ");
    fflush(stdin);
    gets(cliente.apellido);

    printf("\n Ingrese su dni: ");
    fflush(stdin);
    gets(cliente.dni);

    printf("\n Ingrese su email: ");
    fflush(stdin);
    gets(cliente.email);

    printf("\n Ingrese su domicilio: ");
    fflush(stdin);
    gets(cliente.domicilio);

    printf("\n Ingrese su telefono: ");
    fflush(stdin);
    gets(cliente.telefono);

    cliente.eliminado=0;

    cliente.nroCliente=nroClienteA();

    return cliente;
}
