#include "options-form.h"
#include "ui_options-form.h"

optionsForm::optionsForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::optionsForm)
{
    ui->setupUi(this);
}

optionsForm::~optionsForm()
{
    delete ui;
}
