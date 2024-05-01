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
    QGridLayout *gridLayout_3;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QPushButton *btn_IniciarSesion;
    QLabel *lbl_b2M;
    QLabel *lbl_pngMenu;
    QFrame *frameMI;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *LE_NumCuenta;
    QLineEdit *LE_Username;
    QLineEdit *LE_Contra;
    QPushButton *btn_Ingresar;
    QComboBox *CB_Cargo;
    QWidget *tab_2;
    QGridLayout *gridLayout_4;
    QLabel *lbl_pngE;
    QFrame *frameE;
    QGridLayout *gridLayout_8;
    QLabel *lbl_codigoE;
    QPushButton *btn_archivoE;
    QLabel *lbl_codigoE_2;
    QLabel *lbl_facultadE;
    QLabel *lbl_carreraE;
    QComboBox *cb_carreraE;
    QLineEdit *le_codigoE;
    QComboBox *cb_facultadE;
    QLineEdit *le_pathE;
    QFrame *frameE2;
    QGridLayout *gridLayout_7;
    QPushButton *btn_closeE;
    QPushButton *btn_silaboE;
    QWidget *tab_3;
    QGridLayout *gridLayout_5;
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
    QFrame *frameB;
    QGridLayout *gridLayout_15;
    QRadioButton *Bbtn_aceptados;
    QRadioButton *Bbtn_proceso;
    QPushButton *Bbtn_cerrar;
    QTableWidget *tableWidget;
    QWidget *tab_5;
    QGridLayout *gridLayout_18;
    QLabel *Dlbl_png;
    QFrame *Dframe2;
    QGridLayout *gridLayout_17;
    QLabel *Dlabel;
    QTableWidget *DRTW_revision;
    QLabel *Dlabel2;
    QPushButton *Dbtn_salir;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(910, 715);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_3 = new QGridLayout(centralwidget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
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
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 884, 640));
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
        btn_IniciarSesion = new QPushButton(tab);
        btn_IniciarSesion->setObjectName(QString::fromUtf8("btn_IniciarSesion"));
        btn_IniciarSesion->setGeometry(QRect(120, 480, 611, 81));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::Button, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush);
        btn_IniciarSesion->setPalette(palette2);
        QFont font;
        font.setFamily(QString::fromUtf8("Cambria"));
        font.setPointSize(14);
        font.setBold(false);
        font.setWeight(50);
        btn_IniciarSesion->setFont(font);
        lbl_b2M = new QLabel(tab);
        lbl_b2M->setObjectName(QString::fromUtf8("lbl_b2M"));
        lbl_b2M->setGeometry(QRect(10, 10, 841, 41));
        lbl_b2M->setScaledContents(false);
        lbl_pngMenu = new QLabel(tab);
        lbl_pngMenu->setObjectName(QString::fromUtf8("lbl_pngMenu"));
        lbl_pngMenu->setGeometry(QRect(20, 59, 811, 411));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::Button, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush);
        lbl_pngMenu->setPalette(palette3);
        lbl_pngMenu->setScaledContents(true);
        frameMI = new QFrame(tab);
        frameMI->setObjectName(QString::fromUtf8("frameMI"));
        frameMI->setGeometry(QRect(9, 59, 851, 511));
        frameMI->setFrameShape(QFrame::StyledPanel);
        frameMI->setFrameShadow(QFrame::Raised);
        label = new QLabel(frameMI);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 30, 121, 21));
        label_2 = new QLabel(frameMI);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(60, 70, 71, 16));
        label_3 = new QLabel(frameMI);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(50, 110, 81, 16));
        label_4 = new QLabel(frameMI);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(80, 150, 41, 16));
        LE_NumCuenta = new QLineEdit(frameMI);
        LE_NumCuenta->setObjectName(QString::fromUtf8("LE_NumCuenta"));
        LE_NumCuenta->setGeometry(QRect(130, 20, 211, 31));
        LE_Username = new QLineEdit(frameMI);
        LE_Username->setObjectName(QString::fromUtf8("LE_Username"));
        LE_Username->setGeometry(QRect(130, 60, 211, 31));
        LE_Contra = new QLineEdit(frameMI);
        LE_Contra->setObjectName(QString::fromUtf8("LE_Contra"));
        LE_Contra->setGeometry(QRect(130, 100, 211, 31));
        btn_Ingresar = new QPushButton(frameMI);
        btn_Ingresar->setObjectName(QString::fromUtf8("btn_Ingresar"));
        btn_Ingresar->setGeometry(QRect(100, 190, 481, 51));
        CB_Cargo = new QComboBox(frameMI);
        CB_Cargo->setObjectName(QString::fromUtf8("CB_Cargo"));
        CB_Cargo->setGeometry(QRect(120, 140, 231, 31));
        tabWidget->addTab(tab, QString());
        btn_IniciarSesion->raise();
        lbl_pngMenu->raise();
        lbl_b2M->raise();
        frameMI->raise();
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout_4 = new QGridLayout(tab_2);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        lbl_pngE = new QLabel(tab_2);
        lbl_pngE->setObjectName(QString::fromUtf8("lbl_pngE"));
        lbl_pngE->setScaledContents(true);

        gridLayout_4->addWidget(lbl_pngE, 0, 0, 1, 1);

        frameE = new QFrame(tab_2);
        frameE->setObjectName(QString::fromUtf8("frameE"));
        frameE->setEnabled(true);
        frameE->setFrameShape(QFrame::StyledPanel);
        frameE->setFrameShadow(QFrame::Raised);
        gridLayout_8 = new QGridLayout(frameE);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        lbl_codigoE = new QLabel(frameE);
        lbl_codigoE->setObjectName(QString::fromUtf8("lbl_codigoE"));
        QFont font1;
        font1.setPointSize(12);
        lbl_codigoE->setFont(font1);

        gridLayout_8->addWidget(lbl_codigoE, 2, 0, 1, 1);

        btn_archivoE = new QPushButton(frameE);
        btn_archivoE->setObjectName(QString::fromUtf8("btn_archivoE"));

        gridLayout_8->addWidget(btn_archivoE, 4, 2, 1, 1);

        lbl_codigoE_2 = new QLabel(frameE);
        lbl_codigoE_2->setObjectName(QString::fromUtf8("lbl_codigoE_2"));
        lbl_codigoE_2->setFont(font1);

        gridLayout_8->addWidget(lbl_codigoE_2, 4, 0, 1, 1);

        lbl_facultadE = new QLabel(frameE);
        lbl_facultadE->setObjectName(QString::fromUtf8("lbl_facultadE"));
        lbl_facultadE->setFont(font1);

        gridLayout_8->addWidget(lbl_facultadE, 0, 0, 1, 1);

        lbl_carreraE = new QLabel(frameE);
        lbl_carreraE->setObjectName(QString::fromUtf8("lbl_carreraE"));
        lbl_carreraE->setFont(font1);

        gridLayout_8->addWidget(lbl_carreraE, 1, 0, 1, 1);

        cb_carreraE = new QComboBox(frameE);
        cb_carreraE->addItem(QString());
        cb_carreraE->setObjectName(QString::fromUtf8("cb_carreraE"));
        QFont font2;
        font2.setPointSize(11);
        cb_carreraE->setFont(font2);

        gridLayout_8->addWidget(cb_carreraE, 1, 2, 1, 1);

        le_codigoE = new QLineEdit(frameE);
        le_codigoE->setObjectName(QString::fromUtf8("le_codigoE"));
        le_codigoE->setFont(font2);

        gridLayout_8->addWidget(le_codigoE, 2, 2, 1, 1);

        cb_facultadE = new QComboBox(frameE);
        cb_facultadE->addItem(QString());
        cb_facultadE->addItem(QString());
        cb_facultadE->addItem(QString());
        cb_facultadE->addItem(QString());
        cb_facultadE->setObjectName(QString::fromUtf8("cb_facultadE"));
        cb_facultadE->setFont(font2);

        gridLayout_8->addWidget(cb_facultadE, 0, 2, 1, 1);

        le_pathE = new QLineEdit(frameE);
        le_pathE->setObjectName(QString::fromUtf8("le_pathE"));
        le_pathE->setEnabled(false);

        gridLayout_8->addWidget(le_pathE, 6, 2, 1, 1);

        frameE2 = new QFrame(frameE);
        frameE2->setObjectName(QString::fromUtf8("frameE2"));
        frameE2->setFrameShape(QFrame::StyledPanel);
        frameE2->setFrameShadow(QFrame::Raised);
        gridLayout_7 = new QGridLayout(frameE2);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        btn_closeE = new QPushButton(frameE2);
        btn_closeE->setObjectName(QString::fromUtf8("btn_closeE"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Sans Serif Collection"));
        font3.setPointSize(7);
        btn_closeE->setFont(font3);

        gridLayout_7->addWidget(btn_closeE, 1, 0, 1, 1);

        btn_silaboE = new QPushButton(frameE2);
        btn_silaboE->setObjectName(QString::fromUtf8("btn_silaboE"));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::Button, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush);
        btn_silaboE->setPalette(palette4);
        QFont font4;
        font4.setFamily(QString::fromUtf8("Sans Serif Collection"));
        font4.setPointSize(11);
        font4.setBold(false);
        font4.setWeight(50);
        btn_silaboE->setFont(font4);

        gridLayout_7->addWidget(btn_silaboE, 1, 1, 1, 1);


        gridLayout_8->addWidget(frameE2, 7, 2, 1, 1);


        gridLayout_4->addWidget(frameE, 1, 0, 2, 1);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        gridLayout_5 = new QGridLayout(tab_3);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
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
        Rlbl_seleccion->setFont(font1);

        gridLayout_11->addWidget(Rlbl_seleccion, 0, 0, 1, 1);

        Rle_seleccion = new QLineEdit(frame_2);
        Rle_seleccion->setObjectName(QString::fromUtf8("Rle_seleccion"));
        Rle_seleccion->setEnabled(false);

        gridLayout_11->addWidget(Rle_seleccion, 0, 1, 1, 1);

        Rlbl_estadoA = new QLabel(frame_2);
        Rlbl_estadoA->setObjectName(QString::fromUtf8("Rlbl_estadoA"));
        Rlbl_estadoA->setFont(font1);

        gridLayout_11->addWidget(Rlbl_estadoA, 1, 0, 1, 1);

        Rle_estadoA = new QLineEdit(frame_2);
        Rle_estadoA->setObjectName(QString::fromUtf8("Rle_estadoA"));
        Rle_estadoA->setEnabled(false);

        gridLayout_11->addWidget(Rle_estadoA, 1, 1, 1, 1);

        Rlbl_name_4 = new QLabel(frame_2);
        Rlbl_name_4->setObjectName(QString::fromUtf8("Rlbl_name_4"));
        Rlbl_name_4->setFont(font1);

        gridLayout_11->addWidget(Rlbl_name_4, 2, 0, 1, 1);

        Rcb_cambiarE = new QComboBox(frame_2);
        Rcb_cambiarE->addItem(QString());
        Rcb_cambiarE->setObjectName(QString::fromUtf8("Rcb_cambiarE"));
        Rcb_cambiarE->setFont(font2);

        gridLayout_11->addWidget(Rcb_cambiarE, 2, 1, 1, 1);

        Rlbl_comentario = new QLabel(frame_2);
        Rlbl_comentario->setObjectName(QString::fromUtf8("Rlbl_comentario"));
        Rlbl_comentario->setFont(font1);

        gridLayout_11->addWidget(Rlbl_comentario, 3, 0, 1, 1);

        Rle_comentario = new QLineEdit(frame_2);
        Rle_comentario->setObjectName(QString::fromUtf8("Rle_comentario"));
        Rle_comentario->setEnabled(true);

        gridLayout_11->addWidget(Rle_comentario, 3, 1, 1, 1);

        Rbtn_cambiar = new QPushButton(frame_2);
        Rbtn_cambiar->setObjectName(QString::fromUtf8("Rbtn_cambiar"));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Sans Serif Collection"));
        font5.setPointSize(11);
        Rbtn_cambiar->setFont(font5);

        gridLayout_11->addWidget(Rbtn_cambiar, 4, 1, 1, 1);

        Rbtn_cerrar = new QPushButton(frame_2);
        Rbtn_cerrar->setObjectName(QString::fromUtf8("Rbtn_cerrar"));

        gridLayout_11->addWidget(Rbtn_cerrar, 5, 1, 1, 1);


        gridLayout_10->addWidget(frame_2, 0, 1, 1, 1);


        gridLayout_5->addWidget(frameR, 1, 0, 1, 1);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        gridLayout_6 = new QGridLayout(tab_4);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        lbl_pngD = new QLabel(tab_4);
        lbl_pngD->setObjectName(QString::fromUtf8("lbl_pngD"));
        lbl_pngD->setScaledContents(true);

        gridLayout_6->addWidget(lbl_pngD, 0, 0, 1, 1);

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


        gridLayout_6->addWidget(frameB, 1, 0, 1, 1);

        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        gridLayout_18 = new QGridLayout(tab_5);
        gridLayout_18->setObjectName(QString::fromUtf8("gridLayout_18"));
        Dlbl_png = new QLabel(tab_5);
        Dlbl_png->setObjectName(QString::fromUtf8("Dlbl_png"));
        Dlbl_png->setScaledContents(true);

        gridLayout_18->addWidget(Dlbl_png, 0, 0, 1, 1);

        Dframe2 = new QFrame(tab_5);
        Dframe2->setObjectName(QString::fromUtf8("Dframe2"));
        Dframe2->setFrameShape(QFrame::StyledPanel);
        Dframe2->setFrameShadow(QFrame::Raised);
        gridLayout_17 = new QGridLayout(Dframe2);
        gridLayout_17->setObjectName(QString::fromUtf8("gridLayout_17"));
        Dlabel = new QLabel(Dframe2);
        Dlabel->setObjectName(QString::fromUtf8("Dlabel"));
        QPalette palette5;
        QBrush brush1(QColor(6, 36, 88, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette5.setBrush(QPalette::Active, QPalette::Text, brush1);
        QBrush brush2(QColor(6, 36, 88, 128));
        brush2.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Active, QPalette::PlaceholderText, brush2);
#endif
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush2);
#endif
        QBrush brush3(QColor(120, 120, 120, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette5.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        QBrush brush4(QColor(0, 0, 0, 128));
        brush4.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        Dlabel->setPalette(palette5);

        gridLayout_17->addWidget(Dlabel, 0, 2, 1, 1);

        DRTW_revision = new QTableWidget(Dframe2);
        DRTW_revision->setObjectName(QString::fromUtf8("DRTW_revision"));

        gridLayout_17->addWidget(DRTW_revision, 0, 1, 1, 1);

        Dlabel2 = new QLabel(Dframe2);
        Dlabel2->setObjectName(QString::fromUtf8("Dlabel2"));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette6.setBrush(QPalette::Active, QPalette::Text, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette6.setBrush(QPalette::Active, QPalette::PlaceholderText, brush2);
#endif
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Text, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette6.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush2);
#endif
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette6.setBrush(QPalette::Disabled, QPalette::Text, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette6.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        Dlabel2->setPalette(palette6);

        gridLayout_17->addWidget(Dlabel2, 0, 0, 1, 1);

        Dbtn_salir = new QPushButton(Dframe2);
        Dbtn_salir->setObjectName(QString::fromUtf8("Dbtn_salir"));

        gridLayout_17->addWidget(Dbtn_salir, 1, 1, 1, 1);


        gridLayout_18->addWidget(Dframe2, 1, 0, 1, 1);

        tabWidget->addTab(tab_5, QString());

        gridLayout_2->addWidget(tabWidget, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_3->addWidget(scrollArea, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 910, 22));
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
        btn_IniciarSesion->setText(QApplication::translate("MainWindow", "INICIAR SESION", nullptr));
        lbl_b2M->setText(QString());
        lbl_pngMenu->setText(QString());
        label->setText(QApplication::translate("MainWindow", "Numero de Cuenta", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "UserName", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Contrase\303\261a", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Cargo", nullptr));
        btn_Ingresar->setText(QApplication::translate("MainWindow", "Ingresar", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "MENU", nullptr));
        lbl_pngE->setText(QString());
        lbl_codigoE->setText(QApplication::translate("MainWindow", "Codigo de clase:", nullptr));
        btn_archivoE->setText(QApplication::translate("MainWindow", "BUSCAR", nullptr));
        lbl_codigoE_2->setText(QApplication::translate("MainWindow", "Archivo:", nullptr));
        lbl_facultadE->setText(QApplication::translate("MainWindow", "Facultad:", nullptr));
        lbl_carreraE->setText(QApplication::translate("MainWindow", "Carrera:", nullptr));
        cb_carreraE->setItemText(0, QApplication::translate("MainWindow", "...", nullptr));

        cb_facultadE->setItemText(0, QApplication::translate("MainWindow", "...", nullptr));
        cb_facultadE->setItemText(1, QApplication::translate("MainWindow", "FI", nullptr));
        cb_facultadE->setItemText(2, QApplication::translate("MainWindow", "FCAS", nullptr));
        cb_facultadE->setItemText(3, QApplication::translate("MainWindow", "FA&D", nullptr));

        le_pathE->setText(QString());
        btn_closeE->setText(QApplication::translate("MainWindow", "Cerrar\n"
"Sesion", nullptr));
        btn_silaboE->setText(QApplication::translate("MainWindow", "Ingresar", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "ENTREGA", nullptr));
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
        Bbtn_aceptados->setText(QApplication::translate("MainWindow", "Aceptados", nullptr));
        Bbtn_proceso->setText(QApplication::translate("MainWindow", "En proceso", nullptr));
        Bbtn_cerrar->setText(QApplication::translate("MainWindow", "Cerrar Sesion", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "BOARD", nullptr));
        Dlbl_png->setText(QString());
        Dlabel->setText(QApplication::translate("MainWindow", "...................................................................................", nullptr));
        Dlabel2->setText(QApplication::translate("MainWindow", "..................................................................................", nullptr));
        Dbtn_salir->setText(QApplication::translate("MainWindow", "SALIR", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("MainWindow", "DOCENTE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
