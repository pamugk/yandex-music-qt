#ifndef TRACK_H
#define TRACK_H

#include <QTime>
#include <QUrl>

#include "entity.h"
#include "label.h"

namespace api
{
    struct Track final: public Entity
    {
        struct Normalization
        {
            double gain;
            double peak;
        };

        Track(long id);
        long getId() override;
        Type getType() override;

        /*!
         * \brief available
         */
        bool available;
        /*!
         * \brief availableForPremiumUsers
         */
        bool availableForPremiumUsers;
        /*!
         * \brief availableFullWithoutPermission
         */
        bool availableFullWithoutPermission;
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
        int fileSize;
        /*!
         * \brief lyricsAvailable
         */
        bool lyricsAvailable;
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
        bool rememberPosition;
        /*!
         * \brief storageDir
         */
        QString storageDir;
        /*!
         * \brief title
         */
        QString title;

    private:
        long id;
    };
}

#endif // TRACK_H
