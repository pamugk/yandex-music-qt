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

    /*!
     * \brief The Playlist class
     */
    struct Playlist final: public Entity
    {

        enum Visibility
        {
            PUBLIC,
            PRIVATE
        };

        struct Owner
        {
            qint64 id = -1;
            QString login;
            QString name;
            QString sex;
            bool verified = false;
        };

        Playlist(qint64 id);
        qint64 getId() override;
        Type getType() override;

        /*!
         * \brief title
         */
        QString title;
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
        bool available = false;
        /*!
         * \brief collective
         */
        bool collective = false;
        /*!
         * \brief coverUri
         */
        QUrl coverUri;
        /*!
         * \brief ogImage
         */
        QUrl ogImage;
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
        bool banner = false;
        /*!
         * \brief premiere
         */
        bool premiere = false;
        /*!
         * \brief kind
         */
        int kind = -1;
        /*!
         * \brief owner
         */
        Owner owner;
        /*!
         * \brief revision
         */
        int revision = -1;
        /*!
         * \brief snapshot
         */
        int snapshot = -1;
        /*!
         * \brief tags
         */
        QVector<Tag> tags;
        /*!
         * \brief trackCount
         */
        int trackCount = -1;
        /*!
         * \brief visibility
         */
        Visibility visibility = Visibility::PRIVATE;
        /*!
         * \brief likesCount
         */
        int likesCount = -1;

    private:
        /*!
         * \brief id Playlist id
         */
        qint64 id;
    };
}


#endif // PLAYLIST_H
