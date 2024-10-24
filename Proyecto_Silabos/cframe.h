#ifndef CFRAME_H
#define CFRAME_H

#include <QMainWindow>
#include <QtSql>

#include "Usuario.h"
#include "Clase.h"
#include "arbolb.h"
#include "listaD.h"
#include "nodoD.h"

QT_BEGIN_NAMESPACE
namespace Ui { class cframe; }
QT_END_NAMESPACE

class cframe : public QMainWindow
{
    Q_OBJECT

public:
    cframe(QWidget *parent = NULL);
    ~cframe();

private slots:
    void on_Mbtn_ingresar_clicked(); //login
    void on_Acb_acciones_currentIndexChanged(int index); //no usado, no borrar, conflicto en ui
    void on_btn_sesion_clicked(); //se encuentra debajo en CADA tab, puede mostrar info de bienvenida o opcion de cerrar sesión
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
    void on_pushButton_clicked();
    void on_Itw_usuarios_cellClicked(int row, int column);
    void on_Brb_aprobados_clicked();
    void on_Brb_proceso_clicked();
    void on_Rtw_revision_cellClicked(int row, int column);
    void on_Ftw_feed_cellClicked(int row, int column);
    void on_Btw_dashboard_cellClicked(int row, int column);
    void on_Ftw_feed_cellActivated(int row, int column);

    void on_Mcb_tipo_currentIndexChanged(int index);

private:
    Ui::cframe *ui;

    void visibilidad();
    //variables para actualizar el cframe admin
    QString nombre,numero_cuenta,tipo_usuario;
    QString password;
    //relacionado con DB
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    QString connectionString = QString("Driver={ODBC Driver 18 for SQL Server};Server=tcp:estrudatosii.database.windows.net,1433;Database=ProyectoTest;Uid=rajuria;Pwd={TobiichiOrigami11!};Encrypt=yes;TrustServerCertificate=no;Connection Timeout=30;");
    QList<Usuario> DescargarUsuarios();
    QList<Clase> DescargarClases();
    QList<Silabos> DescargarListaSilabos();
    QList<Silabos> SilabosDescargados;
    void DescargarSilabos();
    QString Encrypt(QString, int);
    QString Decrypt(QString, int);
    int Key=980487;
    QList<Usuario> UsuariosRegistrados;
    QList<Clase> ClasesAgregadas;
    QStringList Sedes;
    QStringList Facultades;
    QStringList Carreras;
    QStringList Clases;
    QByteArray docx2BA(QString);
    void BA2docx(QByteArray, QString);
    void SubirSilabo(QString, QByteArray);
    QByteArray DescargarSilabo(QString);
    void Conectar();
    void Su();

    //HASTA AQUI+
    arbolB *arbol;

    void MostrarSilabos();
    void mostrarUsuarios();
    listaD<Usuario> listaUsuarios;
    nodoD<Usuario> *actD;
    nodoD<Usuario> *ultD;
    bool cuentaNumero(const std::string &tt);

    void SubirDatos(); //DB
    void mostrarSilabosBoard(bool aprobado);
    void mostrarSilabosFeed(QString cuenta);
    short tipo;

    bool cambiarPath=false, cambiarEstado=false;
    void modificarDatosSilabo(int id,QString pathNuevo, bool silabo);
    int id=0;

    QString cargarArchivo(QString nombre,bool);

    void cambiarSilabo(int id, QString pathActual,short i);

    //relacionado con SILABOS

    //relacionado con DB

    //relacionado con USUARIOS

    void insertarUser();




};
#endif // CFRAME_H
