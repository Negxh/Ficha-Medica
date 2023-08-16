#include <iostream>
#include <vector>

using namespace std;

#include "Atencion.h"


#ifndef PACIENTE_H
#define PACIENTE_H

class Paciente
{
private:
    string rut;
    string nombre;
    string ApellidoPaterno;
    string ApellidoMaterno;
    int fechaNacimiento;
    vector<Atencion *> fichaMedica;

public:
    Paciente(string rut, string nombre, string ApellidoPaterno,
             string ApellidoMaterno, int fechaNacimiento)
    {
        this->rut = rut;
        this->nombre = nombre;
        this->ApellidoPaterno = ApellidoPaterno;
        this->ApellidoMaterno = ApellidoMaterno;
        this->fechaNacimiento = fechaNacimiento;
    }
    string getNombre()
    {
        return nombre;
    }
    string getRut()
    {
        return rut;
    }
    string getApellidoPaterno()
    {
        return ApellidoPaterno;
    }
    string getApellidoMaterno()
    {
        return ApellidoMaterno;
    }
    int getFechaNacimiento()
    {
        return fechaNacimiento;
    }
    void setNombre(string nombre)
    {
        this->nombre = nombre;
    }
    void setRut(string rut)
    {
        this->rut = rut;
    }
    void setApellidoPaterno(string ApellidoPaterno)
    {
        this->ApellidoPaterno = ApellidoPaterno;
    }
    void setApellidoMaterno(string ApellidoMaterno)
    {
        this->ApellidoMaterno = ApellidoMaterno;
    }
    void setFechaNacimiento(int fechaNacimiento)
    {
        this->fechaNacimiento = fechaNacimiento;
    }
    void AgregarFichaMedica(Atencion *a)
    {
        fichaMedica.push_back(a);
        cout << "----------------------------------------------------" << endl;
        cout << "Se ha agregado su ficha correctamente." << endl;
        cout << "----------------------------------------------------" << endl;
    }
    void cambiarDiagnostico(string diagnostico)
    {
        for (int i = 0; i < fichaMedica.size(); i++)
        {
            fichaMedica[i]->setDiagnostico(diagnostico);
        }
    }

    void virtual imprimir()
    {
        cout << "----------------------------------------------------" << endl;
        cout << "Nombre: " << nombre << " " << ApellidoPaterno << " " << ApellidoMaterno << endl;
        cout << "Rut: " << rut << endl;
        cout << "Fecha de Nacimiento: " << fechaNacimiento << endl;
        for (int i = 0; i < fichaMedica.size(); i++)
        {
            fichaMedica[i]->imprimirfichamedica();
            cout << "----------------------------------------------------" << endl;
        }
    }
};

#endif