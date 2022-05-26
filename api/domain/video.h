#ifndef VIDEO_H
#define VIDEO_H

#include <QString>
#include <QTime>
#include <QUrl>
#include <QVector>

#include "entity.h"

namespace api
{
    struct Video final: public Entity
    {
        Video();
        qint64 getId() override;
        Type getType() override;

        /*!
         * \brief youtubeUrl
         */
        QUrl youtubeUrl;
        /*!
         * \brief thumbnailUrl
         */
        QUrl thumbnailUrl;
        /*!
         * \brief title
         */
        QString title;
        /*!
         * \brief text
         */
        QString text;
        /*!
         * \brief duration
         */
        QTime duration;
        /*!
         * \brief regions
         */
        QVector<QString> regions;
    };
}

#endif // VIDEO_H
