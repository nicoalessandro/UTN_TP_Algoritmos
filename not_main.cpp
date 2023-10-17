#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// Definir una estructura para almacenar las reservas
struct Reserva {
    int cod_ciudad;
    int cod_dia;
    int DNI;
};

// Funci�n para cargar el archivo RESERVAS.DAT
void cargar_archivo(ofstream& file) {
    Reserva reserva;
    int siguiente;

    while (true) {
        cout << "Ingrese el codigo de la ciudad (0..99) o -1 para terminar: "<< endl;
        cin >> siguiente;

        if (siguente >=0 && siguiente < 100) {

            reserva.cod_ciudad = siguiente;
 
            cout << "Ingrese el código del día (0..6): "<< endl;
            cin >> reserva.cod_dia;

            cout << "Ingrese el DNI (integer): "<< endl;
            cin >> reserva.DNI;   

        }
        else {

            if (siguiente > 0) {
                //si elige un numero mayor a 99...
                cout << "El número ingresado supera el código máximo utilizado"<< endl;
            }

            else {
                //si elige un numero menor a 0...
                cout << "Usted a Terminado de ingresar los datos..."<< endl;
            }
        }// finaliza funcion de carga de archivo RESERVAS.DAT



        // Escribir la reserva en el archivo binario
        file.write(reinterpret_cast<char*>(&reserva), sizeof(Reserva));
    }
}

// Funci�n para procesar el archivo y generar el informe
void procesar_archivo(ifstream& file) {
    vector<vector<int>> reservas(100, vector<int>(7, 0)); // Matriz para almacenar las reservas por ciudad y d�a

    Reserva reserva;

    while (file.read(reinterpret_cast<char*>(&reserva), sizeof(Reserva))) {
        if (reserva.cod_ciudad >= 0 && reserva.cod_ciudad < 100 && reserva.cod_dia >= 0 && reserva.cod_dia < 7) {
            reservas[reserva.cod_ciudad][reserva.cod_dia]++;
        }
    }

    // Llamar a la función para emitir el informe
    emitir_reporte(reservas);
}

// Función para emitir el informe
void emitir_reporte(const vector<vector<int>>& reservas) {
    cout << "Informe de reservas por ciudad y día:" << endl;

    for (int ciudad = 0; ciudad < 100; ciudad++) {
        int total_reservas_ciudad = 0;

        for (int dia = 0; dia < 7; dia++) {
            total_reservas_ciudad += reservas[ciudad][dia];
        }

        cout << "Ciudad " << ciudad << ": " << total_reservas_ciudad << " reservas." << endl;
    }
}

int main() {
    while (true) {
        cout << "Menú:" << endl;
        cout << "1. Cargar archivo" << endl;
        cout << "2. Procesar archivo" << endl;
        cout << "3. Emitir reporte" << endl;
        cout << "4. Salir" << endl;
        int opcion;
        cin >> opcion;

        if (opcion == 1) {
            // Opción 1: cargar datos en el archivo
            ofstream file("RESERVAS.DAT", ios::binary | ios::app);
            cargar_archivo(file);
            file.close();
        } else if (opcion == 2) {
            // Opción 2: procesar el archivo
            ifstream file("RESERVAS.DAT", ios::binary);
            procesar_archivo(file);
            file.close();
        } else if (opcion == 3) {
            // Opción 3: emitir el informe
            ifstream file("RESERVAS.DAT", ios::binary);
            procesar_archivo(file);
            file.close();
        } else if (opcion == 4) {
            // Opción 4: salir del programa
            break;
        } else {
            cout << "Opción no válida. Inténtalo de nuevo." << endl;
        }
    }

    return 0;
}
