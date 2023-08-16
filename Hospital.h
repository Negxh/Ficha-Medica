#include <iostream>
#include <map>
#include <queue>

using namespace std;

#include "Paciente.h"

#ifndef HOSPITAL_H
#define HOSPITAL_H

class Hospital
{
private:
    map<string, Paciente *> Clientes;
    Paciente *box[50];
    queue<Paciente *> listaespera; // cola lista de espera
public:
    Hospital()
    {
        for (int i = 0; i < 50; i++)
        {
            box[i] = NULL;
        }
    }
    void agregarListaEspera(Paciente *p)
    {
        listaespera.push(p);
    }
    void imprimirListaEspera()
    {
        queue<Paciente *> aux;
        while (listaespera.size() > 0)
        {
            listaespera.front()->imprimir();
            aux.push(listaespera.front());
            listaespera.pop();
        }
        while (aux.size() > 0)
        {
            listaespera.push(aux.front());
            aux.pop();
        }
    }
    void agregarbox()
    {
        if (listaespera.size() != 0)
        {
            for (int i = 0; i < 50; i++)
            {
                if (box[i] == NULL)
                {
                    box[i] = listaespera.front();
                    cout << "----------------------------------------------------" << endl;
                    cout << "Paciente " << listaespera.front()->getNombre() << " "
                         << listaespera.front()->getApellidoPaterno() << " "
                         << listaespera.front()->getApellidoMaterno();
                    cout << " ,ha sido agergado en el box " << i + 1 << endl;
                    listaespera.pop();
                    break;
                }
            }
        }
        else
        {
            cout << "----------------------------------------------------" << endl;
            cout << "No hay pacientes en lista de espera" << endl;
            cout << "----------------------------------------------------" << endl;
        }
    }
    void agregarboxurgente(string rutbusq)
    {
        queue<Paciente *> aux;
        while (listaespera.size() > 0)
        {
            if (listaespera.front()->getRut() == rutbusq)
            {
                for (int i = 0; i < 50; i++)
                {
                    if (box[i] == NULL)
                    {
                        box[i] = listaespera.front();
                        cout << "----------------------------------------------------" << endl;
                        cout << "Paciente " << listaespera.front()->getNombre() << " "
                             << listaespera.front()->getApellidoPaterno() << " "
                             << listaespera.front()->getApellidoMaterno();
                        cout << " ,ha sido agergado en el box " << i + 1 << endl;
                        break;
                    }
                }
            }
            aux.push(listaespera.front());
            listaespera.pop();
        }
        while (aux.size() > 0)
        {
            listaespera.push(aux.front());
            aux.pop();
        }
    }
    void sacarlistaespera(string rutbusq)
    {
        queue<Paciente *> aux;
        while (listaespera.size() > 0)
        {
            if (listaespera.front()->getRut() == rutbusq)
            {
                listaespera.pop();
                break;
            }
            aux.push(listaespera.front());
            listaespera.pop();
        }
        while (aux.size() > 0)
        {
            listaespera.push(aux.front());
            aux.pop();
        }
    }
    void registrarPaciente(Paciente *p)
    {
        string rut = p->getRut();
        Clientes[rut] = p;
        cout << "----------------------------------------------------" << endl;
        cout << "Paciente ingresado correctamente." << endl;
        cout << "----------------------------------------------------" << endl;
    }
    char BuscarPaciente(string rutbusq)
    {
        map<string, Paciente *>::iterator recorre = Clientes.begin();
        recorre = Clientes.find(rutbusq);
        if (recorre != Clientes.end())
        {
            return 'V';
        }
        else
        {
            return 'F';
        }
    }
    void imprimirmapClientes()
    {
        map<string, Paciente *>::iterator recorre = Clientes.begin();
        while (recorre != Clientes.end())
        {
            recorre->second->imprimir();
            recorre++;
        }
    }
    void DarAlta(int numbox, string diagnostico)
    {
        map<string, Paciente *>::iterator it;
        for (it = Clientes.begin(); it != Clientes.end(); it++)
        {
            if (box[numbox - 1]->getRut() == it->second->getRut())
            {
                it->second->cambiarDiagnostico(diagnostico);
            }
        }
        box[numbox - 1] = NULL;
    }
    void imprimirfichamedicabox(int numbox)
    {
        if (box[numbox - 1] != NULL)
        {
            box[numbox - 1]->imprimir();
        }
        else
        {
            cout << "----------------------------------------------------" << endl;
            cout << "No hay paciente en el box numero " << numbox << endl;
            cout << "----------------------------------------------------" << endl;
        }
    }
    void boxDisponibles()
    {
        int boxDisponibles = 50;
        for (int i = 0; i < 50; i++)
        {
            if (box[i] != NULL)
            {
                boxDisponibles--;
            }
        }
        cout << "------------------------------------------------------------------------" << endl;
        cout << "En el Hospital hay un total de " << boxDisponibles << " box de atencion disponibles" << endl;
        cout << "------------------------------------------------------------------------" << endl;
    }
};

#endif