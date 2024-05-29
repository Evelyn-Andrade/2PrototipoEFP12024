// peliculas cine
#ifndef PELICULAS_H
#define PELICULAS_H

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>

using namespace std;

struct Medico {
    int codigo;
    char nombre[50];
    char especialidad[50];
};

class MedicoCRUD {
public:
    void IngresarMedico();
    void ModificarMedico();
    void BorrarMedico();
    void DesplegarMedico();
    void CrudMedicos();
    bool ValidarMedico(int codigo);
};

#endif // PELICULAS_H

