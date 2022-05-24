#ifndef PODCAST_H
#define PODCAST_H

#include <QDate>
#include <QString>
#include <QUrl>

#include "entity.h"
#include "episode.h"

namespace api
{
    struct Podcast final: public Entity
    {
        Podcast(long id);
        long getId() override;
        Type getType() override;

        /*!
         * \brief title Podcast title
         */
        QString title;
        /*!
         * \brief year Podcast release year
         */
        int year;
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
         * \brief genre Podcast genre
         */
        QString genre;
        /*!
         * \brief trackCount Podcast episode total count
         */
        int episodeCount;
        /*!
         * \brief recent Recent podcast flag
         */
        bool recent;
        /*!
         * \brief popular Popular podcast flag
         */
        bool popular;
        /*!
         * \brief available Podcast availability flag
         */
        bool available;
        /*!
         * \brief availableForMobile Mobile app podcast availability
         */
        bool availableForMobile;
        /*!
         * \brief availablePartially Free users podcast availability (partial)
         */
        bool availablePartially;
        /*!
         * \brief bests Best podcast episode ids
         */
        QVector<long> bests;
        /*!
         * \brief volumes Podcast episodes
         */
        QVector<Episode> episodes;

    private:
        long id;
    };
}

#endif // PODCAST_H
