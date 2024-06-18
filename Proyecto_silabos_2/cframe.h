#ifndef CFRAME_H
#define CFRAME_H

#include <QMainWindow>
#include <QApplication>
#include <QProcess>
#include <QList>
#include <QtSql>
#include <QMessageBox>

#include <QFile>
#include <QByteArray>
#include <QString>

#include "Usuario.h"
#include "Clases.h"
#include "listaD.h"
#include "nodoD.h"

QT_BEGIN_NAMESPACE
namespace Ui { class cframe; }
QT_END_NAMESPACE

class cframe : public QMainWindow
{
    Q_OBJECT

public:
    cframe(QWidget *parent = nullptr);
    ~cframe();
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    QString connectionString = QString("Driver={ODBC Driver 18 for SQL Server};Server=tcp:estrudatosii.database.windows.net,1433;Database=ProyectoTest;Uid=rajuria;Pwd={TobiichiOrigami11!};Encrypt=yes;TrustServerCertificate=no;Connection Timeout=30;");
    //QList<Usuario> DescargarUsuarios();
    QList<Clase> DescargarClases();
    void ConectarBase();

private slots:
    void on_Mbtn_ingresar_clicked();
    void on_Acb_acciones_currentIndexChanged(int index);
    void on_btn_sesion_clicked();
    void on_Ecb_sede_currentIndexChanged(int index);
    void on_Rbtn_cambiar_clicked();
    void on_Abtn_cambioContra_clicked();
    void on_Acb_acciones_currentIndexChanged(const QString &arg1);
    void on_Ebtn_archivo_clicked();
    void on_Ebtn_fechas_clicked();
    void on_Ebtn_enviar_clicked();


    void on_Ecb_sede_currentIndexChanged(const QString &arg1);

    void on_Ecb_facultad_currentIndexChanged(const QString &arg1);

    void on_Ecb_carrera_currentIndexChanged(const QString &arg1);

private:
    Ui::cframe *ui;
    void visibilidad();
    //variables para actualizar el cframe admin
    QString nombre,numero_cuenta,tipo_usuario;
    QString password;

    //criptografia aplica en usuarios
//    QString Encrypt(QString, int);
//    QString Decrypt(QString, int);
  //  int Key=980487;

    //referente a usuarios
   // QList<Usuario> UsuariosRegistrados;

    listaD<Usuario> listaUsuarios;
    nodoD<Usuario> *actD;
    nodoD<Usuario> *ultD;

    //referente a clases
    QList<Clase> ClasesAgregadas;
    QStringList Sedes;
    QStringList Facultades;
    QStringList Carreras;
    QStringList Clases;
    void cargarClasesDB();

    //referente a archivos
    QByteArray docx2BA(QString);
    void BA2docx(QByteArray, QString);
    void SubirSilabo(QString, QByteArray);
    QByteArray DescargarSilabo(QString);
};
#endif // CFRAME_H
