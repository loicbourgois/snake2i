#include "clickablelabel.h"

ClickableLabel::ClickableLabel(QString type)
{
    this->type = type;
}

void ClickableLabel::mousePressEvent(QMouseEvent *event)
{
    emit clicked(this->type);
}

