#ifndef CFRAME_H
#define CFRAME_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class cframe; }
QT_END_NAMESPACE

class cframe : public QMainWindow
{
    Q_OBJECT

public:
    cframe(QWidget *parent = nullptr);
    ~cframe();

private slots:
    void on_Mbtn_ingresar_clicked();

    void on_Acb_acciones_currentIndexChanged(int index);

    void on_btn_sesion_clicked();

    void on_Ecb_sede_currentIndexChanged(int index);

    void on_Rbtn_cambiar_clicked();

    void on_Abtn_cambioContra_clicked();

    void on_Acb_acciones_currentIndexChanged(const QString &arg1);

private:
    Ui::cframe *ui;
    void visibilidad();
    //variables para actualizar el cframe admin
    QString nombre,numero_cuenta,tipo_usuario;
    QString password;
};
#endif // CFRAME_H
