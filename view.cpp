#include "view.h"

View::View(QWidget * parent,bool cursorH) : QGraphicsView(parent)
{
    setBackgroundBrush(QBrush(QColor(0,0,0), Qt::SolidPattern));
    scale(2,2);
    setRenderHints(QPainter::Antialiasing
                   | QPainter::SmoothPixmapTransform
                   | QPainter::HighQualityAntialiasing);
    setMouseTracking(true);
    if(cursorH)
        viewport()->setCursor(Qt::BlankCursor);
}
