#ifndef JSON_SERIALIZATION_H
#define JSON_SERIALIZATION_H

#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkReply>

#include "../search.h"
#include "../searchcategory.h"
#include "../searchsuggestions.h"

namespace utils
{
    void deserialize(const QJsonObject &json, api::Album *album);
    void deserialize(const QJsonObject &json, api::Artist *artist);
    void deserialize(const QJsonObject &json, api::Episode *episode);
    void deserialize(const QJsonObject &json, api::Playlist *playlist);
    void deserialize(const QJsonObject &json, api::Podcast *podcast);
    void deserialize(const QJsonObject &json, api::Track *track);

    QString serializeSearchType(api::SearchCategory type);
    void deserializeSearchResult(const QJsonObject &json, api::SearchResult &result);
    void deserializeSearchSuggestions(const QJsonObject &json, api::SearchSuggestions &result);

    QJsonDocument tryReadJsonResponse(QNetworkReply *reply);
}
#endif // JSON_SERIALIZATION_H
