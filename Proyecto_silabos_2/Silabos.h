#ifndef SILABOS_H
#define SILABOS_H


#include <string>
#include <QString>

using std::string;
using std::ofstream;

class Silabo {
private:
    string facultad;//
    string carrera;//
    int insertadoPor;//
    string datosClase;//
    QString rutaSilabos;//
    QString rutaFechas;//

    string estado;
    string observacion; // Para que digan que quieren de cambi

    int id; // Para mantener track de los archivos
    short numRevisiones; // Para contar cuantas veces se ha revisado el silabo
    short numRechazado;//veces que ha sido rechazado
    short visibilidad;//quien lo puede revisar segun estado

public:

    Silabo(int id,string facultad, string carrera, int insertadoPor, string datosClase, QString rutaSilabos,QString rutaFechas, string estado, string observacion,  short numRevisiones,short numRechazados, short visibilidad)
        :  id(id),facultad(facultad), carrera(carrera), insertadoPor(insertadoPor), datosClase(datosClase),rutaSilabos(rutaSilabos),rutaFechas(rutaFechas),estado(estado), observacion(observacion), numRevisiones(numRevisiones),numRechazado(numRechazados),visibilidad(visibilidad){
    }
    ~Silabo(){}

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

    long toNum() const {
        long val = 0;
        for (int i = 0; i < datosClase.size(); i++) {
            char c = datosClase[i];
            val += c;
        }

        return val;
    }

};


#endif // SILABOS_H
