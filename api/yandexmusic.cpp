#include <QUrlQuery>

#include "utils/json_serialization.h"
#include "yandexmusic.h"

namespace api
{
    const QString YandexMusic::API_HOST = "https://api.music.yandex.net";

    YandexMusic::YandexMusic(QObject *parent)
        : QObject{parent}
    {
        apiClient = new QNetworkAccessManager(this);
    }

    QNetworkReply *YandexMusic::search(const QString &text, int page, SearchCategory type, bool nocorrect)
    {
        QUrlQuery urlParams;
        urlParams.addQueryItem("text", text);
        urlParams.addQueryItem("page", QString::number(page));
        urlParams.addQueryItem("type", utils::serializeSearchType(type));
        urlParams.addQueryItem("nocorrect", nocorrect ? "true" : "false");
        QUrl url(QString("%1/search").arg(API_HOST));
        url.setQuery(urlParams);
        return apiClient->get(QNetworkRequest(url));
    }

    QNetworkReply *YandexMusic::findSearchSuggestions(const QString &part)
    {
        QUrlQuery urlParams;
        urlParams.addQueryItem("part", part);
        QUrl url(QString("%1/search/suggest").arg(API_HOST));
        url.setQuery(urlParams);
        return apiClient->get(QNetworkRequest(url));
    }
}
