/********************************************************************************
** Form generated from reading UI file 'dg_sesion.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DG_SESION_H
#define UI_DG_SESION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_dg_sesion
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;

    void setupUi(QDialog *dg_sesion)
    {
        if (dg_sesion->objectName().isEmpty())
            dg_sesion->setObjectName(QStringLiteral("dg_sesion"));
        dg_sesion->resize(400, 300);
        buttonBox = new QDialogButtonBox(dg_sesion);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(dg_sesion);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 90, 71, 41));
        label_2 = new QLabel(dg_sesion);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(60, 150, 61, 21));
        lineEdit = new QLineEdit(dg_sesion);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(170, 100, 113, 20));
        lineEdit_2 = new QLineEdit(dg_sesion);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(170, 150, 113, 20));

        retranslateUi(dg_sesion);
        QObject::connect(buttonBox, SIGNAL(accepted()), dg_sesion, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), dg_sesion, SLOT(reject()));

        QMetaObject::connectSlotsByName(dg_sesion);
    } // setupUi

    void retranslateUi(QDialog *dg_sesion)
    {
        dg_sesion->setWindowTitle(QApplication::translate("dg_sesion", "Usuario", 0));
        label->setText(QApplication::translate("dg_sesion", "Usuario", 0));
        label_2->setText(QApplication::translate("dg_sesion", "Contrase\303\261a", 0));
    } // retranslateUi

};

namespace Ui {
    class dg_sesion: public Ui_dg_sesion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DG_SESION_H
