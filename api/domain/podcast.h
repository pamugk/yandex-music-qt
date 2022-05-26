#ifndef PODCAST_H
#define PODCAST_H

#include <QDate>
#include <QString>
#include <QUrl>

#include "artist.h"
#include "entity.h"
#include "label.h"

namespace api
{
    struct Episode;

    struct Podcast final: public Entity
    {
        Podcast(qint64 id);
        qint64 getId() override;
        Type getType() override;

        /*!
         * \brief title Podcast title
         */
        QString title;
        /*!
         * \brief contentWarning
         */
        QString contentWarning;
        /*!
         * \brief year Podcast release year
         */
        int year = -1;
        /*!
         * \brief releaseDate Podcast release date
         */
        QDate releaseDate;
        /*!
         * \brief coverUri Podcast cover URI
         */
        QUrl coverUri;
        /*!
         * \brief ogImage Podcast Open Graph preview
         */
        QUrl ogImage;
        /*!
         * \brief trackCount
         */
        int trackCount = -1;
        /*!
         * \brief genre Podcast genre
         */
        QString genre;
        /*!
         * \brief trackCount Podcast episode total count
         */
        int episodeCount = -1;
        /*!
         * \brief recent Recent podcast flag
         */
        bool recent = false;
        /*!
         * \brief popular Popular podcast flag
         */
        bool popular = false;
        /*!
         * \brief available Podcast availability flag
         */
        bool available = true;
        /*!
         * \brief availableForMobile Mobile app podcast availability
         */
        bool availableForMobile = true;
        /*!
         * \brief availablePartially Free users podcast availability (partial)
         */
        bool availablePartially = true;
        /*!
         * \brief bests Best podcast episode ids
         */
        QVector<qint64> bests;
        /*!
         * \brief volumes Podcast episodes
         */
        QVector<Episode> episodes;
        /*!
         * \brief labels Labels where podcast was recorded
         */
        QVector<Label> labels;

    private:
        qint64 id;
    };

    struct Episode final: public Entity
    {
        Episode(qint64 id);
        qint64 getId() override;
        Type getType() override;

        /*!
         * \brief available
         */
        bool available = true;
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
         * \brief albums
         */
        QVector<Podcast> podcasts;
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
         * \brief previewDuration
         */
        QTime previewDuration;
        /*!
         * \brief rememberPosition
         */
        bool rememberPosition = false;
        /*!
         * \brief title
         */
        QString title;
        /*!
         * \brief artists
         */
        QVector<Artist> artists;
        /*!
         * \brief regions
         */
        QVector<QString> regions;
        /*!
         * \brief publicationDate
         */
        QDate publicationDate;

    private:
        qint64 id;
    };
}

#endif // PODCAST_H
