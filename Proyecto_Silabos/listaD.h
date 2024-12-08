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
    int cantidadUsuarios=0;
public:
    //funciones respecto a lista, insersion y otra info respecto a ella
    listaD();
    ~listaD();

    void listaInsertarFinal         (const tipo &);
    bool listaVacia                 ()const;
    int listaTamano                 ();

    //acciones con los datos
    QString tipoUsuario             (short t);
    QString sede                    (short t);
    QString faseUsuario             (QString estado);
    bool numCuentaDisponible        (QString num);
    QString login                   (QString cuenta, QString nombre,QString contraActual, short type);

    short numeroTipoUsuario         (const QString &tipoStr);

    bool verficarContraAceptada     (QString cuenta, QString contradeseada, short type);

    void DeleteUser                 (QString cuenta, listaD<Usuario>& listaUsuarios);                       // elimina usario
    void cambioContra               (QString contraNueva, QString cuenta, listaD<Usuario>& listaUsuarios);  //cambia contraseña
    void solicitarCambioContra      (QString solicitud, QString cuenta, listaD<Usuario>& listaUsuarios);    //cambia contraseña
    void aceptarCambioContra        (bool aceptar, QString cuenta, listaD<Usuario>& listaUsuarios);         //cambia contraseña
    QString obtenerContraAnterior   (QString cuenta,listaD<Usuario>& listaUsuarios);


};

template<typename tipo>
listaD<tipo>::listaD() :PrimPtr(0),UltPtr(0), cantidadUsuarios(0)
{}

template<typename tipo>
listaD<tipo>::~listaD()
{
    if (!listaVacia()) {
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
            cantidadUsuarios--;
            delete ptrTemp;
        }
        cout << "Vacio\n";
    }
}

template<typename tipo>
void listaD<tipo>::listaInsertarFinal(const tipo &Dato)
{
    nodoD<tipo> *nuevo=new nodoD<tipo>(Dato);
    if(listaVacia()){
        PrimPtr=nuevo;
        UltPtr=nuevo;
    }else{
        if(cantidadUsuarios==1){
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
    cantidadUsuarios++;

}

template<typename tipo>
bool listaD<tipo>::listaVacia() const
{
    return PrimPtr==nullptr;
}

template<typename tipo>
int listaD<tipo>::listaTamano()
{
    return cantidadUsuarios;
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
        tipoStr = "ERROR";
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
        return -1;
    }
}
template<typename tipo>
QString listaD<tipo>::faseUsuario(const QString estado)
{
    if (estado == "Prerevision" || estado == "Devolver a Academia" ) {
        return "JEFE ACADEMICO/ COORDINADOR DE CARRERA";
    } else if (estado == "Rechazado" || estado == "Rechazar") {
        return "DOCENTE";
    } else if (estado == "Cargar silabo (Enviar a IEDD)" || estado == "Correcion Mayor" || estado == "Correcion Menor" || estado == "Aprobado con condicion") {
        return "IEDD";
    } else if (estado == "Listo para revision 1" || estado == "Aprobado" || estado == "Aprobado con condicion"  ) { //"Correcion Mayor"
        return "CONSULTOR";
    } else {
        return "N/A";
    }
}
template<typename tipo>
QString listaD<tipo>::sede(short t)
{
    QString tipoStr;
    switch (t) {
    case 1:
        tipoStr = "UNITEC";
        break;
    case 2:
        tipoStr = "CEUTEC";
        break;
    case 3:
        tipoStr = "UNITEC-CEUTEC";
        break;

    default:
        tipoStr = "N/A";
        break;
    }
    return tipoStr;
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
void listaD<tipo>::DeleteUser(QString cuenta, listaD<Usuario>& listaUsuarios)
{
    nodoD<Usuario>* temp = listaUsuarios.PrimPtr;
    while (temp != nullptr) {
        if (temp->getDato().getCuenta() == cuenta) {
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
            listaUsuarios.cantidadUsuarios--;
            return;
        }
        temp = temp->SigPtr;
    }
    return;
}
template<typename tipo>
bool listaD<tipo>::verficarContraAceptada(QString cuenta, QString contradeseada, short type)
{
    nodoD<Usuario>* temp = PrimPtr;
    while (temp != nullptr) {
        if (temp->Dato.getCuenta() == cuenta &&
                temp->Dato.getContraAnterior().startsWith("°") &&
                temp->Dato.getTipo() == type) {
            return true;
        }
        temp = temp->SigPtr;
    }

    return false;
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
void listaD<tipo>::cambioContra(QString contraNueva, QString cuenta, listaD<Usuario>& listaUsuarios) {
    nodoD<Usuario>* temp = listaUsuarios.PrimPtr;

    while (temp != nullptr) {
        if (temp->getDato().getCuenta() == cuenta) {
            if (temp->Dato.getContraAnterior().startsWith("°")) {
                QString nuevaContra = temp->getDato().getContraAnterior().mid(1);
                temp->Dato.setContraAnterior("");
                temp->Dato.setContraActual(nuevaContra);

            } else {
                temp->Dato.setContraAnterior("");
            }
            return;
        }
        temp = temp->SigPtr;
    }
}

template<typename tipo>
void listaD<tipo>::solicitarCambioContra(QString solicitud, QString cuenta, listaD<Usuario>& listaUsuarios) {
    nodoD<Usuario> *temp = listaUsuarios.PrimPtr;
    while (temp != nullptr) {
        if (temp->getDato().getCuenta() == cuenta) {
            temp->Dato.setContraAnterior(solicitud);
            return;
        }
        temp = temp->SigPtr;
    }
}

template<typename tipo>
void listaD<tipo>::aceptarCambioContra(bool aceptar, QString cuenta, listaD<Usuario> &listaUsuarios)
{
    nodoD<Usuario>* temp = listaUsuarios.PrimPtr;

    while (temp != nullptr) {
        if (temp->getDato().getCuenta() == cuenta) {
            if(aceptar){
                QString contraSolicitada = "°" + temp->Dato.getContraAnterior();
                temp->Dato.setContraAnterior(contraSolicitada);
            }else{
                temp->Dato.setContraAnterior("RECHAZADA");
            }
            return;
        }
        temp = temp->SigPtr;
    }
}

template<typename tipo>
QString listaD<tipo>::obtenerContraAnterior(QString cuenta,listaD<Usuario>& listaUsuarios)
{
    nodoD<Usuario> *temp = listaUsuarios.PrimPtr;
    while (temp != nullptr) {
        if (temp->getDato().getCuenta() == cuenta) {

            return temp->Dato.getContraAnterior();
        }
        temp = temp->SigPtr;
    }
}

#endif // LISTAD_H
