#include "mainwindow.h"
#include <ui_mainwindow.h>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->mygl->setFocus();

    //Root
    connect(ui->mygl, SIGNAL(sendRoot(QTreeWidgetItem*)), this, SLOT(slot_addRoot(QTreeWidgetItem*)));

    //Current node
    connect(ui->treeWidget, SIGNAL(itemClicked(QTreeWidgetItem*,int)), ui->mygl, SLOT(slot_currentNode(QTreeWidgetItem*)));

    //Operations
    connect(ui->rotate, SIGNAL(valueChanged(double)), ui->mygl, SLOT(slot_rotate(double)));
    connect(ui->translate_x, SIGNAL(valueChanged(double)), ui->mygl, SLOT(slot_translate_x(double)));
    connect(ui->translate_y, SIGNAL(valueChanged(double)), ui->mygl, SLOT(slot_translate_y(double)));
    connect(ui->scale_x, SIGNAL(valueChanged(double)), ui->mygl, SLOT(slot_scale_x(double)));
    connect(ui->scale_y, SIGNAL(valueChanged(double)), ui->mygl, SLOT(slot_scale_y(double)));

    //Add square as geometry
    connect(ui->addSquare, SIGNAL(clicked(bool)), ui->mygl, SLOT(slot_addSquare()));

    //Add S/R/T node as child
    connect(ui->addRotate, SIGNAL(clicked(bool)), ui->mygl, SLOT(slot_addRotate()));
    connect(ui->addScale, SIGNAL(clicked(bool)), ui->mygl, SLOT(slot_addScale()));
    connect(ui->addTranslate, SIGNAL(clicked(bool)), ui->mygl, SLOT(slot_addTranslate()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionQuit_triggered()
{
    QApplication::exit();
}

void MainWindow::slot_addRoot(QTreeWidgetItem* r) {
    ui->treeWidget->addTopLevelItem(r);
}
