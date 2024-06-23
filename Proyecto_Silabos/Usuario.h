#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
#include <string>
#include <QApplication>


using std::string;

class Usuario{
    friend class cframe;
private:

    QString Nombre,ContrasenaActual,ContrasenaAnterior;
    short Tipo;
    QString NumeroCuenta;

public:
    Usuario( QString cuenta, QString nombre,QString contraActual, QString contraAnterior,short tipo)
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

    void setNombre(const QString& nombreN) {
        Nombre = nombreN;
    }
    void setContraActual(const QString& contraActualN) {
        ContrasenaActual = contraActualN;
    }

    void setContraAnterior(const QString& contraAnteriorN) {
        ContrasenaAnterior = contraAnteriorN;
    }

    void setTipo(short tipoN) {
        Tipo = tipoN;
    }
    void setCuenta(int cuentaN) {
        NumeroCuenta = cuentaN;
    }

    // Getters
    QString getNombre() const        {return Nombre;}

    QString getContraActual() const  {return ContrasenaActual;}

    QString getContraAnterior() const{return ContrasenaAnterior;}

    short getTipo() const           {return Tipo;}

    QString getCuenta() const           {return NumeroCuenta;}

};

#endif // USUARIO_H
