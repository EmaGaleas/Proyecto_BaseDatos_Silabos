/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_3;
    QLabel *lbl_pngMenu;
    QPushButton *btn_entregarM;
    QPushButton *btn_revision;
    QPushButton *btn_dashboardM;
    QLabel *lbl_b2M;
    QLabel *lbl_b1M;
    QWidget *tab_2;
    QGridLayout *gridLayout_4;
    QLabel *lbl_pngE;
    QFrame *frameE2;
    QGridLayout *gridLayout_7;
    QPushButton *btn_sesion;
    QLabel *lbl_nameE;
    QLineEdit *le_nameE;
    QLabel *lbl_cuentaE;
    QLineEdit *le_claveE;
    QLabel *lbl_contraE;
    QLineEdit *le_cuentaE;
    QFrame *frameE;
    QGridLayout *gridLayout_8;
    QComboBox *cb_carreraE;
    QPushButton *btn_closeE;
    QLineEdit *le_codigoE;
    QLabel *lbl_facultadE;
    QComboBox *cb_facultadE;
    QLabel *lbl_codigoE;
    QPushButton *btn_archivoE;
    QLabel *lbl_carreraE;
    QLineEdit *le_pathE;
    QLabel *lbl_codigoE_2;
    QPushButton *btn_silaboE;
    QWidget *tab_3;
    QGridLayout *gridLayout_5;
    QFrame *frameR1;
    QGridLayout *gridLayout_9;
    QLineEdit *Rle_clave;
    QComboBox *Rcb_usuario;
    QLineEdit *Rle_name;
    QPushButton *Rbtn_sesion;
    QLabel *Rlbl_contra;
    QLabel *Rlbl_usuario;
    QLabel *Rlbl_name;
    QLabel *lbl_pngR;
    QFrame *frameR;
    QGridLayout *gridLayout_10;
    QFrame *Rframe1;
    QGridLayout *gridLayout_12;
    QTableWidget *RTW_revision;
    QFrame *frame_2;
    QGridLayout *gridLayout_11;
    QLabel *Rlbl_seleccion;
    QLineEdit *Rle_seleccion;
    QLabel *Rlbl_estadoA;
    QLineEdit *Rle_estadoA;
    QLabel *Rlbl_name_4;
    QComboBox *Rcb_cambiarE;
    QLabel *Rlbl_comentario;
    QLineEdit *Rle_comentario;
    QPushButton *Rbtn_cambiar;
    QPushButton *Rbtn_cerrar;
    QWidget *tab_4;
    QGridLayout *gridLayout_6;
    QLabel *lbl_pngD;
    QFrame *frameB1;
    QGridLayout *gridLayout_13;
    QFrame *frameBB1;
    QGridLayout *gridLayout_14;
    QLabel *Blbl_name;
    QLineEdit *Ble_name;
    QLabel *Blbl_usuario;
    QComboBox *Bcb_usuario;
    QLabel *Blbl_contra;
    QLineEdit *Ble_clave;
    QPushButton *Bbtn_sesion;
    QFrame *frameB;
    QGridLayout *gridLayout_15;
    QRadioButton *Bbtn_aceptados;
    QRadioButton *Bbtn_proceso;
    QPushButton *Bbtn_cerrar;
    QTableWidget *tableWidget;
    QWidget *tab_5;
    QGridLayout *gridLayout_18;
    QLabel *Dlbl_png;
    QFrame *Dframe1;
    QGridLayout *gridLayout_16;
    QLineEdit *Dle_cuenta;
    QLabel *Dlbl_contraE;
    QLineEdit *Dle_clave;
    QLabel *Dlbl_cuenta;
    QPushButton *Dbtn_sesion;
    QLineEdit *Dle_name;
    QLabel *Dlbl_name;
    QPushButton *Dbtn_salir;
    QFrame *Dframe2;
    QGridLayout *gridLayout_17;
    QTableWidget *DRTW_revision;
    QLabel *Dlabel2;
    QLabel *Dlabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(910, 715);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        QPalette palette;
        QBrush brush(QColor(203, 232, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        scrollArea->setPalette(palette);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 886, 641));
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        tabWidget = new QTabWidget(scrollAreaWidgetContents);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Button, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush);
        tabWidget->setPalette(palette1);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout_3 = new QGridLayout(tab);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        lbl_pngMenu = new QLabel(tab);
        lbl_pngMenu->setObjectName(QString::fromUtf8("lbl_pngMenu"));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::Button, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush);
        lbl_pngMenu->setPalette(palette2);
        lbl_pngMenu->setScaledContents(true);

        gridLayout_3->addWidget(lbl_pngMenu, 0, 1, 1, 2);

        btn_entregarM = new QPushButton(tab);
        btn_entregarM->setObjectName(QString::fromUtf8("btn_entregarM"));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::Button, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush);
        btn_entregarM->setPalette(palette3);
        QFont font;
        font.setFamily(QString::fromUtf8("Cambria"));
        font.setPointSize(14);
        font.setBold(false);
        font.setWeight(50);
        btn_entregarM->setFont(font);

        gridLayout_3->addWidget(btn_entregarM, 1, 0, 1, 1);

        btn_revision = new QPushButton(tab);
        btn_revision->setObjectName(QString::fromUtf8("btn_revision"));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::Button, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush);
        btn_revision->setPalette(palette4);
        btn_revision->setFont(font);

        gridLayout_3->addWidget(btn_revision, 1, 1, 1, 2);

        btn_dashboardM = new QPushButton(tab);
        btn_dashboardM->setObjectName(QString::fromUtf8("btn_dashboardM"));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::Button, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush);
        btn_dashboardM->setPalette(palette5);
        btn_dashboardM->setFont(font);

        gridLayout_3->addWidget(btn_dashboardM, 1, 3, 1, 1);

        lbl_b2M = new QLabel(tab);
        lbl_b2M->setObjectName(QString::fromUtf8("lbl_b2M"));
        lbl_b2M->setScaledContents(false);

        gridLayout_3->addWidget(lbl_b2M, 0, 3, 1, 1);

        lbl_b1M = new QLabel(tab);
        lbl_b1M->setObjectName(QString::fromUtf8("lbl_b1M"));
        QPalette palette6;
        QBrush brush1(QColor(0, 0, 127, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette6.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        QBrush brush2(QColor(240, 240, 240, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette6.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        lbl_b1M->setPalette(palette6);
        lbl_b1M->setScaledContents(false);

        gridLayout_3->addWidget(lbl_b1M, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout_4 = new QGridLayout(tab_2);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        lbl_pngE = new QLabel(tab_2);
        lbl_pngE->setObjectName(QString::fromUtf8("lbl_pngE"));
        lbl_pngE->setScaledContents(true);

        gridLayout_4->addWidget(lbl_pngE, 0, 0, 1, 1);

        frameE2 = new QFrame(tab_2);
        frameE2->setObjectName(QString::fromUtf8("frameE2"));
        frameE2->setFrameShape(QFrame::StyledPanel);
        frameE2->setFrameShadow(QFrame::Raised);
        gridLayout_7 = new QGridLayout(frameE2);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        btn_sesion = new QPushButton(frameE2);
        btn_sesion->setObjectName(QString::fromUtf8("btn_sesion"));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::Button, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::Button, brush);
        btn_sesion->setPalette(palette7);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Sans Serif Collection"));
        font1.setPointSize(11);
        font1.setBold(false);
        font1.setWeight(50);
        btn_sesion->setFont(font1);

        gridLayout_7->addWidget(btn_sesion, 3, 1, 1, 1);

        lbl_nameE = new QLabel(frameE2);
        lbl_nameE->setObjectName(QString::fromUtf8("lbl_nameE"));
        QFont font2;
        font2.setPointSize(12);
        lbl_nameE->setFont(font2);

        gridLayout_7->addWidget(lbl_nameE, 0, 0, 1, 1);

        le_nameE = new QLineEdit(frameE2);
        le_nameE->setObjectName(QString::fromUtf8("le_nameE"));
        QFont font3;
        font3.setPointSize(11);
        le_nameE->setFont(font3);

        gridLayout_7->addWidget(le_nameE, 0, 1, 1, 1);

        lbl_cuentaE = new QLabel(frameE2);
        lbl_cuentaE->setObjectName(QString::fromUtf8("lbl_cuentaE"));
        lbl_cuentaE->setFont(font2);

        gridLayout_7->addWidget(lbl_cuentaE, 1, 0, 1, 1);

        le_claveE = new QLineEdit(frameE2);
        le_claveE->setObjectName(QString::fromUtf8("le_claveE"));
        le_claveE->setFont(font3);

        gridLayout_7->addWidget(le_claveE, 2, 1, 1, 1);

        lbl_contraE = new QLabel(frameE2);
        lbl_contraE->setObjectName(QString::fromUtf8("lbl_contraE"));
        lbl_contraE->setFont(font2);

        gridLayout_7->addWidget(lbl_contraE, 2, 0, 1, 1);

        le_cuentaE = new QLineEdit(frameE2);
        le_cuentaE->setObjectName(QString::fromUtf8("le_cuentaE"));
        le_cuentaE->setFont(font3);

        gridLayout_7->addWidget(le_cuentaE, 1, 1, 1, 1);


        gridLayout_4->addWidget(frameE2, 1, 0, 1, 1);

        frameE = new QFrame(tab_2);
        frameE->setObjectName(QString::fromUtf8("frameE"));
        frameE->setEnabled(true);
        frameE->setFrameShape(QFrame::StyledPanel);
        frameE->setFrameShadow(QFrame::Raised);
        gridLayout_8 = new QGridLayout(frameE);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        cb_carreraE = new QComboBox(frameE);
        cb_carreraE->addItem(QString());
        cb_carreraE->setObjectName(QString::fromUtf8("cb_carreraE"));
        cb_carreraE->setFont(font3);

        gridLayout_8->addWidget(cb_carreraE, 1, 2, 1, 1);

        btn_closeE = new QPushButton(frameE);
        btn_closeE->setObjectName(QString::fromUtf8("btn_closeE"));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Sans Serif Collection"));
        font4.setPointSize(7);
        btn_closeE->setFont(font4);

        gridLayout_8->addWidget(btn_closeE, 2, 3, 1, 1);

        le_codigoE = new QLineEdit(frameE);
        le_codigoE->setObjectName(QString::fromUtf8("le_codigoE"));
        le_codigoE->setFont(font3);

        gridLayout_8->addWidget(le_codigoE, 2, 2, 1, 1);

        lbl_facultadE = new QLabel(frameE);
        lbl_facultadE->setObjectName(QString::fromUtf8("lbl_facultadE"));
        lbl_facultadE->setFont(font2);

        gridLayout_8->addWidget(lbl_facultadE, 0, 0, 1, 1);

        cb_facultadE = new QComboBox(frameE);
        cb_facultadE->addItem(QString());
        cb_facultadE->addItem(QString());
        cb_facultadE->addItem(QString());
        cb_facultadE->addItem(QString());
        cb_facultadE->setObjectName(QString::fromUtf8("cb_facultadE"));
        cb_facultadE->setFont(font3);

        gridLayout_8->addWidget(cb_facultadE, 0, 2, 1, 1);

        lbl_codigoE = new QLabel(frameE);
        lbl_codigoE->setObjectName(QString::fromUtf8("lbl_codigoE"));
        lbl_codigoE->setFont(font2);

        gridLayout_8->addWidget(lbl_codigoE, 2, 0, 1, 1);

        btn_archivoE = new QPushButton(frameE);
        btn_archivoE->setObjectName(QString::fromUtf8("btn_archivoE"));

        gridLayout_8->addWidget(btn_archivoE, 4, 2, 1, 1);

        lbl_carreraE = new QLabel(frameE);
        lbl_carreraE->setObjectName(QString::fromUtf8("lbl_carreraE"));
        lbl_carreraE->setFont(font2);

        gridLayout_8->addWidget(lbl_carreraE, 1, 0, 1, 1);

        le_pathE = new QLineEdit(frameE);
        le_pathE->setObjectName(QString::fromUtf8("le_pathE"));
        le_pathE->setEnabled(false);

        gridLayout_8->addWidget(le_pathE, 6, 2, 1, 1);

        lbl_codigoE_2 = new QLabel(frameE);
        lbl_codigoE_2->setObjectName(QString::fromUtf8("lbl_codigoE_2"));
        lbl_codigoE_2->setFont(font2);

        gridLayout_8->addWidget(lbl_codigoE_2, 4, 0, 1, 1);

        btn_silaboE = new QPushButton(frameE);
        btn_silaboE->setObjectName(QString::fromUtf8("btn_silaboE"));
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::Button, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette8.setBrush(QPalette::Disabled, QPalette::Button, brush);
        btn_silaboE->setPalette(palette8);
        btn_silaboE->setFont(font1);

        gridLayout_8->addWidget(btn_silaboE, 6, 3, 1, 1);


        gridLayout_4->addWidget(frameE, 2, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        gridLayout_5 = new QGridLayout(tab_3);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        frameR1 = new QFrame(tab_3);
        frameR1->setObjectName(QString::fromUtf8("frameR1"));
        frameR1->setFrameShape(QFrame::StyledPanel);
        frameR1->setFrameShadow(QFrame::Raised);
        gridLayout_9 = new QGridLayout(frameR1);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        Rle_clave = new QLineEdit(frameR1);
        Rle_clave->setObjectName(QString::fromUtf8("Rle_clave"));
        Rle_clave->setFont(font3);

        gridLayout_9->addWidget(Rle_clave, 2, 1, 1, 1);

        Rcb_usuario = new QComboBox(frameR1);
        Rcb_usuario->addItem(QString());
        Rcb_usuario->addItem(QString());
        Rcb_usuario->addItem(QString());
        Rcb_usuario->addItem(QString());
        Rcb_usuario->addItem(QString());
        Rcb_usuario->setObjectName(QString::fromUtf8("Rcb_usuario"));
        Rcb_usuario->setFont(font3);

        gridLayout_9->addWidget(Rcb_usuario, 1, 1, 1, 1);

        Rle_name = new QLineEdit(frameR1);
        Rle_name->setObjectName(QString::fromUtf8("Rle_name"));
        Rle_name->setFont(font3);

        gridLayout_9->addWidget(Rle_name, 0, 1, 1, 1);

        Rbtn_sesion = new QPushButton(frameR1);
        Rbtn_sesion->setObjectName(QString::fromUtf8("Rbtn_sesion"));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Sans Serif Collection"));
        font5.setPointSize(11);
        Rbtn_sesion->setFont(font5);

        gridLayout_9->addWidget(Rbtn_sesion, 3, 1, 1, 1);

        Rlbl_contra = new QLabel(frameR1);
        Rlbl_contra->setObjectName(QString::fromUtf8("Rlbl_contra"));
        Rlbl_contra->setFont(font2);

        gridLayout_9->addWidget(Rlbl_contra, 2, 0, 1, 1);

        Rlbl_usuario = new QLabel(frameR1);
        Rlbl_usuario->setObjectName(QString::fromUtf8("Rlbl_usuario"));
        Rlbl_usuario->setFont(font2);

        gridLayout_9->addWidget(Rlbl_usuario, 1, 0, 1, 1);

        Rlbl_name = new QLabel(frameR1);
        Rlbl_name->setObjectName(QString::fromUtf8("Rlbl_name"));
        Rlbl_name->setFont(font2);

        gridLayout_9->addWidget(Rlbl_name, 0, 0, 1, 1);

        Rbtn_sesion->raise();
        Rle_clave->raise();
        Rcb_usuario->raise();
        Rlbl_name->raise();
        Rle_name->raise();
        Rlbl_contra->raise();
        Rlbl_usuario->raise();

        gridLayout_5->addWidget(frameR1, 1, 0, 1, 1);

        lbl_pngR = new QLabel(tab_3);
        lbl_pngR->setObjectName(QString::fromUtf8("lbl_pngR"));
        lbl_pngR->setScaledContents(true);

        gridLayout_5->addWidget(lbl_pngR, 0, 0, 1, 1);

        frameR = new QFrame(tab_3);
        frameR->setObjectName(QString::fromUtf8("frameR"));
        frameR->setFrameShape(QFrame::StyledPanel);
        frameR->setFrameShadow(QFrame::Raised);
        gridLayout_10 = new QGridLayout(frameR);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        Rframe1 = new QFrame(frameR);
        Rframe1->setObjectName(QString::fromUtf8("Rframe1"));
        Rframe1->setFrameShape(QFrame::StyledPanel);
        Rframe1->setFrameShadow(QFrame::Raised);
        gridLayout_12 = new QGridLayout(Rframe1);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        RTW_revision = new QTableWidget(Rframe1);
        RTW_revision->setObjectName(QString::fromUtf8("RTW_revision"));

        gridLayout_12->addWidget(RTW_revision, 0, 0, 1, 1);


        gridLayout_10->addWidget(Rframe1, 0, 0, 1, 1);

        frame_2 = new QFrame(frameR);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_11 = new QGridLayout(frame_2);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        Rlbl_seleccion = new QLabel(frame_2);
        Rlbl_seleccion->setObjectName(QString::fromUtf8("Rlbl_seleccion"));
        Rlbl_seleccion->setFont(font2);

        gridLayout_11->addWidget(Rlbl_seleccion, 0, 0, 1, 1);

        Rle_seleccion = new QLineEdit(frame_2);
        Rle_seleccion->setObjectName(QString::fromUtf8("Rle_seleccion"));
        Rle_seleccion->setEnabled(false);

        gridLayout_11->addWidget(Rle_seleccion, 0, 1, 1, 1);

        Rlbl_estadoA = new QLabel(frame_2);
        Rlbl_estadoA->setObjectName(QString::fromUtf8("Rlbl_estadoA"));
        Rlbl_estadoA->setFont(font2);

        gridLayout_11->addWidget(Rlbl_estadoA, 1, 0, 1, 1);

        Rle_estadoA = new QLineEdit(frame_2);
        Rle_estadoA->setObjectName(QString::fromUtf8("Rle_estadoA"));
        Rle_estadoA->setEnabled(false);

        gridLayout_11->addWidget(Rle_estadoA, 1, 1, 1, 1);

        Rlbl_name_4 = new QLabel(frame_2);
        Rlbl_name_4->setObjectName(QString::fromUtf8("Rlbl_name_4"));
        Rlbl_name_4->setFont(font2);

        gridLayout_11->addWidget(Rlbl_name_4, 2, 0, 1, 1);

        Rcb_cambiarE = new QComboBox(frame_2);
        Rcb_cambiarE->addItem(QString());
        Rcb_cambiarE->setObjectName(QString::fromUtf8("Rcb_cambiarE"));
        Rcb_cambiarE->setFont(font3);

        gridLayout_11->addWidget(Rcb_cambiarE, 2, 1, 1, 1);

        Rlbl_comentario = new QLabel(frame_2);
        Rlbl_comentario->setObjectName(QString::fromUtf8("Rlbl_comentario"));
        Rlbl_comentario->setFont(font2);

        gridLayout_11->addWidget(Rlbl_comentario, 3, 0, 1, 1);

        Rle_comentario = new QLineEdit(frame_2);
        Rle_comentario->setObjectName(QString::fromUtf8("Rle_comentario"));
        Rle_comentario->setEnabled(true);

        gridLayout_11->addWidget(Rle_comentario, 3, 1, 1, 1);

        Rbtn_cambiar = new QPushButton(frame_2);
        Rbtn_cambiar->setObjectName(QString::fromUtf8("Rbtn_cambiar"));
        Rbtn_cambiar->setFont(font5);

        gridLayout_11->addWidget(Rbtn_cambiar, 4, 1, 1, 1);

        Rbtn_cerrar = new QPushButton(frame_2);
        Rbtn_cerrar->setObjectName(QString::fromUtf8("Rbtn_cerrar"));

        gridLayout_11->addWidget(Rbtn_cerrar, 5, 1, 1, 1);


        gridLayout_10->addWidget(frame_2, 0, 1, 1, 1);


        gridLayout_5->addWidget(frameR, 2, 0, 1, 1);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        gridLayout_6 = new QGridLayout(tab_4);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        lbl_pngD = new QLabel(tab_4);
        lbl_pngD->setObjectName(QString::fromUtf8("lbl_pngD"));
        lbl_pngD->setScaledContents(true);

        gridLayout_6->addWidget(lbl_pngD, 0, 0, 1, 1);

        frameB1 = new QFrame(tab_4);
        frameB1->setObjectName(QString::fromUtf8("frameB1"));
        frameB1->setFrameShape(QFrame::StyledPanel);
        frameB1->setFrameShadow(QFrame::Raised);
        gridLayout_13 = new QGridLayout(frameB1);
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        frameBB1 = new QFrame(frameB1);
        frameBB1->setObjectName(QString::fromUtf8("frameBB1"));
        frameBB1->setFrameShape(QFrame::StyledPanel);
        frameBB1->setFrameShadow(QFrame::Raised);
        gridLayout_14 = new QGridLayout(frameBB1);
        gridLayout_14->setObjectName(QString::fromUtf8("gridLayout_14"));
        Blbl_name = new QLabel(frameBB1);
        Blbl_name->setObjectName(QString::fromUtf8("Blbl_name"));
        Blbl_name->setFont(font2);

        gridLayout_14->addWidget(Blbl_name, 0, 0, 1, 1);

        Ble_name = new QLineEdit(frameBB1);
        Ble_name->setObjectName(QString::fromUtf8("Ble_name"));
        Ble_name->setFont(font3);

        gridLayout_14->addWidget(Ble_name, 0, 1, 1, 1);

        Blbl_usuario = new QLabel(frameBB1);
        Blbl_usuario->setObjectName(QString::fromUtf8("Blbl_usuario"));
        Blbl_usuario->setFont(font2);

        gridLayout_14->addWidget(Blbl_usuario, 1, 0, 1, 1);

        Bcb_usuario = new QComboBox(frameBB1);
        Bcb_usuario->addItem(QString());
        Bcb_usuario->addItem(QString());
        Bcb_usuario->addItem(QString());
        Bcb_usuario->setObjectName(QString::fromUtf8("Bcb_usuario"));
        Bcb_usuario->setFont(font3);

        gridLayout_14->addWidget(Bcb_usuario, 1, 1, 1, 1);

        Blbl_contra = new QLabel(frameBB1);
        Blbl_contra->setObjectName(QString::fromUtf8("Blbl_contra"));
        Blbl_contra->setFont(font2);

        gridLayout_14->addWidget(Blbl_contra, 2, 0, 1, 1);

        Ble_clave = new QLineEdit(frameBB1);
        Ble_clave->setObjectName(QString::fromUtf8("Ble_clave"));
        Ble_clave->setFont(font3);

        gridLayout_14->addWidget(Ble_clave, 2, 1, 1, 1);

        Bbtn_sesion = new QPushButton(frameBB1);
        Bbtn_sesion->setObjectName(QString::fromUtf8("Bbtn_sesion"));
        Bbtn_sesion->setFont(font5);

        gridLayout_14->addWidget(Bbtn_sesion, 3, 1, 1, 1);


        gridLayout_13->addWidget(frameBB1, 0, 0, 1, 1);


        gridLayout_6->addWidget(frameB1, 1, 0, 1, 1);

        frameB = new QFrame(tab_4);
        frameB->setObjectName(QString::fromUtf8("frameB"));
        frameB->setFrameShape(QFrame::StyledPanel);
        frameB->setFrameShadow(QFrame::Raised);
        gridLayout_15 = new QGridLayout(frameB);
        gridLayout_15->setObjectName(QString::fromUtf8("gridLayout_15"));
        Bbtn_aceptados = new QRadioButton(frameB);
        Bbtn_aceptados->setObjectName(QString::fromUtf8("Bbtn_aceptados"));

        gridLayout_15->addWidget(Bbtn_aceptados, 1, 2, 1, 1);

        Bbtn_proceso = new QRadioButton(frameB);
        Bbtn_proceso->setObjectName(QString::fromUtf8("Bbtn_proceso"));

        gridLayout_15->addWidget(Bbtn_proceso, 0, 2, 1, 1);

        Bbtn_cerrar = new QPushButton(frameB);
        Bbtn_cerrar->setObjectName(QString::fromUtf8("Bbtn_cerrar"));

        gridLayout_15->addWidget(Bbtn_cerrar, 2, 2, 1, 1);

        tableWidget = new QTableWidget(frameB);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        gridLayout_15->addWidget(tableWidget, 2, 0, 1, 1);


        gridLayout_6->addWidget(frameB, 2, 0, 1, 1);

        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        gridLayout_18 = new QGridLayout(tab_5);
        gridLayout_18->setObjectName(QString::fromUtf8("gridLayout_18"));
        Dlbl_png = new QLabel(tab_5);
        Dlbl_png->setObjectName(QString::fromUtf8("Dlbl_png"));
        Dlbl_png->setScaledContents(true);

        gridLayout_18->addWidget(Dlbl_png, 0, 0, 1, 1);

        Dframe1 = new QFrame(tab_5);
        Dframe1->setObjectName(QString::fromUtf8("Dframe1"));
        Dframe1->setFrameShape(QFrame::StyledPanel);
        Dframe1->setFrameShadow(QFrame::Raised);
        gridLayout_16 = new QGridLayout(Dframe1);
        gridLayout_16->setObjectName(QString::fromUtf8("gridLayout_16"));
        Dle_cuenta = new QLineEdit(Dframe1);
        Dle_cuenta->setObjectName(QString::fromUtf8("Dle_cuenta"));
        Dle_cuenta->setFont(font3);

        gridLayout_16->addWidget(Dle_cuenta, 1, 1, 1, 1);

        Dlbl_contraE = new QLabel(Dframe1);
        Dlbl_contraE->setObjectName(QString::fromUtf8("Dlbl_contraE"));
        Dlbl_contraE->setFont(font2);

        gridLayout_16->addWidget(Dlbl_contraE, 2, 0, 1, 1);

        Dle_clave = new QLineEdit(Dframe1);
        Dle_clave->setObjectName(QString::fromUtf8("Dle_clave"));
        Dle_clave->setFont(font3);

        gridLayout_16->addWidget(Dle_clave, 2, 1, 1, 1);

        Dlbl_cuenta = new QLabel(Dframe1);
        Dlbl_cuenta->setObjectName(QString::fromUtf8("Dlbl_cuenta"));
        Dlbl_cuenta->setFont(font2);

        gridLayout_16->addWidget(Dlbl_cuenta, 1, 0, 1, 1);

        Dbtn_sesion = new QPushButton(Dframe1);
        Dbtn_sesion->setObjectName(QString::fromUtf8("Dbtn_sesion"));
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::Button, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette9.setBrush(QPalette::Disabled, QPalette::Button, brush);
        Dbtn_sesion->setPalette(palette9);
        Dbtn_sesion->setFont(font1);

        gridLayout_16->addWidget(Dbtn_sesion, 3, 1, 1, 1);

        Dle_name = new QLineEdit(Dframe1);
        Dle_name->setObjectName(QString::fromUtf8("Dle_name"));
        Dle_name->setFont(font3);

        gridLayout_16->addWidget(Dle_name, 0, 1, 1, 1);

        Dlbl_name = new QLabel(Dframe1);
        Dlbl_name->setObjectName(QString::fromUtf8("Dlbl_name"));
        Dlbl_name->setFont(font2);

        gridLayout_16->addWidget(Dlbl_name, 0, 0, 1, 1);

        Dbtn_salir = new QPushButton(Dframe1);
        Dbtn_salir->setObjectName(QString::fromUtf8("Dbtn_salir"));

        gridLayout_16->addWidget(Dbtn_salir, 3, 0, 1, 1);


        gridLayout_18->addWidget(Dframe1, 1, 0, 1, 1);

        Dframe2 = new QFrame(tab_5);
        Dframe2->setObjectName(QString::fromUtf8("Dframe2"));
        Dframe2->setFrameShape(QFrame::StyledPanel);
        Dframe2->setFrameShadow(QFrame::Raised);
        gridLayout_17 = new QGridLayout(Dframe2);
        gridLayout_17->setObjectName(QString::fromUtf8("gridLayout_17"));
        DRTW_revision = new QTableWidget(Dframe2);
        DRTW_revision->setObjectName(QString::fromUtf8("DRTW_revision"));

        gridLayout_17->addWidget(DRTW_revision, 0, 1, 1, 1);

        Dlabel2 = new QLabel(Dframe2);
        Dlabel2->setObjectName(QString::fromUtf8("Dlabel2"));
        QPalette palette10;
        QBrush brush3(QColor(6, 36, 88, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette10.setBrush(QPalette::Active, QPalette::WindowText, brush3);
        palette10.setBrush(QPalette::Active, QPalette::Text, brush3);
        QBrush brush4(QColor(6, 36, 88, 128));
        brush4.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette10.setBrush(QPalette::Active, QPalette::PlaceholderText, brush4);
#endif
        palette10.setBrush(QPalette::Inactive, QPalette::WindowText, brush3);
        palette10.setBrush(QPalette::Inactive, QPalette::Text, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette10.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush4);
#endif
        QBrush brush5(QColor(120, 120, 120, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette10.setBrush(QPalette::Disabled, QPalette::WindowText, brush5);
        palette10.setBrush(QPalette::Disabled, QPalette::Text, brush5);
        QBrush brush6(QColor(0, 0, 0, 128));
        brush6.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette10.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush6);
#endif
        Dlabel2->setPalette(palette10);

        gridLayout_17->addWidget(Dlabel2, 0, 0, 1, 1);

        Dlabel = new QLabel(Dframe2);
        Dlabel->setObjectName(QString::fromUtf8("Dlabel"));
        QPalette palette11;
        palette11.setBrush(QPalette::Active, QPalette::WindowText, brush3);
        palette11.setBrush(QPalette::Active, QPalette::Text, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette11.setBrush(QPalette::Active, QPalette::PlaceholderText, brush4);
#endif
        palette11.setBrush(QPalette::Inactive, QPalette::WindowText, brush3);
        palette11.setBrush(QPalette::Inactive, QPalette::Text, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette11.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush4);
#endif
        palette11.setBrush(QPalette::Disabled, QPalette::WindowText, brush5);
        palette11.setBrush(QPalette::Disabled, QPalette::Text, brush5);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette11.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush6);
#endif
        Dlabel->setPalette(palette11);

        gridLayout_17->addWidget(Dlabel, 0, 2, 1, 1);


        gridLayout_18->addWidget(Dframe2, 2, 0, 1, 1);

        tabWidget->addTab(tab_5, QString());

        gridLayout_2->addWidget(tabWidget, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 910, 25));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(menubar->sizePolicy().hasHeightForWidth());
        menubar->setSizePolicy(sizePolicy);
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MANEJO DE SILABOS", nullptr));
        lbl_pngMenu->setText(QString());
        btn_entregarM->setText(QApplication::translate("MainWindow", "ENTREGA", nullptr));
        btn_revision->setText(QApplication::translate("MainWindow", "REVISION", nullptr));
        btn_dashboardM->setText(QApplication::translate("MainWindow", "VER DASHBOARD", nullptr));
        lbl_b2M->setText(QString());
        lbl_b1M->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "MENU", nullptr));
        lbl_pngE->setText(QString());
        btn_sesion->setText(QApplication::translate("MainWindow", "Iniciar Sesion", nullptr));
        lbl_nameE->setText(QApplication::translate("MainWindow", "Nombre Completo:", nullptr));
        lbl_cuentaE->setText(QApplication::translate("MainWindow", "Numero de cuenta:", nullptr));
        lbl_contraE->setText(QApplication::translate("MainWindow", "Clave:", nullptr));
        cb_carreraE->setItemText(0, QApplication::translate("MainWindow", "...", nullptr));

        btn_closeE->setText(QApplication::translate("MainWindow", "Cerrar\n"
"Sesion", nullptr));
        lbl_facultadE->setText(QApplication::translate("MainWindow", "Facultad:", nullptr));
        cb_facultadE->setItemText(0, QApplication::translate("MainWindow", "...", nullptr));
        cb_facultadE->setItemText(1, QApplication::translate("MainWindow", "FI", nullptr));
        cb_facultadE->setItemText(2, QApplication::translate("MainWindow", "FCAS", nullptr));
        cb_facultadE->setItemText(3, QApplication::translate("MainWindow", "FA&D", nullptr));

        lbl_codigoE->setText(QApplication::translate("MainWindow", "Codigo de clase:", nullptr));
        btn_archivoE->setText(QApplication::translate("MainWindow", "BUSCAR", nullptr));
        lbl_carreraE->setText(QApplication::translate("MainWindow", "Carrera:", nullptr));
        le_pathE->setText(QString());
        lbl_codigoE_2->setText(QApplication::translate("MainWindow", "Archivo:", nullptr));
        btn_silaboE->setText(QApplication::translate("MainWindow", "Ingresar", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "ENTREGA", nullptr));
        Rcb_usuario->setItemText(0, QApplication::translate("MainWindow", "...", nullptr));
        Rcb_usuario->setItemText(1, QApplication::translate("MainWindow", "JEFE ACADEMICO", nullptr));
        Rcb_usuario->setItemText(2, QApplication::translate("MainWindow", "COORDINADOR DE CARRERA", nullptr));
        Rcb_usuario->setItemText(3, QApplication::translate("MainWindow", "IEDD", nullptr));
        Rcb_usuario->setItemText(4, QApplication::translate("MainWindow", "CONSULTOR", nullptr));

        Rbtn_sesion->setText(QApplication::translate("MainWindow", "Iniciar Sesion", nullptr));
        Rlbl_contra->setText(QApplication::translate("MainWindow", "Clave:", nullptr));
        Rlbl_usuario->setText(QApplication::translate("MainWindow", "Tipo de usuario:", nullptr));
        Rlbl_name->setText(QApplication::translate("MainWindow", "Nombre Completo:", nullptr));
        lbl_pngR->setText(QString());
        Rlbl_seleccion->setText(QApplication::translate("MainWindow", "Seleccion:", nullptr));
        Rlbl_estadoA->setText(QApplication::translate("MainWindow", "Estado Actual:", nullptr));
        Rlbl_name_4->setText(QApplication::translate("MainWindow", "Cambiar Estado:", nullptr));
        Rcb_cambiarE->setItemText(0, QApplication::translate("MainWindow", "...", nullptr));

        Rlbl_comentario->setText(QApplication::translate("MainWindow", "Comentario:", nullptr));
        Rbtn_cambiar->setText(QApplication::translate("MainWindow", "Cambiar", nullptr));
        Rbtn_cerrar->setText(QApplication::translate("MainWindow", "Cerrar Sesion", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "REVISION", nullptr));
        lbl_pngD->setText(QString());
        Blbl_name->setText(QApplication::translate("MainWindow", "Nombre Completo:", nullptr));
        Blbl_usuario->setText(QApplication::translate("MainWindow", "Tipo de usuario:", nullptr));
        Bcb_usuario->setItemText(0, QApplication::translate("MainWindow", "...", nullptr));
        Bcb_usuario->setItemText(1, QApplication::translate("MainWindow", "DIRECTORES", nullptr));
        Bcb_usuario->setItemText(2, QApplication::translate("MainWindow", "DECANOS", nullptr));

        Blbl_contra->setText(QApplication::translate("MainWindow", "Clave:", nullptr));
        Bbtn_sesion->setText(QApplication::translate("MainWindow", "Iniciar Sesion", nullptr));
        Bbtn_aceptados->setText(QApplication::translate("MainWindow", "Aceptados", nullptr));
        Bbtn_proceso->setText(QApplication::translate("MainWindow", "En proceso", nullptr));
        Bbtn_cerrar->setText(QApplication::translate("MainWindow", "Cerrar Sesion", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "BOARD", nullptr));
        Dlbl_png->setText(QString());
        Dlbl_contraE->setText(QApplication::translate("MainWindow", "Clave:", nullptr));
        Dlbl_cuenta->setText(QApplication::translate("MainWindow", "Numero de cuenta:", nullptr));
        Dbtn_sesion->setText(QApplication::translate("MainWindow", "REVISAR", nullptr));
        Dlbl_name->setText(QApplication::translate("MainWindow", "Nombre registrado:", nullptr));
        Dbtn_salir->setText(QApplication::translate("MainWindow", "SALIR", nullptr));
        Dlabel2->setText(QApplication::translate("MainWindow", "..................................................................................", nullptr));
        Dlabel->setText(QApplication::translate("MainWindow", "...................................................................................", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("MainWindow", "DOCENTE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
