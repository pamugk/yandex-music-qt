#ifndef LABEL_H
#define LABEL_H

#include <QString>

namespace api
{
    struct Label
    {
        qint64 id = -1;
        QString name;
    };
}

#endif // LABEL_H
