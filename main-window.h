#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "options-form.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void goToOptions();

private:
    Ui::MainWindow *ui;
    OptionsForm * optionsForm;
};

#endif // MAINWINDOW_H
