#include "game-form.h"
#include "ui_game-form.h"
#include "launch-game-form.h"
#include "main-window.h"
#include "util.h"
#include <QKeyEvent>
#include <QTimer>

#include <QDebug>

GameForm::GameForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameForm)
{
    ui->setupUi(this);

    QObject::connect(this->ui->pushButtonPrecedent, SIGNAL(clicked()),
                     this, SLOT(precedent()));

    QObject::connect(this->ui->pushButtonGo, SIGNAL(clicked()),
                     this, SLOT(go()));

    view = new View(this);
    ui->widgetView->layout()->addWidget(view);
    scene = new Scene(this);
    view->setScene(scene);
    map = new Map("./square.map");
    snake =Snake(scene);
    snake.setDirection(map->getDirection());
    for(int x = 0 ; x < map->getWidth() ; x++)
    {
        for(int y = 0 ; y < map->getHeight() ; y++)
        {
            if(map->getTile(x, y) == 'w')
            {
                scene->addItem(new Wall(scene, x, y));
            }
            else if(map->getTile(x, y) == 'h')
            {
                scene->addItem(new Blank(scene, x, y));
            }
            else if(map->getTile(x, y) == 'b')
            {
                scene->addItem(new Blank(scene, x, y));
            }
            else if(map->getTile(x, y) == ' ')
            {
                scene->addItem(new Blank(scene, x, y));
            }
        }
    }
    for(int x = 0 ; x < map->getWidth() ; x++)
    {
        for(int y = 0 ; y < map->getHeight() ; y++)
        {
            if(map->getTile(x, y) == 'h')
            {
                snake.addHead(x, y);
            }
            else if(map->getTile(x, y) == 'b')
            {
                snake.addBodyPart(x, y);
            }
        }
    }
    food = new Food(scene, 0,0);
    scene->addItem(food);
    popFood();
}

GameForm::~GameForm()
{
    delete ui;
}

void GameForm::precedent()
{
    ((MainWindow*)(this->parent()))->setCentralWidget(new LaunchGameForm((MainWindow*)(this->parent())));
}

void GameForm::advance()
{
    this->snake.move(*map);
    if(snake.getHead()->pos().x() == food->pos().x()
            && snake.getHead()->pos().y() == food->pos().y())
    {
        popFood();
        snake.addBodyPart(10,10);
    }
    scene->advance();
}

void GameForm::go()
{
    setFocus();
    QTimer * timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(advance()));
    timer->start(200);
}

void GameForm::popFood()
{
    int step = 20;
    int x = Util::getRandomInt(0, map->getWidth()-1);
    int y = Util::getRandomInt(0, map->getHeight()-1);
    while(map->getTile(x, y) == 'w')
    {
        x = Util::getRandomInt(0, map->getWidth()-1);
        y = Util::getRandomInt(0, map->getHeight()-1);
    }
    x *= step;
    y *= step;
    food->setPos(x, y);
}

void GameForm::keyPressEvent(QKeyEvent * event){
    if (event->key()==Qt::Key_Z)
    {
        snake.setDirection('u');
    }
    else if (event->key()==Qt::Key_S)
    {
        snake.setDirection('d');
    }
    else if (event->key()==Qt::Key_Q)
    {
        snake.setDirection('l');
    }
    else if (event->key()==Qt::Key_D)
    {
        snake.setDirection('r');
    }
}

void GameForm::mousePressEvent ( QMouseEvent * event ){
    setFocus();
}
