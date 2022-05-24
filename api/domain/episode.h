#ifndef EPISODE_H
#define EPISODE_H

#include <QDate>
#include <QTime>
#include <QUrl>

#include "entity.h"

namespace api
{
    struct Episode final: public Entity
    {
        Episode(long id);
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
        /*!
         * \brief publicationDate
         */
        QDate publicationDate;

    private:
        long id;
    };
}

#endif // EPISODE_H
