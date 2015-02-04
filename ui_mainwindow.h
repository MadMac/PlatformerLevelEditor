/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Wed 4. Feb 14:57:23 2015
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionRun;
    QAction *actionNew;
    QAction *actionSave;
    QAction *actionLoad;
    QAction *actionExit;
    QAction *actionLevel;
    QAction *actionAddObject;
    QAction *actionMoveObject;
    QAction *actionPen;
    QAction *actionActionSelectObject;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_9;
    QTreeWidget *layers;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *addLayerButton;
    QPushButton *deleteLayerButton;
    QListView *listView;
    QPushButton *addAttributeButton;
    QVBoxLayout *verticalLayout_8;
    QScrollArea *mapEditor;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_2;
    QTabWidget *tilesetTab;
    QWidget *tab;
    QGridLayout *gridLayout;
    QScrollArea *tileScrollArea;
    QWidget *scrollAreaWidgetContents_3;
    QWidget *tab_2;
    QGridLayout *gridLayout_3;
    QScrollArea *objectScrollArea;
    QWidget *scrollAreaWidgetContents_2;
    QToolBar *toolBar;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuTools;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->resize(1124, 622);
        MainWindow->setUnifiedTitleAndToolBarOnMac(false);
        actionRun = new QAction(MainWindow);
        actionRun->setObjectName(QString::fromUtf8("actionRun"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../PlatformerLevelEditor-build-desktop-Qt_4_7_3_for_Desktop_-_MinGW_4_4__Qt_SDK__Debug/icons/run.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRun->setIcon(icon);
        actionRun->setIconVisibleInMenu(true);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../PlatformerLevelEditor-build-desktop-Qt_4_7_3_for_Desktop_-_MinGW_4_4__Qt_SDK__Debug/icons/newMap.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew->setIcon(icon1);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("../PlatformerLevelEditor-build-desktop-Qt_4_7_3_for_Desktop_-_MinGW_4_4__Qt_SDK__Debug/icons/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon2);
        actionLoad = new QAction(MainWindow);
        actionLoad->setObjectName(QString::fromUtf8("actionLoad"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("../PlatformerLevelEditor-build-desktop-Qt_4_7_3_for_Desktop_-_MinGW_4_4__Qt_SDK__Debug/icons/load.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLoad->setIcon(icon3);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionLevel = new QAction(MainWindow);
        actionLevel->setObjectName(QString::fromUtf8("actionLevel"));
        actionAddObject = new QAction(MainWindow);
        actionAddObject->setObjectName(QString::fromUtf8("actionAddObject"));
        actionMoveObject = new QAction(MainWindow);
        actionMoveObject->setObjectName(QString::fromUtf8("actionMoveObject"));
        actionPen = new QAction(MainWindow);
        actionPen->setObjectName(QString::fromUtf8("actionPen"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("../PlatformerLevelEditor-build-desktop-Qt_4_7_3_for_Desktop_-_MinGW_4_4__Qt_SDK__Debug/icons/pen.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPen->setIcon(icon4);
        actionActionSelectObject = new QAction(MainWindow);
        actionActionSelectObject->setObjectName(QString::fromUtf8("actionActionSelectObject"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        centralWidget->setMinimumSize(QSize(1057, 0));
        centralWidget->setLayoutDirection(Qt::LeftToRight);
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalLayout_9->setSizeConstraint(QLayout::SetDefaultConstraint);
        layers = new QTreeWidget(centralWidget);
        new QTreeWidgetItem(layers);
        new QTreeWidgetItem(layers);
        new QTreeWidgetItem(layers);
        new QTreeWidgetItem(layers);
        layers->setObjectName(QString::fromUtf8("layers"));
        layers->setMaximumSize(QSize(250, 16777215));
        layers->setContextMenuPolicy(Qt::DefaultContextMenu);
        layers->setTabKeyNavigation(false);
        layers->setDefaultDropAction(Qt::IgnoreAction);
        layers->setSelectionMode(QAbstractItemView::SingleSelection);
        layers->setSelectionBehavior(QAbstractItemView::SelectRows);
        layers->setUniformRowHeights(false);
        layers->setWordWrap(false);
        layers->setHeaderHidden(false);

        verticalLayout_9->addWidget(layers);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        addLayerButton = new QPushButton(centralWidget);
        addLayerButton->setObjectName(QString::fromUtf8("addLayerButton"));

        horizontalLayout_3->addWidget(addLayerButton);

        deleteLayerButton = new QPushButton(centralWidget);
        deleteLayerButton->setObjectName(QString::fromUtf8("deleteLayerButton"));

        horizontalLayout_3->addWidget(deleteLayerButton);


        verticalLayout_9->addLayout(horizontalLayout_3);

        listView = new QListView(centralWidget);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setMaximumSize(QSize(250, 16777215));

        verticalLayout_9->addWidget(listView);

        addAttributeButton = new QPushButton(centralWidget);
        addAttributeButton->setObjectName(QString::fromUtf8("addAttributeButton"));

        verticalLayout_9->addWidget(addAttributeButton);


        horizontalLayout_2->addLayout(verticalLayout_9);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        mapEditor = new QScrollArea(centralWidget);
        mapEditor->setObjectName(QString::fromUtf8("mapEditor"));
        mapEditor->setMinimumSize(QSize(1, 1));
        mapEditor->setSizeIncrement(QSize(0, 0));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(42, 96, 138, 100));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        mapEditor->setPalette(palette);
        mapEditor->setFrameShadow(QFrame::Sunken);
        mapEditor->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        mapEditor->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        mapEditor->setWidgetResizable(true);
        mapEditor->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 546, 279));
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        mapEditor->setWidget(scrollAreaWidgetContents);

        verticalLayout_8->addWidget(mapEditor);

        tilesetTab = new QTabWidget(centralWidget);
        tilesetTab->setObjectName(QString::fromUtf8("tilesetTab"));
        tilesetTab->setMaximumSize(QSize(16777215, 260));
        tilesetTab->setContextMenuPolicy(Qt::DefaultContextMenu);
        tilesetTab->setAutoFillBackground(false);
        tilesetTab->setStyleSheet(QString::fromUtf8(""));
        tilesetTab->setTabPosition(QTabWidget::North);
        tilesetTab->setTabShape(QTabWidget::Rounded);
        tilesetTab->setElideMode(Qt::ElideNone);
        tilesetTab->setDocumentMode(false);
        tilesetTab->setTabsClosable(false);
        tilesetTab->setMovable(false);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout = new QGridLayout(tab);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tileScrollArea = new QScrollArea(tab);
        tileScrollArea->setObjectName(QString::fromUtf8("tileScrollArea"));
        tileScrollArea->setMaximumSize(QSize(16777215, 250));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush2(QColor(74, 99, 125, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        tileScrollArea->setPalette(palette1);
        tileScrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 522, 214));
        tileScrollArea->setWidget(scrollAreaWidgetContents_3);

        gridLayout->addWidget(tileScrollArea, 0, 0, 1, 1);

        tilesetTab->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout_3 = new QGridLayout(tab_2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        objectScrollArea = new QScrollArea(tab_2);
        objectScrollArea->setObjectName(QString::fromUtf8("objectScrollArea"));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::Base, brush);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        objectScrollArea->setPalette(palette2);
        objectScrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 522, 214));
        objectScrollArea->setWidget(scrollAreaWidgetContents_2);

        gridLayout_3->addWidget(objectScrollArea, 0, 0, 1, 1);

        tilesetTab->addTab(tab_2, QString());

        verticalLayout_8->addWidget(tilesetTab);


        horizontalLayout_2->addLayout(verticalLayout_8);

        MainWindow->setCentralWidget(centralWidget);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setMovable(false);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1124, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuTools = new QMenu(menuBar);
        menuTools->setObjectName(QString::fromUtf8("menuTools"));
        MainWindow->setMenuBar(menuBar);

        toolBar->addAction(actionNew);
        toolBar->addSeparator();
        toolBar->addAction(actionSave);
        toolBar->addAction(actionLoad);
        toolBar->addSeparator();
        toolBar->addAction(actionRun);
        toolBar->addSeparator();
        toolBar->addAction(actionPen);
        toolBar->addAction(actionAddObject);
        toolBar->addAction(actionMoveObject);
        toolBar->addAction(actionActionSelectObject);
        toolBar->addSeparator();
        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuTools->menuAction());
        menuFile->addAction(actionExit);
        menuTools->addAction(actionLevel);

        retranslateUi(MainWindow);

        tilesetTab->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Level Editor", 0));
        actionRun->setText(QApplication::translate("MainWindow", "run", 0));
        actionRun->setShortcut(QApplication::translate("MainWindow", "F5", 0));
        actionNew->setText(QApplication::translate("MainWindow", "new", 0));
#ifndef QT_NO_TOOLTIP
        actionNew->setToolTip(QApplication::translate("MainWindow", "New Map", 0 ));
#endif // QT_NO_TOOLTIP
        actionSave->setText(QApplication::translate("MainWindow", "save", 0 ));
#ifndef QT_NO_TOOLTIP
        actionSave->setToolTip(QApplication::translate("MainWindow", "Save", 0 ));
#endif // QT_NO_TOOLTIP
        actionSave->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0 ));
        actionLoad->setText(QApplication::translate("MainWindow", "Load", 0 ));
#ifndef QT_NO_TOOLTIP
        actionLoad->setToolTip(QApplication::translate("MainWindow", "Load", 0 ));
#endif // QT_NO_TOOLTIP
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0 ));
        actionLevel->setText(QApplication::translate("MainWindow", "Level", 0 ));
        actionAddObject->setText(QApplication::translate("MainWindow", "AddObject", 0 ));
        actionMoveObject->setText(QApplication::translate("MainWindow", "moveObject", 0 ));
        actionPen->setText(QApplication::translate("MainWindow", "Pen", 0 ));
        actionActionSelectObject->setText(QApplication::translate("MainWindow", "selectObject", 0 ));
        QTreeWidgetItem *___qtreewidgetitem = layers->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("MainWindow", "Layers", 0 ));

        const bool __sortingEnabled = layers->isSortingEnabled();
        layers->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = layers->topLevelItem(0);
        ___qtreewidgetitem1->setText(0, QApplication::translate("MainWindow", "Background", 0 ));
        QTreeWidgetItem *___qtreewidgetitem2 = layers->topLevelItem(1);
        ___qtreewidgetitem2->setText(0, QApplication::translate("MainWindow", "Foreground", 0 ));
        QTreeWidgetItem *___qtreewidgetitem3 = layers->topLevelItem(2);
        ___qtreewidgetitem3->setText(0, QApplication::translate("MainWindow", "Collision", 0 ));
        QTreeWidgetItem *___qtreewidgetitem4 = layers->topLevelItem(3);
        ___qtreewidgetitem4->setText(0, QApplication::translate("MainWindow", "Objects", 0 ));
        layers->setSortingEnabled(__sortingEnabled);

        addLayerButton->setText(QApplication::translate("MainWindow", "Add Layer", 0 ));
        deleteLayerButton->setText(QApplication::translate("MainWindow", "Delete Layer", 0 ));
        addAttributeButton->setText(QApplication::translate("MainWindow", "Add Attribute", 0 ));
        tilesetTab->setTabText(tilesetTab->indexOf(tab), QApplication::translate("MainWindow", "Tab 1", 0 ));
        tilesetTab->setTabText(tilesetTab->indexOf(tab_2), QApplication::translate("MainWindow", "Page", 0 ));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0 ));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0 ));
        menuTools->setTitle(QApplication::translate("MainWindow", "Tools", 0 ));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
