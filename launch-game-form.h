#ifndef LAUNCHGAMEFORM_H
#define LAUNCHGAMEFORM_H

#include <QWidget>

namespace Ui {
class LaunchGameForm;
}

class LaunchGameForm : public QWidget
{
    Q_OBJECT

public:
    explicit LaunchGameForm(QWidget *parent = 0);
    ~LaunchGameForm();
public slots:
    void launchGame();
    void precedent();

private:
    Ui::LaunchGameForm *ui;
};

#endif // LAUNCHGAMEFORM_H
