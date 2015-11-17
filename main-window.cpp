#include "main-window.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    optionsForm = new OptionsForm();
    ui->setupUi(this);
    QObject::connect(this->ui->pushButtonOptions, SIGNAL(clicked()),
                         this, SLOT(goToOptions()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::goToOptions()
{
    this->setCentralWidget(optionsForm);
}
