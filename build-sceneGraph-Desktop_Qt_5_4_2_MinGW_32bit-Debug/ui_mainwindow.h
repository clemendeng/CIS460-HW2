/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>
#include "mygl.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuit;
    QWidget *centralWidget;
    MyGL *mygl;
    QDoubleSpinBox *scale_x;
    QDoubleSpinBox *translate_y;
    QDoubleSpinBox *scale_y;
    QDoubleSpinBox *translate_x;
    QDoubleSpinBox *rotate;
    QPushButton *addSquare;
    QLabel *label_sx;
    QLabel *label_sy;
    QLabel *label_tx;
    QLabel *label_ty;
    QLabel *label_Scale;
    QLabel *label_Rotate;
    QLabel *label_Translate;
    QTreeWidget *treeWidget;
    QPushButton *addScale;
    QPushButton *addRotate;
    QPushButton *addTranslate;
    QMenuBar *menuBar;
    QMenu *menuFile;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(891, 640);
        MainWindow->setIconSize(QSize(50, 30));
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        mygl = new MyGL(centralWidget);
        mygl->setObjectName(QStringLiteral("mygl"));
        mygl->setGeometry(QRect(270, 10, 611, 592));
        scale_x = new QDoubleSpinBox(centralWidget);
        scale_x->setObjectName(QStringLiteral("scale_x"));
        scale_x->setGeometry(QRect(20, 50, 62, 22));
        scale_x->setMinimum(-10);
        scale_x->setMaximum(10);
        scale_x->setSingleStep(0.5);
        translate_y = new QDoubleSpinBox(centralWidget);
        translate_y->setObjectName(QStringLiteral("translate_y"));
        translate_y->setGeometry(QRect(190, 90, 62, 22));
        translate_y->setMinimum(-10);
        translate_y->setMaximum(10);
        translate_y->setSingleStep(0.5);
        scale_y = new QDoubleSpinBox(centralWidget);
        scale_y->setObjectName(QStringLiteral("scale_y"));
        scale_y->setGeometry(QRect(20, 90, 62, 22));
        scale_y->setMinimum(-10);
        scale_y->setMaximum(10);
        scale_y->setSingleStep(0.5);
        translate_x = new QDoubleSpinBox(centralWidget);
        translate_x->setObjectName(QStringLiteral("translate_x"));
        translate_x->setGeometry(QRect(190, 50, 62, 22));
        translate_x->setMinimum(-10);
        translate_x->setMaximum(10);
        translate_x->setSingleStep(0.5);
        rotate = new QDoubleSpinBox(centralWidget);
        rotate->setObjectName(QStringLiteral("rotate"));
        rotate->setGeometry(QRect(100, 70, 62, 22));
        rotate->setMinimum(-360);
        rotate->setMaximum(360);
        rotate->setSingleStep(5);
        addSquare = new QPushButton(centralWidget);
        addSquare->setObjectName(QStringLiteral("addSquare"));
        addSquare->setGeometry(QRect(80, 160, 93, 28));
        label_sx = new QLabel(centralWidget);
        label_sx->setObjectName(QStringLiteral("label_sx"));
        label_sx->setGeometry(QRect(10, 50, 55, 16));
        label_sy = new QLabel(centralWidget);
        label_sy->setObjectName(QStringLiteral("label_sy"));
        label_sy->setGeometry(QRect(10, 90, 55, 16));
        label_tx = new QLabel(centralWidget);
        label_tx->setObjectName(QStringLiteral("label_tx"));
        label_tx->setGeometry(QRect(180, 50, 55, 16));
        label_ty = new QLabel(centralWidget);
        label_ty->setObjectName(QStringLiteral("label_ty"));
        label_ty->setGeometry(QRect(180, 90, 55, 16));
        label_Scale = new QLabel(centralWidget);
        label_Scale->setObjectName(QStringLiteral("label_Scale"));
        label_Scale->setGeometry(QRect(30, 20, 55, 16));
        label_Rotate = new QLabel(centralWidget);
        label_Rotate->setObjectName(QStringLiteral("label_Rotate"));
        label_Rotate->setGeometry(QRect(110, 20, 55, 16));
        label_Translate = new QLabel(centralWidget);
        label_Translate->setObjectName(QStringLiteral("label_Translate"));
        label_Translate->setGeometry(QRect(190, 20, 55, 16));
        treeWidget = new QTreeWidget(centralWidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setGeometry(QRect(10, 200, 251, 401));
        addScale = new QPushButton(centralWidget);
        addScale->setObjectName(QStringLiteral("addScale"));
        addScale->setGeometry(QRect(10, 120, 71, 31));
        addRotate = new QPushButton(centralWidget);
        addRotate->setObjectName(QStringLiteral("addRotate"));
        addRotate->setGeometry(QRect(90, 120, 81, 31));
        addTranslate = new QPushButton(centralWidget);
        addTranslate->setObjectName(QStringLiteral("addTranslate"));
        addTranslate->setGeometry(QRect(180, 120, 91, 31));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 891, 26));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionQuit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Scene Graph", 0));
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", 0));
        actionQuit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0));
        addSquare->setText(QApplication::translate("MainWindow", "Draw Square", 0));
        label_sx->setText(QApplication::translate("MainWindow", "x", 0));
        label_sy->setText(QApplication::translate("MainWindow", "y", 0));
        label_tx->setText(QApplication::translate("MainWindow", "x", 0));
        label_ty->setText(QApplication::translate("MainWindow", "y", 0));
        label_Scale->setText(QApplication::translate("MainWindow", "Scale", 0));
        label_Rotate->setText(QApplication::translate("MainWindow", "Rotate", 0));
        label_Translate->setText(QApplication::translate("MainWindow", "Translate", 0));
        addScale->setText(QApplication::translate("MainWindow", "Add Scale", 0));
        addRotate->setText(QApplication::translate("MainWindow", "Add Rotate", 0));
        addTranslate->setText(QApplication::translate("MainWindow", "Add Translate", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
