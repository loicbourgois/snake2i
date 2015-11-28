#include "game-form.h"
#include "ui_game-form.h"

GameForm::GameForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameForm)
{
    ui->setupUi(this);
    view = new View(this);
    ui->widgetView->layout()->addWidget(view);
    scene = new Scene(this);
    view->setScene(scene);
    map = new Map("./square.map");
    for(int x = 0 ; x < map->getWidth() ; x++)
    {
        for(int y = 0 ; y < map->getHeight() ; y++)
        {
            if(map->getTile(x, y) == 'w')
                scene->addItem(new Wall(scene, x, y));
            else if(map->getTile(x, y) == ' ')
                scene->addItem(new Blank(scene, x, y));
        }
    }
}

GameForm::~GameForm()
{
    delete ui;
}
