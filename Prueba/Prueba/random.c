#include "cliente.h"
#include "cuenta.h"
#include "movimiento.h"

// ACA SE ENCUENTRA LAS FUNCIONES PARA LA CARGA RANDOM
void cargarRandom(){
    stCliente cliente;
    stCuenta cuenta;
    stMovimiento movimiento;
    srand(time(NULL));
    int num=0;
    FILE* archi = fopen(ARCHI_CLIENTE,"a+b");
    FILE* archiCuenta = fopen(ARCHI_CUENTA,"a+b");
    FILE* archiMov = fopen(ARCHI_MOVIMIENTOS,"a+b");
    if(archi){
        if(archiCuenta){
            if(archiMov){
                cliente.id=0;
                cliente.nroCliente=0;
                cuenta.id=0;
                cuenta.nroCuenta=0;
                movimiento.id=0;
                for(int i =0;i<50;i++){
                    num = generarNumRand();
                    cliente = cargarClienteRandom(cliente.id,cliente.nroCliente,num);
                    fwrite(&cliente,sizeof(stCliente),1,archi);
                    cuenta.id=cliente.id;
                        for(int j = 0;j<3;j++){
                            cuenta = cargarCuentaRandom(cliente,j+1,cuenta.id,cuenta.nroCuenta);
                            fwrite(&cuenta,sizeof(stCuenta),1,archiCuenta);
                            movimiento.id=cuenta.id;
                                for(int z=0;z<10;z++){
                                    movimiento = cargarMovimientoRandom(cuenta,movimiento.id);
                                    fwrite(&movimiento,sizeof(stMovimiento),1,archiMov);
                                }
                                cuenta.id=movimiento.id;
                        }
                        cliente.id=cuenta.id;
                }
                fclose(archiMov);
            }
            fclose(archiCuenta);
        }
        fclose(archi);
    }
}

int generarNumRand(){
    int i = 0;
    i=rand()%20;
    return i;
}

void getName(char n[],int numRan){
    char names[][20]={"Amalio","Juan","Roberto","Antonio","Pedro","Fernando","Jacinto","Anibal","Antonio","Atalayo",
                           "Bertino","Anastasio","Amor","Arturo","Diego","Mario","Tamaro","Adolfo","Alfonso","Pedro","Alfredo",
                           "Rolando","Mauro","Amancio","Benicio","Bertin","Ildefonso","Amilcar","Cuchuflito","Jazmino",
                           "Remilgo","Lucia","Maria","Josefina","Catalina","Agustina","Mirta","Mario","Angela","Ariel","Julia","Carla","Ester"};
    strcpy(n,names[numRan]);
}

void getLastname(char l[],int numRan){
    char lastNames[][20]={"Fernandez","Garcia","Perez","Martinez","Gomez","Diaz","Sosa","Torres","Ruiz","Suarez",
                           "Castro","Gimenez","Vazquez","Acosta","Gutierrez","Ramirez","Flores","Benitez","Aguirre","Ortiz",
                           "Medina","Herrera","Dominguez","Moreno","Rojas","Peralta","Silva","Morales","Luna",
                           "Mendez","Romero","Molina","Montiel","Messi","Rodriguez","Gonzalez","Velasco","Menodza","Rolon"};
    strcpy(l,lastNames[numRan]);
}


void getDni(char d[],int numRan){
    char dnis[][20]={"28740858","29651813","40184442","26104249","32997809","35794895","27589790","38354542","34180521","24021740",
                           "30462341","39294102","27810158","26978925","31489645","30170275","41543371","29233430","23010622","23278318","36174131",
                           "27711944","37790238","29343879","27116347","38697631","35025026","31928840","37681104","37977745",
                           "29810168","13312512","43740918","42157668","9548756","8451259","17485126","14789562","12200498","17631436","45189478","40143256","35495614",
                           "20157448","22546321","33547896","29412589","18476512","19412568","24789514"};
    strcpy(d,dnis[numRan]);
}

void getEmail(char e[],int numRan){
    char emails[][20]={"amalio_32@gmail.com","juan1993@gmail.com","perez@gmail.com","martinez2001@gmail.com","pedrio_81@gmail.com","fer23@gmail.com","jacintoo2@gmail.com","anibal54@gmail.com","antonio_192@gmail.com","atalavo2001@gmail.com",
                           "ccastro@gmail.com","gimenezAnastasio732@gmail.com","vazquezAmor@gmail.com","acosta536@gmail.com","diego_183@gmail.com","ramirezMario1993@gmail.com","flores4@gmail.com","benitez_76@gmail.com","alffonso_37@gmail.com","ppedroo@gmail.com",
                           "alfredo19@gmail.com","herreraMauro@gmail.com","mauro_82@gmail.com","moreno_ush@gmail.com","rojass41@gmail.com","peraltaIldefonso_76@gmail.com","silva21_@gmail.com","moraless_37@gmail.com","lunna41@gmail.com",
                           "mendez_scum@gmail.com","miguelangel21@gmail.com","carla.gutierrez@hotmail.com","laura28@yahoo.com","ester_avila@gmail.com","angela38@gmail.com","juan22@hotmail.com","juan50@hotmail.com"};




    strcpy(e, emails[numRan]);
}

void getDomicilio(char d[],int numRan){
    char domicilios[][20]={"avellaneda 2650","tucuman 3450","luro 1265","juan b justo 6578","las heras 3245","catamarca 1782","salta 2341","cordoba 2333","san luis 3214",
                                "entre rios 1892","colon 1200","colon 3456","formosa 4562","luro 8791","constitucion 3401","jujuy 4362","alem 1342","san luis 2341","la rioja 3221",
                                "luro 4563","colon 2341","Rivadavia 1234","San Martín 5674","Belgrano 4326","Mitre 7897","Sarmiento 3445",
                                "25 de Mayo 2101","Moreno 3654","San Juan 987","Belgrano 3217","Santa Fe 5437","Rivadavia 2104","Pellegrini 1237","Alsina 4568","Independencia 789",
                                "Aconcagua 785","San Martín 4546", "Rivadavia 7839"," Belgrano 1011"," Sarmiento 2746"," 9 de Julio 3469"," Mitre 2852"," Pueyrredón 4753","Güemes 4554","Independencia 3147",
                                "San Lorenzo 4258", "Colón 11369", "Urquiza 471", "Rivadavia 2563", "Belgrano 3654", "Sáenz Peña 836", "Córdoba 1227", "San Juan 501", "Alsina 212"};


    strcpy(d,domicilios[numRan]);
}

void getTelefono(char t[],int numRan){
    char telefonos[][20]={"2235347689","2234134567","2235768543","2236768956","2235345654","2235346123","2235879345","2234456879","2234234657","2236579243",
                           "2236143245","2234476897","2235243567","2235568093","2235768567","2235365789","2235478090","2235037067","2235254089","2237524049","2236254054",
                           "2235451083","2232254586","2235354084","2236284287","2235654253","2238557086","2235557059","2235254247","2235274268",
                           "2239257283"};

    strcpy(t,telefonos[numRan]);
}
