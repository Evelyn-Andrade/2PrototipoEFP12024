//menu cine
#include "menu.h"
#include "entrenador.h"
#include "horario.h"
#include "Salas.h"
#include "peliculas.h"
#include "usuarios.h"
#include "Bitacora.h"
#include "resultados.h"
#include "Login.h"
#include <iostream>
#include <windows.h>

using namespace std;

menu::menu()
{
    //ctor
}

void menu::MenuGeneral()
{
    system("cls");
    int opc;

    do
    {
        cout << "\n";
        cout << "\t+------------------------------------------+" << endl;
        cout << "\t|\t\t            \t\t   |" << endl;
        cout << "\t|  Evelyn Sofia Andrade Luna \t9959-23-1224       |" << endl;
        cout << "\t|\t\t            \t\t   |" << endl;
        cout << "\t|\t\tMenu general\t\t   |" << endl;
        cout << "\t|\t\t            \t\t   |" << endl;
        cout << "\t+------------------------------------------+" << endl;
        cout << "\t|\t\t            \t\t   |" << endl;
        cout << "\t|\t\t1) Catalogos\t\t   |" << endl;
        cout << "\t|\t\t            \t\t   |" << endl;
        cout << "\t|\t\t2) Procesos \t\t   |" << endl;
        cout << "\t|\t\t            \t\t   |" << endl;
        cout << "\t|\t\t3) Reportes \t\t   |" << endl;
        cout << "\t|\t\t            \t\t   |" << endl;
        cout << "\t|\t    4) Salir del Programa\t   |" << endl;
        cout << "\t|\t\t            \t\t   |" << endl;
        cout << "\t+------------------------------------------+" << endl;
        cout << "\n" << endl;
        cout << "\t\tIngrese el numero de opcion: ";
        cin >> opc;

        switch(opc)
        {
        case 1:
            system("cls");
            Catalogos();
            system("pause");
            system("cls");
            break;
        case 2:
            system("cls");
            Procesos();
            system("pause");
            system("cls");
            break;
        case 3:
            system("cls");
            Reportes();
            system("pause");
            system("cls");
            break;
        case 4:
            exit(0);
            break;
        default:
            cout << "\n\t Opcion invalida...Por favor prueba otra vez..";
            cin.ignore();
            cin.get();
            system("cls");
        }
    } while (opc!=4);
}

void menu::Catalogos()
{
    system("cls");
    int opc;

    do
    {
        cout << "\n";
        cout << "\t+------------------------------------------+" << endl;
        cout << "\t|\t\t            \t\t   |" << endl;
        cout << "\t|\t     Menu de Catalogos\t\t   |" << endl;
        cout << "\t|\t\t            \t\t   |" << endl;
        cout << "\t+------------------------------------------+" << endl;
        cout << "\t|\t\t            \t\t   |" << endl;
        cout << "\t|\t\t1) Clientes\t\t   |" << endl;
        cout << "\t|\t\t            \t\t   |" << endl;
        cout << "\t|\t\t2) Salas\t\t   |" << endl;
        cout << "\t|\t\t            \t\t   |" << endl;
        cout << "\t|\t\t3) Peliculas \t\t   |" << endl;
        cout << "\t|\t\t            \t\t   |" << endl;
        cout << "\t|\t\t4) Horarios\t\t   |" << endl;
        cout << "\t|\t\t            \t\t   |" << endl;
        cout << "\t|\t\t            \t\t   |" << endl;
        cout << "\t|\t\t5) Usuarios\t\t   |" << endl;
        cout << "\t|\t\t            \t\t   |" << endl;
        cout << "\t|\t    6) Regresar al Menu\t\t   |" << endl;
        cout << "\t|\t\t            \t\t   |" << endl;
        cout << "\t|\t    7) Salir del Programa\t   |" << endl;
        cout << "\t|\t\t            \t\t   |" << endl;
        cout << "\t+------------------------------------------+" << endl;
        cout << "\n" << endl;
        cout << "\t\tIngrese el numero de opcion: ";
        cin >> opc;

        switch(opc)
        {
        case 1:
        {
            entrenador entrena;
            entrena.menu();
        }
            break;
        case 2:
        {
            ClinicaCRUD CClinicas;
            CClinicas.CrudClinicas();
        }
            break;
        case 3:
        {
           MedicoCRUD MMedico;
           MMedico.CrudMedicos();
        }
            break;
        case 4:
         {
            HorarioCRUD HHorario;
            HHorario.CrudHorarios();
        }
            break;
        case 5  :
        {
            usuarios usu;
            usu.menu();
        }
            break;
        case 6:
            MenuGeneral();
        case 7:
            exit(0);
            break;
        default:
            cout << "\n\t Opcion invalida...Por favor prueba otra vez..";
            cin.ignore();
            cin.get();
            system("cls");
        }
    } while (opc!=8);
}

void menu::Procesos()
{
     system("cls");
    int opc;

    do
    {
        system("cls");
        cout << "\n";
        cout << "\t+------------------------------------------+" << endl;
        cout << "\t|\t\t            \t\t   |" << endl;
        cout << "\t|\t     Menu de Procesos\t\t   |" << endl;;
        cout << "\t|\t\t            \t\t   |" << endl;
        cout << "\t+------------------------------------------+" << endl;
        cout << "\t|\t\t            \t\t   |" << endl;
        cout << "\t|\t\t1) Registrar Funcion \t\t   |" << endl;
        cout << "\t|\t\t            \t\t   |" << endl;
        cout << "\t|\t\t2) Bitacora \t\t   |" << endl;
        cout << "\t|\t\t            \t\t   |" << endl;
        cout << "\t|\t    3) Regresar al menu\t\t   |" << endl;
        cout << "\t|\t\t            \t\t   |" << endl;
        cout << "\t+------------------------------------------+" << endl;
        cout << "\n" << endl;
        cout << "\t\tIngrese el numero de opcion: ";
        cin >> opc;

        switch(opc)
        {
        case 1:{
            resultados RResultado;
            RResultado.Menu_alumno();

        }
            break;
        case 2:
            {
                Bitacora bitacora;
                bitacora.mostrarBitacora();
                break;
            }
        case 3:
            MenuGeneral();
        default:
            cout << "\n\t Opcion invalida...Por favor prueba otra vez..";
            cin.ignore();
            cin.get();
            system("cls");
        }
    } while (opc!=3);
}

void menu::Reportes()
{
     system("cls");
    Bitacora bitacora; // Creamos un objeto Bitacora

    int opcion;
    string usuario;

    do {
        system("cls");
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\t|   Submenu Reportes          |"<< endl;
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\t 1. Generar reporte completo" << endl;
        cout << "\t\t\t 2. Generar reporte por usuario" << endl;
        cout << "\t\t\t 3. Salir" << endl;
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\t|Opcion a escoger:[1/2/3]     |" << endl;
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\tSeleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                 system("cls");
                bitacora.generarReporteCompleto(); // Llamamos al método para generar reporte completo
                system("pause");
                break;
            case 2:
                 system("cls");
                cout << "Ingrese el nombre de usuario para generar el reporte: ";
                cin >> usuario;
                bitacora.generarReportePorUsuario(usuario); // Llamamos al método para generar reporte por usuario
                system("pause");
                break;
            case 3:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción no válida. Por favor, seleccione una opción válida." << endl;
                break;
        }
    } while (opcion != 3);
}
