#include "main-window.h"
#include "ui_main-window.h"

#include "main-form.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setCentralWidget(new MainForm(this));
}

MainWindow::~MainWindow()
{
    delete ui;
}


