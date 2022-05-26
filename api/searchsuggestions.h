#ifndef SEARCHSUGGESTIONS_H
#define SEARCHSUGGESTIONS_H

#include <QSharedPointer>
#include <QString>
#include <QVector>

#include "domain/entity.h"

namespace api
{
    struct SearchSuggestions
    {
        QSharedPointer<Entity> best;
        QVector<QString> suggestions;
    };
}

#endif // SEARCHSUGGESTIONS_H
