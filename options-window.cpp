#include "options-window.h"
#include "ui_options-window.h"

optionsWindow::optionsWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::optionsWindow)
{
    ui->setupUi(this);
}

optionsWindow::~optionsWindow()
{
    delete ui;
}
