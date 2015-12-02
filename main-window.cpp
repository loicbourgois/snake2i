#include "main-window.h"
#include "ui_main-window.h"

#include "game-form.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(new GameForm(this));
}

MainWindow::~MainWindow()
{
    delete ui;
}


