// peliculas cine
#include "peliculas.h"
#include "bitacora.h"
#include "login.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <conio.h>
#include <iomanip>
#include <string>

using namespace std;

void MedicoCRUD::CrudMedicos() {
    int choice;
    do {
        system("cls");
        cout << "\t\t\t----------------------------------------------" << endl;
        cout << "\t\t\t| SISTEMA DE CINEPOLIS - GESTION DE PELICULAS |" << endl;
        cout << "\t\t\t----------------------------------------------" << endl;
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
                IngresarMedico();
                system("Pause");
                break;
            case 2:
                system("Cls");
                ModificarMedico();
                system("Pause");
                break;
            case 3:
                system("Cls");
                BorrarMedico();
                system("Pause");
                break;
            case 4:
                DesplegarMedico();
                break;
            case 5:
                break;
            default:
                cout << "\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
                cin.get();
        }
    } while (choice != 5);
}

// Función que valida si ya existe el médico para evitar redundancia de datos
bool MedicoCRUD::ValidarMedico(int codigo) {
    fstream archivo("pelicula.dat", ios::binary | ios::in | ios::out);
    if (!archivo) {
        return false;
    }

    Medico medico;
    bool encontrado = false;
    while (archivo.read(reinterpret_cast<char*>(&medico), sizeof(Medico))) {
        if (medico.codigo == codigo) {
            encontrado = true;
            break;
        }
    }

    archivo.close();

    return encontrado;
}

// Aquí se agregan médicos que son almacenados
void MedicoCRUD::IngresarMedico() {
    string codigoPrograma = "6000";
    system("cls");
    cout << "\n------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "\n-------------------------------------------------Agregar Pelicula--------------------------------------------" << endl;
    Medico medico;
    cout << "Ingrese el codigo de la pelicula: ";
    cin >> medico.codigo;
    cin.ignore();
    if (ValidarMedico(medico.codigo)) {
        system("cls");
        cout << "El codigo de la pelicula ya existe, intente de nuevo!!" << endl << endl << endl << endl;
        return;
    }

    cout << "Ingrese el nombre: ";
    cin.getline(medico.nombre, 50);

    cout << "Ingrese la categoria: ";
    cin.getline(medico.especialidad, 50);

    ofstream archivo("pelicula.dat", ios::binary | ios::app);
    archivo.write(reinterpret_cast<const char*>(&medico), sizeof(Medico));
    archivo.close();

    Bitacora Auditoria;
    string user, pass;

    Auditoria.ingresoBitacora(user, codigoPrograma, "IMED"); // IMED = Insertar Medico

    cout << "Pelicula agregada exitosamente!" << endl;
}

// Modificar médicos
void MedicoCRUD::ModificarMedico() {
    string codigoPrograma = "6000";
    cout << "\n------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "\n------------------------------------------------- Modificacion de Peliculas --------------------------------------------" << endl;
    int codigo;
    cout << "Ingrese el codigo de la pelicula a modificar: ";
    cin >> codigo;

    fstream archivo("pelicula.dat", ios::binary | ios::in | ios::out);
    if (!archivo) {
        cout << "No hay peliculas registradas." << endl;
        return;
    }

    Medico medico;
    bool encontrado = false;
    while (archivo.read(reinterpret_cast<char*>(&medico), sizeof(Medico))) {
        if (medico.codigo == codigo) {
            cout << "Ingrese el nuevo nombre: ";
            cin.ignore();
            cin.getline(medico.nombre, 50);

            cout << "Ingrese la nueva categoria: ";
            cin.getline(medico.especialidad, 50);

            archivo.seekp(-static_cast<int>(sizeof(Medico)), ios::cur);
            archivo.write(reinterpret_cast<const char*>(&medico), sizeof(Medico));

            encontrado = true;
            break;
        }
    }

    archivo.close();

    Bitacora Auditoria;
    string user, pass;

    Auditoria.ingresoBitacora(user, codigoPrograma, "UMED"); // UMED = Update Medico

    if (!encontrado) {
        cout << "No se encontró la pelicula con el codigo ingresado." << endl;
    } else {
        cout << "Pelicula modificada exitosamente!" << endl;
    }
}

void MedicoCRUD::BorrarMedico() {
    string codigoPrograma = "6000";
    int codigo;
    cout << "\n------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "\n-------------------------------------------------Eliminar Pelicula------------------------------------------------------" << endl;
    cout << "Ingrese el codigo de la pelicula a eliminar: ";
    cin >> codigo;

    ifstream archivo("pelicula.dat", ios::binary);
    if (!archivo) {
        cout << "No hay pelicula registradas." << endl;
        return;
    }

    ofstream archivoTmp("pelicula_tmp.dat", ios::binary);
    Medico medico;
    bool eliminado = false;
    while (archivo.read(reinterpret_cast<char*>(&medico), sizeof(Medico))) {
        if (medico.codigo != codigo) {
            archivoTmp.write(reinterpret_cast<const char*>(&medico), sizeof(Medico));
        } else {
            eliminado = true;
        }
    }

    archivo.close();
    archivoTmp.close();

    remove("pelicula.dat");
    rename("pelicula_tmp.dat", "pelicula.dat");

    Bitacora Auditoria;
    string user, pass;

    Auditoria.ingresoBitacora(user, codigoPrograma, "DMED"); // DMED = Delete Medico

    if (eliminado) {
        cout << "Pelicula eliminada exitosamente!" << endl;
    } else {
        cout << "No se encontró la pelicula con el codigo ingresado." << endl;
    }
}

void MedicoCRUD::DesplegarMedico() {
    system("cls");
    string codigoPrograma = "6000";
    cout << "-----------------Despliegue de Peliculas registradas---------------------" << endl;
    ifstream archivo("pelicula.dat", ios::binary);
    if (!archivo) {
        cout << "No hay peliculas registradas." << endl;
        return;
    }

    Medico medico;
    while (archivo.read(reinterpret_cast<char*>(&medico), sizeof(Medico))) {
        cout << "Codigo: " << medico.codigo << endl;
        cout << "Nombre: " << medico.nombre << endl;
        cout << "Categoria: " << medico.especialidad << endl;
        cout << "-----------------------------" << endl;
    }

    archivo.close();

    Bitacora Auditoria;
    string user, pass;

    Auditoria.ingresoBitacora(user, codigoPrograma, "RMED"); // RMED = Read Medico

    cout << "Presione Enter para continuar...";
    cin.ignore();
    cin.get();
}

