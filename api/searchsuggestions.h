#ifndef SEARCHSUGGESTIONS_H
#define SEARCHSUGGESTIONS_H

#include <QString>
#include <QVector>

namespace api
{
    class SearchSuggestions
    {
        QVector<QString> suggestions;

    public:
        SearchSuggestions();
        const QVector<QString> &getSuggestions() const;
        void setSuggestions(const QVector<QString> &newSuggestions);
    };
}

#endif // SEARCHSUGGESTIONS_H
