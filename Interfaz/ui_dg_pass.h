/********************************************************************************
** Form generated from reading UI file 'dg_pass.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DG_PASS_H
#define UI_DG_PASS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_dg_pass
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLineEdit *lineEdit;
    QCheckBox *cb_pass;

    void setupUi(QDialog *dg_pass)
    {
        if (dg_pass->objectName().isEmpty())
            dg_pass->setObjectName(QStringLiteral("dg_pass"));
        dg_pass->resize(400, 300);
        buttonBox = new QDialogButtonBox(dg_pass);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(dg_pass);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 120, 141, 41));
        lineEdit = new QLineEdit(dg_pass);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(180, 130, 113, 20));
        cb_pass = new QCheckBox(dg_pass);
        cb_pass->setObjectName(QStringLiteral("cb_pass"));
        cb_pass->setGeometry(QRect(320, 130, 70, 17));

        retranslateUi(dg_pass);
        QObject::connect(buttonBox, SIGNAL(accepted()), dg_pass, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), dg_pass, SLOT(reject()));

        QMetaObject::connectSlotsByName(dg_pass);
    } // setupUi

    void retranslateUi(QDialog *dg_pass)
    {
        dg_pass->setWindowTitle(QApplication::translate("dg_pass", "Activar/Desactivar", 0));
        label->setText(QApplication::translate("dg_pass", "Ingrese Contrase\303\261a", 0));
        cb_pass->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class dg_pass: public Ui_dg_pass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DG_PASS_H
