#include <iostream>//Necesario para interactuar con el Usuario en Gral.
#include <fstream> //Necesario para funcion CARGAR ARCHIVO.
#include <string>

using namespace std;

//Declaracion de VARIABLES GLOBALES_______________________________________________________________________________________________

string nombre_archivo = "reservas.dat";

//Declaracion de ESTRUCTURAS GLOBALES_____________________________________________________________________________________________

struct Reserva {
    int cod_ciudad;
    int cod_dia;
    int DNI;
};


//Declaracion de FUNCIONES________________________________________________________________________________________________________

void mostrarMenu();
void cargar_archivo(const string &nombreArchivo);
void procesar_archivo();
void emitir_reporte();
void mostrar_reservas(const string &nombreArchivo);
/*void verificar_archivo(const string &nombre_archivo);*/


//PROGAMA PRINCIPAL______________________________________________________________________________________________________________________
int main() {//___________________________________________________COMIENZO DE LA FUNCION MAIN_____________________________________________
	
	// Declaracion de variables Locales Main:
	int c=0; int opcion;
	
	do {
        mostrarMenu(); // Llamamos a la función de menú para mostrar las opciones
        cout << "Selecciona una opción: ";
        cin >> opcion;

        switch (opcion){
            
			
			case 1:// Realiza acciones para la opción 1: CARGAR ARCHIVO--------------------------------------------------
                
				/*verificar_archivo(nombre_archivo);*/
				cargar_archivo(nombre_archivo);
                
                c=0; //REINICIA CONTADOR DE ERROR CONSECUTIVO;
                break;//__________________________________________fin de case 1:___________________________________________________
            
            
			
			case 2:// Realiza acciones para la opción 2: PROCESAR ARCHIVO-----------------------------------------------
                
                procesar_archivo();
                mostrar_reservas(nombre_archivo);
                
                c=0; //REINICIA CONTADOR DE ERROR CONSECUTIVO;
                break;//__________________________________________fin de case 2:___________________________________________________*/
            
           
		   
		    case 3:// Realiza acciones para la opción 3: EMITIR REPORTE----------------------------------------------------------
                
                emitir_reporte();
                
                c=0; //REINICIA CONTADOR DE ERROR CONSECUTIVO;
                break;//_________________________________________fin de case 3:___________________________________________________
            
			
			case 4:// Realiza acciones para la opción 4: SALIR---------------------------------------------------------------------
                cout << "Saliendo del programa." << endl;
				
                break;
            
			default:
            	
            	/*Si el usuario comete menos de 3 errores consecutivos vuelve a solicitar el ingreso del menu.
				De lo contrario saldra de menera directa como si hubiera seleccionado la opcion 4*/
				
                c++; // CONTADOR
                
                if (c == 3){
					
					//Se ejecuta si el usuario HA FALLADO por 3ra vez consecutiva;
                	cout << "Ya ha intentado 3 veces consecutivas una opcion incorrecta... " << endl;
                	cout << "¡¡¡Ud debe aprender a leer consignas!!!" << endl;
                	cout << "¡¡¡DE TODOS LOS USUARIOS QUE TUVE USTED FUE EL PEOR!!!" << endl;
                	cout << "Saliendo del programa." << endl;
                	opcion = 4;
				}
				
            	else {
				
				//se ejecuta si el usuario NO ha fallado por 3ra vez consecutiva;
                cout << "Opción no válida. Inténtalo de nuevo." << endl;
                }
				break;
		}
    }while (opcion != 4);
	return 0;
} /*_____________________________________________________FIN DE LA FUNCION MAIN____________________________________________*/

//Codigo de MostrarMenu()

void mostrarMenu() { // Muestra las opciones del menú;-------------------------------------------
    
    cout << "Menú:" << std::endl;
    cout << "1. Cargar archivo" << endl;
    cout << "2. Procesar archivo" << endl;
    cout << "3. Emitir reporte" << endl;
    cout << "4. Salir" << endl;
}
//----------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------FIN DE LA FUNCION-----------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------








//________________________________________________________FUNCION CARGAR_ARCHIVO()_____________________________________________
//_____________________________________________________________________________________________________________________________
//_____________________________________________________________________________________________________________________________



void cargar_archivo(const string &nombre_archivo){
	/*La función cargar_archivo: debe recibir a través de sus parámetros el archivo abierto
	RESERVAS.DAT, y solicitarle al usuario que ingrese los datos para grabar en el mismo*/
    
    //Declaracion de variables locales en el ambito de cargar_archivo:
    Reserva reserva;
    int v=1; //bandera de validez
    
    
	// Abrir el archivo en modo de escritura binaria;	
	ofstream file(nombre_archivo.c_str(), ios::binary);

    if (!file.is_open()) {
        cout << "Error al abrir el archivo." << endl;
        return;
    }


	//La primera solicitud sirve de validacion para el primer ingreso al ciclo;
    do{
    	v=1;
		cout << "Ingrese el código de la ciudad (0..99) o -1 para terminar: ";
    	cin >> reserva.cod_ciudad;
    	if(reserva.cod_ciudad<-1 || reserva.cod_ciudad>99){
    		cout << "ERROR!!! HA INGRESADO UN VALOR INCORRECTO!!! "<< endl;
    		cout << "El valor debe estar comprendido entre -1 y 99 incluidos"<< endl;
    		v=0;
		}
    } while (v==0);
    

	while (reserva.cod_ciudad != -1) {
        
        do{
    		v=1;
			cout << "Ingrese el código del día (0..6): ";
    		cin >> reserva.cod_dia;
    		if(reserva.cod_dia<0 || reserva.cod_dia>6){
    			cout << "ERROR!!! HA INGRESADO UN VALOR INCORRECTO!!! "<< endl;
    			cout << "El valor debe estar comprendido entre 0 y 6 incluidos"<< endl;
    			v=0;
				}
    	} while (v==0);

        do{
    		v=1;
			cout << "Ingrese el DNI: ";
    		cin >> reserva.DNI;
    		if(reserva.DNI<20000000){
    			cout << "ERROR!!! HA INGRESADO UN VALOR INCORRECTO!!! "<< endl;
    			cout << "El valor debe ser mayor a 20.000.000"<< endl;
    			v=0;
			}
    	} while (v==0);

        // Escribir la reserva en el archivo binario
        file.write(reinterpret_cast<char*>(&reserva), sizeof(Reserva));
        
        //Se ingresa el codigo que servira al siguiente ciclo;
	    do{
    		v=1;
			cout << "Ingrese el código de la ciudad (0..99) o -1 para terminar: ";
    		cin >> reserva.cod_ciudad;
    		if(reserva.cod_ciudad<-1 || reserva.cod_ciudad>99){
    			cout << "ERROR!!! HA INGRESADO UN VALOR INCORRECTO!!! "<< endl;
    			cout << "El valor debe estar comprendido entre -1 y 99 incluidos"<< endl;
    			v=0;
			}
    	} while (v==0);
    }

    file.close();
}
//----------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------FIN DE LA FUNCION-----------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------










//_______________________________________________FUNCION VERIFICAR_ARCHIVO()___________________________________________________
//_____________________________________________________________________________________________________________________________
//_____________________________________________________________________________________________________________________________

/*void verificar_archivo(const string &nombre_archivo) {
    // Verificar si el archivo existe
    ifstream archivoVerificar(const &nombre_archivo);
    
    if (!archivoVerificar.is_open()) {
        // El archivo no existe, lo creamos
        ofstream file(const &nombre_archivo, ios::binary);
        
        if (!file.is_open()) {
            cout << "Error al crear el archivo." << endl;
            return;
        }

        file.close();
        cout << "Archivo creado con éxito." << endl;
    } else {
        archivoVerificar.close();
        // El archivo ya existe, puedes abrirlo y realizar las operaciones necesarias.
        // Aquí agregarías la lógica para cargar datos en el archivo existente.
        // ...
    }
}*/
//----------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------FIN DE LA FUNCION-----------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------









//_______________________________________________FUNCION PROCESAR_ARCHIVO()____________________________________________________
//_____________________________________________________________________________________________________________________________
//_____________________________________________________________________________________________________________________________


void procesar_archivo(){
	/*La función procesar_archivo: que tiene dos parámetros, de entrada el archivo que se
	generó en el punto anterior, y de salida la matriz donde se cargarán los punteros.*/
	cout << "Procesando Archivo..."<< endl;
	}
//----------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------FIN DE LA FUNCION-----------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------








//________________________________________________________FUNCION EMITIR_REPORTE()_____________________________________________
//_____________________________________________________________________________________________________________________________
//_____________________________________________________________________________________________________________________________


void emitir_reporte(){
	/*La función emitir_reporte: que recibe la matriz creada en el punto anterior e imprime
	por pantalla un listado ordenado por cod_ciudad ascendente, con la cantidad total de
	reservas efectuadas para cada ciudad.*/
	cout << "Emitiendo Reporte..."<< endl;
	
	}
//----------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------FIN DE LA FUNCION-----------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------

	
	
	
	
	
	
	
	
//________________________________________________________FUNCION MOSTRAR_RESERVAS()____________________________________________
//_____________________________________________________________________________________________________________________________
//_____________________________________________________________________________________________________________________________
	
void mostrar_reservas(const string &nombre_archivo) {
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
//----------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------FIN DE LA FUNCION-----------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------


