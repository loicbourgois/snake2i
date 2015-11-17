#ifndef MAINFORM_H
#define MAINFORM_H

#include <QWidget>

namespace Ui {
class MainForm;
}

class MainForm : public QWidget
{
    Q_OBJECT

public:
    explicit MainForm(QWidget *parent = 0);
    ~MainForm();
public slots:
    void goToOptions();
    void play();
    void instructions();
    void edit();

private:
    Ui::MainForm *ui;
};

#endif // MAINFORM_H
