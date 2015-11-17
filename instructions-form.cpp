#include "instructions-form.h"
#include "ui_instructions-form.h"

InstructionsForm::InstructionsForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InstructionsForm)
{
    ui->setupUi(this);
}

InstructionsForm::~InstructionsForm()
{
    delete ui;
}
