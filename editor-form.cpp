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
    map = new Map();
    loadMap();
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
            else if(map->getTile(x, y) == '.')
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
                this->head = new Head(scene, x, y);
                scene->addItem(head);
            }
            else if(map->getTile(x, y) == 'b')
            {
                this->body = new BodyPart(scene, x, y);
                scene->addItem(body);
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

void EditorForm::on_testButton_clicked()
{
    map->setTile('w',5,5);
    scene->addItem(new Wall(scene,5,5));
}
