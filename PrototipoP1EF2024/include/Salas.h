//salas cine
#ifndef SALAS_H
#define SALAS_H

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>

using namespace std;

struct Clinica {
    int codigo;
    char nombre[50];
    char direccion[100];
};

class ClinicaCRUD {
public:
    void IngresarClinica();
    void ModificarClinica();
    void BorrarClinica();
    void DesplegarClinica();
    void CrudClinicas();
    bool ValidarClinica(int codigo);
};

#endif // SALAS_H
