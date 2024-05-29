// horario cine
#include "horario.h"
#include "bitacora.h"
#include "login.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <conio.h>
#include <iomanip>
#include <string>

using namespace std;

void HorarioCRUD::CrudHorarios() {
    int choice;
    do {
        system("cls");
        cout << "\t\t\t--------------------------------------------" << endl;
        cout << "\t\t\t| SISTEMA DE CINE - GESTION DE HORARIOS    |" << endl;
        cout << "\t\t\t--------------------------------------------" << endl;
        cout << "\t\t\t 1. Ingresar" << endl;
        cout << "\t\t\t 2. Modificar" << endl;
        cout << "\t\t\t 3. Borrar" << endl;
        cout << "\t\t\t 4. Desplegar" << endl;
        cout << "\t\t\t 5. Regresar Menu Anterior" << endl;
        cout << "\t\t\t --------------------------------------------" << endl;
        cout << "\t\t\t |   Opcion a escoger:[1|2|3|4|5|]           |" << endl;
        cout << "\t\t\t --------------------------------------------" << endl;
        cout << "\t\t\tIngresa tu Opcion: ";
        cin >> choice;

        switch (choice) {
            case 1:
                IngresarHorario();
                system("Pause");
                break;
            case 2:
                system("Cls");
                ModificarHorario();
                system("Pause");
                break;
            case 3:
                system("Cls");
                BorrarHorario();
                system("Pause");
                break;
            case 4:
                DesplegarHorario();
                break;
            case 5:
                break;
            default:
                cout << "\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
                cin.get();
        }
    } while (choice != 5);
}

// Función que valida si ya existe el horario para evitar redundancia de datos
bool HorarioCRUD::ValidarHO(int codigo) {
    fstream archivo("Horario.dat", ios::binary | ios::in | ios::out);
    if (!archivo) {
        return false;
    }

    Horario horario;
    bool encontrada = false;
    while (archivo.read(reinterpret_cast<char*>(&horario), sizeof(Horario))) {
        if (horario.codigo == codigo) {
            encontrada = true;
            break;
        }
    }

    archivo.close();

    return encontrada;
}

// Aquí se agregan horarios que son almacenados
void HorarioCRUD::IngresarHorario() {
    string codigoPrograma = "4000";
    system("cls");
    cout << "\n------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "\n-------------------------------------------------Agregar Horario--------------------------------------------" << endl;
    Horario horario;
    cout << "Ingrese el codigo del horario: ";
    cin >> horario.codigo;
    cin.ignore();
    if (ValidarHO(horario.codigo)) {
        system("cls");
        cout << "El codigo del horario ya existe, intente de nuevo!!" << endl << endl << endl << endl;
        return;
    }

    cout << "Ingrese el dia: ";
    cin.getline(horario.dia, 50);

    cout << "Ingrese la hora: ";
    cin.getline(horario.hora, 50);

    ofstream archivo("Horario.dat", ios::binary | ios::app);
    archivo.write(reinterpret_cast<const char*>(&horario), sizeof(Horario));
    archivo.close();

    Bitacora Auditoria;
    string user, pass;

    Auditoria.ingresoBitacora(user, codigoPrograma, "IHO"); // IHO = Insertar Horario

    cout << "Horario agregado exitosamente!" << endl;
}

// Modificar horarios
void HorarioCRUD::ModificarHorario() {
    string codigoPrograma = "4000";
    cout << "\n------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "\n-------------------------------------------------Modificacion de Horarios--------------------------------------------" << endl;
    int codigo;
    cout << "Ingrese el codigo del horario a modificar: ";
    cin >> codigo;

    fstream archivo("Horario.dat", ios::binary | ios::in | ios::out);
    if (!archivo) {
        cout << "No hay horarios registrados." << endl;
        return;
    }

    Horario horario;
    bool encontrada = false;
    while (archivo.read(reinterpret_cast<char*>(&horario), sizeof(Horario))) {
        if (horario.codigo == codigo) {
            cout << "Ingrese el nuevo dia: ";
            cin.ignore();
            cin.getline(horario.dia, 50);

            cout << "Ingrese la nueva hora: ";
            cin.getline(horario.hora, 50);

            archivo.seekp(-static_cast<int>(sizeof(Horario)), ios::cur);
            archivo.write(reinterpret_cast<const char*>(&horario), sizeof(Horario));

            encontrada = true;
            break;
        }
    }

    archivo.close();

    Bitacora Auditoria;
    string user, pass;

    Auditoria.ingresoBitacora(user, codigoPrograma, "UHO"); // UHO = Update Horario

    if (!encontrada) {
        cout << "No se encontró el horario con el codigo ingresado." << endl;
    } else {
        cout << "Horario modificado exitosamente!" << endl;
    }
}

void HorarioCRUD::BorrarHorario() {
    string codigoPrograma = "4000";
    int codigo;
    cout << "\n------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "\n-------------------------------------------------Eliminar Horarios--------------------------------------------" << endl;
    cout << "Ingrese el codigo del horario a eliminar: ";
    cin >> codigo;

    ifstream archivo("Horario.dat", ios::binary);
    if (!archivo) {
        cout << "No hay horarios registrados." << endl;
        return;
    }

    ofstream archivoTmp("Horario_tmp.dat", ios::binary);
    Horario horario;
    bool eliminada = false;
    while (archivo.read(reinterpret_cast<char*>(&horario), sizeof(Horario))) {
        if (horario.codigo != codigo) {
            archivoTmp.write(reinterpret_cast<const char*>(&horario), sizeof(Horario));
        } else {
            eliminada = true;
        }
    }

    archivo.close();
    archivoTmp.close();

    remove("Horario.dat");
    rename("Horario_tmp.dat", "Horario.dat");

    Bitacora Auditoria;
    string user, pass;

    Auditoria.ingresoBitacora(user, codigoPrograma, "DHO"); // DHO = Delete Horario

    if (eliminada) {
        cout << "Horario eliminado exitosamente!" << endl;
    } else {
        cout << "No se encontró el horario con el codigo ingresado." << endl;
    }
}

void HorarioCRUD::DesplegarHorario() {
    system("cls");
    string codigoPrograma = "4000";
    cout << "-----------------Despliegue de horarios registrados---------------------" << endl;
    ifstream archivo("Horario.dat", ios::binary);
    if (!archivo) {
        cout << "No hay horarios registrados." << endl;
        return;
    }

    Horario horario;
    while (archivo.read(reinterpret_cast<char*>(&horario), sizeof(Horario))) {
        cout << "Codigo: " << horario.codigo << endl;
        cout << "Dia: " << horario.dia << endl;
        cout << "Hora: " << horario.hora << endl;
        cout << "-----------------------------" << endl;
    }

    archivo.close();

    Bitacora Auditoria;
    string user, pass;

    Auditoria.ingresoBitacora(user, codigoPrograma, "RHO"); // RHO = Read Horario

    cout << "Presione Enter para continuar...";
    cin.ignore();
    cin.get();
}
