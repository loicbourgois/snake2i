#include "options-form.h"
#include "ui_options-form.h"

#include "main-form.h"
#include "main-window.h"

OptionsForm::OptionsForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OptionsForm)
{
    ui->setupUi(this);
    QObject::connect(this->ui->pushButtonPrecedent, SIGNAL(clicked()),
                     this, SLOT(precedent()));
}

OptionsForm::~OptionsForm()
{
    delete ui;
}

void OptionsForm::precedent()
{
    ((MainWindow*)(this->parent()))->setCentralWidget(new MainForm((MainWindow*)(this->parent())));
}
