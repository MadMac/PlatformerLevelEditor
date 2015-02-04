/********************************************************************************
** Form generated from reading UI file 'newmap.ui'
**
** Created: Wed 4. Feb 14:57:23 2015
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWMAP_H
#define UI_NEWMAP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_newMap
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *lineEdit;
    QLabel *label;
    QLabel *label_3;
    QLineEdit *tilesetPathText;
    QPushButton *loadTileset;
    QLabel *label_4;
    QLineEdit *lWidth;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *lHeight;
    QLabel *label_2;
    QLineEdit *objectsPathText;
    QPushButton *loadObjects;

    void setupUi(QDialog *newMap)
    {
        if (newMap->objectName().isEmpty())
            newMap->setObjectName(QString::fromUtf8("newMap"));
        newMap->resize(425, 305);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(newMap->sizePolicy().hasHeightForWidth());
        newMap->setSizePolicy(sizePolicy);
        newMap->setSizeGripEnabled(false);
        buttonBox = new QDialogButtonBox(newMap);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        lineEdit = new QLineEdit(newMap);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(30, 40, 251, 20));
        label = new QLabel(newMap);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 20, 61, 16));
        label_3 = new QLabel(newMap);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 70, 46, 13));
        tilesetPathText = new QLineEdit(newMap);
        tilesetPathText->setObjectName(QString::fromUtf8("tilesetPathText"));
        tilesetPathText->setGeometry(QRect(30, 90, 251, 20));
        loadTileset = new QPushButton(newMap);
        loadTileset->setObjectName(QString::fromUtf8("loadTileset"));
        loadTileset->setGeometry(QRect(290, 90, 31, 23));
        label_4 = new QLabel(newMap);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(30, 170, 46, 13));
        lWidth = new QLineEdit(newMap);
        lWidth->setObjectName(QString::fromUtf8("lWidth"));
        lWidth->setGeometry(QRect(70, 190, 51, 20));
        label_5 = new QLabel(newMap);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(30, 190, 31, 16));
        label_6 = new QLabel(newMap);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(140, 190, 46, 13));
        lHeight = new QLineEdit(newMap);
        lHeight->setObjectName(QString::fromUtf8("lHeight"));
        lHeight->setGeometry(QRect(200, 190, 51, 20));
        label_2 = new QLabel(newMap);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 120, 46, 13));
        objectsPathText = new QLineEdit(newMap);
        objectsPathText->setObjectName(QString::fromUtf8("objectsPathText"));
        objectsPathText->setGeometry(QRect(30, 140, 251, 20));
        loadObjects = new QPushButton(newMap);
        loadObjects->setObjectName(QString::fromUtf8("loadObjects"));
        loadObjects->setGeometry(QRect(290, 140, 31, 23));

        retranslateUi(newMap);
        QObject::connect(buttonBox, SIGNAL(accepted()), newMap, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), newMap, SLOT(reject()));

        QMetaObject::connectSlotsByName(newMap);
    } // setupUi

    void retranslateUi(QDialog *newMap)
    {
        newMap->setWindowTitle(QApplication::translate("newMap", "New level", 0 ));
        lineEdit->setText(QApplication::translate("newMap", "Name", 0 ));
        label->setText(QApplication::translate("newMap", "Level name", 0 ));
        label_3->setText(QApplication::translate("newMap", "Tileset", 0 ));
        loadTileset->setText(QApplication::translate("newMap", "...", 0 ));
        label_4->setText(QApplication::translate("newMap", "Size", 0 ));
        label_5->setText(QApplication::translate("newMap", "Width", 0 ));
        label_6->setText(QApplication::translate("newMap", "Height", 0 ));
        label_2->setText(QApplication::translate("newMap", "Objects", 0 ));
        loadObjects->setText(QApplication::translate("newMap", "...", 0 ));
    } // retranslateUi

};

namespace Ui {
    class newMap: public Ui_newMap {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWMAP_H
