#ifndef LISTAD_H
#define LISTAD_H
#include <nodoD.h>
#include <iostream>
#include <QMessageBox>
#include <Usuario.h>
#include <fstream>
#include <string>
#include <QApplication>
using std::cout;
using std::string;
using std::cerr;


template<typename tipo>
class listaD{
    friend class cframe;
    friend class Arbol;
private:
    nodoD<tipo> *PrimPtr;
    nodoD<tipo> *UltPtr;
    int Cantidad=0;

public:
    listaD();
    ~listaD();

    void InsertarFin(const tipo &);
    bool Vacia()const;

    QString tipoUsuario(short t);
    bool numCuentaDisponible(QString num);
    QString login(QString cuenta, QString nombre,QString contraActual, short type);
    void cambioContra(QString contraNueva, QString cuenta, listaD<Usuario>& listaUsuarios);
    short numeroTipoUsuario(const QString &tipoStr);
    bool verficarContraActualizada(QString cuenta, QString contradeseada, short type);
    int size();



};

template<typename tipo>
listaD<tipo>::listaD() :PrimPtr(0),UltPtr(0), Cantidad(0)
{}

template<typename tipo>
listaD<tipo>::~listaD()
{
    if (!Vacia()) {
        cout << "Limpiando\n" << std::endl;
        nodoD<tipo> *ptrAct = PrimPtr;
        nodoD<tipo> *ptrTemp;
        while (ptrAct != 0) {
            ptrTemp = ptrAct;
            //            cout << ptrTemp->Dato << "\n";
            ptrAct = ptrAct->SigPtr;
            if (ptrAct != nullptr) {
                ptrAct->AntPtr = nullptr;
            }
            Cantidad--;
            delete ptrTemp;
        }
        cout << "Vacio\n";
    }
}

template<typename tipo>
void listaD<tipo>::InsertarFin(const tipo &Dato)
{
    nodoD<tipo> *nuevo=new nodoD<tipo>(Dato);
    if(Vacia()){
        PrimPtr=nuevo;
        UltPtr=nuevo;
    }else{
        if(Cantidad==1){
            nuevo->SigPtr=0;
            nuevo->AntPtr=PrimPtr;
            UltPtr=nuevo;
            PrimPtr->SigPtr=nuevo;
        }else{
            nuevo->SigPtr=0;
            nuevo->AntPtr=UltPtr;
            UltPtr->SigPtr=nuevo;
            UltPtr=nuevo;
        }
    }
    Cantidad++;

}

template<typename tipo>
bool listaD<tipo>::Vacia() const
{
    return PrimPtr==nullptr;
}

template<typename tipo>
QString listaD<tipo>::tipoUsuario(short t)
{
    QString tipoStr;

    switch (t) {
    case 1:
        tipoStr = "DOCENTE";
        break;
    case 2:
        tipoStr = "DIRECTOR";
        break;
    case 3:
        tipoStr = "DECANO";
        break;
    case 4:
        tipoStr = "JEFE ACADEMICO";
        break;
    case 5:
        tipoStr = "COORDINADOR DE CARRERA";
        break;
    case 6:
        tipoStr = "IEDD";
        break;
    case 7:
        tipoStr = "CONSULTOR";
        break;
    default:
        tipoStr = "ERROR"; // En caso de que el tipo no esté definido
        break;
    }

    return tipoStr;
}
template<typename tipo>
short listaD<tipo>::numeroTipoUsuario(const QString &tipoStr)
{
    if (tipoStr == "DOCENTE") {
        return 1;
    } else if (tipoStr == "DIRECTOR") {
        return 2;
    } else if (tipoStr == "DECANO") {
        return 3;
    } else if (tipoStr == "JEFE ACADEMICO") {
        return 4;
    } else if (tipoStr == "COORDINADOR DE CARRERA") {
        return 5;
    } else if (tipoStr == "IEDD") {
        return 6;
    } else if (tipoStr == "CONSULTOR") {
        return 7;
    } else {
        return -1; // En caso de que el tipo no sea reconocido
    }
}

template<typename tipo>
bool listaD<tipo>::numCuentaDisponible(QString num)
{
    nodoD<Usuario>* temp = PrimPtr;
    while (temp != nullptr) {
        if (temp->getDato().getCuenta() == num) {
            return false;
        }
        temp = temp->SigPtr;
    }
    return true;
}

template<typename tipo>
QString listaD<tipo>::login(QString cuenta, QString nombre, QString contraActual, short type)
{
    nodoD<Usuario>* temp = PrimPtr;
    while (temp != nullptr) {
        if (temp->getDato().getCuenta() == cuenta &&
            temp->getDato().getNombre() == nombre &&
            temp->getDato().getContraActual() == contraActual &&
            temp->getDato().getTipo() == type) {
            return temp->getDato().getContraAnterior();
        }
        temp = temp->SigPtr;
    }

   return "no";
}
template<typename tipo>
bool listaD<tipo>::verficarContraActualizada(QString cuenta, QString contradeseada, short type)
{
    nodoD<Usuario>* temp = PrimPtr;
    while (temp != nullptr) {
        if (temp->getDato().getCuenta() == cuenta &&
            (temp->getDato().getContraAnterior() == contradeseada)&&
            temp->getDato().getTipo() == type) {
            return true;
        }
        temp = temp->SigPtr;
    }

    return false;
}

template<typename tipo>
int listaD<tipo>::size()
{
   return Cantidad;
}
template<typename tipo>
void listaD<tipo>::cambioContra(QString contraNueva, QString cuenta, listaD<Usuario>& listaUsuarios)
{
    nodoD<Usuario>* temp = listaUsuarios.PrimPtr;

    while (temp != nullptr) {
        if (temp->getDato().getCuenta() == cuenta) {
            if (true) {
                if (temp == listaUsuarios.PrimPtr && temp == listaUsuarios.UltPtr) {
                    listaUsuarios.PrimPtr = listaUsuarios.UltPtr = nullptr;
                } else if (temp == listaUsuarios.PrimPtr) {
                    listaUsuarios.PrimPtr = temp->SigPtr;
                    listaUsuarios.PrimPtr->AntPtr = nullptr;
                } else if (temp == listaUsuarios.UltPtr) {
                    listaUsuarios.UltPtr = temp->AntPtr;
                    listaUsuarios.UltPtr->SigPtr = nullptr;
                } else {
                    temp->AntPtr->SigPtr = temp->SigPtr;
                    temp->SigPtr->AntPtr = temp->AntPtr;
                }
                delete temp;
                listaUsuarios.Cantidad--;

            } else {
                temp->getDato().setContraActual(contraNueva);
            }
            return;
        }
        temp = temp->SigPtr;
    }
}


#endif // LISTAD_H
