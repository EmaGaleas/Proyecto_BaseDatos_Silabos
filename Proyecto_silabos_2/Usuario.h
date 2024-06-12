#ifndef USUARIO_H
#define USUARIO_H


#include <iostream>
#include <string>

using std::string;

class Usuario{
    friend class cframe;
private:
    string nombre,contraActual,contraAnterior;
    short tipo;
    int cuenta;
public:
    Usuario( int cuenta, string nombre,string contraActual, string contraAnterior,short tipo)
        : cuenta(cuenta),nombre(nombre), contraActual(contraActual),contraAnterior(contraAnterior),tipo(tipo){

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
        nombre = nombreN;
    }
    void setContraActual(const string& contraActualN) {
        contraActual = contraActualN;
    }

    void setContraAnterior(const string& contraAnteriorN) {
        contraAnterior = contraAnteriorN;
    }

    void setTipo(short tipoN) {
        tipo = tipoN;
    }
    void setCuenta(int cuentaN) {
        cuenta = cuentaN;
    }

    // Getters
    string getNombre() const        {return nombre;}

    string getContraActual() const  {return contraActual;}

    string getContraAnterior() const{return contraAnterior;}

    short getTipo() const           {return tipo;}

    int getCuenta() const           {return cuenta;}


};

#endif // USUARIO_H
