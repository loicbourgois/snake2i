#include "game-form.h"
#include "ui_game-form.h"

GameForm::GameForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameForm)
{
    ui->setupUi(this);
}

GameForm::~GameForm()
{
    delete ui;
}
