#ifndef INSTRUCTIONSFORM_H
#define INSTRUCTIONSFORM_H

#include <QWidget>

namespace Ui {
class InstructionsForm;
}

class InstructionsForm : public QWidget
{
    Q_OBJECT

public:
    explicit InstructionsForm(QWidget *parent = 0);
    ~InstructionsForm();

private:
    Ui::InstructionsForm *ui;
};

#endif // INSTRUCTIONSFORM_H
