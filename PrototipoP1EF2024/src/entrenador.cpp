// clientes cine
#include "entrenador.h"
#include "bitacora.h"
#include "login.h"
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include<string>

using namespace std;

entrenador::entrenador(string id, string nom1, string nom2, string ape1, string ape2, string fechan)
{
    this->id = id;
    this->nom1 = nom1;
    this->nom2 = nom2;
    this->ape1 = ape1;
    this->ape2 = ape2;
    this->fechan = fechan;
}

string entrenador::setid(string id)
{
    this->id = id;
    return id;
}

string entrenador::getid()
{
    return id;
}

string entrenador::setnom1(string nom1)
{
    this->nom1 = nom1;
    return nom1;
}

string entrenador::getnom1()
{
    return nom1;
}

string entrenador::setnom2(string nom2)
{
    this->nom2 = nom2;
    return nom2;
}

string entrenador::getnom2()
{
    return nom2;
}

string entrenador::setape1(string ape1)
{
    this->ape1 = ape1;
    return ape1;
}

string entrenador::getape1()
{
    return ape1;
}

string entrenador::setape2(string ape2)
{
    this->ape2 = ape2;
    return ape2;
}

string entrenador::getape2()
{
    return ape2;
}

string entrenador::setfechan(string fechan)
{
    this->fechan = fechan;
    return fechan;
}

string entrenador::getfechan()
{
    return fechan;
}

void entrenador::menu()
{
    system("cls");
    int opc;
    char continuar;

    string usuarioActual = Login::getUsuarioActual();
    Bitacora bitacora;
    bitacora.ingresoBitacora(usuarioActual, "2002", "ENTRE");

    do
    {
        cout << "\n";
        cout << "\t+------------------------------------------+" << endl;
        cout << "\t|\t\t            \t\t   |" << endl;
        cout << "\t|\t  Catalogo de Clientes  \t   |" << endl;
        cout << "\t|\t\t            \t\t   |" << endl;
        cout << "\t+------------------------------------------+" << endl;
        cout << "\t|\t\t            \t\t   |" << endl;
        cout << "\t|\t\t1) Insertar\t\t   |" << endl;
        cout << "\t|\t\t            \t\t   |" << endl;
        cout << "\t|\t\t2) Desplegar \t\t   |" << endl;
        cout << "\t|\t\t            \t\t   |" << endl;
        cout << "\t|\t\t3) Modificar \t\t   |" << endl;
        cout << "\t|\t\t            \t\t   |" << endl;
        cout << "\t|\t\t4) Borrar\t\t   |" << endl;
        cout << "\t|\t\t            \t\t   |" << endl;
        cout << "\t|\t    5) Salir del programa\t   |" << endl;
        cout << "\t|\t\t            \t\t   |" << endl;
        cout << "\t|\t    6) Regresar al menu\t\t   |" << endl;
        cout << "\t|\t\t            \t\t   |" << endl;
        cout << "\t+------------------------------------------+" << endl;
        cout << "\n" << endl;
        cout << "\t\tIngrese el numero de opcion: ";
        cin >> opc;

        switch(opc)
        {
        case 1:
            system("cls");
            do
				{
					insertar();
					cout<<" -> Deseas ingresar a otro cliente? (S/N): ";
					cin>>continuar;
				}while(continuar=='S' || continuar=='s');
            system("pause");
            system("cls");
            break;
        case 2:
            system("cls");
            desplegar();
            system("pause");
            system("cls");
            break;
        case 3:
            system("cls");
            modificar();
            system("pause");
            system("cls");
            break;
        case 4:
            system("cls");
            borrar();
            system("pause");
            system("cls");
            break;
        case 5:
            exit(0);
            break;
        case 6:
            system("cls");
            break;
        default:
            cout << "\n\t Opcion invalida...Por favor prueba otra vez..";
            cin.ignore();
            cin.get();
            system("cls");
        }
    } while (opc!=6);
}

void entrenador::insertar()
{
    string usuarioActual = Login::getUsuarioActual();
    Bitacora bitacora;
    bitacora.ingresoBitacora(usuarioActual, "2003", "ENTREI");

    cout << "\n";
    cout << "\t+------------------------------------------+" << endl;
    cout << "\t|\t\t            \t\t   |" << endl;
    cout << "\t|      Agregar detalles del Cliente \t   |" << endl;
    cout << "\t|\t\t            \t\t   |" << endl;
    cout << "\t+------------------------------------------+" << endl;
    cout << "\n";

    srand(time(NULL));
    Entrenador entrenador;
    int numAleatorio = (rand() % 9998) + 1;

    string idString = "No-" + to_string(numAleatorio);

    for (int i = 0; i < idString.length(); ++i) {
        entrenador.id[i] = idString[i];
    }
    entrenador.id[idString.length()] = '\0';

    cout<<"        -> Generando codigo del cliente: " << entrenador.id<<endl;
    cin.ignore();

    cout<<"        -> Ingrese el 1er. nombre del cliente: ";
    cin.getline(entrenador.nom1, 45);

    cout<<"        -> Ingrese el 2do. nombre del cliente: ";
    cin.getline(entrenador.nom2, 45);

    cout<<"        -> Ingrese el 1er. apellido del cliente: ";
    cin.getline(entrenador.ape1, 45);

    cout<<"        -> Ingrese el 2do. apellido del cliente: ";
    cin.getline(entrenador.ape2, 45);

    cout<<"        -> Ingrese fecha de naciemineto del cliente: ";
    cin.getline(entrenador.fechan, 45);


    cout << "\n";
    cout<<"+---------------------------------------------------------+"<< endl;
    cout << "\n";

    ofstream archivo("Entrenador.dat", ios::binary | ios::app);
    archivo.write(reinterpret_cast<const char*>(&entrenador), sizeof(entrenador));
    archivo.close();
}

void entrenador::desplegar()
{
    string usuarioActual = Login::getUsuarioActual();
    Bitacora bitacora;
    bitacora.ingresoBitacora(usuarioActual, "2004", "ENTRED");

    cout << "\n";
    cout << "\t+------------------------------------------+" << endl;
    cout << "\t|\t\t            \t\t   |" << endl;
    cout << "\t|       Ver detalles del Cliente  \t   |" << endl;
    cout << "\t|\t\t            \t\t   |" << endl;
    cout << "\t+------------------------------------------+" << endl;
    cout << "\n";

    ifstream archivo("Entrenador.dat", ios::binary | ios::in);
    if(!archivo)
    {
        cout << "No hay informacion registrada...";
        cout << "\n";
        return;
    }
        Entrenador entrenador;

        while (archivo.read(reinterpret_cast<char*>(&entrenador), sizeof(Entrenador)))
        {
            cout<<"       -> Codigo del Cliente: "<< entrenador.id << endl;
            cout<<"       -> 1er. Nombre del Cliente: "<< entrenador.nom1 << endl;
            cout<<"       -> 2do. Nombre del Cliente: "<< entrenador.nom2 << endl;
            cout<<"       -> 1er. Apellido del Cliente: "<< entrenador.ape1 << endl;
            cout<<"       -> 2er. Apellido del Cliente: "<< entrenador.ape2 << endl;
            cout<<"       -> Fecha de nacimiento del Cliente: "<< entrenador.fechan << endl;
            cout << "     +-----------------------------------------------+" << endl;
            cout << "\n";
        }

        archivo.close();

    cout << "Presione Enter Para Continuar";
    cin.ignore();
    cin.get();
}

void entrenador::modificar()
{
    string usuarioActual = Login::getUsuarioActual();
    Bitacora bitacora;
    bitacora.ingresoBitacora(usuarioActual, "2005", "ENTREM");

    cout << "\n";
    cout << "\t+------------------------------------------+" << endl;
    cout << "\t|\t\t            \t\t   |" << endl;
    cout << "\t|     Modificar detalles del Cliente \t   |" << endl;
    cout << "\t|\t\t            \t\t   |" << endl;
    cout << "\t+------------------------------------------+" << endl;
    cout << "\n";

    fstream archivo;
    string idEntre;
    bool encontrado = false;

    archivo.open("Entrenador.dat", ios::binary | ios::in | ios::out);
    if (!archivo) {
        cout << "       -> Error, no se encuentra informacion...";
        cout << "\n";
        return;
    }
    cout << "       -> Ingrese el codigo del Cliente: ";
    cin >> idEntre;

    Entrenador entrenador;

    while (archivo.read(reinterpret_cast<char*>(&entrenador), sizeof(Entrenador))) {
        if (entrenador.id == idEntre) {
            encontrado = true;

            cout << "\n" << endl;
            cout << "           Cliente encontrado con exito!" << endl;
            cout << "\n" << endl;
            cout<<"        -> Ingrese codigo del Cliente: ";
            cin >> entrenador.id;
            cout<<"        -> Ingrese el 1er. nombre del Cliente: ";
            cin >> entrenador.nom1;
            cout<<"        -> Ingrese el 2do. nombre del Cliente: ";
            cin >> entrenador.nom2;
            cout<<"        -> Ingrese el 1er. apellido del Cliente: ";
            cin >> entrenador.ape1;
            cout<<"        -> Ingrese el 2do. apellido del Cliente: ";
            cin >> entrenador.ape2;
            cout<<"        -> Ingrese fecha de naciemineto del Cliente: ";
            cin >> entrenador.fechan;
             cout << "\n" << endl;

            archivo.seekp(-static_cast<int>(sizeof(Entrenador)), ios::cur);
            archivo.write(reinterpret_cast<char*>(&entrenador), sizeof(Entrenador));
            break;
        }
    }

    archivo.close();

    if (!encontrado) {
        cout << "       -> No se encontró un Cliente con el ID proporcionado." << endl;
        cout << "\n" << endl;
    }

    cout << "Presione Enter Para Continuar";
    cin.ignore();
    cin.get();
}

void entrenador::borrar()
{
    string usuarioActual = Login::getUsuarioActual();
    Bitacora bitacora;
    bitacora.ingresoBitacora(usuarioActual, "2006", "ENTREB");

    cout << "\n";
    cout << "\t+------------------------------------------+" << endl;
    cout << "\t|\t\t            \t\t   |" << endl;
    cout << "\t|     Eliminar detalles del Cliente \t   |" << endl;
    cout << "\t|\t\t            \t\t   |" << endl;
    cout << "\t+------------------------------------------+" << endl;
    cout << "\n";

    ifstream archivo("Entrenador.dat", ios::binary);
    string idEntre;

	if(!archivo)
	{
		cout<<"       -> Error, no se encuentra informacion...";
		cout << "\n";
		return;
	}

	ofstream archivo2("entrenador2.dat", ios::binary);

	Entrenador entrenador;

    cout<<"       -> Ingrese el codigo del Cliente: ";
    cin>>idEntre;

    bool resta = false;

		while(archivo.read(reinterpret_cast<char*>(&entrenador), sizeof(Entrenador)))
		{
			if(entrenador.id != idEntre)
			{
				archivo2.write(reinterpret_cast<const char*>(&entrenador), sizeof(Entrenador));
			}
			else
			{
			    resta = true;
			}

		}
		archivo.close();
		archivo2.close();

		remove("Entrenador.dat");

		rename("entrenador2.dat","Entrenador.dat");

		if (resta)
        {
        cout << "\n" << endl;
        cout << "       -> Cliente eliminado con exito." << endl;
        cout << "\n";
        }
        else
        {
        cout << "\n" << endl;
        cout << "       -> No se a podido encontrar al cliente" << endl;
        cout << "\n";
        }
}
