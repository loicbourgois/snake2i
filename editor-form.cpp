#include "editor-form.h"

#include "ui_launch-game-form.h"

#include "main-window.h"
#include "game-form.h"
#include "main-form.h"
#include <QString>
#include <QMouseEvent>
#include "clickablelabel.h"

EditorForm::EditorForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditorForm)
{
    choice = 0;
    ui->setupUi(this);
    view = new View(this,true);
    ui->widgetView->layout()->addWidget(view);
    scene = new SceneEditor(this);
    view->setScene(scene);
    map = new Map();
    loadMap();
    connect(scene,SIGNAL(deleted(double,double)),this,SLOT(onDeleted(double,double)));
    bodyPlaced = false;
    headPlaced = false;
    cursor = new Wall(NULL,0,0);
    cursor->setZValue(9999);
    setMouseTracking(true);

    ClickableLabel * wall = new ClickableLabel("wall");
    QPixmap wallPNG("wall.png");
    wall->setPixmap(wallPNG);
    wall->setMaximumSize(80,80);
    connect(wall,SIGNAL(clicked(QString)),SLOT(onClicked(QString)));
    ui->gridLayout->addWidget(wall);

    ClickableLabel * head = new ClickableLabel("head");
    QPixmap headPNG("head.png");
    head->setPixmap(headPNG);
    head->setMaximumSize(80,80);
    connect(head,SIGNAL(clicked(QString)),SLOT(onClicked(QString)));
    ui->gridLayout->addWidget(head);

    ClickableLabel * blank = new ClickableLabel("blank");
    QPixmap blankPNG("blank.png");
    blank->setPixmap(blankPNG);
    blank->setMaximumSize(80,80);
    connect(blank,SIGNAL(clicked(QString)),SLOT(onClicked(QString)));
    ui->gridLayout->addWidget(blank);

}

EditorForm::~EditorForm()
{
    delete ui;
}

void EditorForm::loadMap()
{
    for(int x = 0 ; x < map->getWidth() ; x++)
    {
        for(int y = 0 ; y < map->getHeight() ; y++)
        {
            if(map->getTile(x, y) == 'w')
            {
                scene->addItem(new Wall(NULL, x, y));
            }
            else if(map->getTile(x, y) == 'h')
            {
                scene->addItem(new Blank(NULL, x, y));
            }
            else if(map->getTile(x, y) == 'b')
            {
                scene->addItem(new Blank(NULL, x, y));
            }
            else if(map->getTile(x, y) == '.')
            {
                scene->addItem(new Blank(NULL, x, y));
            }
        }
    }
    for(int x = 0 ; x < map->getWidth() ; x++)
    {
        for(int y = 0 ; y < map->getHeight() ; y++)
        {
            if(map->getTile(x, y) == 'h')
            {
                this->head = new Head(NULL, x, y);
                scene->addItem(head);
                headPlaced = true;
            }
            else if(map->getTile(x, y) == 'b')
            {
                this->body = new BodyPart(NULL, x, y);
                scene->addItem(body);
                bodyPlaced = true;
            }
        }
    }
}

char EditorForm::guessDirection()
{
    char retour = ' ';
    for(int i = 0 ; i < map->getHeight() ; i++)
        for(int j = 0 ; j < map->getWidth() ;j++)
        {
            if(map->getTile(j,i) == 'h')
            {
                if(map->getTile(j,i+1) == 'b')
                    retour = 'u';
                if(map->getTile(j,i-1) == 'b')
                    retour = 'd';
                if(map->getTile(j+1,i) == 'b')
                    retour = 'l';
                if(map->getTile(j-1,i) == 'b')
                    retour = 'r';
            }
        }
    return retour;
}

void EditorForm::on_buttonLoadMap_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Choisir une carte"), "",tr("Map Files (*.map)"));
    map = new Map(fileName.toStdString());
    loadMap();
}

void EditorForm::on_buttonSaveMap_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),"",
                                                    tr(".map"));
    QFile saveFile(fileName);
    if(saveFile.open(QIODevice::WriteOnly))
    {
        QTextStream stream(&saveFile);
        stream << guessDirection() << "\n";
        stream << map->getWidth() << "\n";
        stream << map->getHeight()<< "\n";
        for (int colonne = 0; colonne < map->getHeight() ; colonne++)
        {
            for(int ligne = 0; ligne < map->getWidth(); ligne++)
            {
                stream << map->getTile(ligne,colonne);
            }
            stream << "\n";
        }
        saveFile.close();
    }
}

void EditorForm::onDeleted(double x, double y)
{
    //BLANK 0
    //WALL 1
    //HEAD 2
    //BODY 3
    QTransform useless;
    switch(choice)
    {
    case 0 :
        if(map->getTile(x/20,y/20) == 'h')
        {
            headPlaced = false;
            QStringList splited = map->getPosition('b').split('|');
            if(splited.size() == 2)
            {
                int i = splited[0].toInt();
                int j = splited[1].toInt();
                //Reparer le splited
                scene->removeItem(scene->itemAt(i*20,j*20,useless));
                scene->addItem(new Blank(NULL,i,j));
                map->setTile('.',i,j);
                bodyPlaced = false;
            }
        }
        if(map->getTile(x/20,y/20) == 'b')
        {
            headPlaced = false;
            QStringList splited = map->getPosition('h').split('|');
            if(splited.size() == 2)
            {
                int i = splited[0].toInt();
                int j = splited[1].toInt();
                //Reparer le splited
                scene->removeItem(scene->itemAt(i*20,j*20,useless));
                scene->addItem(new Blank(NULL,i,j));
                map->setTile('.',i,j);
                bodyPlaced = false;
            }
        }
        map->setTile('.',x/20,y/20);
        if(scene->itemAt(x,y,useless) != 0)
            scene->removeItem(scene->itemAt(x,y,useless));
        scene->addItem(new Blank(NULL,x/20,y/20));
        break;
    case 1 :
        if(map->getTile(x/20,y/20) == 'h')
        {
            headPlaced = false;
            QStringList splited = map->getPosition('b').split('|');
            if(splited.size() == 2)
            {
                int i = splited[0].toInt();
                int j = splited[1].toInt();
                scene->removeItem(scene->itemAt(i*20,j*20,useless));
                scene->addItem(new Blank(NULL,i,j));
                map->setTile('.',i,j);
                bodyPlaced = false;
            }
        }
        if(map->getTile(x/20,y/20) == 'b')
        {
            headPlaced = false;
            QStringList splited = map->getPosition('h').split('|');
            if(splited.size() == 2)
            {
                int i = splited[0].toInt();
                int j = splited[1].toInt();
                scene->removeItem(scene->itemAt(i*20,j*20,useless));
                scene->addItem(new Blank(NULL,i,j));
                map->setTile('.',i,j);
                bodyPlaced = false;
            }
        }
        map->setTile('w',x/20,y/20);
        if(scene->itemAt(x,y,useless) != 0)
            scene->removeItem(scene->itemAt(x,y,useless));
        scene->addItem(new Wall(NULL,x/20,y/20));
        break;
    case 2 :
        if(headPlaced == false && bodyPlaced == false)
        {
            map->setTile('h',x/20,y/20);
            if(scene->itemAt(x,y,useless) != 0)
                scene->removeItem(scene->itemAt(x,y,useless));
            scene->addItem(new Head(NULL,x/20,y/20));
            choice = 3;
            headPlaced = true;
        }
        break;
    case 3 :
        if(bodyPlaced == false && headPlaced == true && map->getTile(x/20,y/20) != 'h')
        {
            QStringList splited = map->getPosition('h').split('|');
            if(splited.size() == 2)
            {
                int i = splited[0].toInt();
                int j = splited[1].toInt();
                if(x/20 == i && y/20 == j+1 ||
                        x/20 == i && y/20 == j-1 ||
                        x/20 == i+1 && y/20 == j ||
                        x/20 == i-1 && y/20 == j)
                {
                    map->setTile('b',x/20,y/20);
                    if(scene->itemAt(x,y,useless) != 0)
                        scene->removeItem(scene->itemAt(x,y,useless));
                    scene->addItem(new BodyPart(NULL,x/20,y/20));
                    scene->removeItem(scene->itemAt(i*20,j*20,useless));
                    Head * head = new Head(NULL,i,j);
                    head->setDirection(guessDirection());
                    scene->addItem(head);
                    bodyPlaced = true;
                    choice = 0;
                }
            }
        }
        break;
    default:
        break;
    }
}

void EditorForm::on_headButton_clicked()
{
    if(choice != 3)
        choice = 2;
}

void EditorForm::on_blankButton_clicked()
{
    if(choice != 3)
        choice = 0;
}

void EditorForm::on_wallButton_clicked()
{
    if(choice != 3)
        choice = 1;
}

void EditorForm::onClicked(QString type)
{
    if(type == "wall")
        if(choice != 3)
            choice = 1;
    if(type == "blank")
        if(choice != 3)
            choice = 0;
    if(type == "head")
        if(choice != 3)
            choice = 2;
}







