#ifndef CUSTOMSLOTS_H
#define CUSTOMSLOTS_H

#include "draggablerectitem.h"
#include <QDebug>
class CustomSlots : public QObject
{
    Q_OBJECT
public:
    explicit CustomSlots();
public slots:
    void addNew();
};

#endif // CUSTOMSLOTS_H
