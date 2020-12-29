/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionIniciar_Sesi_n;
    QAction *actionCerrar_Sesi_n;
    QAction *actionNuevo_Usuario;
    QWidget *centralWidget;
    QPushButton *pb_pass;
    QPushButton *pb_alarm;
    QLabel *lb_principal;
    QPushButton *pb_desac;
    QLabel *lb_date;
    QLabel *lb_usuario1;
    QLabel *lb_usuario2;
    QPushButton *pb_browse;
    QLabel *lb_browse;
    QGroupBox *groupBox;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QComboBox *comboBox_puertos;
    QPushButton *button_refresh_ports;
    QPushButton *button_connect;
    QLineEdit *edit_estado;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *le_estado;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *le_peso;
    QLabel *label_5;
    QLineEdit *le_infra;
    QLabel *label_6;
    QLineEdit *le_estadopeso;
    QLabel *label_7;
    QPushButton *pb_setpeso;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuIniciar_Sesion;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(875, 610);
        actionIniciar_Sesi_n = new QAction(MainWindow);
        actionIniciar_Sesi_n->setObjectName(QStringLiteral("actionIniciar_Sesi_n"));
        actionCerrar_Sesi_n = new QAction(MainWindow);
        actionCerrar_Sesi_n->setObjectName(QStringLiteral("actionCerrar_Sesi_n"));
        actionNuevo_Usuario = new QAction(MainWindow);
        actionNuevo_Usuario->setObjectName(QStringLiteral("actionNuevo_Usuario"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pb_pass = new QPushButton(centralWidget);
        pb_pass->setObjectName(QStringLiteral("pb_pass"));
        pb_pass->setGeometry(QRect(210, 120, 171, 50));
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/Keys.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_pass->setIcon(icon);
        pb_alarm = new QPushButton(centralWidget);
        pb_alarm->setObjectName(QStringLiteral("pb_alarm"));
        pb_alarm->setGeometry(QRect(210, 190, 171, 50));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/image/Bell.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_alarm->setIcon(icon1);
        lb_principal = new QLabel(centralWidget);
        lb_principal->setObjectName(QStringLiteral("lb_principal"));
        lb_principal->setGeometry(QRect(0, 0, 600, 80));
        QFont font;
        font.setPointSize(16);
        font.setUnderline(true);
        lb_principal->setFont(font);
        lb_principal->setLayoutDirection(Qt::LeftToRight);
        lb_principal->setAlignment(Qt::AlignCenter);
        pb_desac = new QPushButton(centralWidget);
        pb_desac->setObjectName(QStringLiteral("pb_desac"));
        pb_desac->setGeometry(QRect(210, 260, 171, 50));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/image/off.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_desac->setIcon(icon2);
        lb_date = new QLabel(centralWidget);
        lb_date->setObjectName(QStringLiteral("lb_date"));
        lb_date->setGeometry(QRect(440, 70, 231, 21));
        QFont font1;
        font1.setPointSize(11);
        lb_date->setFont(font1);
        lb_usuario1 = new QLabel(centralWidget);
        lb_usuario1->setObjectName(QStringLiteral("lb_usuario1"));
        lb_usuario1->setGeometry(QRect(20, 70, 71, 31));
        lb_usuario2 = new QLabel(centralWidget);
        lb_usuario2->setObjectName(QStringLiteral("lb_usuario2"));
        lb_usuario2->setGeometry(QRect(106, 70, 71, 31));
        pb_browse = new QPushButton(centralWidget);
        pb_browse->setObjectName(QStringLiteral("pb_browse"));
        pb_browse->setGeometry(QRect(30, 320, 75, 23));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/image/Camera.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_browse->setIcon(icon3);
        lb_browse = new QLabel(centralWidget);
        lb_browse->setObjectName(QStringLiteral("lb_browse"));
        lb_browse->setGeometry(QRect(120, 320, 401, 23));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 410, 571, 131));
        horizontalLayoutWidget = new QWidget(groupBox);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(130, 20, 431, 25));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        comboBox_puertos = new QComboBox(horizontalLayoutWidget);
        comboBox_puertos->setObjectName(QStringLiteral("comboBox_puertos"));
        comboBox_puertos->setMaximumSize(QSize(350, 16777215));
        comboBox_puertos->setCursor(QCursor(Qt::PointingHandCursor));
        comboBox_puertos->setEditable(false);

        horizontalLayout->addWidget(comboBox_puertos);

        button_refresh_ports = new QPushButton(horizontalLayoutWidget);
        button_refresh_ports->setObjectName(QStringLiteral("button_refresh_ports"));
        button_refresh_ports->setMaximumSize(QSize(120, 16777215));

        horizontalLayout->addWidget(button_refresh_ports);

        button_connect = new QPushButton(groupBox);
        button_connect->setObjectName(QStringLiteral("button_connect"));
        button_connect->setGeometry(QRect(290, 70, 151, 31));
        edit_estado = new QLineEdit(groupBox);
        edit_estado->setObjectName(QStringLiteral("edit_estado"));
        edit_estado->setGeometry(QRect(130, 70, 151, 31));
        edit_estado->setCursor(QCursor(Qt::BlankCursor));
        edit_estado->setFrame(true);
        edit_estado->setReadOnly(true);
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 70, 46, 13));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 20, 71, 16));
        le_estado = new QLineEdit(centralWidget);
        le_estado->setObjectName(QStringLiteral("le_estado"));
        le_estado->setGeometry(QRect(500, 230, 113, 20));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(520, 210, 81, 16));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(530, 260, 71, 16));
        le_peso = new QLineEdit(centralWidget);
        le_peso->setObjectName(QStringLiteral("le_peso"));
        le_peso->setGeometry(QRect(500, 280, 113, 20));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(530, 110, 71, 16));
        le_infra = new QLineEdit(centralWidget);
        le_infra->setObjectName(QStringLiteral("le_infra"));
        le_infra->setGeometry(QRect(500, 130, 113, 20));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(540, 160, 51, 16));
        le_estadopeso = new QLineEdit(centralWidget);
        le_estadopeso->setObjectName(QStringLiteral("le_estadopeso"));
        le_estadopeso->setGeometry(QRect(500, 180, 113, 20));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(626, 280, 51, 20));
        QFont font2;
        font2.setPointSize(10);
        label_7->setFont(font2);
        pb_setpeso = new QPushButton(centralWidget);
        pb_setpeso->setObjectName(QStringLiteral("pb_setpeso"));
        pb_setpeso->setGeometry(QRect(520, 310, 75, 23));
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 875, 21));
        menuIniciar_Sesion = new QMenu(menuBar);
        menuIniciar_Sesion->setObjectName(QStringLiteral("menuIniciar_Sesion"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuIniciar_Sesion->menuAction());
        menuIniciar_Sesion->addAction(actionIniciar_Sesi_n);
        menuIniciar_Sesion->addAction(actionCerrar_Sesi_n);
        menuIniciar_Sesion->addAction(actionNuevo_Usuario);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionIniciar_Sesi_n->setText(QApplication::translate("MainWindow", "Iniciar Sesi\303\263n", 0));
        actionCerrar_Sesi_n->setText(QApplication::translate("MainWindow", "Cerrar Sesi\303\263n", 0));
        actionNuevo_Usuario->setText(QApplication::translate("MainWindow", "Nuevo Usuario", 0));
        pb_pass->setText(QApplication::translate("MainWindow", " Cambiar Contrase\303\261a", 0));
        pb_alarm->setText(QApplication::translate("MainWindow", " Activar / Desactivar Alarma", 0));
        lb_principal->setText(QApplication::translate("MainWindow", "Sistema de control", 0));
        pb_desac->setText(QApplication::translate("MainWindow", " Activar / Desactivar Sistema", 0));
        lb_date->setText(QString());
        lb_usuario1->setText(QApplication::translate("MainWindow", "Usuario Actual:", 0));
        lb_usuario2->setText(QString());
        pb_browse->setText(QApplication::translate("MainWindow", "Directorio", 0));
        lb_browse->setText(QString());
        groupBox->setTitle(QApplication::translate("MainWindow", "Modo Servidor TCP-IP", 0));
        button_refresh_ports->setText(QApplication::translate("MainWindow", "Actualizar Puertos", 0));
        button_connect->setText(QApplication::translate("MainWindow", "Conectar", 0));
        edit_estado->setPlaceholderText(QString());
        label->setText(QApplication::translate("MainWindow", "Estado", 0));
        label_2->setText(QApplication::translate("MainWindow", "Puerto Serie", 0));
        label_3->setText(QApplication::translate("MainWindow", "Estado Actual", 0));
        label_4->setText(QApplication::translate("MainWindow", "Peso Actual", 0));
        label_5->setText(QApplication::translate("MainWindow", "Infrarrojo", 0));
        label_6->setText(QApplication::translate("MainWindow", "Peso", 0));
        label_7->setText(QApplication::translate("MainWindow", "g", 0));
        pb_setpeso->setText(QApplication::translate("MainWindow", "Set Peso", 0));
        menuIniciar_Sesion->setTitle(QApplication::translate("MainWindow", "Usuario", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
