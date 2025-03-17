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
//hola
cframe::cframe(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::cframe)
    ,arbol(new arbolB(5))
{
    ui->setupUi(this);
    ui->tabWidget->setCurrentIndex(0);

    visibilidad();
    ui->tabWidget->tabBar()->hide();

    QImage menu(":/new/prefix1/menu.png");
    ui->lbl_png->setPixmap(QPixmap::fromImage(menu));
    ui->lbl_png->setStyleSheet("background-color: #A61400;");
//    QMessageBox::StandardButton reply;
//    reply = QMessageBox::information(this, "Bienvenido", "Cargar base de datos para iniciar.\nEsto puede tardar unos segundos.", QMessageBox::Ok);
//    if (reply == QMessageBox::Ok) {
//       Conectar();
//    }else{

//    }
insertarUser();
}

cframe::~cframe()
{
    //SubirDatos();
    delete ui;
    delete arbol;
}
void cframe::insertarUser()
{
    Usuario* Temp = new Usuario("11111111","1JUAN","111","",1, 2);
    listaUsuarios.listaInsertarFinal(*Temp);
    delete Temp;
    Usuario* Temp1 = new Usuario("22222222","2JUAN","222","",2, 1);
    listaUsuarios.listaInsertarFinal(*Temp1);
    delete Temp1;
    Usuario* Temp2 = new Usuario("66666666","6JUAN","666","",6, 3);
    listaUsuarios.listaInsertarFinal(*Temp2);
    delete Temp2;
    Usuario* Temp3 = new Usuario("44444444","4JUAN","444","",4, 2);
    listaUsuarios.listaInsertarFinal(*Temp3);
    delete Temp3;
    Usuario* Temp4= new Usuario("55555555","5JUAN","555","",5, 3);
    listaUsuarios.listaInsertarFinal(*Temp4);
    delete Temp4;
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
    }else if(ui->tabWidget->currentIndex()==4 || ui->tabWidget->currentIndex()==6){
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
        QMessageBox::critical(this, "Error", "Porfavor, llena todos los Espacios");
    }else{
        //Conectar;
        QString contraDeseada= listaUsuarios.login(ui->Mle_cuenta->text(), ui->Mle_name->text(),ui->Mle_contra->text() ,ui->Mcb_tipo->currentIndex());
        if(contraDeseada!="no" ){

            if(listaUsuarios.verficarContraAceptada(ui->Mle_cuenta->text(),  contraDeseada, ui->Mcb_tipo->currentIndex())){
                QMessageBox::information(this, "Cambio de contraseña", "Su solicitud de contraseña fue aprobada:\n"+contraDeseada);
                listaUsuarios.cambioContra(ui->Mle_contra->text(), ui->Mle_cuenta->text(), listaUsuarios);
            }
            if(contraDeseada == "RECHAZADA"){
                QMessageBox::information(this, "Cambio de contraseña", "Su solicitud de contraseña fue rechazada:\n"+contraDeseada);
                listaUsuarios.cambioContra(ui->Mle_contra->text(), ui->Mle_cuenta->text(), listaUsuarios);
            }
            tipo=ui->Mcb_tipo->currentIndex();
            ui->Albl_cuenta->setText(ui->Mle_cuenta->text());
            ui->Albl_tipo->setText(ui->Mcb_tipo->currentText());
            ui->Albl_username->setText(ui->Mle_name->text());

            QStringList acciones;
            if(ui->Mcb_tipo->currentIndex()==1){
                acciones << "..." << "FEED" << "ENTREGAR";
                ui->Acb_acciones->addItems(acciones);
            }else if(ui->Mcb_tipo->currentIndex()==2||ui->Mcb_tipo->currentIndex()==3){
                acciones << "..." << "BOARD" <<"USUARIOS";
                ui->Acb_acciones->addItems(acciones);
            }else if(ui->Mcb_tipo->currentIndex()==6 ){
                acciones << "..." << "REVISION"<<"USUARIOS"<<"FEED"<<"BOARD";
                ui->Acb_acciones->addItems(acciones);
            }else if(ui->Mcb_tipo->currentIndex()==4||ui->Mcb_tipo->currentIndex()==5){
                acciones << "..." << "REVISION";
                ui->Acb_acciones->addItems(acciones);
            }else if(ui->Mcb_tipo->currentIndex()==7){
                acciones << "..." << "REVISION";
                ui->Acb_acciones->addItems(acciones);
            }
            ui->Mle_cuenta->clear();
            ui->Mle_contra->clear();
            ui->Mle_name->clear();

            ui->tabWidget->setCurrentIndex(5);
            ui->btn_sesion->setVisible(true);
        }else{
            QMessageBox::critical(this, "Error", "Datos incongruentes");

        }
    }
    visibilidad();
}

void cframe::on_Acb_acciones_currentIndexChanged(int index)
{}

void cframe::on_btn_sesion_clicked()
{
    if(ui->tabWidget->currentIndex() ==0){
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Guía",
                                      "¿Desea ver el manual de uso?",
                                      QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            QDesktopServices::openUrl(QUrl::fromLocalFile("https://acortar.link/P805nZ"));
        }else{}
    }else{
        if(ui->tabWidget->currentIndex() != 5){
            ui->tabWidget->setCurrentIndex(5);
        } else {
            ui->Acb_acciones->clear();
            ui->Mcb_tipo->setCurrentIndex(0);
            ui->tabWidget->setCurrentIndex(0);
            ui->btn_sesion->setText("Manual de uso");
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

void cframe::on_Acb_acciones_currentIndexChanged(const QString &arg1)
{
    if(arg1=="ENTREGAR"){
        QStringList item;
        ui->Ecb_sede->clear();
        item<<"..."<<"UNITEC"<<"CEUTEC";
        ui->Ecb_sede->addItems(item);
        ui->tabWidget->setCurrentIndex(1);
    }else if(arg1=="REVISION"){
        QStringList items;
        ui->Rcb_estadoCambiar->clear();
        if(tipo==4 || tipo==5){//jefe o coordinador
            ui->RC->setVisible(false);
            ui->Rcb_consultor->setVisible(false);
            items<<"..."<<"Cargar silabo (Enviar a IEDD)"<<"Rechazar";
            ui->Rcb_estadoCambiar->addItems(items);
        }else if(tipo==6){//en iedd
            ui->RC->setVisible(true);
            ui->Rcb_consultor->setVisible(true);
            items<<"..."<<"Listo para revision 1"<<"Devolver a Academia";
            ui->Rcb_consultor->clear();
            ui->Rcb_estadoCambiar->addItems(items);
            actD = listaUsuarios.PrimPtr;
            while (actD != nullptr) {
                Usuario usuario = actD->getDato();
                if (usuario.getTipo() == 7) {
                    ui->Rcb_consultor->addItem(usuario.getNombre()); // Agregar solo los consultores
                }
                actD = actD->SigPtr;
            }
        }else if(tipo==7){//consultor
            ui->RC->setVisible(false);
            ui->Rcb_consultor->setVisible(false);
            items<<"...";
            ui->Rcb_estadoCambiar->addItems(items);
        }
        ui->tabWidget->setCurrentIndex(2);
        MostrarSilabos();
    }else if(arg1=="BOARD"){
        ui->tabWidget->setCurrentIndex(3);
    }else if(arg1=="FEED"){
        ui->tabWidget->setCurrentIndex(4);
        mostrarSilabosFeed(ui->Albl_cuenta->text());
    }else if(arg1=="USUARIOS"){
        mostrarUsuarios();
        ui->tabWidget->setCurrentIndex(6);
    }else if(arg1=="..."){
    }
    ui->Acb_acciones->setCurrentIndex(0);
    visibilidad();

}

void cframe::on_Ebtn_archivo_clicked()
{
    QString filePath = cargarArchivo(ui->Ecb_carrera->currentText(),false);
    if (filePath=="...") {
        QMessageBox::critical(this, "Error", "Porfavor, llene todos los espacios");

    }else{
        ui->Elbl_path_archivo->setText(filePath);
    }
}

void cframe::on_Ebtn_fechas_clicked()
{
    QString filePath = cargarArchivo(ui->Ecb_carrera->currentText(),true);
    if (filePath=="...") {
        QMessageBox::critical(this, "Error", "Porfavor, llene todos los espacios");
    }else{
        ui->Elbl_path_fechas->setText(filePath);
    }
}

void cframe::on_Ebtn_enviar_clicked()
{
    std::vector<Silabos> silabos = arbol->obtenerTodos();
    QString facultad = ui->Ecb_facultad->currentText();
    QString carrera = ui->Ecb_carrera->currentText();
    QString datosClase = ui->Ecb_clases->currentText();
    QString path_silabo=ui->Elbl_path_archivo->text();
    QString path_fecha = (ui->Ecb_sede->currentIndex() != 1) ? "" : ui->Elbl_path_fechas->text();

    if(path_silabo=="..." || (ui->Ecb_sede->currentIndex()==2 && path_fecha=="...")){
        QMessageBox::critical(this, "Error", "Porfavor llenar todos los Espacios!");
    }else{
        if (ui->Ecb_sede->currentText().toStdString() == "UNITEC") {
            facultad = "-" + facultad;
        }
        int indice = silabos.size() + 1;
        Silabos s(facultad.toStdString(),
                  carrera.toStdString(),
                  indice,
                  ui->Albl_cuenta->text().toInt(),  // insertadoPor
                  datosClase.toStdString(),
                  path_silabo,
                  path_fecha,
                  "Prerevision",
                  "NO APLICA",
                  0,  // numRevisiones
                  0,  // numRechazado
                  0   // veces revisado de forma general
                  );
        arbol->insertar(s);
        ui->Ecb_carrera->setCurrentIndex(0);
        ui->Ecb_facultad->setCurrentIndex(0);
        ui->Ecb_sede->setCurrentIndex(0);
        ui->Ecb_clases->setCurrentIndex(0);
        ui->Elbl_path_fechas->setText("...");
        ui->Elbl_path_archivo->setText("...");
    }
}
void cframe::MostrarSilabos() {
    std::vector<Silabos> silabos = arbol->obtenerTodos();
    ui->Rtw_revision->clear();
    ui->Rtw_revision->setRowCount(0);
    ui->Rtw_revision->setColumnCount(16);
    QStringList headers;
    headers <<"SEDE"<< "ID" << "Facultad" << "Carrera" << "Insertado Por" << "Datos Clase"
           << "Cuadro de Planificaciones" << "Cuadro de Fechas" << "Estado" << "Ubicación"<< "Observación"
           << "# Revisiones Consultor" << "Número de Rechazados" << "# Revisiones General"
           << "Cambiar CP"<<"Cambiar Fechas";
    ui->Rtw_revision->setHorizontalHeaderLabels(headers);
    bool mostrar=false;
    for (const Silabos& s : silabos) {
        if((tipo==4 || tipo==5)&& (s.getEstado()=="Prerevision" || s.getEstado()=="Devolver a Academia")){//jefe o coordnaor
            mostrar=true;
        }else if(tipo==6 && (s.getEstado()=="Cargar silabo (Enviar a IEDD)" || s.getEstado()=="Correcion Mayor" || s.getEstado()=="Correcion Menor" || s.getEstado()=="Aprobado con condicion")){//ieed
            mostrar=true;
        }else if(tipo==7 && (s.getEstado()=="Listo para revision 1" || s.getEstado()=="Aprobado" || s.getEstado()=="Aprobado con condicion" )){//comsultor
            mostrar=true;
        }else{
            mostrar=false;
        }
        if(mostrar){
            int row = ui->Rtw_revision->rowCount();
            ui->Rtw_revision->insertRow(row);
            QTableWidgetItem *itemSede = new QTableWidgetItem();
            QString facultad = QString::fromStdString(s.getFacultad());
            if (!facultad.isEmpty() && facultad.at(0) == '-') {
                itemSede->setText("UNITEC");
            } else {
                itemSede->setText("CEUTEC");
            }
            ui->Rtw_revision->setItem(row, 0,itemSede);
            ui->Rtw_revision->setItem(row, 1, new QTableWidgetItem(QString::number(s.getId())));
            ui->Rtw_revision->setItem(row, 2, new QTableWidgetItem(facultad));
            ui->Rtw_revision->setItem(row, 3, new QTableWidgetItem(QString::fromStdString(s.getCarreras())));
            ui->Rtw_revision->setItem(row, 4, new QTableWidgetItem(QString::number(s.getInsertadoPor())));
            ui->Rtw_revision->setItem(row, 5, new QTableWidgetItem(QString::fromStdString(s.getDatosClase())));

            ui->Rtw_revision->setItem(row, 6, new QTableWidgetItem("CP_"+QString::fromStdString(s.getDatosClase())+".docx"));
            QString Ruta =s.getRutaFechas();
            if (!Ruta.isEmpty()) {
                    ui->Rtw_revision->setItem(row, 7, new QTableWidgetItem("F_"+QString::fromStdString(s.getDatosClase())+".docx"));
            }else{}
            ui->Rtw_revision->setItem(row, 8, new QTableWidgetItem(QString::fromStdString(s.getEstado())));
            ui->Rtw_revision->setItem(row, 9, new QTableWidgetItem(listaUsuarios.faseUsuario(QString::fromStdString(s.getEstado()))));
            ui->Rtw_revision->setItem(row, 10, new QTableWidgetItem(QString::fromStdString(s.getObservacion())));
            ui->Rtw_revision->setItem(row, 11, new QTableWidgetItem(QString::number(s.getNumRevisiones())));
            ui->Rtw_revision->setItem(row, 12, new QTableWidgetItem(QString::number(s.getNumRechazados())));
            ui->Rtw_revision->setItem(row, 13, new QTableWidgetItem(QString::number(s.getVisibilidad())));
            ui->Rtw_revision->setItem(row, 14, new QTableWidgetItem("RELOAD CP"));
            ui->Rtw_revision->setItem(row, 15, new QTableWidgetItem("RELOAD FECHAS"));
        }
    }
    ui->Rtw_revision->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void cframe::on_Ecb_sede_currentIndexChanged(const QString &arg1)
{
    Facultades.clear();
    Carreras.clear();
    ui->Ecb_facultad->clear();
    ui->Ecb_carrera->clear();
    ui->Ecb_clases->clear();
    if (ui->Ecb_sede->currentIndex() == 0) {
    } else if (ui->Ecb_sede->currentIndex() == 1) {
        Facultades = QStringList({"Ciencias Administrativas y Sociales", "Ingeniería",
                                   "Ciencias de la Salud", "Arte y Diseño"});
    } else if (ui->Ecb_sede->currentIndex() == 2) {
        Facultades = QStringList({"Licenciaturas", "Ingenierías", "Técnicos",
                                   "E. Ciencias de la Salud"});
    } else { }
    QSet<QString> temp = QSet<QString>::fromList(Facultades);
    Facultades = temp.toList();
    ui->Ecb_facultad->addItem("...");
    ui->Ecb_facultad->addItems(Facultades);
}

void cframe::on_Ecb_facultad_currentIndexChanged(const QString &arg1)
{
    Carreras.clear();
    ui->Ecb_carrera->clear();
    ui->Ecb_clases->clear();

    if (ui->Ecb_sede->currentIndex() == 1) {
        if (arg1 == "Ciencias Administrativas y Sociales") {
            Carreras = QStringList({"Administración de la Hospitalidad y Turismo",
                                     "Administración Industrial e Inteligencia de Negocios",
                                     "Derecho", "Relaciones Internacionales"});
        } else if (arg1 == "Ingeniería") {
            Carreras = QStringList({"Ingeniería Biomédica", "Ciencia de Datos e Inteligencia Artificial",
                                     "Ingeniería Civil", "Ingeniería en Energía"});
        } else if (arg1 == "Ciencias de la Salud") {
            Carreras = QStringList({"Cirugía Dental", "Medicina y Cirugía",
                                     "Nutrición", "Psicología"});
        } else if (arg1 == "Arte y Diseño") {
            Carreras = QStringList({"Animación Digital y Diseño Interactivo",
                                     "Diseño Gráfico", "Diseño de Modas",
                                     "Arquitectura", "Gastronomía"});
        }
    } else if (ui->Ecb_sede->currentIndex() == 2) {
        if (arg1 == "Licenciaturas") {
            Carreras = QStringList({"Economía", "Periodismo"});
        } else if (arg1 == "Ingenierías") {
            Carreras = QStringList({"Informática", "Electrónica"});
        } else if (arg1 == "Técnicos") {
            Carreras = QStringList({"Desarrollo y Cuidado Infantil", "Diseño de Interiores"});
        } else if (arg1 == "E. Ciencias de la Salud") {
            Carreras = QStringList({"Enfermería", "Psicología"});
        } else {
            Carreras.clear();
        }
    }
    QSet<QString> temp = QSet<QString>::fromList(Carreras);
    Carreras = temp.toList();
    ui->Ecb_carrera->addItem("...");
    ui->Ecb_carrera->addItems(Carreras);
}

void cframe::on_Ecb_carrera_currentIndexChanged(const QString &arg1)
{
    Clases.clear();
    ui->Ecb_clases->clear();
    if (ui->Ecb_sede->currentIndex() == 1) {
        if (arg1 == "Ciencia de Datos e Inteligencia Artificial") {
            Clases = QStringList({"IAR101", "CDD301", "IAR401"});
        }
    } else if (ui->Ecb_sede->currentIndex() == 2) {
        if (arg1 == "Economía") {
            Clases = QStringList({"ECO402", "ECO403"});
        }
    }
    QSet<QString> temp = QSet<QString>::fromList(Clases);
    Clases = temp.toList();
    ui->Ecb_clases->addItem("...");
    ui->Ecb_clases->addItems(Clases);
}

void cframe::on_Rbtn_cambiar_clicked()
{

    if(ui->Rle_seleccion->text().isEmpty()||ui->Rle_comentarios->text().isEmpty()||ui->Rle_estadoActual->text().isEmpty() || ui->Rcb_estadoCambiar->currentText() == "..."){
        QMessageBox::critical(this, "Error", "Porfavor, llene todos los espacios.");
    }else{
        cambiarEstado=true;
        modificarDatosSilabo(id,"QString pathNuevo",false);
        QMessageBox::information(this,"Datos congruetes","Datos han sido actualizados.");
        ui->Rle_seleccion->setText("");
        ui->Rle_comentarios->setText("");
        ui->Rle_estadoActual->setText("");
        ui->Rcb_estadoCambiar->setCurrentIndex(0);
    }

}
void cframe::modificarDatosSilabo(int id, QString pathNuevo, bool silabo)
{
    std::vector<Silabos> silabos = arbol->obtenerTodos();
    Silabos* s = arbol->buscar(id);
    if (s == nullptr) {
        return;
    }
    if(s->getId()==id && cambiarPath){
        if(s->getEstado()=="Aprobar"){
            QMessageBox::warning(this, "No posible", "Ya ha sido aprobado");
        }else{

            if(ui->tabWidget->currentIndex() == 2){
                if(silabo){
                    s->setRutaSilabos(pathNuevo);
                }else{
                    s->setRutaFechas(pathNuevo);
                }
                cambiarPath=false;
                MostrarSilabos();
            }else{
//                if(s->getNumRevisiones()>=2){
//                    QMessageBox::warning(this,"RECHAZADO","El silabo "+QString::fromStdString(s->getDatosClase()+"\nHa excedido el numero de revisiones\nRealice el proceso de ENTREGA de nuevo"));
//                    s->setEstado("Rechazar");
//                    return;
//                }
                if(silabo){
                    s->setRutaSilabos(pathNuevo);
                }else{
                    if(pathNuevo!="QString pathNuevo"){
                        s->setRutaFechas(pathNuevo);
                    }
                }
                cambiarPath=false;
                s->setEstado("Prerevision");
                //s->setNumRevisiones(s->getNumRevisiones()+1);
                s->setObservacion("Reloaded");
                s->setVisibilidad(s->getVisibilidad()+1);
                mostrarSilabosFeed(ui->Albl_cuenta->text());
                MostrarSilabos();
            }
        }
        return;
    }else if(s->getId()==id && cambiarEstado){
        string nuevaObservacion=ui->Rle_comentarios->text().toStdString();
        string nuevoEstado=ui->Rcb_estadoCambiar->currentText().toStdString();
        int nuevoNumRevisiones=s->getNumRevisiones();
        if(tipo==6 && nuevoEstado=="Listo para revision 1"){
            s->setVisibilidad(s->getVisibilidad()+1);
            nuevoNumRevisiones++;
        }
        if (nuevoNumRevisiones > 2) {
            QMessageBox::StandardButton reply;
            reply = QMessageBox::question(this, "Revisión Excedida",
                                          "El silabo " + QString::fromStdString(s->getDatosClase()) +
                                          "\nHa excedido el número de revisiones rechazadas permitidas.\n",
                                          QMessageBox::Yes | QMessageBox::No);

            if (reply == QMessageBox::Yes) {
                s->setNumRevisiones(0);
                s->setEstado("Prerevision");
            } else {
                s->setEstado("Rechazar");
            }
            s->setNumRechazado(s->getNumRechazados()+1);
            cambiarEstado=false;
            s->setVisibilidad(s->getVisibilidad()+1);
            MostrarSilabos();
            return;
        }
//        if(nuevoNumRevisiones>2){
//            QMessageBox::warning(this,"RECHAZADO","El silabo "+QString::fromStdString(s->getDatosClase()+"\nHa excedido el numero de revisiones\nNuevo estado: RECHAZADO"));
//            s->setEstado("Rechazar");
//            s->setNumRechazado(s->getNumRechazados()+1);
//            cambiarEstado=false;
//            return;
//        }
        s->setEstado(nuevoEstado);
        s->setObservacion(nuevaObservacion);
        s->setNumRevisiones(nuevoNumRevisiones);
        s->setVisibilidad(s->getVisibilidad()+1);
        cambiarEstado=false;
        MostrarSilabos();
        return;
    }
}
QString cframe::cargarArchivo(QString nombre, bool fechas)
{
    if( ui->Ecb_clases->currentText() == "...")
    {
        QMessageBox::critical(this, "Error", "Por favor, llene todos los espacios.");
    }
    else
    {
        QString filePath = QFileDialog::getOpenFileName(this, "Explorador de Archivos DOC", QDir::homePath(), "Document Files (*.doc *.docx)");
        if (!filePath.isEmpty())
        {
            return filePath;
        }
    }
}

void cframe::on_Abtn_cambioContra_clicked()
{
    bool ok;
    while (true) {
        QString newPassword = QInputDialog::getText(this, "Nueva Contraseña", "Ingrese la Nueva Contraseña: ", QLineEdit::Password, "", &ok);
        if (!ok) {
            return;
        }
        if (newPassword.isEmpty()) {
            QMessageBox::critical(this, "Error", "Por favor, ingrese una contraseña válida.");
        } else {
            actD = listaUsuarios.PrimPtr;
            while (actD != nullptr) {
                Usuario usuario = actD->getDato();
                if (usuario.getCuenta() == ui->Albl_cuenta->text()) {
                    QString oldPassword = QInputDialog::getText(this, "Contraseña Anterior", "Ingrese la Contraseña Anterior\npara confirmar su identidad: ", QLineEdit::Password, "", &ok);
                    if (!ok) {
                        return;
                    }
                    if (oldPassword != usuario.getContraActual()) {
                        QMessageBox::critical(this, "Error", "Contraseña original incorrecta.");
                        break;
                    }else{
                        usuario.setContraAnterior(newPassword);
                        listaUsuarios.solicitarCambioContra(newPassword, ui->Albl_cuenta->text(), listaUsuarios);
                        QMessageBox::information(this, "Contraseña ", "Cambio ha sido solicitado: "+usuario.getContraAnterior());
                        return;
                    }
                    return;
                }
                actD = actD->SigPtr;
            }
            if (actD == nullptr) {
                QMessageBox::critical(this, "Error", "No se encontró el usuario correspondiente para cambiar la contraseña.");
            }
        }
    }
}
QList<Usuario> cframe::DescargarUsuarios()
{
    //Base de datos debe estar abierta!!!
    QList<Usuario> UsuariosDescargados;
    QSqlQuery *Query = new QSqlQuery();
    Query->prepare("select * from SilabosUsuarios");
    Query->exec();
    int CurrentRow=0;
    while(Query->next())
    {
        //QString cuenta, QString nombre,QString contraActual, QString contraAnterior,short tipo,short sede
        Usuario* Temp = new Usuario(Query->value(0).toString(),Query->value(3).toString(),Query->value(1).toString(),Query->value(2).toString(),Query->value(4).toInt(),2);
        UsuariosDescargados.append(*Temp);
        listaUsuarios.listaInsertarFinal(*Temp);
        delete Temp;
        CurrentRow++;
    }
    return UsuariosDescargados;
}
void cframe::mostrarUsuarios()
{
    ui->Itw_usuarios->clearContents();
    QStringList headers = { "CUENTA", "NOMBRE", "CONTRASEÑA ACTUAL", "CONTRASEÑA SOLICITADA", "CARGO", "SEDE" };
    ui->Itw_usuarios->setColumnCount(headers.size());
    ui->Itw_usuarios->setHorizontalHeaderLabels(headers);
    ui->Itw_usuarios->setRowCount(listaUsuarios.cantidadUsuarios);
    actD = listaUsuarios.PrimPtr;
    int row = 0;
    while (actD != nullptr && row < listaUsuarios.cantidadUsuarios) {
        Usuario usuario = actD->getDato();
        ui->Itw_usuarios->setItem(row, 0, new QTableWidgetItem(usuario.getCuenta()));
        ui->Itw_usuarios->setItem(row, 1, new QTableWidgetItem(usuario.getNombre()));
        QString contraActualOculta(usuario.getContraActual().length(), '*');
        ui->Itw_usuarios->setItem(row, 2, new QTableWidgetItem(contraActualOculta));
        QString contraSolicitadaOculta(usuario.getContraAnterior().length(), '*');
        ui->Itw_usuarios->setItem(row, 3, new QTableWidgetItem(contraSolicitadaOculta));
        ui->Itw_usuarios->setItem(row, 4, new QTableWidgetItem(listaUsuarios.tipoUsuario(usuario.getTipo())));
        ui->Itw_usuarios->setItem(row, 5, new QTableWidgetItem(listaUsuarios.sede(usuario.getSede())));
        actD = actD->SigPtr;
        ++row;
    }
    ui->Itw_usuarios->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void cframe::on_pushButton_clicked()
{
    if(ui->Ile_contra->text().isEmpty() || ui->Ile_cuenta->text().isEmpty()|| ui->Ile_name->text().isEmpty() || ui->Icb_tipo->currentIndex()==0){
        QMessageBox::critical(this, "Error", "¡Por favor, llene todos los espacios!");

    }else{
        if( cuentaNumero( ui->Ile_cuenta->text().toStdString())  && listaUsuarios.numCuentaDisponible(ui->Ile_cuenta->text())){
            Usuario* Temp = new Usuario(ui->Ile_cuenta->text(),ui->Ile_name->text(),ui->Ile_contra->text(),"",ui->Icb_tipo->currentIndex(), ui->Icb_sede->currentIndex());
            listaUsuarios.listaInsertarFinal(*Temp);
            delete Temp;
            mostrarUsuarios();
            QMessageBox::information(this, "Éxito", "Usuario creado exitosamente.");
            ui->Ile_contra->clear();ui->Ile_cuenta->clear();  ui->Ile_name->clear();ui->Icb_tipo->setCurrentIndex(0);
        }else{
            QMessageBox::critical(this, "Error", "Numero de cuenta no disponible.");

        }
    }
}


bool cframe::cuentaNumero(const std::string &tt)
{
    for (char car : tt) {
        if (!std::isdigit(car)) {
            QMessageBox::warning(this,  "Datos incongruentes","Favor, asegurese de que el numero de cuenta solo contenga digitos.");
            return false;
        }
    }
    if(ui->Ile_cuenta->text().length() !=8){
        QMessageBox::warning(this,  "Datos incongruentes","Favor, asegurese de que la cuenta sea de 8 digitos.");
        return false;
    }
    return true;
}


void cframe::on_Itw_usuarios_cellClicked(int row, int column)
{
    QTableWidgetItem *item = ui->Itw_usuarios->item(row, 0); // Obtener el item de la columna 0 (CUENTA)
     QString cuenta = item->text();
    if (column == 3) { // Columna 3 es la columna de "CONTRASEÑA ANTERIOR"
        QString contraDeseada= listaUsuarios.obtenerContraAnterior(cuenta, listaUsuarios);
        if(contraDeseada.startsWith("°")){
            QMessageBox::warning(this,"Advertencia", "Ya ha aceptado esta propuesta.\nEn espera a que el usuario confirme el cambio.");
            return;
        }
        if (item && (contraDeseada != "RECHAZADA" && !contraDeseada.isEmpty())) {

            QMessageBox::StandardButton reply;
            reply = QMessageBox::question(this, "Confirmación",
                                          "Contraseña propuesta:"+contraDeseada+"\n¿Estás seguro que desea cambiar contraseña de " + cuenta + "?",
                                          QMessageBox::Yes | QMessageBox::No);
            if (reply == QMessageBox::Yes) {
                listaUsuarios.aceptarCambioContra(true, cuenta, listaUsuarios);
                mostrarUsuarios();
                return;
            } else if(reply == QMessageBox::No){
                listaUsuarios.aceptarCambioContra(false, cuenta, listaUsuarios);
                mostrarUsuarios();
                return;
            }else{
                return;
            }
        } else if (contraDeseada == "RECHAZADA"){
            QMessageBox::warning(this,"Advertencia", "Ya ha recchazado esta propuesta.");
            return;
        }else{
        }
    }else if(column == 0 && cuenta != ui->Albl_cuenta->text()){
         QTableWidgetItem *item = ui->Itw_usuarios->item(row, 0);
         QString cuenta = item->text();
         QString nombre= ui->Itw_usuarios->item(row, 1)->text();
         QMessageBox::StandardButton reply;
         reply = QMessageBox::question(this, "Confirmación",
                                       "Desea borrar este usuario: "+nombre+"\nCuenta: "+cuenta+"\n¿Estás seguro?",
                                       QMessageBox::Yes | QMessageBox::No);
         if (reply == QMessageBox::Yes) {
             listaUsuarios.DeleteUser(cuenta, listaUsuarios);
             mostrarUsuarios();
             return;
         } else if(reply == QMessageBox::No){
             return;
         }else{
             return;
         }
    }
}
void cframe::mostrarSilabosBoard(bool aprobado)
{
    std::vector<Silabos> silabos = arbol->obtenerTodos();
    ui->Btw_dashboard->clearContents();
    ui->Btw_dashboard->setRowCount(0);
    ui->Btw_dashboard->setColumnCount(14);
    bool mostrar=false;
    QStringList headers;
    headers << "SEDE" << "ID" << "Facultad" << "Carrera" << "Insertado Por" << "Datos Clase"
            << "Cuadro de Planificaciones" << "Cuadro de Fechas" << "Estado" << "Ubicación"<< "Observación"
            << "# revisiones consultor" << "# veces Rechazado" << "# Revisiones general";
    ui->Btw_dashboard->setHorizontalHeaderLabels(headers);

    for (const Silabos& s : silabos) {
        if (aprobado && s.getEstado() == "Aprobar" && ui->Brb_aprobados->isChecked()){
            mostrar=true;
        }else if(!aprobado && s.getEstado() != "Aprobar" && ui->Brb_proceso->isChecked()){
            mostrar =true;
        }else{
            mostrar=false;
        }

        if(mostrar){
            int row = ui->Btw_dashboard->rowCount();
            ui->Btw_dashboard->insertRow(row);

            QTableWidgetItem *itemSede = new QTableWidgetItem();
            QString facultad = QString::fromStdString(s.getFacultad());
            if (!facultad.isEmpty() && facultad.at(0) == '-') {
                itemSede->setText("UNITEC");
            } else {
                itemSede->setText("CEUTEC");
            }
            ui->Btw_dashboard->setItem(row, 0, itemSede);
            ui->Btw_dashboard->setItem(row, 1, new QTableWidgetItem(QString::number(s.getId())));
            ui->Btw_dashboard->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(s.getFacultad())));
            ui->Btw_dashboard->setItem(row, 3, new QTableWidgetItem(QString::fromStdString(s.getCarreras())));
            ui->Btw_dashboard->setItem(row, 4, new QTableWidgetItem(QString::number(s.getInsertadoPor())));
            ui->Btw_dashboard->setItem(row, 5, new QTableWidgetItem(QString::fromStdString(s.getDatosClase())));
            ui->Btw_dashboard->setItem(row, 6, new QTableWidgetItem("Cuadro de Planificaciones_"+QString::fromStdString(s.getDatosClase())+".docx"));
            QString Ruta =s.getRutaFechas();
            if (!Ruta.isEmpty()) {
                    ui->Btw_dashboard->setItem(row, 7, new QTableWidgetItem("Cuadro de fechas_"+QString::fromStdString(s.getDatosClase())+".docx"));
            }else{}
            ui->Btw_dashboard->setItem(row, 8, new QTableWidgetItem(QString::fromStdString(s.getEstado())));
            ui->Btw_dashboard->setItem(row, 9, new QTableWidgetItem(listaUsuarios.faseUsuario(QString::fromStdString(s.getEstado()))));
            ui->Btw_dashboard->setItem(row, 10, new QTableWidgetItem(QString::fromStdString(s.getObservacion())));
            ui->Btw_dashboard->setItem(row, 11, new QTableWidgetItem(QString::number(s.getNumRevisiones())));
            ui->Btw_dashboard->setItem(row, 12, new QTableWidgetItem(QString::number(s.getNumRechazados())));
            ui->Btw_dashboard->setItem(row, 13, new QTableWidgetItem(QString::number(s.getVisibilidad())));
        }
        mostrar=false;
    }
   // ui->Btw_dashboard->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}
void cframe::mostrarSilabosFeed(QString cuenta)
{
    //            ui->DRTW_revision->setHorizontalHeaderLabels(QStringList() <<"VER DOCX"<<"ORDEN DE INGRESO"<<"INGRESADO POR"<<"# CUENTA"<<"FACULTAD"<<"CARRERA"<<"CODIGO CLASE"<<"OBSERVACION"<<"PATH"<<"RELOAD");

    std::vector<Silabos> silabos = arbol->obtenerTodos();

    ui->Ftw_feed->setRowCount(0);
    ui->Ftw_feed->setColumnCount(16);
    QStringList headers;
    headers <<"SEDE"<< "ID" << "Facultad" << "Carrera" << "Insertado Por" << "Datos Clase"
           << "Cuadro de Planificaciones" << "Cuadro de Fechas" << "Estado" << "Ubicación"<< "Observación"
           << "# revisiones consultor" << "# veces Rechazado" << "# Revisiones general"
           << "Cambiar Silabo"<<"Cambiar Fechas";
    ui->Ftw_feed->setHorizontalHeaderLabels(headers);

    for (const Silabos& s : silabos) {
        bool vistaDocente=false;
        if(s.getInsertadoPor()==cuenta.toInt() ) {
            vistaDocente=true;
        }
        if(vistaDocente || ui->Albl_tipo->text().toStdString()=="IEDD"){
            int row = ui->Ftw_feed->rowCount();
            ui->Ftw_feed->insertRow(row);

            QTableWidgetItem *itemSede = new QTableWidgetItem();
            QString facultad = QString::fromStdString(s.getFacultad());
            if (!facultad.isEmpty() && facultad.at(0) == '-') {
                itemSede->setText("UNITEC");
            } else {
                itemSede->setText("CEUTEC");
            }
            ui->Ftw_feed->setItem(row, 0,itemSede);
            ui->Ftw_feed->setItem(row, 1, new QTableWidgetItem(QString::number(s.getId())));
            ui->Ftw_feed->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(s.getFacultad())));
            ui->Ftw_feed->setItem(row, 3, new QTableWidgetItem(QString::fromStdString(s.getCarreras())));
            ui->Ftw_feed->setItem(row, 4, new QTableWidgetItem(QString::number(s.getInsertadoPor())));
            ui->Ftw_feed->setItem(row, 5, new QTableWidgetItem(QString::fromStdString(s.getDatosClase())));
            ui->Ftw_feed->setItem(row, 6, new QTableWidgetItem("Cuadro de planficaciones_"+QString::fromStdString(s.getDatosClase())+".docx"));
            QString Ruta =s.getRutaFechas();
            if (!Ruta.isEmpty()) {
                    ui->Ftw_feed->setItem(row, 7, new QTableWidgetItem("Cuadro de fechas_"+QString::fromStdString(s.getDatosClase())+".docx"));
            }else{}
            ui->Ftw_feed->setItem(row, 8, new QTableWidgetItem(QString::fromStdString(s.getEstado())));
            ui->Ftw_feed->setItem(row, 9, new QTableWidgetItem(listaUsuarios.faseUsuario(QString::fromStdString(s.getEstado()))));
            ui->Ftw_feed->setItem(row, 10, new QTableWidgetItem(QString::fromStdString(s.getObservacion())));
            ui->Ftw_feed->setItem(row, 11, new QTableWidgetItem(QString::number(s.getNumRevisiones())));
            ui->Ftw_feed->setItem(row, 12, new QTableWidgetItem(QString::number(s.getNumRechazados())));
            ui->Ftw_feed->setItem(row, 13, new QTableWidgetItem(QString::number(s.getVisibilidad())));
            ui->Ftw_feed->setItem(row, 14, new QTableWidgetItem("RELOAD CP"));
            ui->Ftw_feed->setItem(row, 15, new QTableWidgetItem("RELOAD FECHAS"));
        }
    }
    ui->Btw_dashboard->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void cframe::on_Brb_proceso_clicked()
{
    ui->Btw_dashboard->clear();
    mostrarSilabosBoard(false);
}
void cframe::on_Brb_aprobados_clicked()
{
    ui->Btw_dashboard->clear();
    mostrarSilabosBoard(true);
}

void cframe::
on_Rtw_revision_cellClicked(int row, int column)
{
    id = ui->Rtw_revision->item(row, 1)->text().toInt();
    string log=ui->Albl_tipo->text().toStdString();
    ui->Rle_seleccion->setText(ui->Rtw_revision->item(row, column)->text());
    ui->Rle_estadoActual->setText(ui->Rtw_revision->item(row, 8)->text());
    if(tipo ==7 && column!=15 && column !=14){
        QStringList items;
        ui->Rcb_estadoCambiar->clear();
        if( ui->Rtw_revision->item(row, 8)->text().toStdString()=="Aprobado"){
            items<<"..."<<"Aprobar"<<"Aprobado con condicion";

        }else{
            items<<"..."<<"Aprobado"<<"Correcion Mayor"<<"Correcion Menor";
        }
        ui->Rcb_estadoCambiar->addItems(items);
    }else if(column ==6 ){
        std::vector<Silabos> silabos = arbol->obtenerTodos();
        Silabos* s = arbol->buscar(id);
        QString Ruta =s->getRutaSilabos();
        QDesktopServices::openUrl(QUrl::fromLocalFile(Ruta));
    }else if(column ==7 ){
        std::vector<Silabos> silabos = arbol->obtenerTodos();
        Silabos* s = arbol->buscar(id);
        QString Ruta =s->getRutaFechas();
        if (!Ruta.isEmpty()) { // Verifica que la ruta no esté vacía
                QDesktopServices::openUrl(QUrl::fromLocalFile(Ruta));
            }
    }else if(column==14 &&  (log != "CONSULTOR" || log!="DECANO" ||log!= "DIRECTORES") ){
        cambiarSilabo( id, ui->Rtw_revision->item(row, 6)->text(),14);
    }else if(column==15  &&  (log != "CONSULTOR" || log!="DECANO" ||log!= "DIRECTORES")){
        cambiarSilabo( id, ui->Rtw_revision->item(row, 7)->text(),15);

    }else {
    }
    if ((column==14 ||column==15 )&&(log == "CONSULTOR" || log=="DECANO" ||log== "DIRECTOR")){
        QMessageBox::warning(this, "Aviso", "El " + QString::fromStdString(log)+" no tiene permisos para RELOAD.");

    }
}
void cframe::cambiarSilabo(int id, QString pathActual, short i)
{
    QString filePath = QFileDialog::getOpenFileName(this, "Explorador de Archivos DOC", QDir::homePath(), "Document Files (*.doc *.docx)");
    if (pathActual==filePath) {
        QMessageBox::warning(this, "No posible", "Ha seleccionado el mismo documento.");
    }else if(!filePath.isEmpty()){
        cambiarPath=true;
        if(i==14){
            modificarDatosSilabo(id,filePath, true);
        }else{

            modificarDatosSilabo(id,filePath, false);
        }
    }else{
        QMessageBox::warning(this, "No posible", "No ha seleccionado.");
    }
}

void cframe::on_Ftw_feed_cellClicked(int row, int column)
{
    id = ui->Ftw_feed->item(row, 1)->text().toInt();
    string estado = ui->Ftw_feed->item(row, 9)->text().toStdString();
    string log=ui->Albl_tipo->text().toStdString();

    if((column==14 ||column==15 )&& log == "DOCENTE" && (estado=="DOCENTE") ){
        if(column==14 ){
            cambiarSilabo( id, ui->Ftw_feed->item(row, 6)->text(),14);
        }else if(column==15){
            cambiarSilabo( id, ui->Ftw_feed->item(row, 7)->text(),15);
        }
    }else if(column ==6 ){
        std::vector<Silabos> silabos = arbol->obtenerTodos();
        Silabos* s = arbol->buscar(id);
        QString Ruta =s->getRutaSilabos();
        QDesktopServices::openUrl(QUrl::fromLocalFile(Ruta));
    }else if(column ==7 ){
        std::vector<Silabos> silabos = arbol->obtenerTodos();
        Silabos* s = arbol->buscar(id);
        QString Ruta =s->getRutaFechas();
        if (!Ruta.isEmpty()) {
            QDesktopServices::openUrl(QUrl::fromLocalFile(Ruta));
        }
        else{
            QMessageBox::warning(this, "Aviso", "El " + QString::fromStdString(log)+" no tiene permisos para RELOAD. \n Actualmente en el FEED solo puede observar.");

        }
    }else if ((column==14 || column ==15) && estado != "DOCENTE") {
        QMessageBox::warning(this, "Aviso", "El " + QString::fromStdString(log)+" no tiene permisos para RELOAD. \n Actualmente en el FEED solo puede observar.");

    }

//    if(column==6 || column==7)
//    {
//        QString Ruta = ui->Ftw_feed->item(row, column)->text();
//        QDesktopServices::openUrl(QUrl::fromLocalFile(Ruta));
//    }
//    else if((column==14 || column==15) && (log != "CONSULTOR" || log!="DECANO" ||log!= "DIRECTORES" || log!= "IEDD") && check){
//        cambiarPath=true;
//        if(column==14 ){
//            cambiarSilabo( id, ui->Ftw_feed->item(row, 6)->text(),14);
//        }else if(column==15){
//            cambiarSilabo( id, ui->Ftw_feed->item(row, 7)->text(),15);
//        }
//    }
}

void cframe::on_Btw_dashboard_cellClicked(int row, int column)
{
    id = ui->Btw_dashboard->item(row, 1)->text().toInt();
    string log=ui->Albl_tipo->text().toStdString();
    if(column ==6 ){
        std::vector<Silabos> silabos = arbol->obtenerTodos();
        Silabos* s = arbol->buscar(id);
        QString Ruta =s->getRutaSilabos();
        QDesktopServices::openUrl(QUrl::fromLocalFile(Ruta));
    }else if(column ==7 ){
        std::vector<Silabos> silabos = arbol->obtenerTodos();
        Silabos* s = arbol->buscar(id);
        QString Ruta =s->getRutaFechas();
        if (!Ruta.isEmpty()) {
            QDesktopServices::openUrl(QUrl::fromLocalFile(Ruta));
        }

    }
}
void cframe::on_Ftw_feed_cellActivated      (int row, int column)   {}
void cframe::on_Mcb_tipo_currentIndexChanged(int index)             {}

//QList<Clase> cframe::DescargarClases()
//{
//    QList<Clase> ClasesDescargadas;
//    QSqlQuery *Query = new QSqlQuery();
//    Query->prepare("select * from SilabosClasesDisponibles");
//    Query->exec();
//    int CurrentRow=0;
//    while(Query->next())
//    {
//        //Codigo-Nombre-Carrera-Facultad-Sede
//        Clase* Temp = new Clase(Query->value(0).toString(),Query->value(1).toString(),Query->value(2).toString(),Query->value(3).toString(),Query->value(4).toString());
//        ClasesDescargadas.append(*Temp);
//        delete Temp;
//        CurrentRow++;
//    }
//    return ClasesDescargadas;
//}

//QList<Silabos> cframe::DescargarListaSilabos()
//{
//    QList<Silabos> ClasesDescargadas;
//    QSqlQuery *Query = new QSqlQuery();
//    Query->prepare("select * from SilabosClases");
//    Query->exec();
//    int CurrentRow=0;
//    string Facultad;
//    QString Fechas;
//    while(Query->next())
//    {
//        if(Query->value(3).toString()=="UNITEC")
//        {
//            Facultad="-"+Query->value(2).toString().toStdString();
//            Fechas="";
//        }
//        else
//        {
//            Facultad=Query->value(2).toString().toStdString();
//            Fechas="";
//            Fechas.append("F");
//            Fechas.append(Query->value(4).toString().left(6));
//            Fechas.append(".docx");
//        //Codigo-Nombre-Carrera-Facultad-Sede
//        Silabos* Temp = new Silabos(Facultad,
//                                    Query->value(1).toString().toStdString(),
//                                    Query->value(5).toInt(),  // insertadoPor
//                                    Query->value(4).toString().toStdString(),
//                                    Query->value(4).toString().left(6)+".docx",
//                                    "Fechas""",
//                                    Query->value(6).toString().toStdString(),
//                                    Query->value(7).toString().toStdString(),
//                                    Query->value(8).toInt(),  // numRevisiones
//                                    Query->value(9).toInt(),  // numRechazado
//                                    Query->value(10).toInt()   // visibilidad para jefe (numero 4) y para coordinador(numero 5)
//                                    );
//        ClasesDescargadas.append(*Temp);
//        delete Temp;
//        CurrentRow++;
//        BA2docx(DescargarSilabo(Query->value(4).toString().left(6)),Query->value(4).toString().left(6)+".docx");
//        }
//        //QMessageBox::critical(this, "Lista", Query->value(4).toString());
//    }
//    for(int i=0;i<ClasesDescargadas.size();i++)
//    {
//        arbol->insertar(ClasesDescargadas[i]);
//        //QMessageBox::critical(this, "Arbol", QString::fromStdString(ClasesDescargadas[i].getDatosClase()));
//    }
//    return ClasesDescargadas;

//}

//void cframe::DescargarSilabos()
//{
//    QSqlQuery *Query = new QSqlQuery();
//    Query->prepare("select * from SilabosClases");
//    Query->exec();
//    string Facultad;
//    while(Query->next())
//    {
//        if(Query->value(3).toString()=="UNITEC")
//        {
//            Facultad="-"+Query->value(2).toString().toStdString();
//        }
//        else
//        {
//            Facultad=Query->value(2).toString().toStdString();
//        }
//        Silabos* s = new Silabos(Facultad,
//                                 Query->value(1).toString().toStdString(),
//                                 Query->value(5).toInt(),  // insertadoPor
//                                 Query->value(4).toString().toStdString(),
//                                 Query->value(4).toString().left(6)+".docx",
//                                 "",
//                                 Query->value(6).toString().toStdString(),
//                                 Query->value(7).toString().toStdString(),
//                                 Query->value(8).toInt(),  // numRevisiones
//                                 Query->value(9).toInt(),  // numRechazado
//                                 Query->value(10).toInt()   // visibilidad para jefe (numero 4) y para coordinador(numero 5)
//                                 );
//        //  QMessageBox::critical(this, "Arbol", Query->value(4).toString());
//        arbol->insertar(*s);
//        delete s;
//        BA2docx(DescargarSilabo(Query->value(4).toString().left(6)),Query->value(4).toString().left(6)+".docx");
//        //cout<<"Silabo Cargado "<<Query->value(4).toString().toStdString();
//    }
//}

//QString cframe::Encrypt(QString Message, int Key)
//{
//    QChar c;
//    QString EncryptedMessage;
//    for(int i=0;i<Message.length();i++)
//    {
//        c=Message.at(i).toLatin1()+(Key/(Key%100))%10;
//        EncryptedMessage+=c;
//    }
//    return EncryptedMessage;
//}

//QString cframe::Decrypt(QString Message, int Key)
//{
//    QChar c;
//    QString DecryptedMessage;
//    for(int i=0;i<Message.length();i++)
//    {
//        c=Message.at(i).toLatin1()-(Key/(Key%100))%10;
//        DecryptedMessage+=c;
//    }
//    return DecryptedMessage;
//}

//QByteArray cframe::docx2BA(QString Path)
//{
//    QGuiApplication::setOverrideCursor(Qt::WaitCursor);
//    QFile file(Path);
//    if (!file.open(QIODevice::ReadOnly)) {
//        return QByteArray();
//    }
//    QByteArray byteArray = file.readAll();
//    file.close();
//    QGuiApplication::restoreOverrideCursor();
//    return byteArray;
//}

//void cframe::BA2docx(QByteArray ByteArray, QString NewFile)
//{
//    QFile newFile(NewFile);
//    if (!newFile.open(QIODevice::WriteOnly)) {
//        return;
//    }
//    newFile.write(ByteArray);
//    newFile.close();
//}

//void cframe::SubirSilabo(QString CodigoSilabo, QByteArray Archivo)
//{
//    QSqlQuery query(db);
//    query.prepare("INSERT INTO SilabosArchivos(Codigo,Archivo) VALUES(:Codigo,:docxData)");
//    query.bindValue(":Codigo", CodigoSilabo);
//    query.bindValue(":docxData", Archivo);
//    if (!query.exec())
//    {
//        QMessageBox::critical(this, "Error", "Error en la base de datos. Error: " + query.lastError().text());
//    }
//}

//QByteArray cframe::DescargarSilabo(QString Codigo)
//{
//    QGuiApplication::setOverrideCursor(Qt::WaitCursor);
//    //db.open();
//    QSqlQuery query(db);
//    query.prepare("SELECT Archivo FROM SilabosArchivos WHERE Codigo = :code");
//    query.bindValue(":code", Codigo);
//    if (!query.exec())
//    {
//        QMessageBox::critical(this, "Error", "Error en la base de datos. Error: " + query.lastError().text());
//        db.close();
//        return QByteArray();
//    }
//    QByteArray byteArray;
//    if (query.next())
//    {
//        byteArray = query.value(0).toByteArray();
//    } else
//    {
//        //QMessageBox::critical(this, "Error", "No existe un archivo con el codigo seleccionado");
//    }
//    //db.close();
//    QGuiApplication::restoreOverrideCursor();
//    return byteArray;
//}

//void cframe::Conectar()
//{
//    QGuiApplication::setOverrideCursor(Qt::WaitCursor);
//    db.setDatabaseName(connectionString);
//    if(db.open())
//    {
//        UsuariosRegistrados=DescargarUsuarios();
//        ClasesAgregadas=DescargarClases();
//        SilabosDescargados=DescargarListaSilabos();
//        Sedes.clear();
//        for(int i=0;i<ClasesAgregadas.size();i++)
//        {
//            Sedes.append(ClasesAgregadas[i].Sede);
//        }
//        QSet<QString> temp = QSet<QString>::fromList(Sedes);
//        Sedes = temp.toList();
//        ui->Ecb_sede->clear();
//        ui->Ecb_facultad->clear();
//        ui->Ecb_carrera->clear();
//        ui->Ecb_clases->clear();
//        ui->Ecb_sede->addItem("...");
//        ui->Ecb_sede->addItems(Sedes);
//        QGuiApplication::restoreOverrideCursor();
//        //DescargarSilabos();
//        //QMessageBox::information(this,"Exito!","Conectado a Azure SQL Database");
//    }
//    else
//    {
//        QGuiApplication::restoreOverrideCursor();
//        QMessageBox::critical(this,"Error en la conexion!","No ha sido posible conectar con el servidor. Intentelo de nuevo.");
//    }
//    db.close();

//}

//void cframe::SubirDatos()
//{
//    //subir Usuarios
//    db.open();
//    QSqlQuery query(db);
//    query.prepare("Delete FROM SilabosUsuarios");
//    query.exec();
//    actD = listaUsuarios.PrimPtr;
//    int row = 0;
//    while (actD != nullptr && row < listaUsuarios.listaTamano()) {
//        Usuario usuario = actD->getDato();
//        query.prepare("Insert into SilabosUsuarios (Cuenta, Contrasena,ContrasenaAnterior, NombreCompleto, tipo) VALUES(:Cuenta,:Contrasena,:ContrasenaAnterior,:Nombre,:Tipo)");
//        query.bindValue(":Cuenta", usuario.getCuenta());
//        query.bindValue(":Contrasena", usuario.getContraActual());
//        query.bindValue(":ContrasenaAnterior", usuario.getContraAnterior());
//        query.bindValue(":Nombre", usuario.getNombre());
//        query.bindValue(":Tipo", usuario.getTipo());
//        query.exec();
//        actD = actD->SigPtr;
//        ++row;
//    }

//    //SubirSilabos
//    query.prepare("Delete FROM SilabosClases");
//    query.exec();
//    query.prepare("Delete FROM SilabosArchivos");
//    query.exec();
//    QString Sede;
//    std::vector<Silabos> silabos = arbol->obtenerTodos();
//    for(int i=0;i<silabos.size();i++)
//    {
//        QString facultad = QString::fromStdString(silabos[i].getFacultad());

//        if (!facultad.isEmpty() && facultad.at(0) == '-') {
//            Sede="UNITEC";
//        } else {
//            Sede="CEUTEC";
//        }
//        query.prepare("Insert into SilabosClases (CodigoClase, Carrera, Facultad, Sede, Nombre, InsertadoPor, Estado, Observacion, NumRevisiones, NumRechazado, Visibilidad) VALUES(:Codigo,:Carrera,:Facultad,:Sede,:Nombre,:InsertadoPor,:Estado,:Observacion,:NumRevisiones,:NumRechazado,:Visibilidad)");
//        //:Codigo,:Carrera,:Facultad,:Sede,:Nombre,:InsertadoPor,:Estado,:Observacion,:NumRevisiones,:NumRechazado,:Visibilidad
//        query.bindValue(":Codigo", QString::fromStdString(silabos[i].getDatosClase()).left(6));
//        query.bindValue(":Carrera", QString::fromStdString(silabos[i].getCarreras()));
//        query.bindValue(":Facultad", QString::fromStdString(silabos[i].getFacultad()));
//        query.bindValue(":Sede", Sede);
//        query.bindValue(":Nombre", QString::fromStdString(silabos[i].getDatosClase()));
//        query.bindValue(":InsertadoPor", silabos[i].getInsertadoPor());
//        query.bindValue(":Estado", QString::fromStdString(silabos[i].getEstado()));
//        query.bindValue(":Observacion", QString::fromStdString(silabos[i].getObservacion()));
//        query.bindValue(":NumRevisiones", silabos[i].getNumRevisiones());
//        query.bindValue(":NumRechazado", silabos[i].getNumRechazados());
//        query.bindValue(":Visibilidad", silabos[i].getVisibilidad());
//        SubirSilabo(QString::fromStdString(silabos[i].getDatosClase()).left(6), docx2BA(silabos[i].getRutaSilabos()));
//        query.exec();
//    }
//    db.close();
//}
