#ifndef SEARCHSUGGESTIONS_H
#define SEARCHSUGGESTIONS_H

#include <QString>
#include <QVector>

namespace api
{
    struct SearchSuggestions
    {
        QVector<QString> suggestions;
    };
}

#endif // SEARCHSUGGESTIONS_H
