/* ------------------------------------> LIBRERIAS Y DEFINICIONES DE CONSTANTES <--------------------------------------  */
#include<stdio.h>
#include<process.h>
#include<string.h>
#include<conio.h>
/* ----------------------------------------------> ESTRUCTURAS DE DATOS <-----------------------------------------------*/
// Estructura que guardara los datos del autobus: desde donde sale, a donde se dirige, su tarifa, cuantos boletos se vendieron, los asientos y nombre del chofer
struct autoBuses
{
int codigoAutobus; 
int numeroAutobus; 
char asiento[11][4][20]; 
char nombreChofer[20]; 
char direccion[20]; 
char desde[20]; 
float tarifa; 
int boletoVendido; 
};
/* ----------------------------------------------> VARIABLES GLOBALES <-----------------------------------------------*/
char estadoAsiento[]="Disponible"; 
static int identificador_autobus=1; 
struct autoBuses stAutoB[40]; 
/* ----------------------------------------------> PROTOTIPO DE LAS FUNCIONES <--------------------------------------- */
void nuevoAutobus(); 
void menuPrincipal(); 
void nuevosAsientosAutobus();
void reservarAsiento(); 
void cancelarAsiento(); 
void detalleAsientoAutoB(); 
void lineaDivisora(); 
/* ----------------------------------------------> FUNCIÓN PRINCIPAL DEL PROGRAMA <----------------------------------- */
void main(){
	menuPrincipal(); 
}
/* ----------------------------------------------> DEFINICIÓN DE FUNCIONES <-----------------------------------------  */
// 1. FUNCIÓN MENU PRINCIPAL - MUESTRA EL MENU DEL PROGRAMA. CADA OPCION EJECUTA UNA FUNCION PREVIAMENTE CREADA Y DEFINIDA
void menuPrincipal(){
int opcionMenu; 
	printf("\n"); 
    lineaDivisora(); 
	printf("\n\t\t   ______________________"); 
	printf("\n\n\t\t   SISTEMA DE RESERVACI%cN",224); 
	printf("\n\t\t   ______________________\n\n"); 
	lineaDivisora(); 
/* Mostramos el menu : */
	printf("\n\n\t\t1.Captura de Autobuses");
	printf("\n\t\t2.Reservaciones");
	printf("\n\t\t3.Cancelar");
	printf("\n\t\t4.Detalle asientos");
	printf("\n\t\t5.Salir");
	printf("\n\n\n\tSelecciona una opci%cn ( 1 / 2 / 3 / 4 / 5 ): ",162);
	fflush(stdin); 
	scanf("%d",&opcionMenu); 
/* Cada opcion llama a la funcion definida para realizar las acciones de dicha funcion*/
	switch(opcionMenu){
		case 1 : 
				nuevoAutobus(); 
				break; 
		case 2: reservarAsiento(); 
				break;
		case 3: cancelarAsiento(); 
				break;
		case 4: detalleAsientoAutoB(); 
				break;
		case 5: system("cls"); 
				printf("\n%c GRACIAS POR USAR EL PROGRAMA !\n", 173); 
				getch(); 
				exit(0); 
		default: printf("\t\t\tENTRADA INVALIDA!!!!"); 
				getch(); 
				menuPrincipal(); 
	}
}
// 2. AQUI CAPTURAMOS LOS AUTOBUSES QUE ESTARAN DISPONIBLES E INFORMACION GENERAL DE LOS MISMOS 
void nuevoAutobus(){  
char opcionNuevoAutoB; 
system("cls"); 
printf("\n\n\t\tCapture la informaci%cn del autobus\n\n",162); 
do{ 
	lineaDivisora(); 
	printf("\n\n\t\t C%cdigo Autobus: %d", 162, identificador_autobus); 		
	lineaCodigoAuto: printf("\n\n\tN%cmero de autobus: ", 163); 
	fflush(stdin); 
	stAutoB[identificador_autobus].codigoAutobus=identificador_autobus; 
	scanf("%d",&stAutoB[identificador_autobus].numeroAutobus); 
		if(stAutoB[identificador_autobus].numeroAutobus<1||stAutoB[identificador_autobus].numeroAutobus>9999){ 
			printf("\t\tN%cmero invalido!!!!", 162); 
			goto lineaCodigoAuto; 
		}
	lineaNombre: printf("\n\tCapture el nombre del conductor: "); 
	fflush(stdin);
	gets(stAutoB[identificador_autobus].nombreChofer); 
		if(strlen(stAutoB[identificador_autobus].nombreChofer)>20){ 
			printf("El nombre es muy largo, m%cximo de 20 letras", 160); 
			goto lineaNombre; 
		}
	lineaOrigen: printf("\n\tOrigen: "); 
	fflush(stdin);
	gets(stAutoB[identificador_autobus].desde); 
		if(strlen(stAutoB[identificador_autobus].desde)>20){ 
			printf("El nombre de origen es demasiado largo"); 
			goto lineaOrigen; 
		}
	lineaDestino: printf("\n\tDestino: "); 
	fflush(stdin);
	gets(stAutoB[identificador_autobus].direccion); 
		if(strlen(stAutoB[identificador_autobus].direccion)>20){ 
			printf("El nombre de destino es demasiado largo"); 
			goto lineaDestino; 
		}
	printf("\n\tTarifa: %C", 36); 
	fflush(stdin);
	scanf("%f",&stAutoB[identificador_autobus].tarifa); 
	stAutoB[identificador_autobus].boletoVendido=0; 
	printf("\n"); 
	nuevosAsientosAutobus(); 
	lineaDivisora(); 
printf("\n\n\n\t%c Registrar nuevo autobus (s/n)? ", 168); 
fflush(stdin);
scanf("%c",&opcionNuevoAutoB); 
identificador_autobus++; 
system("cls"); 
printf("\n\n\t\tCapture la informaci%cn del autobus\n\n",162); 
}while(opcionNuevoAutoB=='s'||opcionNuevoAutoB=='S'); 
system("cls");
menuPrincipal(); 
}
// 3. FUNCION PARA RESERVAR LOS ASIENTOS QUE ESTEN DISPONIBLES Y EN AUTOBUSES PARTICULARES Y PREVIAMENTE REGISTRADOS 
void reservarAsiento(){
char nombreReserva[20]; 
int nAutobus; 
int nAsiento; 
char opcionNuevoAutoB; 
system("cls");
	printf("\n"); 
    lineaDivisora(); 
	printf("\n\t\t   ______________________");
	printf("\n\n\t\t\tRESERVACIONES");
	printf("\n\t\t   ______________________\n\n");
	lineaDivisora();
	printf("\n\n\t\tN%cmero de autobus - ", 163); 
	fflush(stdin);
	scanf("%d", &nAutobus); 
		if(nAutobus>=identificador_autobus){ 
			printf("\n\t\t\t%c Ese autob%cs no existe !", 173, 163); 
			reservarAsiento(); 
		}
	lineaAsiento: printf("\n\t\tRegistre su asiento - "); 
		fflush(stdin);
		scanf("%d", &nAsiento); 
			if(nAsiento>44){ 
				printf("\n\t\t%c El autob%cs solo cuenta con 44 asientos!", 173, 163) ; 
				goto lineaAsiento; 	
			}else if(strcmp(stAutoB[nAutobus].asiento[nAsiento/4][(nAsiento%4)-1],"Disponible")==0){ 
				printf("\n\t\tNombre del pasajero - "); 
				nombrePasajero: fflush(stdin); 
				gets(nombreReserva); 
					if(strlen(nombreReserva)>20){ 
						printf("\n\t\t%c El nombre no debe ser mayor a 20 letras!", 173); 
						goto nombrePasajero; 
					}else{ 
						strcpy(stAutoB[nAutobus].asiento[nAsiento/4][nAsiento%4-1],nombreReserva); 
						printf("\n\t\tAsiento reservado!!"); 
						stAutoB[nAutobus].boletoVendido++; 
						printf("\n\t%c Realizar otra reservaci%cn (s/n)?", 168, 162);
						fflush(stdin);
						opcionNuevoAutoB=getchar(); 
							if(opcionNuevoAutoB=='s'||opcionNuevoAutoB=='S'){ 
								system("cls"); 
								reservarAsiento(); 
							}else{
								system("cls");
								menuPrincipal(); 
							}								
					}
			}else{ 
				printf("\n\t%c Ese asiento ya est%c reservado!", 173, 160); 
				printf("\n\t%c Intentar nuevamente (s / n)?", 168);
				fflush(stdin);
				opcionNuevoAutoB=getchar(); 
					if(opcionNuevoAutoB=='s'||opcionNuevoAutoB=='S') 
						reservarAsiento(); 
					else 
					system("cls"); 
					menuPrincipal(); 
			}
}
// 4. FUNCION PARA CANCELAR ASIENTOS EN AUTOBUSES DISPONIBLES
void cancelarAsiento(){
int nAutobus; 
int nAsiento; 
char opcionNuevoAutoB; 
system("cls"); 
	printf("\n");
    lineaDivisora();
	printf("\n\t\t   ______________________");
	printf("\n\n\t\t\tCANCELACIONES");
	printf("\n\t\t   ______________________\n\n");
	lineaDivisora();
	printf("\n\n\t\tNumero de autob%cs - ", 163); 
	fflush(stdin);
	scanf("%d", &nAutobus); 
		if(nAutobus>=identificador_autobus){ 
			printf("\n\t\t\t%c Ese autob%cs no existe!", 173, 163); 
			cancelarAsiento(); 
		}
	lineaAsiento: printf("\n\t\tQue asiento desea cancelar - "); 
		fflush(stdin);
		scanf("%d", &nAsiento); 
			if(nAsiento>44){ 
				printf("\n\t\t%cEl autobus solo cuenta con 44 asientos!", 173) ; 
				goto lineaAsiento; // regreso a la linea indicada
			}else if(strcmp(stAutoB[nAutobus].asiento[nAsiento/4][(nAsiento%4)-1],"Disponible")==0){ 
				printf("\n\t\tESE ASIENTO SI EST%c DISPONIBLE", 181); 
				printf("\n\t\tSERA REDIRIGIDO AL MENU PRINCIPAL"); 
				system("pause"); 
				system("cls"); 
				menuPrincipal(); 
			}else{ 
				strcpy(stAutoB[nAutobus].asiento[nAsiento/4][nAsiento%4-1],"Disponible"); 
				printf("\n\t%c Cancelaci%cn exitosa !", 173, 162); 
				stAutoB[nAutobus].boletoVendido--; 
				printf("\n\t%c Realizar otra cancelaci%cn (s / n)?", 168, 162);  
				fflush(stdin);
				opcionNuevoAutoB=getchar(); 
					if(opcionNuevoAutoB=='s'||opcionNuevoAutoB=='S') 
						cancelarAsiento(); 
					else 
					system("cls"); 
					menuPrincipal(); 
			}
}
// 5. FUNCION QUE ASIGNA ASIENTOS CON EL ESTADO DE DISPONIBLES CUANDO REGISTRAMOS NUEVOS AUTOBUSES
void nuevosAsientosAutobus(){ 
int i,j; 
	for(i=0;i<11;i++){ 
		for(j=0;j<4;j++){ 
			strcpy(stAutoB[identificador_autobus].asiento[i][j],estadoAsiento); 
		}
	}
}
// 6. FUNCION QUE MUESTRA EL ESTADO DE LAS RESERVACIONES HECHAS EN UN AUTOBUS EN PARTICULAR 
void detalleAsientoAutoB(){
int nAutobus,indice=0,j,k; 
char opcionNuevoAutoB; 
system("cls");
	printf("\n");
    lineaDivisora();
	printf("\n\t\t   ______________________");
	printf("\n\n\t\t    VER DETALLES AUTOBUS");
	printf("\n\t\t   ______________________\n\n");
	lineaDivisora();
printf("\n\n\t\tCaptura codigo de autobus.-"); 
fflush(stdin);
scanf("%d",&nAutobus); 
	if(nAutobus>=identificador_autobus){ 
		printf("\n\t\tNo hay registro de ese autobus!!!!"); 
		printf("\n Primero debes registrar un autobus, seras redirigido al menu principal "); 
		getch();
		system("cls");
		menuPrincipal();
	}else{ 
		system("cls");
		printf("\n");
    	lineaDivisora();
		printf("\n\t\t   ______________________");
		printf("\n\n\t\t    VER DETALLES AUTOBUS");
		printf("\n\t\t   ______________________\n\n");
		lineaDivisora();
		// muestro los datos del autobus
		printf("\nNumero de autobus: %d\tNombre del chofer: %s",stAutoB[nAutobus].numeroAutobus,stAutoB[nAutobus].nombreChofer);
		printf("\nOrigen: %s\t\tDestino: %s",stAutoB[nAutobus].desde,stAutoB[nAutobus].direccion);
		printf("\nTarifa: %c %.2f\tBoletos vendidos: %d", 36, stAutoB[nAutobus].tarifa,stAutoB[nAutobus].boletoVendido);
		printf("\n");
		lineaDivisora();
			// inicio ciclo para mostrar asientos.
			for(j=0;j<11;j++){ 
				printf("\n");
					for(k=0;k<4;k++){
						indice++; 
						printf("%d .%s\t",indice,stAutoB[nAutobus].asiento[j][k]); 
					}
			}
	}
printf("\n\n\t\tDesea buscar otro autobus (s/n)??"); 
fflush(stdin);
opcionNuevoAutoB=getchar(); 
	if(opcionNuevoAutoB=='s'||opcionNuevoAutoB=='S')
		detalleAsientoAutoB();
	else 
	system("cls");
	menuPrincipal();
}
// 7. FUNCION DE IMPRESION DE CARACTERES " * " - Esta funcion solo me imprime una linea de caracteres del simbolo asterisco 
void lineaDivisora(){
int j; 
	for(j=0;j<60;j++) 
		printf("*"); 
}
