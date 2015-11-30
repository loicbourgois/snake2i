#ifndef GAMEFORM_H
#define GAMEFORM_H

#include "blank.h"
#include "food.h"
#include "map.h"
#include "scene.h"
#include "snake.h"
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
    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QMouseEvent *event);

public slots:
    void precedent();
    void advance();
    void go();

private:
    Ui::GameForm *ui;
    View * view;
    Scene * scene;
    Map * map;
    Snake snake;
    Food * food;
    void popFood();
};

#endif // GAMEFORM_H
