/********************************************************************************
** Form generated from reading UI file 'newlayer.ui'
**
** Created: Wed 4. Feb 14:57:23 2015
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWLAYER_H
#define UI_NEWLAYER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_newLayer
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLineEdit *layerName;
    QComboBox *layerSelect;

    void setupUi(QDialog *newLayer)
    {
        if (newLayer->objectName().isEmpty())
            newLayer->setObjectName(QString::fromUtf8("newLayer"));
        newLayer->resize(400, 300);
        newLayer->setMinimumSize(QSize(400, 300));
        newLayer->setMaximumSize(QSize(400, 300));
        buttonBox = new QDialogButtonBox(newLayer);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(newLayer);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 30, 61, 16));
        layerName = new QLineEdit(newLayer);
        layerName->setObjectName(QString::fromUtf8("layerName"));
        layerName->setGeometry(QRect(40, 50, 113, 20));
        layerSelect = new QComboBox(newLayer);
        layerSelect->setObjectName(QString::fromUtf8("layerSelect"));
        layerSelect->setGeometry(QRect(40, 90, 111, 22));

        retranslateUi(newLayer);
        QObject::connect(buttonBox, SIGNAL(accepted()), newLayer, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), newLayer, SLOT(reject()));

        QMetaObject::connectSlotsByName(newLayer);
    } // setupUi

    void retranslateUi(QDialog *newLayer)
    {
        newLayer->setWindowTitle(QApplication::translate("newLayer", "New Layer", 0 ));
        label->setText(QApplication::translate("newLayer", "Layer name", 0 ));
        layerSelect->clear();
        layerSelect->insertItems(0, QStringList()
         << QApplication::translate("newLayer", "Background", 0 )
         << QApplication::translate("newLayer", "Foreground", 0 )
         << QApplication::translate("newLayer", "Collision", 0 )
         << QApplication::translate("newLayer", "Objects", 0 )
        );
    } // retranslateUi

};

namespace Ui {
    class newLayer: public Ui_newLayer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWLAYER_H
