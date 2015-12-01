#include "view.h"

View::View(QWidget * parent) : QGraphicsView(parent)
{
    setBackgroundBrush(QBrush(QColor(0,0,0), Qt::SolidPattern));
    scale(2,2);
    setRenderHints(QPainter::Antialiasing
                   | QPainter::SmoothPixmapTransform
                   | QPainter::HighQualityAntialiasing);
}
