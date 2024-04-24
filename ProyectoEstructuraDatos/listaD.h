#ifndef LISTAD_H
#define LISTAD_H
#include <nodoD.h>
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
    void guardarExcelUsuarios(std::ofstream &file, listaD<Usuario> &listaUsuarios);
    void guardarUsuarios(listaD<Usuario> &listaUsuarios);
    void cargarUsuarios();


    bool buscarUsuario(string const numCuenta, string name, string contra,const std::string quienSoy, listaD<Usuario> &listaUsuarios);
    bool cambiarPassword_Username(string const numCuenta, string nuevaContra,string nuevoUsername, listaD<Usuario> &listaUsuarios);


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
void listaD<tipo>::guardarExcelUsuarios(std::ofstream &file, listaD<Usuario> &listaUsuarios)
{
    nodoD<Usuario> *tmp = listaUsuarios.PrimPtr;
    while (tmp != nullptr) {
        Usuario usuario = tmp->getDato();
        file << usuario.getName() << "\t"
             << usuario.getCuenta() << "\t"
             << usuario.getTipo() << "\t"
            << usuario.getContrasena()<<"\n";
        tmp = tmp->SigPtr;
    }
}

template<typename tipo>
void listaD<tipo>::guardarUsuarios(listaD<Usuario> &listaUsuarios)
{
    std::ifstream file;
    file.open("usuarios.xls");
    file.close();
    std::ofstream File("usuarios.xls");
    if (File.is_open()) {
        File << "Nombre\tCuenta\tCargo\tContrasena\n";
        guardarExcelUsuarios(File, listaUsuarios);
        File.close();
        cout << "XLS exportado\n";
    } else {
        cerr << "Error en el archivo\n";
    }
}

template<typename tipo>
void listaD<tipo>::cargarUsuarios()
{
    std::ifstream file("usuarios.xls");
    if (file.is_open()) {

        string header;
        std::getline(file, header);

        string nombre, cuenta, code, contrasena;
        while (file >> nombre >> cuenta >> code >> contrasena) {
            Usuario nuevo(nombre, cuenta, code, contrasena);
            InsertarFin(nuevo);
        }
        file.close();
        cout << "Usuarios cargados desde el archivo\n";
    } else {
        cerr << "Error al abrir el archivo\n";
    }
}

template<typename tipo>
bool listaD<tipo>::buscarUsuario(const std::string numCuenta, std::string name,std::string contra,const std::string quienSoy, listaD<Usuario> &listaUsuarios)
{
    if (!Vacia()) {
        nodoD<tipo> *ptrAct = listaUsuarios.PrimPtr;
        while (ptrAct != 0) {
            Usuario usuario = ptrAct->getDato();
            if(usuario.getCuenta() == numCuenta && usuario.getName()==name && usuario.getContrasena()==contra && usuario.getTipo()==quienSoy){
                return true;
            }else{
                ptrAct = ptrAct->SigPtr;
            }
        }
        return false;
    }
    return false;

}

template<typename tipo>
bool listaD<tipo>::cambiarPassword_Username(const std::string numCuenta, std::string nuevaContra, std::string nuevoUsername,listaD<Usuario> &listaUsuarios)
{
    if (!Vacia()) {
        nodoD<tipo> *ptrAct = listaUsuarios.PrimPtr;
        while (ptrAct != 0) {
            Usuario usuario = ptrAct->getDato();
            if(usuario.getCuenta() == numCuenta){
                usuario.setContrasena(nuevaContra);
                usuario.setName(nuevoUsername);

                ptrAct->setDato(usuario);
                QString mensaje = "neue contra: " + QString::fromStdString(ptrAct->getDato().getContrasena()) + " " + QString::fromStdString(nuevaContra);
                            QMessageBox::information(nullptr, "   ", mensaje);
                return true;
            }else{
                ptrAct = ptrAct->SigPtr;
            }
        }
        return false;
    }
    return false;

}
#endif // LISTAD_H
