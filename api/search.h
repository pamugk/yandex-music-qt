#ifndef SEARCH_H
#define SEARCH_H

#include <QSharedPointer>
#include <QString>
#include <QVector>

#include "domain/album.h"
#include "domain/artist.h"
#include "domain/playlist.h"
#include "domain/podcast.h"

namespace api
{
    struct SearchResult
    {
        template<typename T> requires DomainClass<T>
        struct Part
        {
            int total = 0;
            int perPage = 0;
            int order = 0;
            QVector<T> results;
        };

        bool misspellCorrected = false;
        bool noCorrect = false;

        QString text;
        QString misspellResult;
        QString misspellOriginal;


        QSharedPointer<Entity>best;

        Part<Album> albums;
        Part<Artist> artists;
        Part<Episode> episodes;
        Part<Playlist> playlists;
        Part<Podcast> podcasts;
        Part<Track> tracks;
    };
}

#endif // SEARCH_H
