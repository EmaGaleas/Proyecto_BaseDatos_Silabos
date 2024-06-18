#include "cframe.h"
#include "ui_cframe.h"

#include <QtWidgets>
#include <QImage>
#include <QPixmap>
#include <QLabel>
#include <istream>
#include <string>
#include <sstream>
#include <QMessageBox>
#include <QDesktopServices>
#include <QUrl>
#include <QFileDialog>
#include <QProcess>
#include <fstream>
#include <iostream>
#include <sstream>
#include <QDateTime>
#include <cstdlib>
#include <ctime>
using std::ofstream;
using std::ios;
using std::string;
using std::ios;
using std::cout;

cframe::cframe(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::cframe)
{
    ui->setupUi(this);
    ConectarBase();
    cargarClasesDB();
    ui->tabWidget->setCurrentIndex(0);

    visibilidad();
    ui->tabWidget->tabBar()->hide();

    QImage menu(":/new/prefix1/menu.png");
    ui->lbl_png->setPixmap(QPixmap::fromImage(menu));
    ui->lbl_png->setStyleSheet("background-color: #A61400;");
}

cframe::~cframe()
{
    delete ui;
}

void cframe::visibilidad()
{
    if(ui->tabWidget->currentIndex()==0){
        QImage menu(":/new/prefix1/menu.png");
        ui->lbl_png->setPixmap(QPixmap::fromImage(menu));
    }else if(ui->tabWidget->currentIndex()==1){
        ui->btn_sesion->setText("VOLVER A MENU");
        ui->btn_sesion->setVisible(true);
        QImage menu(":/new/prefix1/entrega.png");
        ui->lbl_png->setPixmap(QPixmap::fromImage(menu));
    }else if(ui->tabWidget->currentIndex()==2){
        ui->btn_sesion->setText("VOLVER A MENU");
        ui->btn_sesion->setVisible(true);
        QImage menu(":/new/prefix1/revision.png");
        ui->lbl_png->setPixmap(QPixmap::fromImage(menu));

    }else if(ui->tabWidget->currentIndex()==3){
        ui->btn_sesion->setText("VOLVER A MENU");
        ui->btn_sesion->setVisible(true);
        QImage menu(":/new/prefix1/dashboard.png");
        ui->lbl_png->setPixmap(QPixmap::fromImage(menu));

    }else if(ui->tabWidget->currentIndex()==4){
        ui->btn_sesion->setText("VOLVER A MENU");
        ui->btn_sesion->setVisible(true);
        QImage menu(":/new/prefix1/actividad.png");
        ui->lbl_png->setPixmap(QPixmap::fromImage(menu));

    }else if(ui->tabWidget->currentIndex()==5){
        ui->btn_sesion->setText("CERRAR SESION");
        ui->btn_sesion->setVisible(true);
        QImage menu(":/new/prefix1/ingresado.png");
        ui->lbl_png->setPixmap(QPixmap::fromImage(menu));

    }
}
void cframe::on_Mbtn_ingresar_clicked(){
    if(ui->Mle_cuenta->text().isEmpty()||ui->Mle_contra->text().isEmpty()||ui->Mle_name->text().isEmpty()||ui->Mcb_tipo->currentText() == "..."){
        QMessageBox::critical(this, "Error", "Porfavor llenar todos los Espacios!");

    }else{
        ui->Albl_cuenta->setText(ui->Mle_cuenta->text());
        ui->Albl_tipo->setText(ui->Mcb_tipo->currentText());
        ui->Albl_username->setText(ui->Mle_name->text());

        if(ui->Mcb_tipo->currentIndex()==1){
            QStringList acciones;
            acciones << "..." << "FEED" << "ENTREGAR";
            ui->Acb_acciones->addItems(acciones);

        }else if(ui->Mcb_tipo->currentIndex()==2||ui->Mcb_tipo->currentIndex()==3){
            QStringList acciones;
            acciones << "..." << "BOARD";
            ui->Acb_acciones->addItems(acciones);
        }else if(ui->Mcb_tipo->currentIndex()==4||ui->Mcb_tipo->currentIndex()==5||ui->Mcb_tipo->currentIndex()==6||ui->Mcb_tipo->currentIndex()==7){
            QStringList acciones;
            acciones << "..." << "REVISION";
            ui->Acb_acciones->addItems(acciones);
        }
        ui->Mle_cuenta->clear();
        ui->Mle_contra->clear();
        ui->Mle_name->clear();

        ui->tabWidget->setCurrentIndex(5);
        ui->btn_sesion->setVisible(true);
    }


    visibilidad();
}
void cframe::on_Acb_acciones_currentIndexChanged(int index){}
void cframe::on_btn_sesion_clicked()
{
    if(ui->tabWidget->currentIndex() ==0){

    }else{
        if(ui->tabWidget->currentIndex() != 5){
            ui->tabWidget->setCurrentIndex(5);
        } else {
            ui->Acb_acciones->clear();
            ui->Mcb_tipo->setCurrentIndex(0);
            ui->tabWidget->setCurrentIndex(0);
            ui->btn_sesion->setText("BIENVENIDO");
        }
        visibilidad();
    }
}
void cframe::on_Ecb_sede_currentIndexChanged(int index)
{
    if(index==1){
        ui->Elbl_fechas->setVisible(true);
        ui->Elbl_path_fechas->setVisible(true);
        ui->Ebtn_fechas->setVisible(true);
    }else if(index==2){
        ui->Elbl_fechas->setVisible(false);
        ui->Elbl_path_fechas->setVisible(false);
        ui->Ebtn_fechas->setVisible(false);
    }
}
void cframe::on_Rbtn_cambiar_clicked()
{

    if(ui->Rle_seleccion->text().isEmpty()||ui->Rle_comentarios->text().isEmpty()||ui->Rle_estadoActual->text().isEmpty()||ui->Rlbl_estado->text().isEmpty()||ui->Rcb_estadoCambiar->currentText() == "..."){
        QMessageBox::critical(this, "Error", "Porfavor llenar todos los Espacios!");
    }

}
void cframe::on_Abtn_cambioContra_clicked()
{
    bool ok;
    while (true) {
        QString newPassword = QInputDialog::getText(this, "Nueva Contrseña", "Ingrese la Nueva Contraseña:", QLineEdit::Password, "", &ok);
        if (!ok) {
            return;
        }
        if (newPassword.isEmpty()) {
            QMessageBox::critical(this, "Error", "Porfavor ingrese una contraseña valida");
        } else {
            password = newPassword;
            QMessageBox::information(this, "Enviado", "Su solicitud fue enviada.");
            return;
        }
    }
}
void cframe::on_Acb_acciones_currentIndexChanged(const QString &arg1)
{
    if(arg1=="ENTREGAR"){
        ui->tabWidget->setCurrentIndex(1);
    }else if(arg1=="REVISION"){
        ui->tabWidget->setCurrentIndex(2);
    }else if(arg1=="BOARD"){
        ui->tabWidget->setCurrentIndex(3);
    }else if(arg1=="FEED"){
        ui->tabWidget->setCurrentIndex(4);
    }else if(arg1=="..."){

    }
    ui->Acb_acciones->setCurrentIndex(0);
    visibilidad();

}
void cframe::on_Ebtn_archivo_clicked()
{
    if(ui->Ecb_sede->currentText() == "..."||ui->Ecb_carrera->currentText() == "..."||ui->Ecb_facultad->currentText() == "..."||ui->Ecb_clases->currentText() == "..."){
        QMessageBox::critical(this, "Error", "Porfavor llenar todos los Espacios!");

    }else{
    QString filePath = QFileDialog::getOpenFileName(this, "Explorador de Archivos DOC", QDir::homePath(), "Document Files (*.doc *.docx)");
    if (!filePath.isEmpty()) {
        ui->Elbl_path_archivo->setText(filePath);
    }
    }


}
void cframe::on_Ebtn_fechas_clicked()
{
    if(ui->Ecb_sede->currentText() == "..."||ui->Ecb_carrera->currentText() == "..."||ui->Ecb_facultad->currentText() == "..."||ui->Ecb_clases->currentText() == "..."){
        QMessageBox::critical(this, "Error", "Porfavor llenar todos los Espacios!");

    }else{
    QString filePath = QFileDialog::getOpenFileName(this, "Explorador de Archivos DOC", QDir::homePath(), "Document Files (*.doc *.docx)");
    if (!filePath.isEmpty()) {
        ui->Elbl_path_fechas->setText(filePath);
    }
    }

}
void cframe::on_Ebtn_enviar_clicked()
{
    //volver a inicializar en 0 los indices para que se muestren ...
    ui->Ecb_carrera->setCurrentIndex(0);
    ui->Ecb_facultad->setCurrentIndex(0);
    ui->Ecb_sede->setCurrentIndex(0);
    ui->Ecb_clases->setCurrentIndex(0);
    ui->Elbl_path_fechas->clear();
    ui->Elbl_path_archivo->clear();
}

//relacionado con las clases disponibles en UNITEC / CEUTEC
QList<Clase> cframe::DescargarClases()
{
    QList<Clase> ClasesDescargadas;
    QSqlQuery *Query = new QSqlQuery();
    Query->prepare("select * from SilabosClases");
    Query->exec();
    short CurrentRow=0;
    while(Query->next())
    {
        //    Clase(string CodigoClase,string Nombre, string Carrera,string Facultad, bool Sede);
        Clase* Temp = new Clase(Query->value(0).toString(),Query->value(4).toString(),Query->value(1).toString(),Query->value(2).toString(),Query->value(3).toString());
        ClasesDescargadas.append(*Temp);

        delete Temp;
        CurrentRow++;
    }
    return ClasesDescargadas;
}
void cframe::cargarClasesDB()
{
    db.open();
    ClasesAgregadas=DescargarClases();
    db.close();
    Sedes.clear();
    for(int i=0;i<ClasesAgregadas.size();i++)
    {
        Sedes.append(ClasesAgregadas[i].Sede);

    }
    QSet<QString> temp = QSet<QString>::fromList(Sedes);
    Sedes = temp.toList();
    //clear a todos los cb
//    ui->Ecb_sede->clear();
//    ui->Ecb_facultad->clear();
//    ui->Ecb_carrera->clear();
//    ui->Ecb_clases->clear();
}

void cframe::ConectarBase()
{
    QGuiApplication::setOverrideCursor(Qt::WaitCursor);
    db.setDatabaseName(connectionString);
    if(db.open())
    {
       listaUsuarios.DescargarUsuarios();
        QGuiApplication::restoreOverrideCursor();
        QMessageBox::information(this,"Exito!","Conectado a Azure SQL Database");
    }
    else
    {
        QGuiApplication::restoreOverrideCursor();
        QMessageBox::critical(this,"Error en la conexion!","No ha sido posible conectar con el servidor. Intentelo de nuevo.");
    }
    db.close();
}


void cframe::on_Ecb_sede_currentIndexChanged(const QString &arg1)
{
    Facultades.clear();
    Facultades.append("...");
    for(int i=0;i<ClasesAgregadas.size();i++)
    {
        if(ClasesAgregadas[i].Sede==arg1)
            Facultades.append(ClasesAgregadas[i].Facultad);
    }
    QSet<QString> temp = QSet<QString>::fromList(Facultades);
    Facultades = temp.toList();
    ui->Ecb_facultad->clear();
    ui->Ecb_carrera->clear();
    ui->Ecb_clases->clear();

    ui->Ecb_facultad->addItems(Facultades);

}


void cframe::on_Ecb_facultad_currentIndexChanged(const QString &arg1)
{
    Carreras.clear();
    Carreras.append("...");
    for(int i=0;i<ClasesAgregadas.size();i++)
    {
        if(ClasesAgregadas[i].Facultad==arg1 && ClasesAgregadas[i].Sede==ui->Ecb_sede->currentText())
            Carreras.append(ClasesAgregadas[i].Carrera);
    }
    QSet<QString> temp = QSet<QString>::fromList(Carreras);
    Carreras = temp.toList();
    ui->Ecb_carrera->clear();
    ui->Ecb_clases->clear();
    ui->Ecb_carrera->addItems(Carreras);
}


void cframe::on_Ecb_carrera_currentIndexChanged(const QString &arg1)
{
    Clases.clear();
    Clases.append("...");
    for(int i=0;i<ClasesAgregadas.size();i++)
    {
        if(ClasesAgregadas[i].Carrera==arg1 && ClasesAgregadas[i].Sede==ui->Ecb_sede->currentText() && ClasesAgregadas[i].Facultad==ui->Ecb_facultad->currentText())
            Clases.append(ClasesAgregadas[i].Nombre);
    }
    QSet<QString> temp = QSet<QString>::fromList(Clases);
    Clases = temp.toList();
    ui->Ecb_clases->clear();
    ui->Ecb_clases->addItems(Clases);
}

