#ifndef HISTORIAL_SILABOS_H
#define HISTORIAL_SILABOS_H
#include "Silabos.h"

class Historial_Silabos : public Silabos {
private:
    int id;
    QString codigoClase;
    QString rutaUltimaModificacion;
    QString fechaUltimaModificacion;
    QString numeroCuentaModificadoPor;
    QString rutaSilaboOriginal;
    QString numeroCuentaConsultorAsignado;
    bool reforma;

public:
    // Constructor predeterminado
    Historial_Silabos()
        : id(0), reforma(false) {}

    // Constructor parametrizado
    Historial_Silabos(int id, QString codigoClase, QString rutaUltimaModificacion, QString fechaUltimaModificacion,
                      QString numeroCuentaModificadoPor, QString rutaSilaboOriginal,
                      QString numeroCuentaConsultorAsignado, bool reforma)
        : id(id), codigoClase(codigoClase), rutaUltimaModificacion(rutaUltimaModificacion),
          fechaUltimaModificacion(fechaUltimaModificacion), numeroCuentaModificadoPor(numeroCuentaModificadoPor),
          rutaSilaboOriginal(rutaSilaboOriginal), numeroCuentaConsultorAsignado(numeroCuentaConsultorAsignado),
          reforma(reforma) {}

    // Getters
    int getId() const {
        return id;
    }

    QString getCodigoClase() const {
        return codigoClase;
    }

    QString getRutaUltimaModificacion() const {
        return rutaUltimaModificacion;
    }

    QString getFechaUltimaModificacion() const {
        return fechaUltimaModificacion;
    }

    QString getNumeroCuentaModificadoPor() const {
        return numeroCuentaModificadoPor;
    }

    QString getRutaSilaboOriginal() const {
        return rutaSilaboOriginal;
    }

    QString getNumeroCuentaConsultorAsignado() const {
        return numeroCuentaConsultorAsignado;
    }

    bool getReforma() const {
        return reforma;
    }

    // Setters
    void setId(int nuevoId) {
        id = nuevoId;
    }

    void setCodigoClase(const QString& nuevoCodigoClase) {
        codigoClase = nuevoCodigoClase;
    }

    void setRutaUltimaModificacion(const QString& nuevaRutaUltimaModificacion) {
        rutaUltimaModificacion = nuevaRutaUltimaModificacion;
    }

    void setFechaUltimaModificacion(const QString& nuevaFechaUltimaModificacion) {
        fechaUltimaModificacion = nuevaFechaUltimaModificacion;
    }

    void setNumeroCuentaModificadoPor(const QString& nuevoNumeroCuentaModificadoPor) {
        numeroCuentaModificadoPor = nuevoNumeroCuentaModificadoPor;
    }

    void setRutaSilaboOriginal(const QString& nuevaRutaSilaboOriginal) {
        rutaSilaboOriginal = nuevaRutaSilaboOriginal;
    }

    void setNumeroCuentaConsultorAsignado(const QString& nuevoNumeroCuentaConsultorAsignado) {
        numeroCuentaConsultorAsignado = nuevoNumeroCuentaConsultorAsignado;
    }

    void setReforma(bool nuevaReforma) {
        reforma = nuevaReforma;
    }

    void imprimirHistorial() const {
        imprimir(); // Llama al método de la clase base
        std::cout << "ID Historial: " << id << "\n"
                  << "Código de Clase: " << codigoClase.toStdString() << "\n"
                  << "Ruta de Última Modificación: " << rutaUltimaModificacion.toStdString() << "\n"
                  << "Fecha de Última Modificación: " << fechaUltimaModificacion.toStdString() << "\n"
                  << "Modificado Por: " << numeroCuentaModificadoPor.toStdString() << "\n"
                  << "Ruta del Silabo Original: " << rutaSilaboOriginal.toStdString() << "\n"
                  << "Consultor Asignado: " << numeroCuentaConsultorAsignado.toStdString() << "\n"
                  << "Reforma: " << (reforma ? "Sí" : "No") << "\n";
    }
};



#endif // HISTORIAL_SILABOS_H
