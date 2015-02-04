/********************************************************************************
** Form generated from reading UI file 'addattribute.ui'
**
** Created: Wed 4. Feb 14:57:24 2015
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDATTRIBUTE_H
#define UI_ADDATTRIBUTE_H

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

class Ui_addAttribute
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLineEdit *lineEdit_2;

    void setupUi(QDialog *addAttribute)
    {
        if (addAttribute->objectName().isEmpty())
            addAttribute->setObjectName(QString::fromUtf8("addAttribute"));
        addAttribute->resize(305, 196);
        buttonBox = new QDialogButtonBox(addAttribute);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 150, 221, 41));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(addAttribute);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 20, 46, 13));
        lineEdit = new QLineEdit(addAttribute);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(50, 40, 161, 20));
        label_2 = new QLabel(addAttribute);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 90, 46, 13));
        lineEdit_2 = new QLineEdit(addAttribute);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(50, 110, 161, 20));

        retranslateUi(addAttribute);
        QObject::connect(buttonBox, SIGNAL(accepted()), addAttribute, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), addAttribute, SLOT(reject()));

        QMetaObject::connectSlotsByName(addAttribute);
    } // setupUi

    void retranslateUi(QDialog *addAttribute)
    {
        addAttribute->setWindowTitle(QApplication::translate("addAttribute", "New Attribute", 0 ));
        label->setText(QApplication::translate("addAttribute", "Name", 0 ));
        label_2->setText(QApplication::translate("addAttribute", "Value", 0 ));
    } // retranslateUi

};

namespace Ui {
    class addAttribute: public Ui_addAttribute {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDATTRIBUTE_H
