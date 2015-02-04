/********************************************************************************
** Form generated from reading UI file 'deletelayer.ui'
**
** Created: Wed 4. Feb 14:57:24 2015
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETELAYER_H
#define UI_DELETELAYER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_deletelayer
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;

    void setupUi(QDialog *deletelayer)
    {
        if (deletelayer->objectName().isEmpty())
            deletelayer->setObjectName(QString::fromUtf8("deletelayer"));
        deletelayer->resize(401, 122);
        buttonBox = new QDialogButtonBox(deletelayer);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(40, 80, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(deletelayer);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 311, 16));

        retranslateUi(deletelayer);
        QObject::connect(buttonBox, SIGNAL(accepted()), deletelayer, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), deletelayer, SLOT(reject()));

        QMetaObject::connectSlotsByName(deletelayer);
    } // setupUi

    void retranslateUi(QDialog *deletelayer)
    {
        deletelayer->setWindowTitle(QApplication::translate("deletelayer", "Dialog", 0 ));
        label->setText(QApplication::translate("deletelayer", "Are you sure you want to remove this layer?", 0 ));
    } // retranslateUi

};

namespace Ui {
    class deletelayer: public Ui_deletelayer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETELAYER_H
