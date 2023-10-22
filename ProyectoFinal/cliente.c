#include "cliente.h"
stCliente cargarClienteRandom(int clienteId, int nroCliente,int num, int numDni){
    stCliente cliente;
    getName(cliente.nombre,num);
    getLastname(cliente.apellido,num);
    getDni(cliente.dni,numDni);
    getEmail(cliente.email,num);
    getDomicilio(cliente.domicilio,num);
    getTelefono(cliente.telefono,num);
    cliente.eliminado=0;
    cliente.id=idautoincremental(clienteId);
    cliente.nroCliente=nroClienteA(nroCliente);

    return cliente;
}

int idautoincremental(int clienteId){
    int id=idAuto();
    if(clienteId > 0){
        id = clienteId;
    }
return id+1;
}

int idAuto(){
    static int i = 0;
    return i;
}

int nroClienteA(int nroCliente){
    int id=nroClienteB();
    if(nroCliente > 0){
        id = nroCliente;
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

    //cliente.id=idautoincremental();

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

//    cliente.nroCliente=nroClienteA();

    return cliente;
}
