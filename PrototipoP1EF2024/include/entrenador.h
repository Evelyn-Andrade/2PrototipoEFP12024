//cine clientes
#ifndef ENTRENADOR_H
#define ENTRENADOR_H
#include <iostream>

using namespace std;

class entrenador
{
    public:

        entrenador() {}
        entrenador(string id, string nom1, string nom2, string ape1, string ape2, string fechan);

        string setid(string id);
        string getid();

        string setnom1(string nom1);
        string getnom1();

        string setnom2(string nom2);
        string getnom2();

        string setape1(string ape1);
        string getape1();

        string setape2(string ape2);
        string getape2();

        string setfechan(string fechan);
        string getfechan();

        void menu();
        void insertar();
        void desplegar();
        void modificar();
        void borrar();

        struct Entrenador
        {
            char id[20];
            char nom1[45];
            char nom2[45];
            char ape1[45];
            char ape2[45];
            char fechan[45];
        };

    protected:

    private:

        string id, nom1, nom2, ape1, ape2, fechan;
};

#endif // ENTRENADOR_H
