#ifndef VIEW_H
#define VIEW_H

#include <QGraphicsView>

class View : public QGraphicsView
{
public:
    View(QWidget * parent, bool cursorH = false);
};

#endif // VIEW_H
