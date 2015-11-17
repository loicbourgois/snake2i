#ifndef OPTIONSWINDOW_H
#define OPTIONSWINDOW_H

#include <QMainWindow>

namespace Ui {
class optionsWindow;
}

class optionsWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit optionsWindow(QWidget *parent = 0);
    ~optionsWindow();

private:
    Ui::optionsWindow *ui;
};

#endif // OPTIONSWINDOW_H
