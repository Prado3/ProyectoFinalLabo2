#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#define ESC 27
#define ARCHI_CLIENTE "cliente.dat"
#define ARCHI_CUENTA "cuenta.dat"
#define ARCHI_MOVIMIENTOS "movimientos.dat"


typedef struct {
    int id;
    int nroCliente;
    char nombre[30];
    char apellido[30];
    char dni[10];
    char email[30];
    char domicilio[45];
    char telefono[12];
    int eliminado;
}stCliente;

// FUNCIONES DE MENU.C
void menuGeneral();
int mostrarOpciones();

// FUNCIONES DE CLIENTE.C
int idautoincremental();
int idAuto();
stCliente cargarClienteRandom(int clienteId, int nroCliente,int num);
void mostrarCliente(stCliente cliente);
stCliente cargarCliente();
int CantidadDatosArchivo(char archivo[], int PesoTipodeDato);
int validarTelefono(char TelefonoCliente[], char NombreArchivo[]);
int validarEmail(char EmailCliente[], char NombreArchivo[]);
int validarDni(char DNICliente[], char NombreArchivo[]);




#endif // CLIENTE_H_INCLUDED
