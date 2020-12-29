/********************************************************************************
** Form generated from reading UI file 'dg_change.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DG_CHANGE_H
#define UI_DG_CHANGE_H

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

class Ui_dg_change
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QCheckBox *checkBox;

    void setupUi(QDialog *dg_change)
    {
        if (dg_change->objectName().isEmpty())
            dg_change->setObjectName(QStringLiteral("dg_change"));
        dg_change->resize(400, 300);
        buttonBox = new QDialogButtonBox(dg_change);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(dg_change);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 50, 150, 50));
        label_2 = new QLabel(dg_change);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 110, 150, 50));
        label_3 = new QLabel(dg_change);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 170, 150, 50));
        lineEdit = new QLineEdit(dg_change);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(200, 65, 113, 20));
        lineEdit_2 = new QLineEdit(dg_change);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(200, 125, 113, 20));
        lineEdit_3 = new QLineEdit(dg_change);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(200, 185, 113, 20));
        checkBox = new QCheckBox(dg_change);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(340, 65, 70, 17));

        retranslateUi(dg_change);
        QObject::connect(buttonBox, SIGNAL(accepted()), dg_change, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), dg_change, SLOT(reject()));

        QMetaObject::connectSlotsByName(dg_change);
    } // setupUi

    void retranslateUi(QDialog *dg_change)
    {
        dg_change->setWindowTitle(QApplication::translate("dg_change", "Cambio de Contrase\303\261a", 0));
        label->setText(QApplication::translate("dg_change", "Ingrese Contrase\303\261a Actual", 0));
        label_2->setText(QApplication::translate("dg_change", "Ingrese Contrase\303\261a Nueva", 0));
        label_3->setText(QApplication::translate("dg_change", "Reingrese Contrase\303\261a Nueva", 0));
        checkBox->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class dg_change: public Ui_dg_change {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DG_CHANGE_H
