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

namespace Ui {
class EditorForm;
}

class EditorForm : public QWidget
{
    Q_OBJECT

public:
    explicit EditorForm(QWidget *parent = 0);
    ~EditorForm();

private slots:
    void on_buttonLoadMap_clicked();

    void on_buttonSaveMap_clicked();

    void on_testButton_clicked();

private:
    Ui::EditorForm *ui;
    View * view;
    Scene * scene;
    Map * map;
    Head * head;
    BodyPart * body;
    void loadMap();
};

#endif // EDITORFORM_H
