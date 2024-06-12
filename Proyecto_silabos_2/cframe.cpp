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
    ui->lbl_color1->setStyleSheet("background-color: #000000;");
    ui->lbl_color2->setStyleSheet("background-color: #000000;");
    ui->lbl_color3->setStyleSheet("background-color: #000000;");
    ui->lbl_color4->setStyleSheet("background-color: #000000;");
    ui->lbl_png->setStyleSheet("background-color: #000000;");

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


void cframe::on_Mbtn_ingresar_clicked()
{

    ui->tabWidget->setCurrentIndex(5);
    ui->btn_sesion->setVisible(true);

    visibilidad();
}


void cframe::on_Acb_acciones_currentIndexChanged(int index)
{
    if(index==1){
        ui->tabWidget->setCurrentIndex(1);
    }else if(index==2){
        ui->tabWidget->setCurrentIndex(2);
    }else if(index==3){
        ui->tabWidget->setCurrentIndex(3);
    }else if(index==4){
        ui->tabWidget->setCurrentIndex(4);
    }
    ui->Acb_acciones->setCurrentIndex(0);
    visibilidad();
}

void cframe::on_btn_sesion_clicked()
{
    if(ui->tabWidget->currentIndex() ==0){

    }else{
        if(ui->tabWidget->currentIndex() != 5){
            ui->tabWidget->setCurrentIndex(5);
        } else {
            ui->tabWidget->setCurrentIndex(0);
            ui->btn_sesion->setText("BIENVENIDO");
        }
        visibilidad();
    }


}


