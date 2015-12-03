#ifndef EDITORFORM_H
#define EDITORFORM_H

#include <QFileDialog>
#include <QWidget>
#include <QTextStream>
#include <QFile>
#include "view.h"
#include "scene.h"
#include "map.h"
#include "wall.h"
#include "blank.h"
#include "snake.h"
#include "bodypart.h"
#include "sceneeditor.h"
#include "ui_editor-form.h"
#include <QDebug>
#include "bodypart.h"

namespace Ui {
class EditorForm;
}

class EditorForm : public QWidget
{
    Q_OBJECT

public:
    explicit EditorForm(QWidget *parent = 0);
    ~EditorForm();
    int choice;

private slots:
    void on_buttonLoadMap_clicked();

    void on_buttonSaveMap_clicked();

    void onDeleted(double x,double y);

    void on_headButton_clicked();

    void on_blankButton_clicked();

    void on_wallButton_clicked();

    void play();
    void instructions();
    void about();


private:
    Ui::EditorForm *ui;
    View * view;
    SceneEditor * scene;
    Map * map;
    Head * head;
    BodyPart * body;

    bool headPlaced;
    bool bodyPlaced;
    void loadMap();
    char guessDirection();
    QGraphicsItem * cursor;
};

#endif // EDITORFORM_H
