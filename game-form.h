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
    explicit GameForm(QWidget *parent);
    ~GameForm();
    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QMouseEvent *event);

public slots:
    void precedent();
    void advance();
    void go();
    void pause();
    void reprendre();
    void restart();
    void updateDifficulty(int diff);
    void zoomMore();
    void zoomLess();

private:
    Ui::GameForm *ui;
    View * view;
    Scene * scene;
    Map * map;
    Snake snake;
    Food * food;
    QTimer * timer;
    void popFood();
    void initSnake();
    unsigned int score;
};

#endif // GAMEFORM_H
