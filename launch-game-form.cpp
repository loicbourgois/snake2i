#include "launch-game-form.h"
#include "ui_launch-game-form.h"

#include "main-window.h"
#include "game-form.h"
#include "main-form.h"

LaunchGameForm::LaunchGameForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LaunchGameForm)
{
    ui->setupUi(this);
    QObject::connect(this->ui->pushButtonPlay, SIGNAL(clicked()),
                         this, SLOT(launchGame()));
    QObject::connect(this->ui->pushButtonPrecedent, SIGNAL(clicked()),
                     this, SLOT(precedent()));
}

LaunchGameForm::~LaunchGameForm()
{
    delete ui;
}

void LaunchGameForm::launchGame()
{
    /*((MainWindow*)(this->parent()))->setCentralWidget(
                new GameForm((MainWindow*)(this->parent()), ui->horizontalSliderDificulty->value()));*/
}

void LaunchGameForm::precedent()
{
    ((MainWindow*)(this->parent()))->setCentralWidget(new MainForm((MainWindow*)(this->parent())));
}
