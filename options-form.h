#ifndef OPTIONSFORM_H
#define OPTIONSFORM_H

#include <QWidget>

namespace Ui {
class optionsForm;
}

class optionsForm : public QWidget
{
    Q_OBJECT

public:
    explicit optionsForm(QWidget *parent = 0);
    ~optionsForm();

private:
    Ui::optionsForm *ui;
};

#endif // OPTIONSFORM_H
