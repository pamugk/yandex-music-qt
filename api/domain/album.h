#ifndef ALBUM_H
#define ALBUM_H

#include <QDate>
#include <QString>
#include <QUrl>

#include "artist.h"
#include "entity.h"
#include "label.h"

namespace api
{
    struct Track;

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

        Album(qint64 id);
        qint64 getId() override;
        Entity::Type getType() override;

        /*!
         * \brief title Album title
         */
        QString title;
        /*!
         * \brief title Content warning for album's contents
         */
        QString contentWarning;
        /*!
         * \brief type Album type
         */
        Type type = Type::FULL;
        /*!
         * \brief year Album original release year
         */
        int originalReleaseYear = -1;
        /*!
         * \brief year Album release year
         */
        int year = -1;
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
        int trackCount = -1;
        /*!
         * \brief likesCount Album likes count
         */
        int likesCount = -1;
        /*!
         * \brief recent Recent album flag
         */
        bool recent = false;
        /*!
         * \brief popular Popular album flag
         */
        bool popular = false;
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
        bool available = true;
        /*!
         * \brief availableForPremiumUsers Album availability
         */
        bool availableForPremiumUsers = false;
        /*!
         * \brief availableForMobile Mobile app album availability
         */
        bool availableForMobile = false;
        /*!
         * \brief availablePartially Free users album availability (partial)
         */
        bool availablePartially = false;
        /*!
         * \brief bests Best album tracks ids
         */
        QVector<qint64> bests;
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
        qint64 id;
    };

    struct Track final: public Entity
    {
        struct Normalization
        {
            double gain;
            double peak;
        };

        struct LyricsInfo
        {
            bool hasAvailableSyncLyrics;
            bool hasAvailableTextLyrics;
        };

        Track(qint64 id);
        qint64 getId() override;
        Type getType() override;

        /*!
         * \brief title
         */
        QString title;
        /*!
         * \brief contentWarning
         */
        QString contentWarning;
        /*!
         * \brief available
         */
        bool available = false;
        /*!
         * \brief availableAsRbt
         */
        bool availableAsRbt = false;
        /*!
         * \brief availableForPremiumUsers
         */
        bool availableForPremiumUsers = false;
        /*!
         * \brief availableFullWithoutPermission
         */
        bool availableFullWithoutPermission = false;
        /*!
         * \brief coverUri
         */
        QUrl coverUri;
        /*!
         * \brief ogImage
         */
        QUrl ogImage;
        /*!
         * \brief duration
         */
        QTime duration;
        /*!
         * \brief fileSize
         */
        int fileSize = -1;
        /*!
         * \brief lyricsAvailable
         */
        bool lyricsAvailable = false;
        /*!
         * \brief lyricsInfo
         */
        LyricsInfo lyricsInfo;
        /*!
         * \brief major
         */
        Label major;
        /*!
         * \brief normalization
         */
        Normalization normalization;
        /*!
         * \brief previewDuration
         */
        QTime previewDuration;
        /*!
         * \brief rememberPosition
         */
        bool rememberPosition = false;
        /*!
         * \brief regions
         */
        QVector<QString> regions;
        /*!
         * \brief albums
         */
        QVector<Album> albums;
        /*!
         * \brief artists
         */
        QVector<Artist> artists;

    private:
        qint64 id;
    };
}

#endif // ALBUM_H
