#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <QColor>
#include <QDateTime>
#include <QString>
#include <QTime>
#include <QUrl>

#include "entity.h"

namespace api
{
    struct Tag
    {
        QString id;
        QString value;
    };

    enum Visibility
    {
        PUBLIC,
        PRIVATE
    };

    /*!
     * \brief The Playlist class
     */
    struct Playlist final: public Entity
    {
        struct Owner
        {
            long id;
            QString login;
            QString name;
            QString sex;
            bool verified;
        };

        Playlist(long id);
        long getId() override;
        Type getType() override;

        /*!
         * \brief description
         */
        QString description;
        /*!
         * \brief descriptionFormatted
         */
        QString descriptionFormatted;
        /*!
         * \brief available
         */
        bool available;
        /*!
         * \brief collective
         */
        bool collective;
        /*!
         * \brief coverUri
         */
        QUrl coverUri;
        /*!
         * \brief created
         */
        QDateTime created;
        /*!
         * \brief modified
         */
        QDateTime modified;
        /*!
         * \brief backgroundColor
         */
        QColor backgroundColor;
        /*!
         * \brief textColor
         */
        QColor textColor;
        /*!
         * \brief duration
         */
        QTime duration;
        /*!
         * \brief banner
         */
        bool banner;
        /*!
         * \brief premiere
         */
        bool premiere;
        /*!
         * \brief kind
         */
        int kind;
        /*!
         * \brief ogImage
         */
        QUrl ogImage;
        /*!
         * \brief owner
         */
        Owner owner;
        /*!
         * \brief revision
         */
        int revision;
        /*!
         * \brief snapshot
         */
        int snapshot;
        /*!
         * \brief tags
         */
        QVector<Tag> tags;
        /*!
         * \brief title
         */
        QString title;
        /*!
         * \brief trackCount
         */
        int trackCount;
        /*!
         * \brief visibility
         */
        Visibility visibility;
        /*!
         * \brief likesCount
         */
        int likesCount;

    private:
        /*!
         * \brief id Playlist id
         */
        long id;
    };
}


#endif // PLAYLIST_H
