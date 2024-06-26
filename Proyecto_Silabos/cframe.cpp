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
    QMessageBox::StandardButton reply;

    reply = QMessageBox::information(this, "Bienvenido", "Cargar base de datos para iniciar.\nEsto puede tardar unos segundos.", QMessageBox::Ok);
    if (reply == QMessageBox::Ok) {
        Conectar();
    }else{

    }

}

cframe::~cframe()
{
    SubirDatos();
    delete ui;
    delete arbol;
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

QList<Clase> cframe::DescargarClases()
{
    QList<Clase> ClasesDescargadas;
    QSqlQuery *Query = new QSqlQuery();
    Query->prepare("select * from SilabosClasesDisponibles");
    Query->exec();
    int CurrentRow=0;
    while(Query->next())
    {
        //Codigo-Nombre-Carrera-Facultad-Sede
        Clase* Temp = new Clase(Query->value(0).toString(),Query->value(1).toString(),Query->value(2).toString(),Query->value(3).toString(),Query->value(4).toString());
        ClasesDescargadas.append(*Temp);
        delete Temp;
        CurrentRow++;
    }
    return ClasesDescargadas;
}

QList<Silabos> cframe::DescargarListaSilabos()
{
    QList<Silabos> ClasesDescargadas;
    QSqlQuery *Query = new QSqlQuery();
    Query->prepare("select * from SilabosClases");
    Query->exec();
    int CurrentRow=0;
    string Facultad;
    QString Fechas;
    while(Query->next())
    {
        if(Query->value(3).toString()=="UNITEC")
        {
            Facultad="-"+Query->value(2).toString().toStdString();
            Fechas="";
        }
        else
        {
            Facultad=Query->value(2).toString().toStdString();
            Fechas="";
            Fechas.append("F");
            Fechas.append(Query->value(4).toString().left(6));
            Fechas.append(".docx");
        //Codigo-Nombre-Carrera-Facultad-Sede
        Silabos* Temp = new Silabos(Facultad,
                                    Query->value(1).toString().toStdString(),
                                    Query->value(5).toInt(),  // insertadoPor
                                    Query->value(4).toString().toStdString(),
                                    Query->value(4).toString().left(6)+".docx",
                                    "Fechas""",
                                    Query->value(6).toString().toStdString(),
                                    Query->value(7).toString().toStdString(),
                                    Query->value(8).toInt(),  // numRevisiones
                                    Query->value(9).toInt(),  // numRechazado
                                    Query->value(10).toInt()   // visibilidad para jefe (numero 4) y para coordinador(numero 5)
                                    );
        ClasesDescargadas.append(*Temp);
        delete Temp;
        CurrentRow++;
        BA2docx(DescargarSilabo(Query->value(4).toString().left(6)),Query->value(4).toString().left(6)+".docx");
        }
        //QMessageBox::critical(this, "Lista", Query->value(4).toString());
    }
    for(int i=0;i<ClasesDescargadas.size();i++)
    {
        arbol->insertar(ClasesDescargadas[i]);
        //QMessageBox::critical(this, "Arbol", QString::fromStdString(ClasesDescargadas[i].getDatosClase()));
    }
    return ClasesDescargadas;

}

void cframe::DescargarSilabos()
{
    QSqlQuery *Query = new QSqlQuery();
    Query->prepare("select * from SilabosClases");
    Query->exec();
    string Facultad;
    while(Query->next())
    {
        if(Query->value(3).toString()=="UNITEC")
        {
            Facultad="-"+Query->value(2).toString().toStdString();
        }
        else
        {
            Facultad=Query->value(2).toString().toStdString();
        }
        Silabos* s = new Silabos(Facultad,
                                 Query->value(1).toString().toStdString(),
                                 Query->value(5).toInt(),  // insertadoPor
                                 Query->value(4).toString().toStdString(),
                                 Query->value(4).toString().left(6)+".docx",
                                 "",
                                 Query->value(6).toString().toStdString(),
                                 Query->value(7).toString().toStdString(),
                                 Query->value(8).toInt(),  // numRevisiones
                                 Query->value(9).toInt(),  // numRechazado
                                 Query->value(10).toInt()   // visibilidad para jefe (numero 4) y para coordinador(numero 5)
                                 );
        //  QMessageBox::critical(this, "Arbol", Query->value(4).toString());
        arbol->insertar(*s);
        delete s;
        BA2docx(DescargarSilabo(Query->value(4).toString().left(6)),Query->value(4).toString().left(6)+".docx");
        //cout<<"Silabo Cargado "<<Query->value(4).toString().toStdString();
    }
}

QString cframe::Encrypt(QString Message, int Key)
{
    QChar c;
    QString EncryptedMessage;
    for(int i=0;i<Message.length();i++)
    {
        c=Message.at(i).toLatin1()+(Key/(Key%100))%10;
        EncryptedMessage+=c;
    }
    return EncryptedMessage;
}

QString cframe::Decrypt(QString Message, int Key)
{
    QChar c;
    QString DecryptedMessage;
    for(int i=0;i<Message.length();i++)
    {
        c=Message.at(i).toLatin1()-(Key/(Key%100))%10;
        DecryptedMessage+=c;
    }
    return DecryptedMessage;
}

QByteArray cframe::docx2BA(QString Path)
{
    QGuiApplication::setOverrideCursor(Qt::WaitCursor);
    QFile file(Path);
    if (!file.open(QIODevice::ReadOnly)) {
        //QMessageBox::critical(this, "Error", "No se pudo abrir el archivo");
        return QByteArray();
    }

    QByteArray byteArray = file.readAll();
    file.close();
    QGuiApplication::restoreOverrideCursor();
    return byteArray;
}

void cframe::BA2docx(QByteArray ByteArray, QString NewFile)
{
    QFile newFile(NewFile);
    if (!newFile.open(QIODevice::WriteOnly)) {
        //QMessageBox::critical(this, "Error", "No se pudo abrir el archivo");
        return;
    }
    newFile.write(ByteArray);
    newFile.close();
}

void cframe::SubirSilabo(QString CodigoSilabo, QByteArray Archivo)
{
    QSqlQuery query(db);
    query.prepare("INSERT INTO SilabosArchivos(Codigo,Archivo) VALUES(:Codigo,:docxData)");
    query.bindValue(":Codigo", CodigoSilabo);
    query.bindValue(":docxData", Archivo);
    if (!query.exec())
    {
        QMessageBox::critical(this, "Error", "Error en la base de datos. Error: " + query.lastError().text());
    }
}

QByteArray cframe::DescargarSilabo(QString Codigo)
{
    QGuiApplication::setOverrideCursor(Qt::WaitCursor);
    //db.open();
    QSqlQuery query(db);
    query.prepare("SELECT Archivo FROM SilabosArchivos WHERE Codigo = :code");
    query.bindValue(":code", Codigo);
    if (!query.exec())
    {
        QMessageBox::critical(this, "Error", "Error en la base de datos. Error: " + query.lastError().text());
        db.close();
        return QByteArray();
    }
    QByteArray byteArray;
    if (query.next())
    {
        byteArray = query.value(0).toByteArray();
    } else
    {
        //QMessageBox::critical(this, "Error", "No existe un archivo con el codigo seleccionado");
    }
    //db.close();
    QGuiApplication::restoreOverrideCursor();
    return byteArray;
}

void cframe::Conectar()
{
    QGuiApplication::setOverrideCursor(Qt::WaitCursor);
    db.setDatabaseName(connectionString);
    if(db.open())
    {
        UsuariosRegistrados=DescargarUsuarios();
        ClasesAgregadas=DescargarClases();
        SilabosDescargados=DescargarListaSilabos();
        Sedes.clear();
        for(int i=0;i<ClasesAgregadas.size();i++)
        {
            Sedes.append(ClasesAgregadas[i].Sede);
        }
        QSet<QString> temp = QSet<QString>::fromList(Sedes);
        Sedes = temp.toList();
        ui->Ecb_sede->clear();
        ui->Ecb_facultad->clear();
        ui->Ecb_carrera->clear();
        ui->Ecb_clases->clear();
        ui->Ecb_sede->addItem("...");
        ui->Ecb_sede->addItems(Sedes);
        QGuiApplication::restoreOverrideCursor();
        //DescargarSilabos();
        //QMessageBox::information(this,"Exito!","Conectado a Azure SQL Database");
    }
    else
    {
        QGuiApplication::restoreOverrideCursor();
        QMessageBox::critical(this,"Error en la conexion!","No ha sido posible conectar con el servidor. Intentelo de nuevo.");
    }
    db.close();

}

void cframe::SubirDatos()
{
    //subir Usuarios
    db.open();
    QSqlQuery query(db);
    query.prepare("Delete FROM SilabosUsuarios");
    query.exec();
    actD = listaUsuarios.PrimPtr;
    int row = 0;
    while (actD != nullptr && row < listaUsuarios.size()) {
        Usuario usuario = actD->getDato();
        query.prepare("Insert into SilabosUsuarios (Cuenta, Contrasena, NombreCompleto, tipo) VALUES(:Cuenta,:Contrasena,:Nombre,:Tipo)");
        query.bindValue(":Cuenta", usuario.getCuenta());
        query.bindValue(":Contrasena", usuario.getContraActual());
        query.bindValue(":Nombre", usuario.getNombre());
        query.bindValue(":Tipo", usuario.getTipo());
        query.exec();
        actD = actD->SigPtr;
        ++row;
    }

    //SubirSilabos
    query.prepare("Delete FROM SilabosClases");
    query.exec();
    query.prepare("Delete FROM SilabosArchivos");
    query.exec();
    QString Sede;
    std::vector<Silabos> silabos = arbol->obtenerTodos();
    for(int i=0;i<silabos.size();i++)
    {
        QString facultad = QString::fromStdString(silabos[i].getFacultad());

        if (!facultad.isEmpty() && facultad.at(0) == '-') {
            Sede="UNITEC";
        } else {
            Sede="CEUTEC";
        }
        query.prepare("Insert into SilabosClases (CodigoClase, Carrera, Facultad, Sede, Nombre, InsertadoPor, Estado, Observacion, NumRevisiones, NumRechazado, Visibilidad) VALUES(:Codigo,:Carrera,:Facultad,:Sede,:Nombre,:InsertadoPor,:Estado,:Observacion,:NumRevisiones,:NumRechazado,:Visibilidad)");
        //:Codigo,:Carrera,:Facultad,:Sede,:Nombre,:InsertadoPor,:Estado,:Observacion,:NumRevisiones,:NumRechazado,:Visibilidad
        query.bindValue(":Codigo", QString::fromStdString(silabos[i].getDatosClase()).left(6));
        query.bindValue(":Carrera", QString::fromStdString(silabos[i].getCarreras()));
        query.bindValue(":Facultad", QString::fromStdString(silabos[i].getFacultad()));
        query.bindValue(":Sede", Sede);
        query.bindValue(":Nombre", QString::fromStdString(silabos[i].getDatosClase()));
        query.bindValue(":InsertadoPor", silabos[i].getInsertadoPor());
        query.bindValue(":Estado", QString::fromStdString(silabos[i].getEstado()));
        query.bindValue(":Observacion", QString::fromStdString(silabos[i].getObservacion()));
        query.bindValue(":NumRevisiones", silabos[i].getNumRevisiones());
        query.bindValue(":NumRechazado", silabos[i].getNumRechazados());
        query.bindValue(":Visibilidad", silabos[i].getVisibilidad());
        SubirSilabo(QString::fromStdString(silabos[i].getDatosClase()).left(6), docx2BA(silabos[i].getRutaSilabos()));
        query.exec();
    }
    db.close();
}

void cframe::on_Mbtn_ingresar_clicked(){
    if(ui->Mle_cuenta->text().isEmpty()||ui->Mle_contra->text().isEmpty()||ui->Mle_name->text().isEmpty()||ui->Mcb_tipo->currentText() == "..."){
        QMessageBox::critical(this, "Error", "Porfavor llenar todos los Espacios!");

    }else{
        //Conectar();
        QString contraDeseada= listaUsuarios.login(ui->Mle_cuenta->text(), ui->Mle_name->text(),ui->Mle_contra->text() ,ui->Mcb_tipo->currentIndex());
        if(contraDeseada!="no"){
            //bool listaD<tipo>::verficarContraActualizada(QString cuenta, QString contradeseada, short type)
            if(contraDeseada != "RECHAZADA" && contraDeseada != "" && contraDeseada.startsWith("°") && listaUsuarios.verficarContraActualizada(ui->Mle_cuenta->text(),  contraDeseada, ui->Mcb_tipo->currentIndex())){
                contraDeseada = contraDeseada.mid(1);

                QMessageBox::information(this, "Cambio de contraseña", "Su solicitud de contraseña fue aprobada\n"+contraDeseada);
                Usuario* Temp = new Usuario(ui->Mle_cuenta->text(),ui->Mle_name->text(),contraDeseada,"",ui->Mcb_tipo->currentIndex());
                listaUsuarios.cambioContra(ui->Mle_contra->text(), ui->Mle_cuenta->text(), listaUsuarios);
                listaUsuarios.InsertarFin(*Temp);
                delete Temp;
            }
            if(contraDeseada == "RECHAZADA"){
                QMessageBox::information(this, "Cambio de contraseña", "Su solicitud de contraseña fue "+contraDeseada);
                Usuario* Temp = new Usuario(ui->Mle_cuenta->text(),ui->Mle_name->text(),ui->Mle_contra->text(),"",ui->Mcb_tipo->currentIndex());
                listaUsuarios.cambioContra(ui->Mle_contra->text(), ui->Mle_cuenta->text(), listaUsuarios);
                listaUsuarios.InsertarFin(*Temp);
                delete Temp;
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
                acciones << "..." << "REVISION"<<"USUARIOS";
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

void cframe::on_Acb_acciones_currentIndexChanged(const QString &arg1)
{

    if(arg1=="ENTREGAR"){
        QStringList item;
        ui->Ecb_sede->clear();
        item<<"..."<<"UNITEC"<<"CEUTEC";
        ui->Ecb_sede->addItems(item);
        ui->tabWidget->setCurrentIndex(1);
    }else if(arg1=="REVISION"){
        //añadi de aqui
        QStringList items;
        ui->Rcb_estadoCambiar->clear();
        if(tipo==4 || tipo==5){//jefe o coordinador
            items<<"..."<<"Cargar silabo (Enviar a IEDD)"<<"Rechazar";
            ui->Rcb_estadoCambiar->addItems(items);
        }else if(tipo==6){//en iedd
            items<<"..."<<"Listo para revision 1"<<"Devolver a Academia";
            ui->Rcb_estadoCambiar->addItems(items);
        }else if(tipo==7){//consultor
            items<<"...";
            ui->Rcb_estadoCambiar->addItems(items);

        }
        //hasta aqui
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
        QMessageBox::critical(this, "Error", "Porfavor llenar todos los Espacios!\n");

    }else{
        ui->Elbl_path_archivo->setText(filePath);

    }



}

void cframe::on_Ebtn_fechas_clicked()
{
    QString filePath = cargarArchivo(ui->Ecb_carrera->currentText(),true);
    if (filePath=="...") {
        QMessageBox::critical(this, "Error", "Porfavor llenar todos los Espacios!\n");

    }else{
        ui->Elbl_path_fechas->setText(filePath);

    }


}

void cframe::on_Ebtn_enviar_clicked()
{
    QString facultad = ui->Ecb_facultad->currentText();
    QString carrera = ui->Ecb_carrera->currentText();
    QString datosClase = ui->Ecb_clases->currentText();
    QString path_silabo=ui->Elbl_path_archivo->text();
    QString path_fecha = (ui->Ecb_sede->currentIndex() != 1) ? "" : ui->Elbl_path_fechas->text();

    if(path_silabo=="..." || (ui->Ecb_sede->currentIndex()==2 && path_fecha=="...")){
        QMessageBox::critical(this, "Error", "Porfavor llenar todos los Espacios!");
    }else{
        //    Silabos(string facultad, string carrera, int insertadoPor, string datosClase, QString rutaSilabos, QString rutaFechas, string estado, string observacion, short numRevisiones, short numRechazado, short visibilidad)

        if (ui->Ecb_facultad->currentIndex() == 1) {
            facultad = "-" + facultad;
        }

        Silabos s(facultad.toStdString(),
                  carrera.toStdString(),
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

        // Insertar el Silabos en el árbol
        arbol->insertar(s);
        //volver a inicializar en 0 los indices para que se muestren ...
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

    ui->Rtw_revision->setRowCount(0);
    ui->Rtw_revision->setColumnCount(15);
    QStringList headers;
    headers <<"SEDE"<< "ID" << "Facultad" << "Carrera" << "Insertado Por" << "Datos Clase"
           << "Ruta Silabos" << "Ruta Fechas" << "Estado" << "Observación"
           << "# Revisiones Consultor" << "Número de Rechazados" << "# Revisiones General"
           << "Cambiar Silabo"<<"Cambiar Fechas";
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
            ui->Rtw_revision->setItem(row, 6, new QTableWidgetItem(s.getRutaSilabos()));
            ui->Rtw_revision->setItem(row, 7, new QTableWidgetItem(s.getRutaFechas()));
            ui->Rtw_revision->setItem(row, 8, new QTableWidgetItem(QString::fromStdString(s.getEstado())));
            ui->Rtw_revision->setItem(row, 9, new QTableWidgetItem(QString::fromStdString(s.getObservacion())));
            ui->Rtw_revision->setItem(row, 10, new QTableWidgetItem(QString::number(s.getNumRevisiones())));
            ui->Rtw_revision->setItem(row, 11, new QTableWidgetItem(QString::number(s.getNumRechazados())));
            ui->Rtw_revision->setItem(row, 12, new QTableWidgetItem(QString::number(s.getVisibilidad())));
            ui->Rtw_revision->setItem(row, 13, new QTableWidgetItem("RELOAD SILABO"));
            ui->Rtw_revision->setItem(row, 14, new QTableWidgetItem("RELOAD CUADRO"));

        }

    }
    ui->Rtw_revision->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void cframe::on_Ecb_sede_currentIndexChanged(const QString &arg1)
{
    Facultades.clear();
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
    ui->Ecb_facultad->addItem("...");
    ui->Ecb_facultad->addItems(Facultades);

}

void cframe::on_Ecb_facultad_currentIndexChanged(const QString &arg1)
{
    Carreras.clear();
    for(int i=0;i<ClasesAgregadas.size();i++)
    {
        if(ClasesAgregadas[i].Facultad==arg1 && ClasesAgregadas[i].Sede==ui->Ecb_sede->currentText())
            Carreras.append(ClasesAgregadas[i].Carrera);
    }
    QSet<QString> temp = QSet<QString>::fromList(Carreras);
    Carreras = temp.toList();
    ui->Ecb_carrera->clear();
    ui->Ecb_clases->clear();
    ui->Ecb_carrera->addItem("...");
    ui->Ecb_carrera->addItems(Carreras);
}

void cframe::on_Ecb_carrera_currentIndexChanged(const QString &arg1)
{
    Clases.clear();
    for(int i=0;i<ClasesAgregadas.size();i++)
    {
        if(ClasesAgregadas[i].Carrera==arg1 && ClasesAgregadas[i].Sede==ui->Ecb_sede->currentText() && ClasesAgregadas[i].Facultad==ui->Ecb_facultad->currentText())
            Clases.append(ClasesAgregadas[i].Nombre);
    }
    QSet<QString> temp = QSet<QString>::fromList(Clases);
    Clases = temp.toList();
    ui->Ecb_clases->clear();
    ui->Ecb_clases->addItem("...");
    ui->Ecb_clases->addItems(Clases);
}

void cframe::on_Rbtn_cambiar_clicked()
{

    if(ui->Rle_seleccion->text().isEmpty()||ui->Rle_comentarios->text().isEmpty()||ui->Rle_estadoActual->text().isEmpty() || ui->Rcb_estadoCambiar->currentText() == "..."){
        QMessageBox::critical(this, "Error", "Porfavor llenar todos los Espacios!");
    }else{
        cambiarEstado=true;
        modificarDatosSilabo(id,"QString pathNuevo",false);
        QMessageBox::information(this,"Datos congruetes","Datos han sido actualizados");
        ui->Rle_seleccion->setText("");
        ui->Rle_comentarios->setText("");
        ui->Rle_estadoActual->setText("");
        ui->Rcb_estadoCambiar->setCurrentIndex(0);
    }

}
void cframe::modificarDatosSilabo(int id, QString pathNuevo, bool silabo)
{
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
                    s->setRutaFechas(pathNuevo);
                }
                cambiarPath=false;
                s->setEstado("Prerevision");
                //s->setNumRevisiones(s->getNumRevisiones()+1);
                s->setObservacion("Reloaded");
                s->setVisibilidad(s->getVisibilidad()+1);
                mostrarSilabosFeed(ui->Albl_cuenta->text());

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
                                          "\nHa excedido el número de revisiones.\n¿Desea reiniciar el contador?",
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
        QMessageBox::critical(this, "Error", "Por favor llenar todos los Espacios!");
    }
    else
    {
        QString filePath = QFileDialog::getOpenFileName(this, "Explorador de Archivos DOC", QDir::homePath(), "Document Files (*.doc *.docx)");
        if (!filePath.isEmpty())
        {
            //            QFileInfo fileInfo(filePath);
            //            QString baseName = fileInfo.baseName(); // Obtiene el nombre del archivo sin la extensión

            //            QString expectedName;
            //            if (fechas)
            //            {
            //                expectedName = nombre + "_FECHAS";
            //            }
            //            else
            //            {
            //                expectedName = nombre;
            //            }

            //            // Comparamos el nombre del archivo sin la extensión
            //            if (baseName == expectedName)
            //            {
            return filePath;
            //            }
            //            else
            //            {
            //                QMessageBox::critical(this, "Error", "El nombre del archivo no coincide con el parámetro esperado.");
            //                return "...";
            //            }
        }
    }
}


void cframe::on_Abtn_cambioContra_clicked()
{
    bool ok;
    while (true) {
        QString newPassword = QInputDialog::getText(this, "Nueva Contraseña", "Ingrese la Nueva Contraseña:", QLineEdit::Password, "", &ok);
        if (!ok) {
            return;
        }
        if (newPassword.isEmpty()) {
            QMessageBox::critical(this, "Error", "Por favor ingrese una contraseña válida.");
        } else {
            actD = listaUsuarios.PrimPtr;
            while (actD != nullptr) {
                Usuario usuario = actD->getDato();
                if (usuario.getCuenta() == ui->Albl_cuenta->text()) {
                    QString oldPassword = QInputDialog::getText(this, "Contraseña Anterior", "Ingrese la Contraseña Anterior\npara confirmar su identidad:", QLineEdit::Password, "", &ok);
                    if (!ok) {
                        return;
                    }
                    if (oldPassword != usuario.getContraActual()) {
                        QMessageBox::critical(this, "Error", "Contraseña original incorrecta.");
                        break;
                    }else{
                        usuario.setContraAnterior(newPassword);
                        //    Usuario( QString cuenta, QString nombre,QString contraActual, QString contraAnterior,short tipo)

                        Usuario* Temp = new Usuario(usuario.getCuenta(),usuario.getNombre(),usuario.getContraActual(),newPassword,usuario.getTipo());
                        listaUsuarios.cambioContra(newPassword, ui->Albl_cuenta->text(), listaUsuarios);

                        listaUsuarios.InsertarFin(*Temp);
                        delete Temp;
                        QMessageBox::information(this, "Contraseña ", "Cambio ha sido solicitado");
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
        //QString cuenta, QString nombre,QString contraActual, QString contraAnterior,short tipo
        Usuario* Temp = new Usuario(Query->value(0).toString(),Query->value(3).toString(),Query->value(1).toString(),Query->value(2).toString(),Query->value(4).toInt());
        UsuariosDescargados.append(*Temp);
        listaUsuarios.InsertarFin(*Temp);
        delete Temp;
        CurrentRow++;
    }
    return UsuariosDescargados;
}
void cframe::mostrarUsuarios()
{
    ui->Itw_usuarios->clearContents();
    QStringList headers = { "CUENTA", "NOMBRE", "CONTRASEÑA ACTUAL", "CONTRASEÑA SOLICITADA", "TIPO" };
    ui->Itw_usuarios->setColumnCount(headers.size());
    ui->Itw_usuarios->setHorizontalHeaderLabels(headers);
    ui->Itw_usuarios->setRowCount(listaUsuarios.Cantidad);

    actD = listaUsuarios.PrimPtr;
    int row = 0;

    while (actD != nullptr && row < listaUsuarios.Cantidad) {
        Usuario usuario = actD->getDato();

        ui->Itw_usuarios->setItem(row, 0, new QTableWidgetItem(usuario.getCuenta()));
        ui->Itw_usuarios->setItem(row, 1, new QTableWidgetItem(usuario.getNombre()));
        ui->Itw_usuarios->setItem(row, 2, new QTableWidgetItem(usuario.getContraActual()));
        ui->Itw_usuarios->setItem(row, 3, new QTableWidgetItem(usuario.getContraAnterior()));
        ui->Itw_usuarios->setItem(row, 4, new QTableWidgetItem(listaUsuarios.tipoUsuario(usuario.getTipo())));

        actD = actD->SigPtr;
        ++row;
    }
    ui->Itw_usuarios->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}
void cframe::on_pushButton_clicked()
{
    if(ui->Ile_contra->text().isEmpty() || ui->Ile_cuenta->text().isEmpty()|| ui->Ile_name->text().isEmpty() || ui->Icb_tipo->currentIndex()==0){
        QMessageBox::critical(this, "Error", "Porfavor llenar todos los Espacios!");

    }else{

        if(  cuentaNumero( ui->Ile_cuenta->text().toStdString())  && listaUsuarios.numCuentaDisponible(ui->Ile_cuenta->text())){
            Usuario* Temp = new Usuario(ui->Ile_cuenta->text(),ui->Ile_name->text(),ui->Ile_contra->text(),"",ui->Icb_tipo->currentIndex());
            listaUsuarios.InsertarFin(*Temp);
            delete Temp;
            mostrarUsuarios();
        }else{
            QMessageBox::critical(this, "Error", "Numero de cuenta no disponible");

        }
    }
}

bool cframe::cuentaNumero(const std::string &tt)
{
    for (char car : tt) {
        if (!std::isdigit(car)) {
            QMessageBox::warning(this,  "Datos incongruentes","Favor, asegurese de que el numero de cuenta solo contenga digitos");
            return false;
        }
    }
    if(ui->Ile_cuenta->text().length() !=8){
        QMessageBox::warning(this,  "Datos incongruentes","Favor, asegurese de que la cuenta sea de 8 digitos");
        return false;
    }
    return true;
}


void cframe::on_Itw_usuarios_cellClicked(int row, int column)
{
    if (column == 3) { // Columna 3 es la columna de "CONTRASEÑA ANTERIOR"
        QTableWidgetItem *item = ui->Itw_usuarios->item(row, 0); // Obtener el item de la columna 0 (CUENTA)
        QString contraDeseada= ui->Itw_usuarios->item(row, 3)->text();

        if (item && (contraDeseada != "RECHAZADA" && !contraDeseada.isEmpty())) {
            QString cuenta = item->text();
            QString nombre= ui->Itw_usuarios->item(row, 1)->text();
            QString contraActual= ui->Itw_usuarios->item(row, 2)->text();
            int tipo= listaUsuarios.numeroTipoUsuario(ui->Itw_usuarios->item(row, 4)->text());

            // Mostrar un mensaje de confirmación
            QMessageBox::StandardButton reply;
            reply = QMessageBox::question(this, "Confirmación",
                                          "Contraseña propuesta:"+contraDeseada+"\n¿Estás seguro que desea cambiar contraseña de " + cuenta + "?",
                                          QMessageBox::Yes | QMessageBox::No);
            if (reply == QMessageBox::Yes) {
                Usuario* Temp = new Usuario(cuenta,nombre,contraActual,contraDeseada="°"+contraDeseada,tipo);
                listaUsuarios.cambioContra(contraActual, ui->Albl_cuenta->text(), listaUsuarios);
                listaUsuarios.InsertarFin(*Temp);
                mostrarUsuarios();
                delete Temp;


            } else {
                Usuario* Temp = new Usuario(cuenta,nombre,contraActual,"RECHAZADA",tipo);
                listaUsuarios.cambioContra(contraActual, ui->Albl_cuenta->text(), listaUsuarios);
                listaUsuarios.InsertarFin(*Temp);
                mostrarUsuarios();
                delete Temp;


            }
        } else {
        }
    }
}




void cframe::mostrarSilabosBoard(bool aprobado)
{
    std::vector<Silabos> silabos = arbol->obtenerTodos();
    ui->Btw_dashboard->clear();
    ui->Btw_dashboard->setRowCount(0);
    ui->Btw_dashboard->setColumnCount(13);
    bool mostrar=false;
    QStringList headers;
    headers << "SEDE" << "ID" << "Facultad" << "Carrera" << "Insertado Por" << "Datos Clase"
            << "Ruta Silabos" << "Ruta Fechas" << "Estado" << "Observación"
            << "# revisiones consultor" << "# veces Rechazado" << "# Revisiones general";
    ui->Btw_dashboard->setHorizontalHeaderLabels(headers);

    for (const Silabos& s : silabos) {

        if (aprobado && s.getEstado() == "Aprobar"){
            mostrar=true;
        }else if(s.getEstado() != "Aprobar"){
            mostrar =true;
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
            ui->Btw_dashboard->setItem(row, 6, new QTableWidgetItem(s.getRutaSilabos()));
            ui->Btw_dashboard->setItem(row, 7, new QTableWidgetItem(s.getRutaFechas()));
            ui->Btw_dashboard->setItem(row, 8, new QTableWidgetItem(QString::fromStdString(s.getEstado())));
            ui->Btw_dashboard->setItem(row, 9, new QTableWidgetItem(QString::fromStdString(s.getObservacion())));
            ui->Btw_dashboard->setItem(row, 10, new QTableWidgetItem(QString::number(s.getNumRevisiones())));
            ui->Btw_dashboard->setItem(row, 11, new QTableWidgetItem(QString::number(s.getNumRechazados())));
            ui->Btw_dashboard->setItem(row, 12, new QTableWidgetItem(QString::number(s.getVisibilidad())));
        }
        mostrar=false;
    }

    ui->Btw_dashboard->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}


void cframe::mostrarSilabosFeed(QString cuenta)
{
    //            ui->DRTW_revision->setHorizontalHeaderLabels(QStringList() <<"VER DOCX"<<"ORDEN DE INGRESO"<<"INGRESADO POR"<<"# CUENTA"<<"FACULTAD"<<"CARRERA"<<"CODIGO CLASE"<<"OBSERVACION"<<"PATH"<<"RELOAD");

    std::vector<Silabos> silabos = arbol->obtenerTodos();

    ui->Ftw_feed->setRowCount(0);
    ui->Ftw_feed->setColumnCount(15);
    QStringList headers;
    headers <<"SEDE"<< "ID" << "Facultad" << "Carrera" << "Insertado Por" << "Datos Clase"
           << "Ruta Silabos" << "Ruta Fechas" << "Estado" << "Observación"
           << "# revisiones consultor" << "# veces Rechazado" << "# Revisiones general"
           << "Cambiar Silabo"<<"Cambiar Fechas";
    ui->Ftw_feed->setHorizontalHeaderLabels(headers);

    for (const Silabos& s : silabos) {
        if(s.getInsertadoPor()==cuenta.toInt() ) {
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
            ui->Ftw_feed->setItem(row, 6, new QTableWidgetItem(s.getRutaSilabos()));
            ui->Ftw_feed->setItem(row, 7, new QTableWidgetItem(s.getRutaFechas()));
            ui->Ftw_feed->setItem(row, 8, new QTableWidgetItem(QString::fromStdString(s.getEstado())));
            ui->Ftw_feed->setItem(row, 9, new QTableWidgetItem(QString::fromStdString(s.getObservacion())));
            ui->Ftw_feed->setItem(row, 10, new QTableWidgetItem(QString::number(s.getNumRevisiones())));
            ui->Ftw_feed->setItem(row, 11, new QTableWidgetItem(QString::number(s.getNumRechazados())));
            ui->Ftw_feed->setItem(row, 12, new QTableWidgetItem(QString::number(s.getVisibilidad())));
            ui->Ftw_feed->setItem(row, 13, new QTableWidgetItem("RELOAD SILABO"));
            ui->Ftw_feed->setItem(row, 14, new QTableWidgetItem("RELOAD CUADRO"));

        }

    }
    ui->Btw_dashboard->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);


}

void cframe::on_Brb_proceso_clicked()
{
    mostrarSilabosBoard(false);

}

void cframe::on_Brb_aprobados_clicked()
{
    mostrarSilabosBoard(true);
}

void cframe::on_Rtw_revision_cellClicked(int row, int column)
{
    // Obtener el ID del Silabo desde la primera columna de la fila seleccionada
    id = ui->Rtw_revision->item(row, 1)->text().toInt();

    // Buscar el Silabo por ID en el árbol
    Silabos* s = arbol->buscar(id);

    if (s != nullptr) {
        ui->Rle_seleccion->setText(ui->Rtw_revision->item(row, column)->text());
        ui->Rle_estadoActual->setText(QString::fromStdString(s->getEstado()));
        if(tipo ==7 && column!=14 && column !=13){
            QStringList items;
            ui->Rcb_estadoCambiar->clear();
            if( ui->Rtw_revision->item(row, 8)->text().toStdString()=="Aprobado"){
                items<<"..."<<"Aprobar"<<"Aprobado con condicion";

            }else{
                items<<"..."<<"Aprobado"<<"Correcion Mayor"<<"Correcion Menor";
            }
            ui->Rcb_estadoCambiar->addItems(items);
        }else if(column ==6 || column==7){
                QString Ruta = ui->Ftw_feed->item(row, column)->text();
                //QMessageBox::warning(this, "No posible", Ruta);
                QDesktopServices::openUrl(QUrl::fromLocalFile(Ruta));
        }else if(column==13 ){

            cambiarSilabo( id, ui->Rtw_revision->item(row, 6)->text(),13);
        }else if(column==14){
            cambiarSilabo( id, ui->Rtw_revision->item(row, 7)->text(),14);

        }else{



        }


    }

}
void cframe::cambiarSilabo(int id, QString pathActual, short i)
{
    QString filePath = QFileDialog::getOpenFileName(this, "Explorador de Archivos DOC", QDir::homePath(), "Document Files (*.doc *.docx)");
    if (pathActual==filePath) {
        QMessageBox::warning(this, "No posible", "Ha seleccionado el mismo silabo");
    }else if(!filePath.isEmpty()){
        cambiarPath=true;
        if(i==13){
            modificarDatosSilabo(id,filePath, true);
        }else{

            modificarDatosSilabo(id,filePath, false);

        }
    }else{
        QMessageBox::warning(this, "No posible", "No ha seleccionado");
    }
}


void cframe::on_Ftw_feed_cellClicked(int row, int column)
{
    id = ui->Ftw_feed->item(row, 1)->text().toInt();
    if(column==6 || column==7)
    {
        QString Ruta = ui->Ftw_feed->item(row, column)->text();
        //QMessageBox::warning(this, "No posible", Ruta);
        QDesktopServices::openUrl(QUrl::fromLocalFile(Ruta));
    }else if(column==13 || column==14){
        cambiarPath=true;
        if(column==13 ){

                    cambiarSilabo( id, ui->Ftw_feed->item(row, 6)->text(),13);
                }else if(column==14){
                    cambiarSilabo( id, ui->Ftw_feed->item(row, 7)->text(),14);

                }
    }
}


void cframe::on_Btw_dashboard_cellClicked(int row, int column)
{
    if(column==6 || column==7)
      {
          QString Ruta = ui->Ftw_feed->item(row, column)->text();
          //QMessageBox::warning(this, "No posible", Ruta);
          QDesktopServices::openUrl(QUrl::fromLocalFile(Ruta));
      }
}


void cframe::on_Ftw_feed_cellActivated(int row, int column)
{

}

