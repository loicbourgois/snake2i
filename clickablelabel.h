#ifndef CLICKABLELABEL_H
#define CLICKABLELABEL_H

#include <QLabel>

class ClickableLabel : public QLabel
{
    Q_OBJECT
public:
    ClickableLabel(QString type);
    QString type;
signals:
    void clicked(QString);
protected:
    void mousePressEvent(QMouseEvent* event);
};

#endif // CLICKABLELABEL_H
