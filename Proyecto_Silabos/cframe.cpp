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
    QMessageBox::StandardButton reply;
    reply = QMessageBox::information(this, "Bienvenido", "Cargar base de datos para iniciar.\nEsto puede tardar unos segundos.", QMessageBox::Ok);
    if (reply == QMessageBox::Ok) {
        Conectar();
    }else{

    }

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
    Query->prepare("select * from SilabosClases");
    Query->exec();
    int CurrentRow=0;
    while(Query->next())
    {
        //Codigo-Nombre-Carrera-Facultad-Sede
        Clase* Temp = new Clase(Query->value(0).toString(),Query->value(4).toString(),Query->value(1).toString(),Query->value(2).toString(),Query->value(3).toString());
        ClasesDescargadas.append(*Temp);
        delete Temp;
        CurrentRow++;
    }
    return ClasesDescargadas;
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
        QMessageBox::critical(this, "Error", "No se pudo abrir el archivo");
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
        QMessageBox::critical(this, "Error", "No se pudo abrir el archivo");
        return;
    }
    newFile.write(ByteArray);
    newFile.close();

}

void cframe::SubirSilabo(QString CodigoSilabo, QByteArray Archivo)
{
    QGuiApplication::setOverrideCursor(Qt::WaitCursor);
    db.open();
    QSqlQuery query(db);
    query.prepare("INSERT INTO SilabosArchivos(Codigo,Archivo) VALUES(:Codigo,:docxData)");
    query.bindValue(":Codigo", CodigoSilabo);
    query.bindValue(":docxData", Archivo);
    if (!query.exec())
    {
        QMessageBox::critical(this, "Error", "Error en la base de datos. Error: " + query.lastError().text());
    }
    db.close();
    QGuiApplication::restoreOverrideCursor();
}

QByteArray cframe::DescargarSilabo(QString Codigo)
{
    QGuiApplication::setOverrideCursor(Qt::WaitCursor);
    db.open();
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
        QMessageBox::critical(this, "Error", "No existe un archivo con el codigo seleccionado");
    }
    db.close();
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
        QMessageBox::information(this,"Exito!","Conectado a Azure SQL Database");
    }
    else
    {
        QGuiApplication::restoreOverrideCursor();
        QMessageBox::critical(this,"Error en la conexion!","No ha sido posible conectar con el servidor. Intentelo de nuevo.");
    }
    db.close();

}

void cframe::on_Mbtn_ingresar_clicked(){
    if(ui->Mle_cuenta->text().isEmpty()||ui->Mle_contra->text().isEmpty()||ui->Mle_name->text().isEmpty()||ui->Mcb_tipo->currentText() == "..."){
        QMessageBox::critical(this, "Error", "Porfavor llenar todos los Espacios!");

    }else{
        //Conectar();

        if(listaUsuarios.login(ui->Mle_cuenta->text(), ui->Mle_name->text(),ui->Mle_contra->text() ,ui->Mcb_tipo->currentIndex())){

            ui->Albl_cuenta->setText(ui->Mle_cuenta->text());
            ui->Albl_tipo->setText(ui->Mcb_tipo->currentText());
            ui->Albl_username->setText(ui->Mle_name->text());

            if(ui->Mcb_tipo->currentIndex()==7){
                QStringList acciones;
                acciones << "..." << "FEED" << "ENTREGAR";
                ui->Acb_acciones->addItems(acciones);

            }else if(ui->Mcb_tipo->currentIndex()==2||ui->Mcb_tipo->currentIndex()==3){
                QStringList acciones;
                acciones << "..." << "BOARD";
                ui->Acb_acciones->addItems(acciones);
            }else if(ui->Mcb_tipo->currentIndex()==6 || ui->Mcb_tipo->currentIndex()==1){
                QStringList acciones;
                acciones << "..." << "REVISION"<<"USUARIOS";
                ui->Acb_acciones->addItems(acciones);
            }else if(ui->Mcb_tipo->currentIndex()==4||ui->Mcb_tipo->currentIndex()==5||ui->Mcb_tipo->currentIndex()==7){
                QStringList acciones;
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
        ui->tabWidget->setCurrentIndex(1);
    }else if(arg1=="REVISION"){
        ui->tabWidget->setCurrentIndex(2);
    }else if(arg1=="BOARD"){
        ui->tabWidget->setCurrentIndex(3);
    }else if(arg1=="FEED"){
        ui->tabWidget->setCurrentIndex(4);
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
            // password = newPassword;

            listaUsuarios.cambioContra(newPassword, numero_cuenta, listaUsuarios);
            QMessageBox::information(this, "Enviado", "Su solicitud fue enviada.\n");
            return;
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
    QStringList headers = { "CUENTA", "NOMBRE", "CONTRASEÑA ACTUAL", "CONTRASEÑA ANTERIOR", "TIPO" };
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
        cuentaNumero( ui->Ile_cuenta->text().toStdString());
        if(listaUsuarios.numCuentaDisponible(ui->Ile_cuenta->text())){
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
    if(column==3){
        QTableWidgetItem *item = ui->Itw_usuarios->item(row, 0);
        if (item) {
            QString dato = item->text();
            QMessageBox::information(this, "Dato en columna 0", "El dato en la columna 0 de esta fila es: " + dato);
        } else {
            QMessageBox::warning(this, "Error", "No se pudo obtener el dato en la columna 0.");
        }
    }
}

