#ifndef YANDEXMUSIC_H
#define YANDEXMUSIC_H

#include <QObject>

#include <QtNetwork>
#include <QOAuth2AuthorizationCodeFlow>

namespace api
{
    class YandexMusic : public QObject
    {
        Q_OBJECT
    public:
        explicit YandexMusic(QObject *parent = nullptr);

        /*!
         * \brief Gets search suggestions
         * \param query Search query
         * \return A list of search suggestions and the best match for passed search query
         */
        QNetworkReply *findSearchSuggestions(const QString &query);

    private:
        static const QString API_HOST;

        QNetworkAccessManager *apiClient;

    signals:

    };
}

#endif // YANDEXMUSIC_H
