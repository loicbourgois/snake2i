#include "options-form.h"
#include "ui_options-form.h"

OptionsForm::OptionsForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OptionsForm)
{
    ui->setupUi(this);
}

OptionsForm::~OptionsForm()
{
    delete ui;
}
