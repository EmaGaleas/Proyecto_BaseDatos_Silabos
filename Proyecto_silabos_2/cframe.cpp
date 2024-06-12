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
    ui->tabWidget->setCurrentIndex(0);

    visibilidad();
    ui->tabWidget->tabBar()->hide();

    QImage menu(":/new/prefix1/menu.png");
    ui->lbl_png->setPixmap(QPixmap::fromImage(menu));
//    ui->lbl_color1->setStyleSheet("background-color: #A61400;");
//    ui->lbl_color2->setStyleSheet("background-color: #A61400;");
//    ui->lbl_color3->setStyleSheet("background-color: #A61400;");
//    ui->lbl_color4->setStyleSheet("background-color: #A61400;");
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


void cframe::on_Acb_acciones_currentIndexChanged(int index)
{}

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

