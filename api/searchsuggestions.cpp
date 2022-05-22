#include "searchsuggestions.h"

namespace api
{
    SearchSuggestions::SearchSuggestions() { }

    const QVector<QString> &SearchSuggestions::getSuggestions() const
    {
        return suggestions;
    }

    void SearchSuggestions::setSuggestions(const QVector<QString> &newSuggestions)
    {
        suggestions = newSuggestions;
    }

}
