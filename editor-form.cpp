#include "editor-form.h"
#include "ui_editor-form.h"
#include <QDebug>
#include "bodypart.h"
EditorForm::EditorForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditorForm)
{
    choice = 0;
    ui->setupUi(this);
    view = new View(this);
    ui->widgetView->layout()->addWidget(view);
    scene = new SceneEditor(this);
    view->setScene(scene);
    map = new Map();
    loadMap();
    connect(scene,SIGNAL(deleted(double,double)),this,SLOT(onDeleted(double,double)));
    bodyPlaced = false;
    headPlaced = false;
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

void EditorForm::on_buttonLoadMap_clicked()
{
    //map = new Map("./square.map");
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Choisir une carte"), "",tr("Map Files (*.map)"));
    map = new Map(fileName.toStdString());
    loadMap();
}
//TODO recuperer la tête et trouver son corps pour en déduire la direction
void EditorForm::on_buttonSaveMap_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),"",
                                                    tr(".map"));
    QFile saveFile(fileName);
    if(saveFile.open(QIODevice::WriteOnly))
    {
        QTextStream stream(&saveFile);
        stream << "u\n"; //Direction au hasard pour l'instant
        stream << map->getWidth();
        stream << map->getHeight();
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
            bodyPlaced = false;
            if(map->getTile(x/20,(y/20)-1) == 'b')
                scene->removeItem(scene->itemAt(x,y-20,useless));
            if( map->getTile(x/20,(y/20)+1) == 'b')
                scene->removeItem(scene->itemAt(x,y+20,useless));
            if(map->getTile((x/20)-1,(y/20)) == 'b')
                scene->removeItem(scene->itemAt(x-20,y,useless));
            if(map->getTile((x/20)+1,(y/20)) == 'b')
                scene->removeItem(scene->itemAt(x+20,y,useless));
        }
        if(map->getTile(x/20,y/20) == 'b')
        {
            headPlaced = false;
            bodyPlaced = false;
            if(map->getTile(x/20,(y/20)-1) == 'h')
                scene->removeItem(scene->itemAt(x,y-20,useless));
            if( map->getTile(x/20,(y/20)+1) == 'h')
                scene->removeItem(scene->itemAt(x,y+20,useless));
            if(map->getTile((x/20)-1,(y/20)) == 'h')
                scene->removeItem(scene->itemAt(x-20,y,useless));
            if(map->getTile((x/20)+1,(y/20)) == 'h')
                scene->removeItem(scene->itemAt(x+20,y,useless));
        }
        map->setTile('.',x/20,y/20);
        scene->removeItem(scene->itemAt(x,y,useless));
        scene->addItem(new Blank(NULL,x/20,y/20));
        break;
    case 1 :
        if(map->getTile(x/20,y/20) == 'h')
        {
            headPlaced = false;
            bodyPlaced = false;
            if(map->getTile(x/20,(y/20)-1) == 'b')
                scene->removeItem(scene->itemAt(x,y-20,useless));
            if( map->getTile(x/20,(y/20)+1) == 'b')
                scene->removeItem(scene->itemAt(x,y+20,useless));
            if(map->getTile((x/20)-1,(y/20)) == 'b')
                scene->removeItem(scene->itemAt(x-20,y,useless));
            if(map->getTile((x/20)+1,(y/20)) == 'b')
                scene->removeItem(scene->itemAt(x+20,y,useless));
        }
        if(map->getTile(x/20,y/20) == 'b')
        {
            headPlaced = false;
            bodyPlaced = false;
            if(map->getTile(x/20,(y/20)-1) == 'h')
                scene->removeItem(scene->itemAt(x,y-20,useless));
            if( map->getTile(x/20,(y/20)+1) == 'h')
                scene->removeItem(scene->itemAt(x,y+20,useless));
            if(map->getTile((x/20)-1,(y/20)) == 'h')
                scene->removeItem(scene->itemAt(x-20,y,useless));
            if(map->getTile((x/20)+1,(y/20)) == 'h')
                scene->removeItem(scene->itemAt(x+20,y,useless));
        }
        map->setTile('w',x/20,y/20);
        scene->removeItem(scene->itemAt(x,y,useless));
        scene->addItem(new Wall(NULL,x/20,y/20));
        break;
    case 2 :
        if(headPlaced == false && bodyPlaced == false)
        {
            map->setTile('h',x/20,y/20);
            scene->removeItem(scene->itemAt(x,y,useless));
            scene->addItem(new Head(NULL,x/20,y/20));
            choice = 3;
            headPlaced = true;
        }
        break;
    case 3 :
        if(bodyPlaced == false && headPlaced == true)
        {
            if((map->getTile(x/20,(y/20)-1) == 'h'
                || map->getTile(x/20,(y/20)+1) == 'h'
                || map->getTile((x/20)-1,(y/20)) == 'h'
                || map->getTile((x/20)+1,(y/20)) == 'h') && map->getTile(x/20,y/20) != 'h')
            {
                map->setTile('b',x/20,y/20);
                scene->removeItem(scene->itemAt(x,y,useless));
                scene->addItem(new BodyPart(NULL,x/20,y/20));
                bodyPlaced = true;
                choice = 0;
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
