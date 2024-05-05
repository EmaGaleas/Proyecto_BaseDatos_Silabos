 #include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QImage>
#include <QPixmap>
#include <QLabel>
#include <istream>
#include <iostream>
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
using std::ofstream;
using std::ios;
using std::string;
using std::ios;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , arbolB(5)
{

    ui->setupUi(this);
    ui->tabWidget->tabBar()->hide(); //EL PODEROSO HIDE TAB

    //imagenes y label color
    QImage menu(":/prefix/principal proyecto.png");
    ui->lbl_pngMenu->setPixmap(QPixmap::fromImage(menu));
    ui->frameMI->setVisible(false);
   ui->btn_CerrarSesion->setVisible(false);
   ui->Btn_CambContra->setVisible(false);
   ui->btn_cambusuario->setVisible(false);
   ui->RB_Board->setVisible(false);
   ui->RB_Entrega->setVisible(false);
   ui->RB_Rastreo->setVisible(false);
    ui->RB_Revision->setVisible(false);


    //ui->lbl_b1M->setStyleSheet("background-color: #062458;");
    ui->lbl_b2M->setStyleSheet("background-color: #750512;");
    ui->btn_IniciarSesion->setStyleSheet("background-color: #062458;");
    ui->btn_CerrarSesion->setStyleSheet("background-color: #062458;");
    QImage entrega(":/prefix/1.png");
    ui->lbl_pngE->setPixmap(QPixmap::fromImage(entrega));
    ui->Dlbl_png->setPixmap(QPixmap::fromImage(entrega));

    QImage revision(":/prefix/2.png");
    ui->lbl_pngR->setPixmap(QPixmap::fromImage(revision));
    QImage dash(":/prefix/3.png");
    ui->lbl_pngD->setPixmap(QPixmap::fromImage(dash));

    //hides iniciales

    //añade las opciones al combobox
    ui->CB_Cargo->addItem("JEFE_ACADEMICO");
    ui->CB_Cargo->addItem("COORDINADOR_DE_CARRERA");
    ui->CB_Cargo->addItem("IEDD");
    ui->CB_Cargo->addItem("CONSULTOR");
    ui->CB_Cargo->addItem("DOCENTE");
    ui->CB_Cargo->addItem("DECANO");
    ui->CB_Cargo->addItem("DIRECTOR");

    ui->Dlabel->setStyleSheet("background-color: #062458;");
    ui->Dlabel2->setStyleSheet("background-color: #062458;");

    connect(ui->RTW_revision, &QTableWidget::cellDoubleClicked, this, &MainWindow::on_RTW_revision_cellClicked);

    listaUsuarios.cargarUsuarios();
    this->arbolSilabo->extraerArbol();
    this->arbolB.extraerArbol();
    QMessageBox::warning(this, "Datos no congruentes", "Favor " + QString::number(arbolB.cant));


    //cosas para sustituir donde diga Rcb_usario
    //index 1 y 2 son jefe_academico y coordinador de carrera
        //index 3 IEDD
        //INDEX 4 CONSULTOR

}

MainWindow::~MainWindow()
{
    listaUsuarios.guardarUsuarios(listaUsuarios);
    this->arbolSilabo->guardar();
    this->arbolB.guardar();
    delete ui;
}

void MainWindow::on_btn_entregarM_clicked(){  ui->tabWidget->setCurrentIndex(1);
                                              QImage menu(":/prefix/menu2.0.png");
                                              ui->lbl_pngMenu->setPixmap(QPixmap::fromImage(menu)); }
void MainWindow::on_btn_revision_clicked(){   ui->tabWidget->setCurrentIndex(2);
                                              QImage menu(":/prefix/principal proyecto.png");
                                              ui->lbl_pngMenu->setPixmap(QPixmap::fromImage(menu));}
void MainWindow::on_btn_dashboardM_clicked(){ ui->tabWidget->setCurrentIndex(3); }

//cambio de tabs
void MainWindow::on_tabWidget_currentChanged(int index)
{
    QMessageBox::StandardButton cambio;
    if((index==2 || index==3 || index==4) && loginDocente){
        cambio= QMessageBox::question(this,"Acceso Denegado","Los docentes no tiene acceso\n¿Desea cerrar sesión? ",QMessageBox::Yes | QMessageBox::No);
        if(cambio==QMessageBox::Yes){
            loginDocente=false;
            ui->tabWidget->setCurrentIndex(index);
            ui->tab_3->setEnabled(true);
            ui->tab_4->setEnabled(true);
            ui->tab_5->setEnabled(true);
            limpiarEntrega();
        }else{
            ui->tabWidget->setCurrentIndex(1);
        }
    }else if((index==1 || index==3 || index==4 )&& loginRevision){
        cambio= QMessageBox::question(this,"Acceso Denegado","Ya ha iniciado sesion para otro proceso\n¿Desea cerrar sesión? ",QMessageBox::Yes | QMessageBox::No);
        if(cambio==QMessageBox::Yes){
            loginRevision=false;
            ui->tabWidget->setCurrentIndex(index);
            ui->tab_2->setEnabled(true);
            ui->tab_4->setEnabled(true);
            ui->tab_5->setEnabled(true);
            limpiarRevision();
        }else{
            ui->tabWidget->setCurrentIndex(2);

        }
    }else if((index==1 || index==2 || index==4) && loginBoard){
        cambio= QMessageBox::question(this,"Acceso Denegado","Ya ha iniciado sesion solo para visualizar\n¿Desea cerrar sesión? ",QMessageBox::Yes | QMessageBox::No);
        if(cambio==QMessageBox::Yes){
            loginBoard=false;
            ui->tabWidget->setCurrentIndex(index);
            ui->tab_3->setEnabled(true);
            ui->tab_2->setEnabled(true);
            ui->tab_5->setEnabled(true);
            limpiarBoard();
        }else{
            ui->tabWidget->setCurrentIndex(3);

        }
    }else if((index==1 || index==2 || index==3) && loginCheck){
        cambio= QMessageBox::question(this,"Acceso Denegado","Ya ha iniciado sesion solo para otro proceso\n¿Desea cerrar sesión? ",QMessageBox::Yes | QMessageBox::No);
        if(cambio==QMessageBox::Yes){
            loginCheck=false;
            ui->tabWidget->setCurrentIndex(index);
            ui->tab_3->setEnabled(true);
            ui->tab_2->setEnabled(true);
            ui->tab_4->setEnabled(true);

        }else{
            ui->tabWidget->setCurrentIndex(4);

        }
    }
}

////logica tab2 de entrega silabo
//void MainWindow::on_btn_sesion_clicked()
//{
//    if(ui->le_nameE->text().isEmpty() || ui->le_claveE->text().isEmpty() || ui->le_cuentaE->text().isEmpty()){
//        QMessageBox::warning(this,"Datos no congruetes","Favor no deje campos sin completar");
//    }else{

//        if(listaUsuarios.buscarUsuario(ui->le_cuentaE->text().toStdString(),ui->le_nameE->text().toStdString(),ui->le_claveE->text().toStdString(),"DOCENTE",listaUsuarios)){

//            bool c=listaUsuarios.cambiarPassword_Username(ui->le_cuentaE->text().toStdString(),"UNITEC2024",ui->le_nameE->text().toStdString(),listaUsuarios);

//            if(c){
//                QMessageBox::warning(this,"Datos no congruetes","ezito ");

//            }
//            ui->frameE->setVisible(true);
//            ui->frameE2->setEnabled(false);
//            loginDocente=true;
//            ui->tab_3->setEnabled(false);
//            ui->tab_4->setEnabled(false);
//            ui->tab_5->setEnabled(false);
//        }else{
//            QMessageBox::warning(this,"Datos no congruetes","Usuario, cuenta o contraseña incorrectas");
//        }

//    }
//}

void MainWindow::on_btn_closeE_clicked()
{
    loginDocente=false;
    ui->tab_3->setEnabled(true);
    ui->tab_4->setEnabled(true);
    ui->tab_5->setEnabled(true);
    limpiarEntrega();
    ui->tabWidget->setCurrentIndex(0);
    activarRegistro();
}
void MainWindow::limpiarEntrega()
{
    QStringList items;
    ui->cb_carreraE->clear();
    items<<"...";
    ui->cb_carreraE->addItems(items);
    ui->le_codigoE->clear();
    ui->le_pathE->clear();
    if(loginDocente){
        ui->cb_facultadE->setCurrentIndex(0);
        ui->cb_carreraE->setCurrentIndex(0);
    }else{
//        ui->le_nameE->clear();
//        ui->le_cuentaE->clear();
//        ui->le_claveE->clear();
        ui->cb_facultadE->setCurrentIndex(0);
        ui->cb_carreraE->setCurrentIndex(0);
        ui->frameE2->setEnabled(true);
        //ui->frameE->setVisible(false);
    }
}

void MainWindow::on_btn_silaboE_clicked()
{
    if(ui->cb_facultadE->currentIndex()==0 || ui->cb_carreraE->currentIndex()==0 || ui->le_codigoE->text().isEmpty() || ui->le_pathE->text().isEmpty()){
        QMessageBox::warning(this,"Datos no congruetes","Favor no deje campos sin completar");
    }else{
        QMessageBox::information(this,"Enviado","Datos han sido enviados");
        cantSilabos=this->arbolSilabo->getCantidadArbol()+1; //id seria cantidad en arbol mas uno

        string codigoClase=ui->le_codigoE->text().toStdString();


        //ya no debe crear un nuevo usuario, ahora solo debe buscar que exisita en la lista y el setter de la nueva contrasena
//        Usuario nuevo("nameLogin", "numCuentaLogin", codigoClase,"poner contrasena ingresada");
//        listaUsuarios.InsertarFin(nuevo);
//        listaUsuarios.guardarUsuarios(listaUsuarios);

        string facultad=ui->cb_facultadE->currentText().toStdString();
        string carrera=ui->cb_carreraE->currentText().toStdString();
        QString path=ui->le_pathE->text();

        Silabo* silaboEjemplo = new Silabo(facultad,carrera,numcuenta,codigoClase,path,"Prerevision","...",cantSilabos,0);


        this->arbolSilabo->add(silaboEjemplo);
        this->arbolSilabo->guardar();
        this->arbolB.insertar(*silaboEjemplo);

        limpiarEntrega();
        QMessageBox::information(this, "Enviado", "Datos han sido enviados\n" + QString::fromStdString(arbolB.print(this->arbolB.root)));

    }
}
void MainWindow::on_btn_archivoE_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Explorador de Archivos PDF", QDir::homePath(), "PDF Files (*.pdf)");
    if (!filePath.isEmpty()) {
        ui->le_pathE->setText(filePath);
    }
}
void MainWindow::on_cb_facultadE_currentIndexChanged(int i)
{
    QStringList items;
    ui->cb_carreraE->clear();
    if(i==1){
        items<<"..."<<"Biomedica"<<"Ciencia de datos e inteligencia artificial"<<"Civil"<<"Energia"<<"Industrial y de sistemas"<<"Mecatronica"<<"Sistemas Computacionales"<<"Telecomunicaciones y electronica";
        ui->cb_carreraE->addItems(items);
    }else if(i==2){
        items<<"..."<<"Administracion de la hospitalidad y el tursimo"<<"Administracion industrial e inteligencia de negocios"<<"Administracion industrial y emprendimiento"<<"Industrial y operaciones"<<"Derecho"<<"Finanzas y Economia"<<"Mercadotecnia y negocios internacionales"<<"Relaciones internacionales";
        ui->cb_carreraE->addItems(items);
    }else if(i==3){
        items<<"..."<<"Animacion digital y diseño interactivo"<<"Arquitectura"<<"Comunicacion audiovisual y publicitaria"<<"Diseno de modas"<<"Diseno Grafico"<<"Gastronomia";
        ui->cb_carreraE->addItems(items);
    }
}

//logica tab3 de revision

//void MainWindow::on_Rcb_usuario_currentIndexChanged(int i)
//{
//    QStringList items;
//    ui->Rcb_cambiarE->clear();
//    if(i==1 || i==2){//jefe o coordinador
//        items<<"..."<<"Cargar silabo (Enviar a IEDD)"<<"Rechazar";
//        ui->Rcb_cambiarE->addItems(items);
//    }else if(i==3){//en iedd
//        items<<"..."<<"Listo para revision 1"<<"Devolver a Academia";
//        ui->Rcb_cambiarE->addItems(items);
//    }else if(i==4){//consultor
//        items<<"...";
//        ui->Rcb_cambiarE->addItems(items);

//    }

//}

//void MainWindow::on_Rbtn_sesion_clicked()
//{
//    if(ui->Rle_name->text().isEmpty() || ui->Rle_clave->text().isEmpty() || ui->Rcb_usuario->currentIndex()==0){
//        QMessageBox::warning(this,"Datos no congruetes","Favor no deje campos sin completar");
//    }else{
//        //this->arbolSilabo->extraer();
//        string quienSoy = ui->Rcb_usuario->currentText().toStdString();
//         if(listaUsuarios.buscarUsuario("11111111",ui->Rle_name->text().toStdString(),ui->Rle_clave->text().toStdString(),quienSoy,listaUsuarios)){
//                ui->frameR->setVisible(true);
//                ui->frameR1->setEnabled(false);
//                loginRevision=true;
//                ui->tab_2->setEnabled(false);
//                ui->tab_4->setEnabled(false);
//                ui->tab_5->setEnabled(false);
//                pruebitaBotonesTab();
//         }else{
//            QMessageBox::warning(this,"Datos no congruetes","Clave incorrecta");
//        }

//    }
//}


void MainWindow::limpiarRevision()
{
    QStringList items;
    ui->Rle_comentario->clear();
    ui->Rle_seleccion->clear();
    ui->Rle_estadoA->clear();
    if(loginRevision){
        ui->Rcb_cambiarE->setCurrentIndex(0);
    }else{
        ui->Rcb_cambiarE->clear();
        items<<"...";
        ui->Rcb_cambiarE->addItems(items);
//        ui->Rle_name->clear();
//        ui->Rle_clave->clear();
//        ui->Rcb_usuario->setCurrentIndex(0);
        ui->Rcb_cambiarE->setCurrentIndex(0);
      //  ui->frameR->setVisible(false);
//        ui->frameR1->setEnabled(true);
    }
}



void MainWindow::on_Rbtn_cerrar_clicked()
{
    loginRevision=false;
    ui->RTW_revision->setRowCount(0);
    ui->tab_2->setEnabled(true);
    ui->tab_4->setEnabled(true);
    ui->tab_5->setEnabled(true);
    limpiarRevision();
    ui->tabWidget->setCurrentIndex(0);
    activarRegistro();
}

void MainWindow::on_Rbtn_cambiar_clicked()
{
    if( ui->Rle_estadoA->text().isEmpty() || ui->Rle_seleccion->text().isEmpty()){
        QMessageBox::warning(this,"Datos no congruetes","No ha seleccionado que editar");
    }else if(ui->Rle_comentario->text().isEmpty()){
        QMessageBox::warning(this,"Datos no congruetes","No olvide comentar");
    }else if(ui->Rcb_cambiarE->currentIndex()==0){
        QMessageBox::warning(this,"Datos no congruetes","No ha seleccionado estado a cambiar");
    }else{
        cambiarEstado=true;
        modificarDatosSilabo(arbolSilabo,id,"QString pathNuevo");
        QMessageBox::information(this,"Datos congruetes","Datos han sido actualizados");
        limpiarRevision();
    }

}



void MainWindow::cambiarSilabo(int id, QString pathActual)
{
    QString filePath = QFileDialog::getOpenFileName(this, "Explorador de Archivos PDF", QDir::homePath(), "PDF Files (*.pdf)");
    if (pathActual==filePath) {//buscar en el arbol
        QMessageBox::warning(this, "No posible", "Ha seleccionado el mismo silabo");
    }else if(!filePath.isEmpty()){
        cambiarPath=true;
        modificarDatosSilabo(arbolSilabo,id,filePath);
    }else{
        QMessageBox::warning(this, "No posible", "No ha seleccionado");
    }
}

void MainWindow::modificarDatosSilabo(Arbol *nodo,int id, QString pathNuevo)
{
    if (nodo == nullptr) {
        return;
    }
    modificarDatosSilabo(nodo->getArbolIzq(),id, pathNuevo);
    Silabo *silabo = nodo->getRaiz();
    if(silabo->getId()==id && cambiarPath){
        if(silabo->getEstado()=="Aprobar"){
            QMessageBox::warning(this, "No posible", "Ya ha sido aprobado");
        }else{

            if(loginRevision){
                silabo->setRuta(pathNuevo);
                cambiarPath=false;
                pruebitaBotonesTab();

            }else{
                if(silabo->getNumRevisiones()>=2){
                    QMessageBox::warning(this,"RECHAZADO","El silabo "+QString::fromStdString(silabo->getCodigoClase()+"\nHa excedido el numero de revisiones\nRealice el proceso de ENTREGA de nuevo"));
                    silabo->setEstado("Rechazar");
                    return;
                }
                silabo->setRuta(pathNuevo);
                cambiarPath=false;
                silabo->setEstado("Prerevision");
                silabo->setNumRevisiones(silabo->getNumRevisiones()+1);
                silabo->setObservacion("Reloaded");

                ui->DRTW_revision->clearContents();
                ui->DRTW_revision->setRowCount(0);
                ui->DRTW_revision->setColumnCount(10);//tab 2 tw_doble
                ui->DRTW_revision->setHorizontalHeaderLabels(QStringList() <<"VER DOCX"<<"ORDEN DE INGRESO"<<"INGRESADO POR"<<"# CUENTA"<<"FACULTAD"<<"CARRERA"<<"CODIGO CLASE"<<"OBSERVACION"<<"PATH"<<"RELOAD");

              //  mostrarDocente(arbolSilabo,0, ui->Dle_cuenta->text().toStdString()); aqui poner en dlecuenta el nombre de docente login
            }
        }

        return;
    }else if(silabo->getId()==id && cambiarEstado){
        string nuevaObservacion=ui->Rle_comentario->text().toStdString();
        string nuevoEstado=ui->Rcb_cambiarE->currentText().toStdString();
        int nuevoNumRevisiones=silabo->getNumRevisiones();

//        if(ui->Rcb_usuario->currentIndex()==3 && nuevoEstado=="Listo para revision 1"){si es IEDD
//            nuevoNumRevisiones++;
//        }
        if(nuevoNumRevisiones>2){
            QMessageBox::warning(this,"RECHAZADO","El silabo "+QString::fromStdString(silabo->getCodigoClase()+"\nHa excedido el numero de revisiones\nNuevo estado: RECHAZADO"));
            silabo->setEstado("Rechazar");
            pruebitaBotonesTab();
            cambiarEstado=false;
            return;
        }

        silabo->setEstado(nuevoEstado);
        silabo->setObservacion(nuevaObservacion);
        silabo->setNumRevisiones(nuevoNumRevisiones);

        pruebitaBotonesTab();
        cambiarEstado=false;
        return;

    }


    modificarDatosSilabo(nodo->getArbolDer(),id, pathNuevo);
}

string MainWindow::obtenerNombre(std::string cuenta)
{
    nodoD<Usuario> *actD=listaUsuarios.PrimPtr;
    while(actD != 0){
        if(cuenta==actD->Dato.cuenta){
            return actD->Dato.name;
        }
        actD=actD->SigPtr;
    }
    return "...";
}

void MainWindow::pruebitaBotonesTab()
{
    ui->RTW_revision->clearContents();
    ui->RTW_revision->setRowCount(0);

    ui->RTW_revision->setColumnCount(13);//tab 2 tw_doble

    ui->RTW_revision->setHorizontalHeaderLabels(QStringList() <<"MODIFCAR"<<"VER DOCX"<<"ORDEN DE INGRESO"<<"ESTADO"<<"INGRESADO POR"<<"# CUENTA"<<"FACULTAD"<<"CARRERA"<<"CODIGO CLASE"<<"PATH"<<"OBSERVACION"<<"RELOAD"<<"# REVISONES");
    int fila = 0;

    recorrerArbolParaTabla(arbolSilabo, fila,listaUsuarios.PrimPtr);
}

void MainWindow::recorrerArbolParaTabla(Arbol *nodo, int &fila,nodoD<Usuario> *actD )
{
    if (nodo == nullptr || actD==0) {
        return;
    }
    bool mostrar=false;
    recorrerArbolParaTabla(nodo->getArbolIzq(), fila,actD);
    Silabo *silabo = nodo->getRaiz();

//index 1 y 2 son jefe_academico y coordinador de carrera
    //index 3 IEDD
    //INDEX 4 CONSULTOR

    if(actD != nullptr){
//        if((ui->Rcb_usuario->currentIndex()==1 || ui->Rcb_usuario->currentIndex()==2)&& (silabo->getEstado()=="Prerevision" || silabo->getEstado()=="Devolver a Academia")){
//            mostrar=true;
//        }else if(ui->Rcb_usuario->currentIndex()==3 && (silabo->getEstado()=="Cargar silabo (Enviar a IEDD)" || silabo->getEstado()=="Correcion Mayor" || silabo->getEstado()=="Correcion Menor" || silabo->getEstado()=="Aprobado con condicion")){
//            mostrar=true;
//        }else if(ui->Rcb_usuario->currentIndex()==4 && (silabo->getEstado()=="Listo para revision 1" || silabo->getEstado()=="Aprobado" || silabo->getEstado()=="Aprobado con condicion" )){
//            mostrar=true;
//        }else{
//            mostrar=false;
//        }

        if(mostrar){
            ui->RTW_revision->setRowCount(fila + 1);
            ui->RTW_revision->setItem(fila, 0, new QTableWidgetItem(QString::fromStdString("EDITAR")));
            ui->RTW_revision->setItem(fila, 1, new QTableWidgetItem(QString::fromStdString("VER")));
            ui->RTW_revision->setItem(fila, 2, new QTableWidgetItem(QString::number(silabo->getId())));
            ui->RTW_revision->setItem(fila, 3, new QTableWidgetItem(QString::fromStdString(silabo->getEstado())));


            string ingresadoPor=obtenerNombre(silabo->getNombre());

            ui->RTW_revision->setItem(fila, 4, new QTableWidgetItem(QString::fromStdString(ingresadoPor)));
            ui->RTW_revision->setItem(fila, 5, new QTableWidgetItem(QString::fromStdString(silabo->getNombre())));

            ui->RTW_revision->setItem(fila, 6, new QTableWidgetItem(QString::fromStdString(silabo->getFacultad())));
            ui->RTW_revision->setItem(fila, 7, new QTableWidgetItem(QString::fromStdString(silabo->getCarreras())));
            ui->RTW_revision->setItem(fila, 8, new QTableWidgetItem(QString::fromStdString(silabo->getCodigoClase())));
            ui->RTW_revision->setItem(fila, 9, new QTableWidgetItem(silabo->getRuta()));
            ui->RTW_revision->setItem(fila, 10, new QTableWidgetItem(QString::fromStdString(silabo->getObservacion())));
            ui->RTW_revision->setItem(fila, 11, new QTableWidgetItem(QString::fromStdString("NUEVO SILABO")));
            ui->RTW_revision->setItem(fila, 12, new QTableWidgetItem(QString::number(silabo->getNumRevisiones())));

            fila++;
        }


    }
    actD = actD->SigPtr;

    recorrerArbolParaTabla(nodo->getArbolDer(), fila,actD);
}

void MainWindow::on_RTW_revision_cellClicked(int row, int column)
{
    if(column==0){
        QString dato = ui->RTW_revision->item(row, 8)->text() +"    Observacion:"  +ui->RTW_revision->item(row, 10)->text();
        id=ui->RTW_revision->item(row, 2)->text().toInt();
        ui->Rle_seleccion->setText(dato);
        QString estado = ui->RTW_revision->item(row, 3)->text();
        ui->Rle_estadoA->setText(estado);

//        if(ui->Rcb_usuario->currentIndex() ==4){ si el usuario login es consultor
//            QStringList items;
//            ui->Rcb_cambiarE->clear();
//            if( ui->RTW_revision->item(row, 3)->text().toStdString()=="Aprobado"){
//                items<<"..."<<"Aprobar"<<"Aprobado con condicion";

//            }else{
//                items<<"..."<<"Aprobado"<<"Correcion Mayor"<<"Correcion Menor";
//            }
//            ui->Rcb_cambiarE->addItems(items);
//        }

    }else if(column ==1){

        QString selectedFilePath = ui->RTW_revision->item(row, 9)->text();
        QDesktopServices::openUrl(QUrl::fromLocalFile(selectedFilePath));

    }else if(column==11){
        cambiarSilabo(ui->RTW_revision->item(row, 2)->text().toInt(),ui->RTW_revision->item(row, 9)->text());
    }

}

//logica tab3 director y decano
//void MainWindow::on_Bbtn_sesion_clicked() {
//    if (ui->Ble_name->text().isEmpty() || ui->Ble_clave->text().isEmpty() || ui->Bcb_usuario->currentIndex() == 0) {
//        QMessageBox::warning(this, "Datos no congruetes", "Favor no deje campos sin completar");
//    } else {
//        string quienSoy = ui->Bcb_usuario->currentText().toStdString();

//        if (listaUsuarios.buscarUsuario("11111111",ui->Ble_name->text().toStdString(),ui->Ble_clave->text().toStdString(),quienSoy,listaUsuarios)){

//            ui->frameB->setVisible(true);
//            ui->frameB1->setEnabled(false);
//            loginBoard = true;
//            ui->tab_3->setEnabled(false);
//            ui->tab_2->setEnabled(false);

//            // Limpiar el QTableWidget antes de agregar nuevos datos
//            ui->tableWidget->clear();
//            ui->tableWidget->setRowCount(0); // Limpiar todas las filas existentes

//            // Agregar encabezados de columna al QTableWidget
//            QStringList headers;
//            headers << "Facultad" << "Carreras" << "Numero de Cuenta" << "Código de Clase" << "Ruta" << "Estado" << "Observación" << "ID" << "Número de Revisiones";
//            ui->tableWidget->setColumnCount(headers.size());
//            ui->tableWidget->setHorizontalHeaderLabels(headers);

//            // Llamar a la función para agregar datos al QTableWidget
//            recorrerArbolParaTable(arbolSilabo, ui->tableWidget, "Prerevision");

//        } else {
//            QMessageBox::warning(this, "Datos no congruetes", "Clave incorrecta");
//        }
//    }
//}
void MainWindow::on_Bbtn_aceptados_clicked()
{
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);

    QStringList headers;
    headers << "Facultad" << "Carreras" << "Numero de Cuenta" << "Código de Clase" << "Ruta" << "Estado" << "Observación" << "ID" << "Número de Revisiones";
    ui->tableWidget->setColumnCount(headers.size());
    ui->tableWidget->setHorizontalHeaderLabels(headers);

    recorrerArbolParaTable(arbolSilabo, ui->tableWidget, "Aprobar");
}

void MainWindow::on_Bbtn_proceso_clicked()
{
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);

    QStringList headers;
    headers << "Facultad" << "Carreras" << "Numero de Cuenta" << "Código de Clase" << "Ruta" << "Estado" << "Observación" << "ID" << "Número de Revisiones";
    ui->tableWidget->setColumnCount(headers.size());
    ui->tableWidget->setHorizontalHeaderLabels(headers);

    recorrerArbolParaTable(arbolSilabo, ui->tableWidget, "n");
}


void MainWindow::recorrerArbolParaTable(Arbol *nodo, QTableWidget *tableWidget, const std::string &estadoMostrar) {
    if (nodo == nullptr) {
        return;
    }

    recorrerArbolParaTable(nodo->getArbolIzq(), tableWidget, estadoMostrar);

    Silabo *silabo = nodo->getRaiz();

    if ((estadoMostrar == "Aprobar" && silabo->getEstado() == "Aprobar") ||
        (estadoMostrar != "Aprobar" && silabo->getEstado() != "Aprobar") ) {

        int row = tableWidget->rowCount();
        tableWidget->insertRow(row);
        tableWidget->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(silabo->getFacultad())));
        tableWidget->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(silabo->getCarreras())));
        tableWidget->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(silabo->getNombre())));
        tableWidget->setItem(row, 3, new QTableWidgetItem(QString::fromStdString(silabo->getCodigoClase())));
        tableWidget->setItem(row, 4, new QTableWidgetItem(silabo->getRuta()));
        tableWidget->setItem(row, 5, new QTableWidgetItem(QString::fromStdString(silabo->getEstado())));
        tableWidget->setItem(row, 6, new QTableWidgetItem(QString::fromStdString(silabo->getObservacion())));
        tableWidget->setItem(row, 7, new QTableWidgetItem(QString::number(silabo->getId())));
        tableWidget->setItem(row, 8, new QTableWidgetItem(QString::number(silabo->getNumRevisiones())));
    }

    recorrerArbolParaTable(nodo->getArbolDer(), tableWidget, estadoMostrar);
}


void MainWindow::on_Bbtn_cerrar_clicked()
{
    loginBoard=false;
    //limpiarBoard();
     ui->tabWidget->setCurrentIndex(0);
    activarRegistro();
}
void MainWindow::limpiarBoard()
{
//    ui->Ble_name->clear();
//    ui->Ble_clave->clear();
//    ui->Bcb_usuario->setCurrentIndex(0);
    ui->tab_3->setEnabled(true);
    ui->tab_2->setEnabled(true);
    ui->tab_5->setEnabled(true);
    ui->frameB->setVisible(false);
    ui->frameB->setEnabled(true);
}

//tab docente confirmar
//void MainWindow::on_Dbtn_sesion_clicked()
//{
//    if(ui->Dle_clave->text().isEmpty() || ui->Dle_cuenta->text().isEmpty() || ui->Dle_name->text().isEmpty()){
//        QMessageBox::warning(this,"Datos incompletos","Favor, no deje campos vacios");
//    }else if(true){
//        QMessageBox::warning(this,"Datos incongruentes","Clave incorrecta");
//    }else{
//        string name=obtenerNombre(ui->Dle_cuenta->text().toStdString());
//        if(name=="..."){
//            QMessageBox::warning(this,"Datos incongruentes","Numero de cuenta o usario incorrectos");

//        }else{
//            if(name!=ui->Dle_name->text().toStdString() ){
//                QMessageBox::warning(this,"Datos incongruentes","Numero de cuenta o usario incorrectos");
//            }else{
//                loginCheck=true;
//                ui->tab_3->setEnabled(false);
//                ui->tab_2->setEnabled(false);
//                ui->tab_4->setEnabled(false);
//                ui->Dframe2->setVisible(true);
//                ui->Dbtn_salir->setVisible(true);

//                ui->DRTW_revision->clearContents();
//                ui->DRTW_revision->setColumnCount(10);//tab 2 tw_doble
//                ui->DRTW_revision->setHorizontalHeaderLabels(QStringList() <<"VER DOCX"<<"ORDEN DE INGRESO"<<"INGRESADO POR"<<"# CUENTA"<<"FACULTAD"<<"CARRERA"<<"CODIGO CLASE"<<"OBSERVACION"<<"PATH"<<"RELOAD");
//                mostrarDocente(arbolSilabo,0, ui->Dle_cuenta->text().toStdString());
//            }
//        }

//    }
//}
void MainWindow::mostrarDocente(Arbol *nodo,int fila,string numCuenta)
{
    if (nodo == nullptr) {
        return;
    }

    mostrarDocente(nodo->getArbolIzq(), fila,numCuenta);
    Silabo *silabo = nodo->getRaiz();

    if(numCuenta == silabo->getNombre() && (silabo->getEstado()=="Rechazar" || silabo->getEstado()=="Aprobar") ){
        ui->DRTW_revision->setRowCount(fila + 1);
        ui->DRTW_revision->setItem(fila, 0, new QTableWidgetItem(QString::fromStdString("VER")));
        ui->DRTW_revision->setItem(fila, 1, new QTableWidgetItem(QString::number(silabo->getId())));

        string ingresadoPor=obtenerNombre(silabo->getNombre());

        ui->DRTW_revision->setItem(fila, 2, new QTableWidgetItem(QString::fromStdString(ingresadoPor)));
        ui->DRTW_revision->setItem(fila, 3, new QTableWidgetItem(QString::fromStdString(silabo->getNombre())));

        ui->DRTW_revision->setItem(fila, 4, new QTableWidgetItem(QString::fromStdString(silabo->getFacultad())));
        ui->DRTW_revision->setItem(fila, 5, new QTableWidgetItem(QString::fromStdString(silabo->getCarreras())));
        ui->DRTW_revision->setItem(fila, 6, new QTableWidgetItem(QString::fromStdString(silabo->getCodigoClase())));
        ui->DRTW_revision->setItem(fila, 7, new QTableWidgetItem(QString::fromStdString(silabo->getObservacion())));

        ui->DRTW_revision->setItem(fila, 8, new QTableWidgetItem(silabo->getRuta()));
        ui->DRTW_revision->setItem(fila, 9, new QTableWidgetItem(QString::fromStdString("NUEVO SILABO")));

        fila++;
    }
    mostrarDocente(nodo->getArbolDer(), fila,numCuenta);
}

void MainWindow::on_Dbtn_salir_clicked()
{
    ui->DRTW_revision->clear();
//    ui->Dle_clave->clear();
//    ui->Dle_cuenta->clear();
//    ui->Dle_name->clear();
    ui->tab_3->setEnabled(true);
    ui->tab_2->setEnabled(true);
    ui->tab_4->setEnabled(true);
    ui->tabWidget->setCurrentIndex(0);
    activarRegistro();

}

void MainWindow::on_DRTW_revision_cellClicked(int row, int column)
{
    if(column ==0){
        QString selectedFilePath = ui->DRTW_revision->item(row, 7)->text();
        QDesktopServices::openUrl(QUrl::fromLocalFile(selectedFilePath));

    }else if(column==9 ){
        cambiarSilabo(ui->DRTW_revision->item(row, 1)->text().toInt(),ui->DRTW_revision->item(row, 8)->text());
    }
}

//LOGICA MENU
void MainWindow::activarRegistro()
{
    ui->lbl_pngMenu->setVisible(false);
    ui->frameMI->setVisible(true);
    ui->btn_IniciarSesion->setVisible(false);

    ui->LE_Contra->setEnabled(true);
    ui->LE_NumCuenta->setEnabled(true);
    ui->LE_Username->setEnabled(true);
    ui->btn_Ingresar->setEnabled(true);
    ui->CB_Cargo->setEnabled(true);

    ui->btn_CerrarSesion->setVisible(false);
    ui->Btn_CambContra->setVisible(false);
    ui->btn_cambusuario->setVisible(false);
    ui->RB_Board->setVisible(false);
    ui->RB_Entrega->setVisible(false);
    ui->RB_Rastreo->setVisible(false);
    ui->RB_Revision->setVisible(false);


}
void MainWindow::on_btn_IniciarSesion_clicked()
{
    ui->lbl_pngMenu->setVisible(false);
    ui->frameMI->setVisible(true);
    ui->btn_IniciarSesion->setVisible(false);

}


void MainWindow::on_btn_Ingresar_clicked()
{
    if(ui->LE_Contra->text().isEmpty()||ui->LE_Username->text().isEmpty()||ui->LE_NumCuenta->text().isEmpty()){
        QMessageBox::warning(this,"Datos no congruetes","Favor no deje campos sin completar");
    }else{
        if(ui->CB_Cargo->currentText().toStdString()=="DOCENTE"||ui->CB_Cargo->currentText().toStdString()=="DECANO"||ui->CB_Cargo->currentText().toStdString()=="IEDD"||ui->CB_Cargo->currentText().toStdString()=="COORDINADOR_DE_CARRERA"||ui->CB_Cargo->currentText().toStdString()=="DIRECTOR"||ui->CB_Cargo->currentText().toStdString()=="JEFE_ACADEMICO"||ui->CB_Cargo->currentText().toStdString()=="CONSULTOR"){

            bool existe=listaUsuarios.buscarUsuario(ui->LE_NumCuenta->text().toStdString(),ui->LE_Username->text().toStdString(),ui->LE_Contra->text().toStdString(),ui->CB_Cargo->currentText().toStdString(),listaUsuarios);

            if(existe){
                numcuenta=ui->LE_NumCuenta->text().toStdString();
                username=ui->LE_Username->text().toStdString();

                ui->LE_Contra->clear();
                ui->LE_NumCuenta->clear();
                ui->LE_Username->clear();
                //desactivo los botones
                ui->LE_Contra->setEnabled(false);
                ui->LE_NumCuenta->setEnabled(false);
                ui->LE_Username->setEnabled(false);
                ui->btn_Ingresar->setEnabled(false);
                ui->CB_Cargo->setEnabled(false);
                //hago visible las nuevas opciones
                ui->btn_CerrarSesion->setVisible(true);
                ui->Btn_CambContra->setVisible(true);
                ui->btn_cambusuario->setVisible(true);
                ui->RB_Board->setVisible(true);
                ui->RB_Entrega->setVisible(true);
                ui->RB_Rastreo->setVisible(true);
                ui->RB_Revision->setVisible(true);

                if(ui->CB_Cargo->currentText().toStdString()=="DOCENTE"){
                    loginDocente=true;
                    //entrega y rastreo
                    ui->RB_Entrega->setEnabled(true);
                    ui->RB_Rastreo->setEnabled(true);
                    ui->RB_Revision->setEnabled(false);
                    ui->RB_Board->setEnabled(false);
                }else if(ui->CB_Cargo->currentText().toStdString()=="JEFE_ACADEMICO"||ui->CB_Cargo->currentText().toStdString()=="IEDD"||ui->CB_Cargo->currentText().toStdString()=="CONSULTOR"||ui->CB_Cargo->currentText().toStdString()=="COORDINADOR_DE_CARRERA"){
                    loginRevision=true;
                    ui->RB_Revision->setEnabled(true);
                    ui->RB_Rastreo->setEnabled(false);
                    ui->RB_Entrega->setEnabled(false);
                    ui->RB_Board->setEnabled(false);
                    //revison
                }else if(ui->CB_Cargo->currentText().toStdString()=="DIRECTOR"||ui->CB_Cargo->currentText().toStdString()=="DECANO"){
                    loginBoard=true;
                    ui->RB_Board->setEnabled(true);
                    ui->RB_Rastreo->setEnabled(false);
                    ui->RB_Entrega->setEnabled(false);
                    ui->RB_Revision->setEnabled(false);
                    //board
                }
            }else{
                QMessageBox::warning(this,"Error de autenticacion","Datos no congruentes");
            }
        }else{
            ui->LE_Contra->clear();
            ui->LE_NumCuenta->clear();
            ui->LE_Username->clear();
        }
    }

}


void MainWindow::on_btn_CerrarSesion_clicked()
{
    ui->lbl_pngMenu->setVisible(true);
    ui->frameMI->setVisible(false);
    ui->btn_IniciarSesion->setVisible(true);

    ui->LE_Contra->setEnabled(true);
    ui->LE_NumCuenta->setEnabled(true);
    ui->LE_Username->setEnabled(true);
    ui->btn_Ingresar->setEnabled(true);
    ui->CB_Cargo->setEnabled(true);

    ui->btn_CerrarSesion->setVisible(false);
    ui->Btn_CambContra->setVisible(false);
    ui->btn_cambusuario->setVisible(false);
    ui->RB_Board->setVisible(false);
    ui->RB_Entrega->setVisible(false);
    ui->RB_Rastreo->setVisible(false);
    ui->RB_Revision->setVisible(false);

    loginDocente=false;
    loginBoard=false;
    loginRevision=false;
    numcuenta="";
}


void MainWindow::on_RB_Entrega_clicked()
{
    ui->tabWidget->setCurrentIndex(1);
    ui->RB_Entrega->setChecked(false);
}


void MainWindow::on_RB_Revision_clicked()
{
  ui->tabWidget->setCurrentIndex(2);
  ui->RB_Revision->setChecked(false);
}


void MainWindow::on_RB_Board_clicked()
{
  ui->tabWidget->setCurrentIndex(3);
  ui->RB_Board->setChecked(false);
}


void MainWindow::on_RB_Rastreo_clicked()
{
  ui->tabWidget->setCurrentIndex(4);
  ui->RB_Rastreo->setChecked(false);
}

