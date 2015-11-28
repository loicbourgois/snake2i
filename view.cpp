#include "view.h"

View::View(QWidget * parent) : QGraphicsView(parent)
{
    setBackgroundBrush(QBrush(Qt::black, Qt::SolidPattern));
}
