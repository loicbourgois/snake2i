#include "editor-form.h"
#include "ui_editor-form.h"

EditorForm::EditorForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditorForm)
{
    ui->setupUi(this);
}

EditorForm::~EditorForm()
{
    delete ui;
}
