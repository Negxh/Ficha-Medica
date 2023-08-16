#include <iostream>
using namespace std;

#include "Hospital.h"
#include "menus.h"

int main()
{
    Hospital *h = new Hospital();
    cout << "----------------------------------------------------" << endl;
    cout << "HOSPITAL PIEGO DORTALES" << endl;
    cout << "----------------------------------------------------" << endl;
    int opcion, numbox;
    string rutbusq, diagnostico, sintomas;
    string nombre, ApellidoMaterno, ApellidoPaterno;
    int fechaNacimiento, fecha;

    while (true)
    {

        menuPrincipal();
        cout << "----------------------------------------------------" << endl;
        cout << "Marque su opcion: ";
        cin >> opcion;
        cout << "----------------------------------------------------" << endl;
        if (opcion == 7)
        {
            cout << "GRACIAS POR PREFERIR HOSPITAL PIEGO DORTALES!" << endl;
            break;
        }
        if (opcion == 1)
        {
            cout << "Ingrese el rut del paciente: ";
            cin >> rutbusq;
            if (h->BuscarPaciente(rutbusq) == 'V')
            {
                cout << "----------------------------------------------------" << endl;
                cout << "Paciente existente en la base de datos." << endl;
                cout << "----------------------------------------------------" << endl;
            }
            else if (h->BuscarPaciente(rutbusq) == 'F')
            {
                cout << "----------------------------------------------------" << endl;
                cout << "Paciente no encontrado en la base de datos." << endl;
                cout << "----------------------------------------------------" << endl;
                cout << "Ingrese el nombre del paciente: ";
                cin >> nombre;
                cout << "Ingrese Apellido Paterno: ";
                cin >> ApellidoPaterno;
                cout << "Ingrese Apellido Materno: ";
                cin >> ApellidoMaterno;
                cout << "Ingrese fecha de nacimiento: ";
                cin >> fechaNacimiento;
                Paciente *p = new Paciente(rutbusq, nombre, ApellidoPaterno, ApellidoMaterno, fechaNacimiento);
                cout << "----------------------------------------------------" << endl;
                h->registrarPaciente(p);
                cout << "----------------------------------------------------" << endl;

                cout << "Que sintomas presenta el paciente?: ";
                cin >> sintomas;
                cout << "Ingrese la fecha actual: ";
                cin >> fecha;
                Atencion *a = new Atencion(fecha, sintomas);
                p->AgregarFichaMedica(a);
                h->agregarListaEspera(p);
                cout << "----------------------------------------------------" << endl;
            }
        }
        if (opcion == 2)
        {
            h->agregarbox();
            cout << "----------------------------------------------------" << endl;
        }
        if (opcion == 3)
        {
            cout << "Ingrese el rut del paciente: ";
            cin >> rutbusq;
            if (h->BuscarPaciente(rutbusq) == 'V')
            {
                cout << "Paciente existente en la base de datos." << endl;
                h->agregarboxurgente(rutbusq);
                h->sacarlistaespera(rutbusq);
                cout << "----------------------------------------------------" << endl;
            }
            else
            {
                cout << "El paciente no existe en la base de datos, ingreselo en la opcion 1" << endl;
                cout << "----------------------------------------------------" << endl;
            }
        }
        if (opcion == 4)
        { // se pregunta el box y el diagnostico?
            cout << "Ingrese el numero de box: ";
            cin >> numbox;

            cout << "Ingresar diagnostico del paciente: ";
            cin >> diagnostico;
            h->DarAlta(numbox, diagnostico);
            cout << "----------------------------------------------------" << endl;
        }
        if (opcion == 5)
        {
            cout << "Ingresar numero del box: ";
            cin >> numbox;
            h->imprimirfichamedicabox(numbox);
            cout << "----------------------------------------------------" << endl;
        }
        if (opcion == 6)
        {
            h->boxDisponibles();
            cout << "----------------------------------------------------" << endl;
        }
        if (opcion == 9)
        { // opcion secreta para ver como va el map
            h->imprimirmapClientes();
            cout << "----------------------------------------------------" << endl;
        }
        if (opcion == 8)
        { // opcion secreta para ver como va la lista de espera
            h->imprimirListaEspera();
            cout << "----------------------------------------------------" << endl;
        }
    }
}
