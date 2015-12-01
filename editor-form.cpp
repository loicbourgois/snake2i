#include "editor-form.h"
#include "ui_editor-form.h"

EditorForm::EditorForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditorForm)
{
    ui->setupUi(this);
    view = new View(this);
    ui->widgetView->layout()->addWidget(view);
    scene = new Scene(this);
    view->setScene(scene);
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
                //snake.addHead(x, y);
            }
            else if(map->getTile(x, y) == 'b')
            {
                //snake.addBodyPart(x, y);
            }
        }
    }
}

void EditorForm::on_buttonLoadMap_clicked()
{
    //map = new Map("./square.map");
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Choisir une carte"), tr("Map Files (*.map)"));
    map = new Map(fileName.toStdString());
    loadMap();
}

void EditorForm::on_buttonSaveMap_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
                               tr(".map"));
    QFile saveFile(fileName);
    if(saveFile.open(QIODevice::WriteOnly))
    {
        QTextStream stream(&saveFile);
        stream << "YOLO" << endl;
        //Récuperer les éléments posé par l'utilisateur sur la carte :
        //Rechercher dans le scene, en fonction de la couleur
        //Récréer la carte dès qu'un element est posé ou alors lorsqu'on charge la map

        saveFile.close();
    }


}
