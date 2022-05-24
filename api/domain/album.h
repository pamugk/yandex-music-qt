#ifndef ALBUM_H
#define ALBUM_H

#include <QDate>
#include <QString>
#include <QUrl>

#include "artist.h"
#include "entity.h"
#include "label.h"
#include "track.h"

namespace api
{

    /*!
     * \brief The Album class
     */
    struct Album final: public Entity
    {
        enum Type
        {
            FULL,
            SINGLE
        };

        Album(long id);
        long getId() override;
        Entity::Type getType() override;

        /*!
         * \brief title Album title
         */
        QString title;
        /*!
         * \brief type Album type
         */
        Type type;
        /*!
         * \brief year Album release year
         */
        int year;
        /*!
         * \brief releaseDate Album release date
         */
        QDate releaseDate;
        /*!
         * \brief coverUri Album cover URI
         */
        QUrl coverUri;
        /*!
         * \brief ogImage Album Open Graph preview
         */
        QUrl ogImage;
        /*!
         * \brief genre Album genre
         */
        QString genre;
        /*!
         * \brief trackCount Album track total count
         */
        int trackCount;
        /*!
         * \brief recent Recent album flag
         */
        bool recent;
        /*!
         * \brief popular Popular album flag
         */
        bool popular;
        /*!
         * \brief artists Artists who authored album
         */
        QVector<Artist> artists;
        /*!
         * \brief labels Labels where album was recorded
         */
        QVector<Label> labels;
        /*!
         * \brief available Album availability flag
         */
        bool available;
        /*!
         * \brief availableForMobile Mobile app album availability
         */
        bool availableForMobile;
        /*!
         * \brief availablePartially Free users album availability (partial)
         */
        bool availablePartially;
        /*!
         * \brief bests Best album tracks ids
         */
        QVector<long> bests;
        /*!
         * \brief bests Best album tracks ids
         */
        QVector<long> prerolls;
        /*!
         * \brief duplicates Album other versions
         */
        QVector<Album> duplicates;
        /*!
         * \brief volumes Album tracks by disks
         */
        QVector<QVector<Track>> volumes;

    private:
        /*!
         * \brief id Album id
         */
        long id;
    };
}

#endif // ALBUM_H
