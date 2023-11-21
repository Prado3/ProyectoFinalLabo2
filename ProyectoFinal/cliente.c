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

int id (){
    static int i = 1;
    return i++;
}
