#include <iostream>
using namespace std;

#ifndef ATENCION_H
#define ATENCION_H

class Atencion
{
private:
    int fecha;
    string sintomas;
    string diagnostico;

public:
    Atencion(int fecha, string sintomas)
    {
        this->fecha = fecha;
        this->sintomas = sintomas;
    }
    int getFecha()
    {
        return fecha;
    }
    string getSintomas()
    {
        return sintomas;
    }
    string getDiagnostico()
    {
        return diagnostico;
    }
    void setFecha(int fecha)
    {
        this->fecha = fecha;
    }
    void setSintomas(string sintomas)
    {
        this->sintomas = sintomas;
    }
    void setDiagnostico(string diagnostico)
    {
        this->diagnostico = diagnostico;
    }
    void virtual imprimirfichamedica()
    {
        cout << "Fecha de atencion: " << fecha << endl;
        cout << "Sintomas: " << sintomas << endl;
        cout << "Diagnostico: " << diagnostico << endl;
    }
};

#endif