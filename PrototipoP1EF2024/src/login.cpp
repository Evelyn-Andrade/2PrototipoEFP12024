// cine
#include "Login.h"
#include "Bitacora.h"
#include "conio.h"
using namespace std;

string Login::usuarioActual = "";

Login::Login(string nombre, string contra, int maxintentos) : nombre(nombre), contra(contra), maxintentos(maxintentos), contintentos(0) {}

void Login::setnombre(string nombre) {
    this->nombre = nombre;
}

string Login::getnombre() const {
    return nombre;
}

void Login::setcontra(string contra) {
    this->contra = contra;
}

string Login::getcontra() const {
    return contra;
}

void Login::resetintentos() {
    contintentos = 0;
}

bool Login::validacion() {
    system("cls");

    fstream archivo;
    string nom;
    string pass;
    bool encontrado = false;


    archivo.open("Usuario.dat", ios::binary | ios::in);

    if (!archivo) {
        cout << "Error, no se encuentra informacion..." << endl;
        return false;
    }

    while (contintentos < maxintentos) {
        system("cls");
        cout << "\t+------------------------------------------+" << endl;
        cout << "\t|\t\t            \t\t   |" << endl;
        cout << "\t|\t   Bienvenido al Sistema\t   |" << endl;
        cout << "\t|\t\t            \t\t   |" << endl;
        cout << "\t+------------------------------------------+" << endl;

        cout << "\n" << endl;
        cout << "\t\t     Intento " << (contintentos + 1) << " de " << maxintentos << "." << endl;
        cout << "\n" << endl;
        cout << "\t\tIngrese su Nombre: ";
        cin >> nom;
        cout << "\n" << endl;
        cout << "\t\tIngrese su contraseña: ";
         pass = "";
         char ch;
          while ((ch = getch()) != '\r') {
            if (ch == '\b') {
                if (!pass.empty()) {
                    cout << "\b \b";
                    pass.pop_back();
                }
            } else {
                cout << '*';
                pass += ch;
            }
        }
        cout << endl;
        Usuarios usuarios;
          system("cls");
        while (archivo.read(reinterpret_cast<char*>(&usuarios), sizeof(Usuarios))) {
            if (nom == usuarios.nombre && pass == usuarios.contra) {
                usuarioActual = nom;
                string codigoPrograma = "2001";
                Bitacora bitacora;
                bitacora.ingresoBitacora(nom, codigoPrograma, "LOG");
                encontrado = true;
                break;
            }
        }

        if (encontrado) {
            cout << "Login exitoso!" << endl;
            archivo.close();
            resetintentos();
            return true;
        } else {
            cout << "Nombre o contrasena incorrectos" << endl;
            contintentos++;
            archivo.clear(); // Limpiar el estado del archivo
            archivo.seekg(0, ios::beg); // Regresar al inicio del archivo
        }

        if (contintentos >= maxintentos) {
            cout << "Se ha alcanzado el numero maximo de intentos. Acceso denegado." << endl;
            archivo.close();
            return false;
        }
    }

    archivo.close();
    return false;
}
