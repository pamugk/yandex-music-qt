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
            Type type;
            QString socialNetwork;
        };

        struct Description
        {
            QString text;
            QUrl uri;
        };

        Artist(long id);
        long getId() override;
        Type getType() override;

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
         * \brief available Artist availability flag
         */
        bool available;
        /*!
         * \brief links Artist links on other sites
         */
        QVector<Link> links;
        /*!
         * \brief ticketsAvailable Tickets for artist concerts availability flag
         */
        bool ticketsAvailable;
        /*!
         * \brief description Artist description
         */
        Description description;
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
        long id;

    };
}

#endif // ARTIST_H
