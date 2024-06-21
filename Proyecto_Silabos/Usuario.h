#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
#include <string>
#include <QApplication>


using std::string;

class Usuario{
    friend class cframe;
private:

    string Nombre,ContrasenaActual,ContrasenaAnterior;
    short Tipo;
    int NumeroCuenta;

public:
    Usuario( int cuenta, string nombre,string contraActual, string contraAnterior,short tipo)
        : NumeroCuenta(cuenta),Nombre(nombre), ContrasenaActual(contraActual),ContrasenaAnterior(contraAnterior),Tipo(tipo){

    }
    ~Usuario(){}

    /*TIPO SI
    1-DOCENTE
    2-DIRECTORES
    3-DECANOS
    4-JEFE ACADEMICO
    5-COORDINADOR DE CARRERA
    6-IEDD
    7-CONSULTOR
    PONER TIPO EN NEGATIVO SI SE APRUEBA CAMBIO DE CONTRA
    */

    void setNombre(const string& nombreN) {
        Nombre = nombreN;
    }
    void setContraActual(const string& contraActualN) {
        ContrasenaActual = contraActualN;
    }

    void setContraAnterior(const string& contraAnteriorN) {
        ContrasenaAnterior = contraAnteriorN;
    }

    void setTipo(short tipoN) {
        Tipo = tipoN;
    }
    void setCuenta(int cuentaN) {
        NumeroCuenta = cuentaN;
    }

    // Getters
    string getNombre() const        {return Nombre;}

    string getContraActual() const  {return ContrasenaActual;}

    string getContraAnterior() const{return ContrasenaAnterior;}

    short getTipo() const           {return Tipo;}

    int getCuenta() const           {return NumeroCuenta;}


};

#endif // USUARIO_H
