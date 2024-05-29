#ifndef RESULTADOS_H
#define RESULTADOS_H
#include <string>

using namespace std;

struct Entrenador
        {
            char id[20];
            char nom1[45];
            char nom2[45];
            char ape1[45];
            char ape2[45];
            char fechan[45];
        };

class resultados {
private:
    string id, codigo_entre, nombre_entre, nom_entre,clinica, medico, horario;

public:
    resultados() {}
    resultados(string id, string codigo_entre, string nombre_entre, string nom_entre, string clinica, string medico, string horario);

    string setid(string id);
    string getid();

    string setcodigo_entre(string codigo_entre);
    string getcodigo_entre();

    string setnombre_entre(string nombre_entre);
    string getnombre_entre();

    string setnom_entre(string nom_entre);
    string getnom_entre();

    string setclinica(string clinica);
    string getclinica();

    string setmedico(string medico);
    string getmedico();

    string sethorario(string horario);
    string gethorario();

    void desplegarBoleta(const char* carnet, string nom1);
    void Menu_alumno();
    void asignacion_entr(const char* carnet);
    void mostrar_cursos();
    bool validarCarnet();
    bool ValidarCL(int codigo);
    bool ValidarME(int codigo);
    bool ValidarHO(int codigo);
    string ObtenerClinica(int codigo);
    string ObtenerClinicaDIR(int codigo);
    string ObtenerMedico(int codigo);
    string ObtenerMedicoESP(int codigo);
    string ObtenerHorario(int codigo);
    string ObtenerHorario2(int codigo);
    bool ValidaAsignacion(const char* carnet);
    bool ValidaAsignacion2(const char* carnet);

    struct Resultados {
        char carnet[20];
        int codigoClinica;
        int codigoMedico;
        int codigoHorario;
    };
};

#endif // RESULTADOS_H
