#include "main-form.h"
#include "ui_main-form.h"

#include "main-window.h"
#include "launch-game-form.h"
#include "options-form.h"
#include "instructions-form.h"
#include "editor-form.h"
#include <QMessageBox>
#include <QIcon>

MainForm::MainForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainForm)
{
    ui->setupUi(this);
    QObject::connect(this->ui->pushButtonOptions, SIGNAL(clicked()),
                         this, SLOT(goToOptions()));
    QObject::connect(this->ui->pushButtonPlay, SIGNAL(clicked()),
                         this, SLOT(play()));
    QObject::connect(this->ui->pushButtonEdit, SIGNAL(clicked()),
                         this, SLOT(edit()));
    QObject::connect(this->ui->pushButtonAbout, SIGNAL(clicked()),
                         this, SLOT(about()));
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

void MainForm::about()
{
    QMessageBox::about(this, "À propos", "Jeux de snake réalisé par Loïc Bourgois et Maxime Desmarchelier pour le cours d'Interface Homme Machine en seconde année à l'IG2I.");
}
