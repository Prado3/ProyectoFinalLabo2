#include "cliente.h"
stCliente cargarClienteRandom(int clienteId, int nroCliente,int num){
    stCliente cliente;
    getName(cliente.nombre,num);
    getLastname(cliente.apellido,num);
    getDni(cliente.dni,num);
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

    //cliente.id=Id;

    printf("\n Ingrese su nombre: ");
    fflush(stdin);
    gets(cliente.nombre);

    printf("\n Ingrese su apellido: ");
    fflush(stdin);
    gets(cliente.apellido);

do{
    int flagDNI;
    char opcionDNI = ' ';
    do{
        printf("\nIngrese su DNI: ");
        fflush(stdin);
        gets(cliente.dni);
        flagDNI = validarDni(cliente.dni, ARCHI_CLIENTE);
        if(flagDNI == 1){
            printf("\nEl DNI ingresado ya se encuentra registrado en la base de datos. Presione cualquier tecla para volver a ingresar un DNI, o presione ESC para salir.");
            opcionDNI = getch();
        }
    }while(opcionDNI != ESC && flagDNI == 1);

    if(flagDNI == 0){

    int flagEmail;
    do{
        printf("\nIngrese su Email: ");
        fflush(stdin);
        gets(cliente.email);
        flagEmail = validarEmail(cliente.email, ARCHI_CLIENTE);
        if(flagEmail == 1){
            printf("\nEl email ingresado ya se encuentra registrado en la base de datos. Por favor, vuelva a ingresar una dirección de email.");
        }
    }while(flagEmail == 1);

    printf("\n Ingrese su domicilio: ");
    fflush(stdin);
    gets(cliente.domicilio);

     int flagTelefono;
    do{
    printf("\nIngrese su Numero de telefono (sin espacios ni guiones): ");
    fflush(stdin);
    gets(cliente.telefono);
    flagTelefono = validarTelefono(cliente.telefono, ARCHI_CLIENTE);
    if(flagTelefono == 1){
        printf("\nEl teléfono ingresado ya se encuentra registrado en la base de datos. Por favor, vuelva a ingresar un teléfono.");
    }
    }while(flagTelefono == 1);

    cliente.eliminado=0;

//    cliente.nroCliente=nroClienteA();

    return cliente;
}









int validarDni(char DNICliente[], char NombreArchivo[]){
    stCliente ClientesCargados;
    int flag = 0;
    FILE * archi = fopen(NombreArchivo, "rb");
    if(archi)
    {
        if (CantidadDatosArchivo(NombreArchivo, sizeof(stCliente)) > 0){
            while(flag == 0 && fread(&ClientesCargados, sizeof(stCliente),1,archi) > 0)
            {
                if(strcmp(DNICliente, ClientesCargados.dni) == 0)
                {
                    flag = 1;
                }
            }
        }
    }
    fclose(archi);
    return flag;
}

int validarEmail(char EmailCliente[], char NombreArchivo[]){
    stCliente ClientesCargados;
    int flag = 0;
    FILE * archi = fopen(NombreArchivo, "rb");
    if(archi){
        if (CantidadDatosArchivo(NombreArchivo, sizeof(stCliente)) > 0){
            while(flag == 0 && fread(&ClientesCargados, sizeof(stCliente), 1, archi) > 0){
                if(strcmp(EmailCliente, ClientesCargados.email) == 0){
                    flag = 1;
                }
            }
        }
    }
    fclose(archi);
    return flag;
}

int validarTelefono(char TelefonoCliente[], char NombreArchivo[]){
    stCliente ClientesCargados;
    int flag = 0;
    FILE * archi = fopen(NombreArchivo, "rb");

    if(archi){
        if (CantidadDatosArchivo(NombreArchivo, sizeof(stCliente)) > 0){
            while(flag == 0 && fread(&ClientesCargados, sizeof(stCliente), 1, archi) > 0)
            {
                if(strcmp(TelefonoCliente, ClientesCargados.telefono) == 0)
                {
                    flag = 1;
                }
            }
        }
    }
    fclose(archi);
    return flag;
}

/*
int CantidadDatosArchivo(char archivo[], int PesoTipodeDato){
    FILE *archi = fopen(archivo, "rb");
    int CantidadDatos;

    if(archi){
        fseek(archi, 0, SEEK_END);
        CantidadDatos = ftell(archi) / PesoTipodeDato;
        fclose(archi);
    }

    else{
        printf("\nEl archivo no puede abrirse correctamente.");
        CantidadDatos = - 1;
    }
    return CantidadDatos;
}


*/
