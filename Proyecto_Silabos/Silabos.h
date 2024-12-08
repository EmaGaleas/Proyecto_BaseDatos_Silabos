
#ifndef SILABOS_H
#define SILABOS_H

#include <string>
#include <QString>
#include <iostream>

using std::string;

class Silabos {
private:
    string facultad;
    string carrera;
    int insertadoPor;
    string datosClase;
    QString rutaSilabos;
    QString rutaFechas;
    string estado;
    string observacion;
    int id;
    short numRevisiones;
    short numRechazado;
    short visibilidad;

public:
    // Constructor predeterminado
    Silabos() :  numRevisiones(0), numRechazado(0), visibilidad(0) {}

    // Constructor parametrizado
    Silabos( string facultad, string carrera, int id, int insertadoPor, string datosClase, QString rutaSilabos,  QString rutaFechas, string estado, string observacion, short numRevisiones, short numRechazado, short visibilidad)
        : facultad(facultad), carrera(carrera), insertadoPor(insertadoPor), datosClase(datosClase), rutaSilabos(rutaSilabos), rutaFechas(rutaFechas), estado(estado), observacion(observacion), numRevisiones(numRevisiones), numRechazado(numRechazado), visibilidad(visibilidad) {
    }

    ~Silabos() {}

    // Getters
    string getFacultad() const {
        return facultad;
    }

    string getCarreras() const {
        return carrera;
    }

    int getInsertadoPor() const {
        return insertadoPor;
    }

    string getDatosClase() const {
        return datosClase;
    }

    QString getRutaSilabos() const {
        return rutaSilabos;
    }

    QString getRutaFechas() const {
        return rutaFechas;
    }

    string getEstado() const {
        return estado;
    }

    string getObservacion() const {
        return observacion;
    }

    int getId() const {
        return id;
    }

    short getNumRevisiones() const {
        return numRevisiones;
    }

    short getNumRechazados() const {
        return numRechazado;
    }

    short getVisibilidad() const {
        return visibilidad;
    }

    // Setters
    void setFacultad(const string& nuevaFacultad) {
        facultad = nuevaFacultad;
    }

    void setCarreras(const string nuevasCarreras) {
        carrera = nuevasCarreras;
    }

    void setInsertadoPor(int insertadoPorN) {
        insertadoPor = insertadoPorN;
    }

    void setDatosClase(const string& datosClaseN) {
        datosClase = datosClaseN;
    }

    void setRutaSilabos(const QString& rutaSilabosN) {
        rutaSilabos = rutaSilabosN;
    }

    void setRutaFechas(const QString& rutaFechasN) {
        rutaFechas = rutaFechasN;
    }

    void setEstado(const string& nuevoEstado) {
        estado = nuevoEstado;
    }

    void setObservacion(const string& nuevaObservacion) {
        observacion = nuevaObservacion;
    }

    void setId(int nuevoId) {
        id = nuevoId;
    }

    void setNumRevisiones(short nuevoNumRevisiones) {
        numRevisiones = nuevoNumRevisiones;
    }

    void setNumRechazado(short nuevoNumRechazado) {
        numRechazado = nuevoNumRechazado;
    }

    void setVisibilidad(short nuevoVisibilidad) {
        visibilidad = nuevoVisibilidad;
    }

    // Método para convertir datos de clase a un valor numérico
    long toNum() const {
        long val = 0;
        for (size_t i = 0; i < datosClase.size(); i++) {
            char c = datosClase[i];
            val += c;
        }
        return val;
    }

    // Método para imprimir los detalles del Silabo
    void imprimir() const {
        std::cout << "ID: " << id << "\n"
                  << "Facultad: " << facultad << "\n"
                  << "Carrera: " << carrera << "\n"
                  << "Insertado por: " << insertadoPor << "\n"
                  << "Datos de clase: " << datosClase << "\n"
                  << "Ruta de Silabos: " << rutaSilabos.toStdString() << "\n"
                  << "Ruta de Fechas: " << rutaFechas.toStdString() << "\n"
                  << "Estado: " << estado << "\n"
                  << "Observación: " << observacion << "\n"
                  << "Número de Revisiones: " << numRevisiones << "\n"
                  << "Número de Rechazados: " << numRechazado << "\n"
                  << "Visibilidad: " << visibilidad << "\n";
    }
    const string &getSede() const;
};
#endif // SILABOS_H
