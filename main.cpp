#include <iostream>//Necesario para interactuar con el Usuario en Gral.
#include <fstream> //Necesario para funcion CARGAR ARCHIVO.
#include <string>//Necesario para leer strings
#include <cstdlib> // Necesario para la función system
using namespace std;

//Declaracion de ESTRUCTURAS GLOBALES_____________________________________________________________________________________________

struct Reserva {    //-------------------->Para Escritura y lectura de un registro
    int cod_ciudad = 0;
    int cod_dia = 0;
    int DNI = 0;
};
struct Nodo{        //-------------------->Bloque de las listas que se registran en la matriz
	Nodo* sig = NULL;
	int dni = 0;
};

//Declaracion de VARIABLES GLOBALES_______________________________________________________________________________________________

const string nombre_archivo = "reservas.dat";
const int num_ciudades = 100;
const int num_dias = 7;


//Declaracion de FUNCIONES________________________________________________________________________________________________________

void mostrarMenu();
void cargar_archivo(const string &nombre_archivo);
void procesar_archivo(const string &nombre_archivo, Nodo* tabla[num_ciudades][num_dias]);
void insertar_lista(Nodo* &p, int DNI);
void emitir_reporte(Nodo* tabla[num_ciudades][num_dias]);
void mostrar(Nodo* p, int &c);
void liberar(Nodo*& p);

//funciones de control:
/*void mostrar_reservas(const string &nombre_archivo);*/


//_____________________________________________________COMIENZO DE LA FUNCION MAIN___________________________________________
//---------------------------------------------------------------------------------------------------------------------------


int main() {//-------------------->MAIN(): INT C, INT OPCION;
	/*
	1_DECLARACION VARIABLES LOCALES;
	2_DO------------------------------------>REPITE MIENTRAS NO SEA OPCION 4
	____2.1SWITCH:
		____2.1.1 OPCION N1: CARGAR ARCHIVO ------------>//Y VUELVE AL MENU;
		____2.1.2 OPCION N2: PROCESAR ARCHIVO----------->//Y VUELVE AL MENU;
		____2.1.3 OPCION N3: EMITIR REPORTE------------->//Y VUELVE AL MENU;
		____2.1.4 OPCION N4: SALIR----------------------------------------------------->OPCION 4: FINALIZA
		____2.1.5 OTROS: INVALIDO:
			____2.1.5.1 CONTAR INVALIDOS CONSECUTIVOS
			____2.1.5.2 SI INVALIDOS CONSECUTIVOS LLEGA A 3:
				____2.1.5.2.1 IMPRIME MENSAJE
				____2.1.5.2.2 SELECCIONA AUTOMATICAMENTE OPCION 4 Y SALE---------------->OPCION 4: FINALIZA
			__2.1.5.2__ SI NO LLEGO A 3 INVALIDOS:
				____2.1.5.2.1 IMPRIME MENSAJE //Y VUELVE AL MENU;
	_2_WHILE: EVALUA LA OPCION SI ES 4 PARA SALIR---------------------------------------------------------->FIN DEL PROGRAMA
	*/
	
	// Declaracion de variables Locales Main:
	int c=0; //------->CONTADOR DE ERRORES
	int opcion;//----->OPCIONES DEL MENU
	Nodo* tabla[num_ciudades][num_dias] = {NULL};

	
	do {
		cout << "------------------------------------------------------------------------------------------------"<<endl;
		cout << "PRESIONE ENTER PARA CONTINUAR!!!!"<<endl;
		cout << "------------------------------------------------------------------------------------------------"<<endl;
		cin.get();
		system("cls");
        mostrarMenu(); // Llamamos a la función de menú para mostrar las opciones
        cout << endl;
		cout << "Selecciona una opcion: ";
        cin >> opcion;
        cout << "------------------------------------------------------------------------------------------------"<<endl;
		cout << "PRESIONE ENTER PARA CONTINUAR!!!!"<<endl;
		cout << "------------------------------------------------------------------------------------------------"<<endl;
		cin.get();
		system("cls");

        switch (opcion){
            
			case 1:
				cargar_archivo(nombre_archivo);
                c=0;
                break;
			case 2:
                procesar_archivo(nombre_archivo, tabla);
                /*mostrar_reservas(nombre_archivo);*/
                c=0;
				break;
		    case 3:
                emitir_reporte(tabla);
                c=0;
                break;
			case 4:
                cout << "Saliendo del programa." << endl;
                break;
			default://-------------------------->En caso de valores invalidos
            c++; //----------------------------->Cuenta errores consecutivos
                if (c == 3){//------------------>Si tenes 3 errores sale del programa
                	cout << "------------------------------------------------------------------------------------------------"<<endl;
                	cout << "Ya ha intentado 3 veces consecutivas una opcion incorrecta... " << endl;
                	cout << "¡¡¡Ud debe aprender a leer consignas!!!" << endl;
                	cout << "¡¡¡DE TODOS LOS USUARIOS QUE TUVE USTED FUE EL PEOR!!!" << endl;
					cout << "PRESIONE ENTER PARA CONTINUAR!!!!"<<endl;
					cout << "------------------------------------------------------------------------------------------------"<<endl;
					cin.get();
                	cout << "Saliendo del programa." << endl;
                	opcion = 4;
				}
            	else {//------------------------------------>Si falla sin llegar a 3
            	cout << "------------------------------------------------------------------------------------------------"<<endl;
                cout << "Opción no valida. Intentalo de nuevo." << endl;
                cout << "------------------------------------------------------------------------------------------------"<<endl;
                }
				break;
		}
    }while (opcion != 4);//--------------------->Mostrar Menu hasta que solicite salir o falles 3 veces en el MENU
	return 0;
}

//_______________________________________________________FIN DE LA FUNCION MAIN______________________________________________
//---------------------------------------------------------------------------------------------------------------------------


void mostrarMenu() { //------------------------------------------------------->FUNCION MOSTRAR MENU()
    
    cout << "__MENU:__" << std::endl;
    cout << "1. Cargar archivo" << endl;
    cout << "2. Procesar archivo" << endl;
    cout << "3. Emitir reporte" << endl;
    cout << "4. Salir" << endl;
}

//___________________________________________________________________________________________________________________________________

void cargar_archivo(const string &nombre_archivo){ //------------------------->CARGAR_ARCHIVO(&NOMBRE_ARCHIVO): Reserva reserva; INT v=1;
	
	/*La función cargar_archivo: debe recibir a través de sus parámetros el archivo abierto
	RESERVAS.DAT, y solicitarle al usuario que ingrese los datos para grabar en el mismo*/
    
    //VARIABLES LOCALES:
    Reserva reserva;
    int v=1; //bandera de validez
    
	// Abrir el archivo en modo de escritura binaria;	
	ofstream file(nombre_archivo.c_str(), ios::binary);

    if (!file.is_open()) {
        cout << "Error al abrir el archivo." << endl;
        return;
    }


    do{//-----------------------------------------> PRIMER VALOR O SALIR DEL REGISTRO
    	v=1;
		cout << "Ingrese el codigo de la ciudad (0..99) o -1 para terminar: ";
    	cin >> reserva.cod_ciudad;
    	if(reserva.cod_ciudad<-1 || reserva.cod_ciudad>99){
    		cout << "ERROR!!! HA INGRESADO UN VALOR INCORRECTO!!! "<< endl;
    		cout << "El valor debe estar comprendido entre -1 y 99 incluidos"<< endl;
    		v=0;
		}
    } while (v==0);//---------------------------------->REPETIR MIENTRAS SEA INVALIDO
    
	while (reserva.cod_ciudad != -1) {
        
        do{//----------------------->INGRESAR DIA HASTA QUE SEA VALIDO
    		v=1;
			cout << "Ingrese el codigo del dia (0..6): ";
    		cin >> reserva.cod_dia;
    		if(reserva.cod_dia<0 || reserva.cod_dia>6){
    			cout << "ERROR!!! HA INGRESADO UN VALOR INCORRECTO!!! "<< endl;
    			cout << "El valor debe estar comprendido entre 0 y 6 incluidos"<< endl;
    			v=0;
				}
    	} while (v==0);

        do{//----------------------->INGRESAR DNI HASTA QUE SEA VALIDO
    		v=1;
			cout << "Ingrese el DNI: ";
    		cin >> reserva.DNI;
    		if(reserva.DNI<20000000){
    			cout << "ERROR!!! HA INGRESADO UN VALOR INCORRECTO!!! "<< endl;
    			cout << "El valor debe ser mayor a 20.000.000"<< endl;
    			v=0;
			}
    	} while (v==0);
    	
		system("cls");//------------> BORRA LA PANTALLA ENTRE REGISTROS
        // Escribir la reserva en el archivo binario------------------>ESCRIBIR REGISTRO EN EL ARCHIVO
        file.write(reinterpret_cast<char*>(&reserva), sizeof(Reserva));
        
	    do{//-----------------------------------> SIGUIENTE VALOR O SALIR DEL REGISTRO
    		v=1;
			cout << "Ingrese el codigo de la ciudad (0..99) o -1 para terminar: ";
    		cin >> reserva.cod_ciudad;
    		if(reserva.cod_ciudad<-1 || reserva.cod_ciudad>99){
    			cout << "ERROR!!! HA INGRESADO UN VALOR INCORRECTO!!! "<< endl;
    			cout << "El valor debe estar comprendido entre -1 y 99 incluidos"<< endl;
    			v=0;
			}
    	} while (v==0);
    }

    file.close();//----------------------------->UNA VEZ QUE SALIMOS DEL REGISTRO SE CIERRA EL ARCHIVO
}

//____________________________________________________________________________________________________________________________________

void procesar_archivo(const string &nombre_archivo, Nodo* tabla[num_ciudades][num_dias]){//------------------------->PROCESAR_ARCHIVO(): Reserva reserva; INT v=1;
	
	/*La función procesar_archivo: que tiene dos parámetros, de entrada el archivo que se
	generó en el punto anterior, y de salida la matriz donde se cargarán los punteros.*/
	int c=0;
	cout << "Procesando Archivo..."<< endl;
	Reserva reserva;//-------------------->Declaracion de variable local en el ambito de reserva
    ifstream file(nombre_archivo.c_str(), ios::in | ios::binary);//--------->Apertura de archivo
    if (!file.is_open()) {//------------------------------------------------>Verificacion apertura.
        cout << "Error al abrir el archivo." << endl;
        return;
    }
    while (file.read(reinterpret_cast<char*>(&reserva), sizeof(Reserva))) {
    	c++;
        cout <<"Procesando Registro N"<<c<< "... Ciudad: " << reserva.cod_ciudad << ", Dia: " << reserva.cod_dia << ", DNI: " << reserva.DNI << endl;
        insertar_lista(tabla[reserva.cod_ciudad][reserva.cod_dia],reserva.DNI);//----------->tabla[i,j] es puntero y reserva.dni es dato nuevo.
    }
    cout <<"SE A FINALIZADO EL PROCESAMIENTO DE REGISTROS CON EXITO !"<<endl;
}//-------------------------------->Fin de PROCESAR_ARCHIVO()

//____________________________________________________________________________________________________________________________________
        
void insertar_lista(Nodo* &p, int DNI){        //-------------------------------------------------------->Declaracion local insertar_lista()
	Nodo* nuevo = new Nodo();//-------Nuevo es una direccion, no tiene campos, apunta a campos
		//si p apunta a un nodo
	if (p != NULL){//----> p apunta a una lista
		nuevo -> sig = p;//---------->Guarda el comienzo de la lista en la direccion apuntada por nuevo
		nuevo -> dni = DNI;//-------->Guarda el dato en la direccion apuntada por nuevo
		p = nuevo;//----------------->Guarda en la tabla la direccion de un nuevo Nodo
	}
	else{//-----------------> p NO apunta a una lista, apunta a NULL
		nuevo -> sig = NULL;//------->Asigna NULL a la direccion apuntada por nuevo para establecer el primer elemento de la lista
		nuevo -> dni = DNI;//-------->Guarda el dato en la direccion apuntada por nuevo
		p = nuevo;//----------------->Guarda en la tabla la direccion de un nuevo Nodo
	}	
}//---------------------------->Fin de INSERTAR_LISTA()
	
//____________________________________________________________________________________________________________________________________

void emitir_reporte(Nodo* tabla[num_ciudades][num_dias]){
	/*La función emitir_reporte: que recibe la matriz creada en el punto anterior e imprime
	por pantalla un listado ordenado por cod_ciudad ascendente, con la cantidad total de
	reservas efectuadas para cada ciudad.*/
	int i, j, b=0, cuenta=0;
	cout << "Emitiendo Reporte..."<< endl;
	for(i=0;i<num_ciudades;i++){
		cuenta = 0;
		for(j=0;j<num_dias;j++){
			if (tabla [i][j]!=NULL){
				if (b!=1){
					cout << "Para la Ciudad N" << i<<" :"<< endl;//--------->Solo se presentara un resultado si hay registros
					b=1;//-------------------------------------------------->Sistema de bandera para que no se repita el dia.
				}
				cout << "Se anotaron el dia N" << j <<" :"<< endl;
				mostrar(tabla[i][j], cuenta);
				liberar(tabla[i][j]);
			}
		}
		if (b==1){
			cout << "Para la Ciudad N " << i<<" la cantidad de Reservas es de: "<< cuenta << endl;
		}
		b=0;
	}
}

void mostrar(Nodo* p, int &c) {
	Nodo* aux = p;
	while( aux!=NULL ) {
		cout << aux->dni << endl;
		aux = aux->sig;
		c= c+1;
	}
}

void liberar(Nodo*& p) {
	Nodo* aux;
	while ( p!=NULL ){
		aux = p; p = p->sig; delete aux;
		}
}


/*/____________________________________________________________________________________________________________________________________

void mostrar_reservas(const string &nombre_archivo) {//---------------------------------->MOSTRAR RESERVAS(&NOMBRE_ARCHIVOS): RESERVA
	// Declaracion de variable local en el ambito de reserva
	Reserva reserva;
	cout << "Ejecutando mostrar_reservas()" << endl;
	//Apertura de Archivo
    ifstream file(nombre_archivo.c_str(), ios::in | ios::binary);
    

    if (!file.is_open()) {
        cout << "Error al abrir el archivo." << endl;
        return;
    }

    while (file.read(reinterpret_cast<char*>(&reserva), sizeof(Reserva))) {
        cout << "Ciudad: " << reserva.cod_ciudad << ", Día: " << reserva.cod_dia << ", DNI: " << reserva.DNI << endl;
    }

    file.close();
}

//_____________________________________________________________________________________________________________________________________
*/

