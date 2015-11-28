#ifndef GAMEFORM_H
#define GAMEFORM_H

#include "blank.h"
#include "map.h"
#include "scene.h"
#include "view.h"
#include "wall.h"
#include <QWidget>

namespace Ui {
class GameForm;
}

class GameForm : public QWidget
{
    Q_OBJECT

public:
    explicit GameForm(QWidget *parent = 0);
    ~GameForm();

private:
    Ui::GameForm *ui;
    View * view;
    Scene * scene;
    Map * map;
};

#endif // GAMEFORM_H
