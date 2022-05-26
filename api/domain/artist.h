#ifndef ARTIST_H
#define ARTIST_H

#include <QDate>
#include <QString>
#include <QVector>
#include <QUrl>

#include "entity.h"

namespace api
{
    /*!
     * \brief The Artist class
     */
    struct Artist final: public Entity
    {
    public:
        struct Link
        {
            enum Type
            {
                OFFICIAL,
                SOCIAL
            };

            QString title;
            QUrl href;
            Type type = Type::OFFICIAL;
            QString socialNetwork;
        };

        struct Description
        {
            QString text;
            QUrl uri;
        };

        struct Counts
        {
            int tracks = -1;
            int directAlbums = -1;
            int alsoAlbums = -1;
            int alsoTracks = 0;
        };

        struct Ratings
        {
            int week = -1;
            int month = -1;
            int day = -1;
        };

        Artist(qint64 id);
        qint64 getId() override;
        Type getType() override;

        /*!
         * \brief name
         */
        QString name;
        /*!
         * \brief various
         */
        bool various;
        /*!
         * \brief composer
         */
        bool composer;
        /*!
         * \brief image Artist image
         */
        QUrl image;
        /*!
         * \brief ogImage Artist Open Graph preview
         */
        QUrl ogImage;
        /*!
         * \brief genres Artist genres
         */
        QVector<QString> genres;
        /*!
         * \brief counts
         */
        Counts counts;
        /*!
         * \brief available Artist availability flag
         */
        bool available = true;
        /*!
         * \brief ratings
         */
        Ratings ratings;
        /*!
         * \brief links Artist links on other sites
         */
        QVector<Link> links;
        /*!
         * \brief ticketsAvailable Tickets for artist concerts availability flag
         */
        bool ticketsAvailable = false;
        /*!
         * \brief likesCount
         */
        int likesCount = -1;
        /*!
         * \brief description Artist description
         */
        Description description;
        /*!
         * \brief countries
         */
        QVector<QString> countries;
        /*!
         * \brief initDate Date of artist career start
         */
        QDate initDate;
        /*!
         * \brief enWikipediaLink Artist Wikipedia page link
         */
        QUrl enWikipediaLink;

    private:
        /*!
         * \brief id Artist id
         */
        qint64 id;

    };
}

#endif // ARTIST_H
