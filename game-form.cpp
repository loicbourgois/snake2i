#include "game-form.h"
#include "ui_game-form.h"
#include "launch-game-form.h"
#include "main-window.h"
#include "util.h"
#include "main-form.h"
#include <QKeyEvent>
#include <QTimer>
#include <QFileDialog>
#include <QDebug>
#include <QMessageBox>
#include "editor-form.h"
#include "instructions-form.h"

GameForm::GameForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameForm),
    score(0)
{
    ui->setupUi(this);
    ui->pushButtonPause->hide();
    ui->pushButtonReprendre->hide();
    ui->pushButtonRestart->hide();
    ui->labelDead->hide();

    QObject::connect(this->ui->pushButtonGo, SIGNAL(clicked()),
                     this, SLOT(go()));
    QObject::connect(this->ui->pushButtonPause, SIGNAL(clicked()),
                     this, SLOT(pause()));
    QObject::connect(this->ui->pushButtonReprendre, SIGNAL(clicked()),
                     this, SLOT(reprendre()));
    QObject::connect(this->ui->pushButtonRestart, SIGNAL(clicked()),
                     this, SLOT(restart()));
    QObject::connect(this->ui->pushButtonMinus, SIGNAL(clicked()),
                     this, SLOT(zoomLess()));
    QObject::connect(this->ui->pushButtonPlus, SIGNAL(clicked()),
                     this, SLOT(zoomMore()));
    QObject::connect(this->ui->pushButtonLoadLevel, SIGNAL(clicked()),
                     this, SLOT(loadLevel()));
    QObject::connect(this->ui->pushButtonAbout, SIGNAL(clicked()),
                         this, SLOT(about()));
    QObject::connect(this->ui->pushButtonEditor, SIGNAL(clicked()),
                         this, SLOT(edit()));
    QObject::connect(this->ui->pushButtonInstructions, SIGNAL(clicked()),
                         this, SLOT(instructions()));

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(advance()));
    timer->setInterval(1000 / ui->horizontalSliderDifficulty->value());
    QObject::connect(this->ui->horizontalSliderDifficulty, SIGNAL(valueChanged(int)),
                     this, SLOT(updateDifficulty(int)));

    view = new View(this);
    ui->widgetView->layout()->addWidget(view);
    scene = new Scene(this);
    view->setScene(scene);
    food = new Food(scene, 0,0);
    scene->addItem(food);
    //
    loadLevel("./default.map");
}

GameForm::~GameForm()
{
    delete ui;
}

void GameForm::precedent()
{
    ((MainWindow*)(this->parent()))->setCentralWidget(new MainForm((MainWindow*)(this->parent())));
}

void GameForm::advance()
{
    this->snake.move(*map);
    if(snake.getHead()->pos().x() == food->pos().x()
            && snake.getHead()->pos().y() == food->pos().y())
    {
        popFood();
        score++;
        ui->labelScore->setText(QString::number(score));
        snake.addBodyPart(0,0);
    }
    scene->advance();
    if(!snake.isAlive())
    {
        this->pause();
        ui->pushButtonReprendre->hide();
        ui->labelDead->show();
    }
}

void GameForm::go()
{
    setFocus();
    timer->start();
    ui->pushButtonGo->hide();
    ui->pushButtonPause->show();
    ui->pushButtonRestart->show();
    ui->labelDead->hide();
}

void GameForm::pause()
{
    if(timer->isActive())
    {
        timer->stop();
        ui->pushButtonGo->hide();
        ui->pushButtonPause->hide();
        ui->pushButtonReprendre->show();
        ui->pushButtonRestart->show();
        ui->labelDead->hide();
    }
}

void GameForm::reprendre()
{
    timer->start();
    ui->pushButtonGo->hide();
    ui->pushButtonPause->show();
    ui->pushButtonReprendre->hide();
    ui->pushButtonRestart->show();
    ui->labelDead->hide();
}

void GameForm::restart()
{
    timer->stop();
    ui->pushButtonGo->show();
    ui->pushButtonPause->hide();
    ui->pushButtonReprendre->hide();
    ui->pushButtonRestart->hide();
    ui->labelDead->hide();
    initSnake();
    popFood();
    score = 0;
    this->ui->labelScore->setText(QString::number(score));
}

void GameForm::updateDifficulty(int diff)
{
    this->timer->setInterval(1000 / diff);
}

void GameForm::zoomMore()
{
    this->view->scale(1.25, 1.25);
}

void GameForm::zoomLess()
{
    this->view->scale(0.8, 0.8);
}

void GameForm::loadLevel(QString level)
{
    pause();
    if(level == "")
    {
        level = QFileDialog::getOpenFileName(this,
                                             "Choisir une carte", "","Map Files (*.map)");
    }
    if(level != "")
    {
        map = new Map(level.toStdString());
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
                else if(map->getTile(x, y) == '.')
                {
                    scene->addItem(new Blank(scene, x, y));
                }
            }
        }
        restart();
    }
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

void GameForm::initSnake()
{
    snake.remove();
    snake = Snake(scene);
    snake.setDirection(map->getDirection());
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
}

void GameForm::keyPressEvent(QKeyEvent * event){
    if(snake.isAlive())
    {
        if (event->key()==Qt::Key_Z || event->key()==Qt::Key_Up)
        {
            if(snake.getDirection() != 'd')
                snake.setDirection('u');
        }
        else if (event->key()==Qt::Key_S || event->key()==Qt::Key_Down)
        {
            if(snake.getDirection() != 'u')
                snake.setDirection('d');
        }
        else if (event->key()==Qt::Key_Q || event->key()==Qt::Key_Left)
        {
            if(snake.getDirection() != 'r')
                snake.setDirection('l');
        }
        else if (event->key()==Qt::Key_D || event->key()==Qt::Key_Right)
        {
            if(snake.getDirection() != 'l')
                snake.setDirection('r');
        }
    }
    if (event->key()==Qt::Key_R)
    {
        restart();
    }
    else if (event->key()==Qt::Key_P || event->key()==Qt::Key_Space || event->key()==Qt::Key_Enter)
    {
        if(timer->isActive())
        {
            pause();
        }
        else if(snake.isAlive())
        {
            reprendre();
        }
    }
}

void GameForm::mousePressEvent ( QMouseEvent * event ){
    setFocus();
}

void GameForm::about()
{
    QMessageBox::about(this, "À propos", "Jeux de snake réalisé par Loïc Bourgois et Maxime Desmarchelier pour le cours d'Interface Homme Machine en seconde année à l'IG2I.");
}

void GameForm::edit()
{
    ((MainWindow*)this->parent())->setCentralWidget(new EditorForm((MainWindow*)this->parent()));
}

void GameForm::instructions()
{
    ((MainWindow*)this->parent())->setCentralWidget(new InstructionsForm((MainWindow*)this->parent()));
}
