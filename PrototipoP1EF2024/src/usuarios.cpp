// usuarios cine
#include <iostream>
#include <fstream>
#include <iomanip>
#include "usuarios.h"
#include "Login.h"
#include "Bitacora.h"

using namespace std;

usuarios::usuarios(string nombre, string contra)
{

    this->nombre = nombre;
    this->contra = contra;

}

string usuarios::setnombre(string nombre)
{
    this->nombre = nombre;
    return nombre;
}

string usuarios::getnombre()
{
    return nombre;
}

string usuarios::setcontra(string contra)
{
    this->contra = contra;
    return contra;
}

string usuarios::getcontra()
{
    return contra;
}

void usuarios::menu()
{
    string usuarioActual = Login::getUsuarioActual();
    Bitacora bitacora;
    bitacora.ingresoBitacora(usuarioActual, "2027", "USU");

    int opc;
    do
    {
        system("cls");

        cout << "\n";
        cout << "\t+------------------------------------------+" << endl;
        cout << "\t|\t\t            \t\t   |" << endl;
        cout << "\t|\t    Catalogo de Usuarios\t   |" << endl;
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
            pideDatos();
            break;
        case 2:
            muestraDatos();
            break;
        case 3:
            editaDatos();
            break;
        case 4:
            borraDatos();
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

void usuarios::pideDatos()
{
    string usuarioActual = Login::getUsuarioActual();
    Bitacora bitacora;
    bitacora.ingresoBitacora(usuarioActual, "2028", "USUI");

    system("cls");

    cout << "\n";
    cout << "\t+------------------------------------------+" << endl;
    cout << "\t|\t\t                               \t\t   |" << endl;
    cout << "\t|        Insertar detalles del Usuario\t   |" << endl;
    cout << "\t|\t\t                               \t\t   |" << endl;
    cout << "\t+------------------------------------------+" << endl;
    cout << "\n";

    Usuarios usuario;

    cout<<"       -> Ingrese un nombre: ";
    cin.ignore();
    cin.getline(usuario.nombre, 80);
    cout<<"       -> Ingrese una contrasena: ";
    cin.getline(usuario.contra, 80);

    ofstream archivo("Usuario.dat", ios::binary | ios::app);

    archivo.write(reinterpret_cast<const char*>(&usuario), sizeof(usuario));

    archivo.close();
}

void usuarios::muestraDatos()
{
    string usuarioActual = Login::getUsuarioActual();
    Bitacora bitacora;
    bitacora.ingresoBitacora(usuarioActual, "2029", "USUD");

    system("cls");

    cout << "\n";
    cout << "\t+------------------------------------------+" << endl;
    cout << "\t|\t\t            \t\t   |" << endl;
    cout << "\t|          Ver detalles del Usuario\t   |" << endl;
    cout << "\t|\t\t            \t\t   |" << endl;
    cout << "\t+------------------------------------------+" << endl;
    cout << "\n";

    ifstream archivo("Usuario.dat", ios::binary | ios::in);
    if(!archivo)
    {
        cout << "No hay informacion registrada";
        return;
    }
        Usuarios usuario;

        while (archivo.read(reinterpret_cast<char*>(&usuario), sizeof(Usuarios)))
        {
            cout<<"       -> Nombre de usuario: "<< usuario.nombre << endl;
            cout<<"       -> Contrasena usuario: "<<usuario.contra << endl;
            cout << "     +-----------------------------------------------+" << endl;
            cout << "\n";
        }
            archivo.close();


    cout << "Presione Enter Para Continuar";
    cin.ignore();
    cin.get();
}

void usuarios::editaDatos()
{
    string usuarioActual = Login::getUsuarioActual();
    Bitacora bitacora;
    bitacora.ingresoBitacora(usuarioActual, "2030", "USUM");

    system("cls");

    fstream archivo;
    string nom;
    bool encontrado = false;

    cout << "\n";
    cout << "\t+------------------------------------------+" << endl;
    cout << "\t|\t\t            \t\t   |" << endl;
    cout << "\t|      Modificar detalles del Usuario\t   |" << endl;
    cout << "\t|\t\t            \t\t   |" << endl;
    cout << "\t+------------------------------------------+" << endl;
    cout << "\n";

    archivo.open("Usuario.dat",ios::binary | ios::in | ios::out);
    if(!archivo){

        cout << "       -> Error, no se encuentra informacion...";
        cout << "\n";
        return;
    }
        cout << "       -> Ingrese el nombre del usuario: ";
        cin >> nom;

        Usuarios usuario;

        while (archivo.read(reinterpret_cast<char*>(&usuario), sizeof(Usuarios))) {
        if (usuario.nombre == nom) {
            encontrado = true;

            cout<<"       -> Ingrese un nombre: ";
            cin >> usuario.nombre;
            cout<<"       -> Ingrese una contrasena: ";
            cin >> usuario.contra;

            archivo.seekp(-static_cast<int>(sizeof(Usuarios)), ios::cur);

            archivo.write(reinterpret_cast<char*>(&usuario), sizeof(Usuarios));
            break;
        }
    }

    archivo.close();

    if (!encontrado) {
        cout << "       -> No se encontró un pais con el ID proporcionado." << endl;
        cout << "\n" << endl;
    }

    cout << "Presione Enter Para Continuar";
    cin.ignore();
    cin.get();
}

void usuarios::borraDatos()
{
    string usuarioActual = Login::getUsuarioActual();
    Bitacora bitacora;
    bitacora.ingresoBitacora(usuarioActual, "2031", "USUB");

   	system("cls");

	string nom;

	cout << "\n";
    cout << "\t+------------------------------------------+" << endl;
    cout << "\t|\t\t            \t\t   |" << endl;
    cout << "\t|       Eliminar detalles del Usuario\t   |" << endl;
    cout << "\t|\t\t            \t\t   |" << endl;
    cout << "\t+------------------------------------------+" << endl;
    cout << "\n";

    ifstream archivo("Usuario.dat", ios::binary);

	if(!archivo)
	{
		cout<<"       -> Error, no se encuentra informacion...";
		cout << "\n";
		return;
	}
	ofstream archivo2("Usuario2.dat", ios::binary);
	Usuarios usuario;

    cout<<"       -> Ingrese el nombre del usuario: ";
    cin>>nom;

    bool resta = false;

		while(archivo.read(reinterpret_cast<char*>(&usuario), sizeof(Usuarios)))
		{
			if(usuario.nombre != nom)
			{
				archivo2.write(reinterpret_cast<const char*>(&usuario), sizeof(Usuarios));
			}
			else
			{
			    resta = true;
			}

		}
		archivo.close();
		archivo2.close();

		remove("Usuario.dat");

		rename("Usuario2.dat","Usuario.dat");

		if (resta)
        {
        cout << "\n" << endl;
        cout << "       -> Usuario eliminado con exito." << endl;
        cout << "\n";
        }
        else
        {
        cout << "\n" << endl;
        cout << "       -> No se a podido encontrar el pais" << endl;
        cout << "\n";
        }
}
