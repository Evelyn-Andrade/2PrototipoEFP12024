// login cine

//Encabezados de proteccion
#ifndef LOGIN_H
#define LOGIN_H
//Librerias
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <conio.h>
#include <iomanip>
#include <ctime>
#include <cstring>
//Encabezados
#include "Bitacora.h"
#include "usuarios.h"

using namespace std;


class Login {
//Atributos privados
private:
    static string usuarioActual; // Variable estática para almacenar el usuario actual
    string nombre; // Nombre de usuario
    string contra; // Contraseña de usuario
    int maxintentos; // Número máximo de intentos permitidos para iniciar sesión
    int contintentos; // Contador de intentos de inicio de sesión
//Atributos publicos
public:
    // Constructor de la clase Login con valores predeterminados
    Login(string nombre = "", string contra = "", int intentos = 3);

    // Funciones para establecer y obtener el nombre de usuario
    void setnombre(string nombre);
    string getnombre() const;

    // Funciones para establecer y obtener la contraseña de usuario
    void setcontra(string contra);
    string getcontra() const;

    // Función para validar el inicio de sesión
    bool validacion();

    // Función para restablecer el contador de intentos de inicio de sesión
    void resetintentos();

    // Función estática para obtener el usuario actual
    static string getUsuarioActual() {
        return usuarioActual;
    }
};

#endif // LOGIN_H
