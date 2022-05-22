#ifndef JSON_SERIALIZATION_H
#define JSON_SERIALIZATION_H

#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkReply>

#include "../api/searchsuggestions.h"

namespace utils
{
    void deserializeSearchSuggestions(const QJsonObject &json, api::SearchSuggestions &result);
    QJsonDocument tryReadJsonResponse(QNetworkReply *reply);
}
#endif // JSON_SERIALIZATION_H
