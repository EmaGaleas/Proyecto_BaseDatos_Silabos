#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
#include <string>
#include <QApplication>
using std::string;

class Usuario{
    friend class cframe;
private:

    QString Nombre, ContrasenaActual, ContrasenaAnterior, NumeroCuenta;
    short Tipo, sede;

public:
    Usuario( QString cuenta, QString nombre,QString contraActual, QString contraAnterior,short tipo, short sede)
        : NumeroCuenta(cuenta),Nombre(nombre), ContrasenaActual(contraActual),ContrasenaAnterior(contraAnterior),Tipo(tipo), sede(sede){

    }
    ~Usuario(){}

    void setNombre              (const QString& nombreN)            { Nombre = nombreN; }
    void setContraActual        (const QString& contraActualN)      { ContrasenaActual = contraActualN; }
    void setContraAnterior      (const QString& contraAnteriorN)    { ContrasenaAnterior = contraAnteriorN; }
    void setCuenta              (int cuentaN)                       { NumeroCuenta = cuentaN; }
    void setSede                (short newSede)                     { sede = newSede; }
    void setTipo                (short tipoN)                       { Tipo = tipoN; }


    QString getNombre()         const                               {return Nombre;}
    QString getContraActual()   const                               {return ContrasenaActual;}
    QString getContraAnterior() const                               {return ContrasenaAnterior;}
    QString getCuenta()         const                               {return NumeroCuenta;}
    QString getEstado()         const                               {return NumeroCuenta;}
    short getSede()             const                               {return sede;}
    short getTipo()             const                               {return Tipo;}

    ;
};
#endif // USUARIO_H

/*TIPO SI
1-DOCENTE
2-DIRECTORES
3-DECANOS
4-JEFE ACADEMICO
5-COORDINADOR DE CARRERA
6-IEDD
7-CONSULTOR
PONER TIPO EN NEGATIVO SI SE APRUEBA CAMBIO DE CONTRA

SEDE
0-UNITEC
1-CEUTEC
2-AMBOS
*/
