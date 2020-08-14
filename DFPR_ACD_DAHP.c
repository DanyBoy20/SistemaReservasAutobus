/* ------------------------------------> LIBRERIAS Y DEFINICIONES DE CONSTANTES <--------------------------------------  */
#include<stdio.h>
#include<process.h>
#include<string.h>
#include<conio.h>
/* ----------------------------------------------> ESTRUCTURAS DE DATOS <-----------------------------------------------*/
// Estructura que guardara los datos del autobus: desde donde sale, a donde se dirige, su tarifa, cuantos boletos se vendieron, los asientos y nombre del chofer
struct autoBuses
{
int codigoAutobus; // es el id de cada autobus, se autoincrementara y es el que se ocupa para asignar reservaciones, cancelaciones y ver el estado de autobuses
int numeroAutobus; // aqui guardare el numero economico (asi se manejan) del autobus
char asiento[11][4][20]; // arreglo para guardar los asientos del autobus
char nombreChofer[20]; // nombre del chofer de ese autobus
char direccion[20]; // a donde se dirigira el autobus
char desde[20]; // desde donde sale el autobus
float tarifa; // cuanto cobra por esa ruta
int boletoVendido; // variable que guardara los boletos vendidos de ese autobus para esa ruta
};
/* ----------------------------------------------> VARIABLES GLOBALES <-----------------------------------------------*/
char estadoAsiento[]="Disponible"; // variable que me guarda el estado de los asientos. la ocupare para asignar ese estado al capturar nuevos autobuses
static int identificador_autobus=1; // esta variable guarda el identificador del autobus
struct autoBuses stAutoB[40]; // arreglo de tipo autoBuses (creada con estructura) - guardara los datos explicados en la estructura anterior
/* ----------------------------------------------> PROTOTIPO DE LAS FUNCIONES <--------------------------------------- */
void nuevoAutobus(); // funcion para agregar nuevo autobus
void menuPrincipal(); // funcion que me despliega el menu principal
void nuevosAsientosAutobus(); // funcion para asignar asientos en estado disponibles al agregar nuevo autobus
void reservarAsiento(); // funcion para reservar asientos
void cancelarAsiento(); // funcion para cancelar una reservacion
void detalleAsientoAutoB(); // funcion para ver a detalle el autobus (datos completos del autobus) y sus asientos
void lineaDivisora(); // esta funcion solo me imprime caracteres " * " , funjen como separadores. solo estan por estetica
/* ----------------------------------------------> FUNCIÓN PRINCIPAL DEL PROGRAMA <----------------------------------- */
void main(){
	menuPrincipal(); // funcion que muestra el menu principal, es todo lo que hay en la funcion principal.
}
/* ----------------------------------------------> DEFINICIÓN DE FUNCIONES <-----------------------------------------  */
// 1. FUNCIÓN MENU PRINCIPAL - MUESTRA EL MENU DEL PROGRAMA. CADA OPCION EJECUTA UNA FUNCION PREVIAMENTE CREADA Y DEFINIDA
void menuPrincipal(){
int opcionMenu; // variable para guardar la opcion elegida del menu, misma que se evaluara con la sentencia switch
	printf("\n"); // salto de linea
    lineaDivisora(); // imprimo separador (funcion que muestra solo caracteres " * " , es por estetica nada más
	printf("\n\t\t   ______________________"); // impresion de titulos y separadores
	printf("\n\n\t\t   SISTEMA DE RESERVACI%cN",224); // impresion de titulos y separadores
	printf("\n\t\t   ______________________\n\n"); // impresion de titulos y separadores
	lineaDivisora(); // imprimo separador (funcion que muestra solo caracteres " * " , es por estetica nada más
/* Mostramos el menu : */
	printf("\n\n\t\t1.Captura de Autobuses");
	printf("\n\t\t2.Reservaciones");
	printf("\n\t\t3.Cancelar");
	printf("\n\t\t4.Detalle asientos");
	printf("\n\t\t5.Salir");
	printf("\n\n\n\tSelecciona una opci%cn ( 1 / 2 / 3 / 4 / 5 ): ",162);
	fflush(stdin); // fflush limpia el bufer, stdin estandar input, lo que se captura con el teclado. 
	scanf("%d",&opcionMenu); // escaneo lo que el usuario tecleo
/* Cada opcion llama a la funcion definida para realizar las acciones de dicha funcion*/
	switch(opcionMenu){
	//elección:  // acciones a hacer
		case 1 : // si se eligio 1
				nuevoAutobus(); // ejecuta la funcion nuevoAutobus
				break; // sal del switch ... lo mismo para los demas breaks
		case 2: reservarAsiento(); // ejecuta la funcion reservarAsiento
				break;
		case 3: cancelarAsiento(); // ejecuta la funcion cancelarAsiento
				break;
		case 4: detalleAsientoAutoB(); // ejecuta la funcion detalleAsientoAutoB
				break;
		case 5: system("cls"); // limpia pantalla
				printf("\n%c GRACIAS POR USAR EL PROGRAMA !\n", 173); // mensaje
				getch(); // esperar captura de tecla
				exit(0); // salor
		default: printf("\t\t\tENTRADA INVALIDA!!!!"); // si no fue ninguna de las opciones mencionadas, se ejecutara la opcion (el caso) por defecto
				getch(); // esperar captura de tecla
				menuPrincipal(); // vuelve a ejecutar el menu principal
	}
}
// 2. AQUI CAPTURAMOS LOS AUTOBUSES QUE ESTARAN DISPONIBLES E INFORMACION GENERAL DE LOS MISMOS 
void nuevoAutobus(){  // void = no deuelve nada
// al ser una variable local en cada funcion, puede llevar el mismo nombre en todas, y la ocupare para repetir el proceso si el usuario lo decide
char opcionNuevoAutoB; 
system("cls"); // limpia pantalla
printf("\n\n\t\tCapture la informaci%cn del autobus\n\n",162); // impresion de mensaje que muestra lo que se tiene que hacer
do{ // ciclo "Hacer ... (mientras)
	lineaDivisora(); // imprime linea
	// imprime el codigo del autobus, si es la primera vez que se ejecuta, vale 1, que es el valor definido en las variables globales (linea 22)
	printf("\n\n\t\t C%cdigo Autobus: %d", 162, identificador_autobus); 
	// linea identificadora (etiqueta:). Con la sentencia goto puedo ir a este tipo de lineas. en este caso, aqui hay un mensaje indicando la accion a realizar	
	lineaCodigoAuto: printf("\n\n\tN%cmero de autobus: ", 163); 
	fflush(stdin); 
	// las siguientes lineas son arreglos y se leeran asi en adelante, segun el campo indicado (y si aplica):
	//el arreglo stAutoB con indice determinado(el valor de identificador_autobus) en su campo codigoAutobus se le asigna el valor de indentificador_autobus
	// supongamos (Y SOLO PARA FINES DE EJEMPLO) que es la primera vez que se ejecuta el programa, entonces identificador_autobus vale 1 y quedaria asi:
	// stAutoB[1].codigoAutobus = 1; 
	// el arreglo stAutoB en su indice uno [1] y su campo codigoAutobus se le asigna el valor 1 ( asi se lee en lineas inferiores de acuerdo al campo escito)
	stAutoB[identificador_autobus].codigoAutobus=identificador_autobus; 
	scanf("%d",&stAutoB[identificador_autobus].numeroAutobus); // escaneo lo que el usuario tecleo y se lo asigno al campo numeroAutobus
		if(stAutoB[identificador_autobus].numeroAutobus<1||stAutoB[identificador_autobus].numeroAutobus>9999){ // si ese valor es menor que 1 y mayor que 9999
			printf("\t\tN%cmero invalido!!!!", 162); // numero invalido
			goto lineaCodigoAuto; // con la sentencia goto voy a lineas especificas, e este caso a la linea "lineaCodigoAuto"
		}
	lineaNombre: printf("\n\tCapture el nombre del conductor: "); // nueva linea ID , aqui se muestra en pantalla el mensaje con la accion a seguir
	fflush(stdin);
	gets(stAutoB[identificador_autobus].nombreChofer); // caoturo el dato y lo asigno al campo nombreChofer
		if(strlen(stAutoB[identificador_autobus].nombreChofer)>20){ // si la captura fue de mas de 20 caracteres
			printf("El nombre es muy largo, m%cximo de 20 letras", 160); // muestro mensaje de error
			goto lineaNombre; // me regreso a la linea mencionada
		}
	lineaOrigen: printf("\n\tOrigen: "); // nueva linea ID , aqui imprimo en pantalla el mensaje Origen (desde donde sale el autobus)
	fflush(stdin);
	gets(stAutoB[identificador_autobus].desde); // asigno al campo desde de la variable tipo autoBuses (es la estructura creada lineas arriba)
		if(strlen(stAutoB[identificador_autobus].desde)>20){ // si lo que se capturo es mayor a 20 caracteres
			printf("El nombre de origen es demasiado largo"); // mensaje
			goto lineaOrigen; // me regreso a la linea indicada
		}
	lineaDestino: printf("\n\tDestino: "); // linea ID , muestro mensaje
	fflush(stdin);
	gets(stAutoB[identificador_autobus].direccion); // asigno al campo direccion de la estructura lo que el usuario tecleo
		if(strlen(stAutoB[identificador_autobus].direccion)>20){ // si ese valor es mayor que 20 caracteres
			printf("El nombre de destino es demasiado largo"); // mensaje de error
			goto lineaDestino; // me regreso a la linea indicada
		}
	printf("\n\tTarifa: %C", 36); // imprimo mensaje
	fflush(stdin);
	scanf("%f",&stAutoB[identificador_autobus].tarifa); // asigno a campo tarifa de la estructura el valor tecleado por usuario
	stAutoB[identificador_autobus].boletoVendido=0; // inicio a cero el valor de boletoVendido. cambiara cuando se hagan reservaciones
	printf("\n"); // salto de linea
	nuevosAsientosAutobus(); // creo los asientos con valor de Disponibles a cada elemento del arreglo
	lineaDivisora(); // imprimo linea divisora
printf("\n\n\n\t%c Registrar nuevo autobus (s/n)? ", 168); // mensaje requiriendo accion del usuario
fflush(stdin);
scanf("%c",&opcionNuevoAutoB); // escaneo respuesta y la asigno a la variable que tendra el mismo nombre en todas las funciones (explicado lineas arriba)
identificador_autobus++; // incremento el codigo del autobus para el siguiente registro de autobus
system("cls"); // limpio pantalla
printf("\n\n\t\tCapture la informaci%cn del autobus\n\n",162); // mensaje siguiente
}while(opcionNuevoAutoB=='s'||opcionNuevoAutoB=='S'); // mientras la respuesta sea s o S
system("cls"); // limpio pantalla
menuPrincipal(); // si la respuesta fue negativa, ejecuto la funcion menuPrincipal
}
// 3. FUNCION PARA RESERVAR LOS ASIENTOS QUE ESTEN DISPONIBLES Y EN AUTOBUSES PARTICULARES Y PREVIAMENTE REGISTRADOS 
void reservarAsiento(){
char nombreReserva[20]; // variable que me guardara el nombre que capture el usuario
int nAutobus; // variable para guardar el codigo del autobus que capture el usuario
int nAsiento; // variable que guardara el numerode asiento que capture el usuario
char opcionNuevoAutoB; // variable a usar en bucle
system("cls"); // limpia pantalla
	printf("\n"); // salto de linea
    lineaDivisora(); // lo siguiente son las lineas divisoras y los titulos
	printf("\n\t\t   ______________________");
	printf("\n\n\t\t\tRESERVACIONES");
	printf("\n\t\t   ______________________\n\n");
	lineaDivisora();
	printf("\n\n\t\tN%cmero de autobus - ", 163); // mensaje requiriendo datos
	fflush(stdin);
	scanf("%d", &nAutobus); // asigno a nAutobus lo que el usuario tecleo
		if(nAutobus>=identificador_autobus){ // si lo que le usuario tecleo no es igual a lo que hay guardado, es decir, si el autobus buscado no esta registrado
			printf("\n\t\t\t%c Ese autob%cs no existe !", 173, 163); // mensaje de error
			reservarAsiento(); // ejecuto nuevamente la funcion reservarAsiento
		}
	lineaAsiento: printf("\n\t\tRegistre su asiento - "); // linea ID , imprimo aqui un mensaje
		fflush(stdin);
		scanf("%d", &nAsiento); // escaneo y asigno a nAsiento lo que el usuario capturo
			if(nAsiento>44){ // si el valor capturado es mayor a 44 (44 asientos)
				printf("\n\t\t%c El autob%cs solo cuenta con 44 asientos!", 173, 163) ; // mensaje de error
				goto lineaAsiento; // me regreso a la linea indicada
			// strcmp devuelve un valor, y lo compara con los parametros / valores que se le pasen. si es igual a cero	
			}else if(strcmp(stAutoB[nAutobus].asiento[nAsiento/4][(nAsiento%4)-1],"Disponible")==0){ 
				printf("\n\t\tNombre del pasajero - "); // Inicio con la reservacion, pidiendo nombre de pasajero
				nombrePasajero: fflush(stdin); // linea ID , limpia buffer
				gets(nombreReserva); // lo que tecleo el usuario, lo asigno a variable nombreReserva
					if(strlen(nombreReserva)>20){ // si ese nombre es mayor a 20
						printf("\n\t\t%c El nombre no debe ser mayor a 20 letras!", 173); // mensaje de error
						goto nombrePasajero; // me regreso a la linea indicada
					}else{ // y si no
						strcpy(stAutoB[nAutobus].asiento[nAsiento/4][nAsiento%4-1],nombreReserva); //asigno el nombre capturado al asiento determinado
						printf("\n\t\tAsiento reservado!!"); // mensaje  de confirmación
						stAutoB[nAutobus].boletoVendido++; // agrego una unidad a la variable boleto. si valia cero, ahora vale uno, si valia uno ahora es dos y asi
						printf("\n\t%c Realizar otra reservaci%cn (s/n)?", 168, 162); // mensaje 
						fflush(stdin);
						opcionNuevoAutoB=getchar(); //capturo lo que el usuario tecleo
							if(opcionNuevoAutoB=='s'||opcionNuevoAutoB=='S'){ // si fue una s  o una S
								system("cls"); // limpio pantalla
								reservarAsiento(); // y vuelvo a iniciar la funcion
							}else{ // y sino
								system("cls"); // limpio pantalla
								menuPrincipal(); // ejecuto la funcion menu principal
							}								
					}
			}else{ // y si no (el asiento ya existe alguien
				printf("\n\t%c Ese asiento ya est%c reservado!", 173, 160); // mensaje , el asiento ya esta reservado
				printf("\n\t%c Intentar nuevamente (s / n)?", 168); // mensaje si lo quiere volver a intentar
				fflush(stdin);
				opcionNuevoAutoB=getchar(); // capturo la respuesta del usuario
					if(opcionNuevoAutoB=='s'||opcionNuevoAutoB=='S') // si eligio s o S
						reservarAsiento(); // ejecuto nuevamente la funcion reservarAsiento
					else // y si no
					system("cls"); // limpio pantalla
					menuPrincipal(); // ejecuto la funcion menuPrincipal
			}
}
// 4. FUNCION PARA CANCELAR ASIENTOS EN AUTOBUSES DISPONIBLES
void cancelarAsiento(){
int nAutobus; // variable para guardar el codigo del autobus que el susuario teclee
int nAsiento; // variable que guarara el asiento que el usuario teclee
char opcionNuevoAutoB; // variable para usar en condicion, si se repite o no la ejecucion
system("cls"); // borro pantalla
	printf("\n");
    lineaDivisora();
	printf("\n\t\t   ______________________");
	printf("\n\n\t\t\tCANCELACIONES");
	printf("\n\t\t   ______________________\n\n");
	lineaDivisora();
	printf("\n\n\t\tNumero de autob%cs - ", 163); //mensaje requiriendo accion del usuario
	fflush(stdin);
	scanf("%d", &nAutobus); // escaneo y asigno lo que el usuario tecleo a la variable nAutobus
		if(nAutobus>=identificador_autobus){ // si no son los mismos identificadores
			printf("\n\t\t\t%c Ese autob%cs no existe!", 173, 163); // mensaje de error
			cancelarAsiento(); // vuelvo a ejecutar la funcion
		}
	lineaAsiento: printf("\n\t\tQue asiento desea cancelar - "); // linea ID, mensaje indicando accion a seguir 
		fflush(stdin);
		scanf("%d", &nAsiento); // escaneo y asigno lo que el usuario capturo en variable nAsiento
			if(nAsiento>44){ // si es mayor a 44 (no hay mas de 44 asientos)
				printf("\n\t\t%cEl autobus solo cuenta con 44 asientos!", 173) ; // mensaje de error
				goto lineaAsiento; // regreso a la linea indicada
			}else if(strcmp(stAutoB[nAutobus].asiento[nAsiento/4][(nAsiento%4)-1],"Disponible")==0){ // si el asiento esta disponible
				printf("\n\t\tESE ASIENTO SI EST%c DISPONIBLE", 181); // mensaje indicando que la captura corresponde a un asiento disponible
				printf("\n\t\tSERA REDIRIGIDO AL MENU PRINCIPAL"); // llevo al usuario al men principal
				system("pause"); // pausa para leer mensaje anterior
				system("cls"); // limpio pantalla
				menuPrincipal(); // ejecuto funcion menuPrincipal
			}else{ // y sino
				strcpy(stAutoB[nAutobus].asiento[nAsiento/4][nAsiento%4-1],"Disponible"); // asigno "Disponible al asiento cancelado
				printf("\n\t%c Cancelaci%cn exitosa !", 173, 162); // mensaje de operacion exitosa
				stAutoB[nAutobus].boletoVendido--; // quito una unidad al campo boletoVendido
				printf("\n\t%c Realizar otra cancelaci%cn (s / n)?", 168, 162);  // mensaje pidiendo accion porparte del usuario
				fflush(stdin);
				opcionNuevoAutoB=getchar(); // capturo lo que el usuario tecleo
					if(opcionNuevoAutoB=='s'||opcionNuevoAutoB=='S') // si tecleo una s o una S
						cancelarAsiento(); // ejecuto nuevamente la funcion cancelarAsiento
					else // y sino
					system("cls"); // limpio pantalla
					menuPrincipal(); // ejecuto funcion menuPrincipal
			}
}
// 5. FUNCION QUE ASIGNA ASIENTOS CON EL ESTADO DE DISPONIBLES CUANDO REGISTRAMOS NUEVOS AUTOBUSES
void nuevosAsientosAutobus(){ 
int i,j; // variables contadores
	for(i=0;i<11;i++){ // primer ciclo - hasta 11 . corresponde a las columnas
		for(j=0;j<4;j++){ // segundo ciclo - hasta 4: corresponde a las filas 
			strcpy(stAutoB[identificador_autobus].asiento[i][j],estadoAsiento); // pongo a disponible los asientos para nuevo autobus
		}
	}
}
// 6. FUNCION QUE MUESTRA EL ESTADO DE LAS RESERVACIONES HECHAS EN UN AUTOBUS EN PARTICULAR 
void detalleAsientoAutoB(){
int nAutobus,indice=0,j,k; // variables locales: nAutobus guarda el autobus que tecleo el usuario, indice para los asientos, j y k para los ciclos
char opcionNuevoAutoB; // variable para repetir si el usuario lo desea
system("cls");
	printf("\n");
    lineaDivisora();
	printf("\n\t\t   ______________________");
	printf("\n\n\t\t    VER DETALLES AUTOBUS");
	printf("\n\t\t   ______________________\n\n");
	lineaDivisora();
printf("\n\n\t\tCaptura codigo de autobus.-"); // mensaje pidiendo accion del usuario
fflush(stdin);
scanf("%d",&nAutobus); // asigno lo que capturo el usuario a variable nAutobus
	if(nAutobus>=identificador_autobus){ // si son diferentes loque tecleo y el identificador
		printf("\n\t\tNo hay registro de ese autobus!!!!"); // mensaje de error
		printf("\n Primero debes registrar un autobus, seras redirigido al menu principal "); // mensaje informativo
		getch();
		system("cls");
		menuPrincipal(); // ejecuto funcion menuPrincipal
	}else{ // y si no ( el autobus si existe)
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
						indice++; // indice para asientos (es solo para verse en pantalla
						// imprimo el asiento segun su indice (numero y el estado - disponible o quien ya lo registro)
						printf("%d .%s\t",indice,stAutoB[nAutobus].asiento[j][k]); 
					}
			}
	}
printf("\n\n\t\tDesea buscar otro autobus (s/n)??"); // mensaje requiriendo accion del usuario
fflush(stdin);
opcionNuevoAutoB=getchar(); // asigno a variable lo que el usuario capture
	if(opcionNuevoAutoB=='s'||opcionNuevoAutoB=='S') // si la captura fue s o S
		detalleAsientoAutoB(); // ejecuto la funcion otra vez
	else // y si no
	system("cls");
	menuPrincipal(); // ejecuto la funcion principal
}
// 7. FUNCION DE IMPRESION DE CARACTERES " * " - Esta funcion solo me imprime una linea de caracteres del simbolo asterisco 
void lineaDivisora(){
int j; // variable contador
	for(j=0;j<60;j++) 
		printf("*"); // esto se imprimira 59 veces
}
