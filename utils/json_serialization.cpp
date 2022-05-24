#include "json_serialization.h"

#include <QJsonArray>

namespace utils
{
    void deserializeSearchSuggestions(const QJsonObject &json, api::SearchSuggestions &result)
    {
        if (json.contains("result"))
        {
            auto suggestResult = json["result"].toObject();
            if (suggestResult.contains("suggestions"))
            {
                auto suggestions = suggestResult["suggestions"].toArray();
                for (auto suggestions: suggestions)
                {
                    result.suggestions.append(suggestions.toString());
                }
            }
        }
    }

    QJsonDocument tryReadJsonResponse(QNetworkReply *reply)
    {
        QJsonParseError parseError;
        auto response = QJsonDocument::fromJson(reply->readAll(), &parseError);
        reply->deleteLater();
        if (parseError.error != QJsonParseError::NoError)
        {

        }

        if (response.isObject() && response.object().contains("error"))
        {

        }
        return response;
    }
}
