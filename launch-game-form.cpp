#include "launch-game-form.h"
#include "ui_launch-game-form.h"

#include "main-window.h"
#include "game-form.h"

LaunchGameForm::LaunchGameForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LaunchGameForm)
{
    ui->setupUi(this);
    QObject::connect(this->ui->pushButtonPlay, SIGNAL(clicked()),
                         this, SLOT(launchGame()));
}

LaunchGameForm::~LaunchGameForm()
{
    delete ui;
}

void LaunchGameForm::launchGame()
{
    ((MainWindow*)(this->parent()))->setCentralWidget(new GameForm((MainWindow*)(this->parent())));
}
