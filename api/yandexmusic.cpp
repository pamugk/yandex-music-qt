#include "yandexmusic.h"

namespace api
{
    const QString YandexMusic::API_HOST = "https://api.music.yandex.net";

    YandexMusic::YandexMusic(QObject *parent)
        : QObject{parent}
    {
        apiClient = new QNetworkAccessManager(this);
    }

    QNetworkReply *YandexMusic::findSearchSuggestions(const QString &query)
    {
        QUrlQuery urlParams;
        urlParams.addQueryItem("part", query);
        QUrl url(QString("%1/search/suggest").arg(API_HOST));
        url.setQuery(urlParams);
        return apiClient->get(QNetworkRequest(url));
    }
}
