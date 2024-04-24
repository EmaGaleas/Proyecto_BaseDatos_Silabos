#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
#include <string>

using std::string;

class Usuario{
    friend class MainWindow;

private:
    string name,cuenta,tipo;
public:
    string contrasena;
    Usuario();
    Usuario(string name, string cuenta,string tipo,string contrasena);
    ~Usuario();

//los numeros de cuenta deben de ser de 8 digitos, unicos y fijos para un manejo estandar y organizado

    const string &getName() const;
    void setName(const string &newName);
    const string &getCuenta() const;
    void setCuenta(const string &newCuenta);
    const string &getTipo() const;
    void setTipo(const string &newTipo);
    const string &getContrasena() const;
    void setContrasena(string &newContrasena);
};





#endif // USUARIO_H
