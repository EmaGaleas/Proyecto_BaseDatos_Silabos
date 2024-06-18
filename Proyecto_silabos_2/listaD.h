#ifndef LISTAD_H
#define LISTAD_H
#include <nodoD.h>
#include <iostream>
#include <QMessageBox>
#include <Usuario.h>
#include <fstream>
#include <QtSql>

using std::cout;
using std::string;
using std::cerr;


template<typename tipo>
class listaD{
    friend class MainWindow;
    //friend class Arbol;
private:
    nodoD<tipo> *PrimPtr;
    nodoD<tipo> *UltPtr;
    int Cantidad;

public:
    listaD();
    ~listaD();
    void InsertarFin(const tipo &);

    bool Vacia()const;

    bool GuardarEnArchivo(string Nombre)const;
    bool ImportarArchivo(string Nombre);

    void guardarUsuariosBase(listaD<Usuario> &listaUsuarios);
    void guardarUsuarios(listaD<Usuario> &listaUsuarios);

    void DescargarUsuarios();
    string cifrarContrasena(string Message, int Key);
    string descifrarContrasena(string Message, int Key);


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
void listaD<tipo>::guardarUsuariosBase(listaD<Usuario> &listaUsuarios)
{

}

template<typename tipo>
void listaD<tipo>::guardarUsuarios(listaD<Usuario> &listaUsuarios)
{

}

template<typename tipo>
void listaD<tipo>::DescargarUsuarios()
{
    //Base de datos debe estar abierta!!!
    QSqlQuery *Query = new QSqlQuery();
    Query->prepare("select * from SilabosUsuarios");
    Query->exec();
    short CurrentRow=0;

    while(Query->next())
    {
        //    Usuario( int cuenta, string nombre,string contraActual, string contraAnterior,short tipo)
        Usuario NUEVO(Query->value(0).toInt(),Query->value(1).toString().toStdString(),Query->value(2).toString().toStdString(),Query->value(3).toString().toStdString(),Query->value(4).toInt());
        InsertarFin(NUEVO);
        CurrentRow++;
    }
}


template<typename tipo>
string listaD<tipo>::cifrarContrasena(string Message, int Key)
{
    Key=980487;
    char c;
    string EncryptedMessage;
    for(size_t i = 0; i < Message.length(); i++)
    {
        c = static_cast<char>(Message[i] + (Key / (Key % 100)) % 10);
        EncryptedMessage += c;
    }
    return EncryptedMessage;
}

template<typename tipo>
string listaD<tipo>::descifrarContrasena(string Message, int Key)
{
    Key=980487;
    char c;
    std::string DecryptedMessage;
    for(size_t i = 0; i < Message.length(); i++)
    {
        c = static_cast<char>(Message[i] - (Key / (Key % 100)) % 10);
        DecryptedMessage += c;
    }
    return DecryptedMessage;
}





#endif // LISTAD_H
