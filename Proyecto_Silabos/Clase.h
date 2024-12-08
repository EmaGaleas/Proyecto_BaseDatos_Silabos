#ifndef CLASE_H
#define CLASE_H
#include <QApplication>

class Clase{
    public:
    Clase();
    Clase(QString,QString,QString,QString,QString);
    ~Clase();
    QString CodigoClase, Nombre, Carrera, Facultad, Sede;
};

inline Clase::Clase(QString Codigo, QString Nombre, QString Carrera, QString Facultad, QString Sede)
{
    this->CodigoClase=Codigo;
    this->Nombre=Nombre;
    this->Carrera=Carrera;
    this->Facultad=Facultad;
    this->Sede=Sede;
}

inline Clase::~Clase()  {}

#endif // CLASE_H
