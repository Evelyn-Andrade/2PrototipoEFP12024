// horario cine
#ifndef HORARIO_H
#define HORARIO_H
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>

using namespace std;

struct Horario {
    int codigo;
    char dia[50];
    char hora[50];
};

class HorarioCRUD {
public:
    void IngresarHorario();
    void ModificarHorario();
    void BorrarHorario();
    void DesplegarHorario();
    void CrudHorarios();
    bool ValidarHO(int codigo);
};

#endif // HORARIO_H

