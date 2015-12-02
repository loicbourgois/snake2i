#include "instructions-form.h"
#include "ui_instructions-form.h"

#include "instructions-form.h"
#include "game-form.h"
#include"editor-form.h"
#include <QMessageBox>
#include "main-window.h"

InstructionsForm::InstructionsForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InstructionsForm)
{
    ui->setupUi(this);
    QObject::connect(this->ui->pushButtonAbout, SIGNAL(clicked()),
                         this, SLOT(about()));
    QObject::connect(this->ui->pushButtonEditeur, SIGNAL(clicked()),
                         this, SLOT(edit()));
    QObject::connect(this->ui->pushButtonPlay, SIGNAL(clicked()),
                         this, SLOT(play()));
}

InstructionsForm::~InstructionsForm()
{
    delete ui;
}

void InstructionsForm::about()
{
    QMessageBox::about(this, "À propos", "Jeux de snake réalisé par Loïc Bourgois et Maxime Desmarchelier pour le cours d'Interface Homme Machine en seconde année à l'IG2I.");
}

void InstructionsForm::edit()
{
    ((MainWindow*)this->parent())->setCentralWidget(new EditorForm((MainWindow*)this->parent()));
}

void InstructionsForm::play()
{
    ((MainWindow*)this->parent())->setCentralWidget(new GameForm((MainWindow*)this->parent()));
}
