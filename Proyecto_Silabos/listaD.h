#ifndef LISTAD_H
#define LISTAD_H
#include <nodoB.h>
#include <iostream>
#include <QMessageBox>
#include <Usuario.h>
#include <fstream>
using std::cout;
using std::string;
using std::cerr;


template<typename tipo>
class listaD{
    friend class MainWindow;
    friend class Arbol;
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
    void cargarUsuarios();

    string cifrarContraseña(string c);
    string descifrarContrasena(string c);

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
void listaD<tipo>::cargarUsuarios()
{

}

template<typename tipo>
string listaD<tipo>::cifrarContraseña(std::string contraseña)
{

}

template<typename tipo>
string listaD<tipo>::descifrarContrasena(std::string contraCifrada)
{

}
#endif // LISTAD_H
