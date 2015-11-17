#include "main-form.h"
#include "ui_main-form.h"

#include "main-window.h"
#include "launch-game-form.h"
#include "options-form.h"
#include "instructions-form.h"
#include "editor-form.h"

MainForm::MainForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainForm)
{
    ui->setupUi(this);
    QObject::connect(this->ui->pushButtonOptions, SIGNAL(clicked()),
                         this, SLOT(goToOptions()));
    QObject::connect(this->ui->pushButtonPlay, SIGNAL(clicked()),
                         this, SLOT(play()));
}

MainForm::~MainForm()
{
    delete ui;
}

void MainForm::goToOptions()
{
   ((MainWindow*)this->parent())->setCentralWidget(new OptionsForm((MainWindow*)this->parent()));
}

void MainForm::play()
{
    ((MainWindow*)this->parent())->setCentralWidget(new LaunchGameForm((MainWindow*)this->parent()));
}

void MainForm::instructions()
{
   ((MainWindow*)this->parent())->setCentralWidget(new InstructionsForm((MainWindow*)this->parent()));
}

void MainForm::edit()
{
    ((MainWindow*)this->parent())->setCentralWidget(new EditorForm((MainWindow*)this->parent()));
}
