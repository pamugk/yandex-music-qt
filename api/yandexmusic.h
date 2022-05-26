#ifndef YANDEXMUSIC_H
#define YANDEXMUSIC_H

#include <QObject>
#include <QNetworkAccessManager>

#include "searchcategory.h"

namespace api
{
    class YandexMusic : public QObject
    {
        Q_OBJECT
    public:
        explicit YandexMusic(QObject *parent = nullptr);

        /*!
         * \brief search
         * \param text
         * \param page
         * \param type
         * \param doNotCorrect
         * \return
         */
        QNetworkReply *search(const QString &text, int page, SearchCategory type, bool nocorrect);

        /*!
         * \brief Gets search suggestions
         * \param query Search query
         * \return A list of search suggestions and the best match for passed search query
         */
        QNetworkReply *findSearchSuggestions(const QString &part);

    private:
        static const QString API_HOST;

        QNetworkAccessManager *apiClient;

    signals:

    };
}

#endif // YANDEXMUSIC_H
