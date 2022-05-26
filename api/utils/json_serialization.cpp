#include "json_serialization.h"

#include <QJsonArray>

namespace utils
{
    QString serializeSearchType(api::SearchCategory type)
    {
        switch (type)
        {
        case api::ALL:
            return "all";
        case api::ALBUM:
            return "album";
        case api::ARTIST:
            return "artist";
        case api::PLAYLIST:
            return "playlist";
        case api::TRACK:
            return "track";
        case api::VIDEO:
            return "video";
        }
    }

    void deserialize(const QJsonObject &json, api::Album *album)
    {
        album->title = json["title"].toString();
        album->contentWarning = json["contentWarning"].toString();
        auto type = json["type"].toString();
        album->type = type == "single" ?
                    api::Album::Type::SINGLE :
                    api::Album::Type::FULL;
        album->originalReleaseYear = json["originalReleaseYear"].toInt(-1);
        album->year = json["year"].toInt(-1);
        if (json.contains("releaseDate") && json["releaseDate"].isString())
        {
            album->releaseDate = QDateTime::fromString(json["releaseDate"].toString(), Qt::ISODate).date();
        }
        album->coverUri = QUrl(json["coverUri"].toString());
        album->ogImage = QUrl(json["ogImage"].toString());
        album->genre = json["genre"].toString();
        album->trackCount = json["trackCount"].toInt(-1);
        album->likesCount = json["likesCount"].toInt(-1);
        album->recent = json["recent"].toBool();
        album->popular = json["veryImportant"].toBool();
        if (json.contains("artists") && json["artists"].isArray())
        {
            for (auto artistJson: json["artists"].toArray())
            {
                auto artistObj = artistJson.toObject();
                api::Artist artist(artistObj["id"].toInteger(-1));
                deserialize(artistObj, &artist);
                album->artists.append(artist);
            }
        }
        if (json.contains("labels") && json["labels"].isArray())
        {
            for (auto labelJson: json["labels"].toArray())
            {
                auto labelObj = labelJson.toObject();
                album->labels.append(api::Label { labelObj["id"].toInteger(-1), labelObj["name"].toString() });
            }
        }
        album->available = json["available"].toBool(true);
        album->availableForPremiumUsers = json["availableForPremiumUsers"].toBool();
        album->availableForMobile = json["availableForMobile"].toBool();
        album->availablePartially = json["availablePartially"].toBool();
        if (json.contains("bests") && json["bests"].isArray())
        {
            for (auto bestJson: json["bests"].toArray())
            {
                album->bests.append(bestJson.toInteger(-1));
            }
        }
        if (json.contains("duplicates") && json["duplicates"].isArray())
        {
            for (auto duplicateJson: json["duplicates"].toArray())
            {
                auto duplicateObj = duplicateJson.toObject();
                api::Album duplicate(duplicateObj["id"].toInteger(-1));
                deserialize(duplicateObj, &duplicate);
                album->duplicates.append(duplicate);
            }
        }
        if (json.contains("volumes") && json["volumes"].isArray())
        {
            auto volumesArray = json["volumes"].toArray();
            QVector<QVector<api::Track>> volumes;
            volumes.resize(volumesArray.count());
            for (int i = 0; i < volumesArray.count(); i++)
            {
                if (volumesArray[i].isArray())
                {
                    auto volumeArray = volumesArray[i].toArray();
                    for (auto trackJson: volumeArray)
                    {
                        auto trackObj = trackJson.toObject();
                        api::Track track(trackObj["id"].toInteger(-1));
                        deserialize(trackObj, &track);
                        volumes[i].append(track);
                    }
                }
            }
            album->volumes = volumes;
        }
    }

    void deserialize(const QJsonObject &json, api::Artist *artist)
    {
        artist->name = json["name"].toString();
        artist->various = json["various"].toBool();
        artist->composer = json["composer"].toBool();
        if (json.contains("cover") && json["cover"].isObject())
        {
            artist->image = json["cover"].toObject()["uri"].toString();
        }
        artist->ogImage = json["ogImage"].toString();
        if (json.contains("genres") && json["genres"].isArray())
        {
            auto genres = json["genres"].toArray();
            artist->genres.resize(genres.count());
            for (int i = 0; i < genres.count(); i++)
            {
                artist->genres[i] = genres[i].toString();
            }
        }
        if (json.contains("counts") && json["counts"].isObject())
        {
            auto counts = json["counts"].toObject();
            artist->counts.tracks = counts["tracks"].toInt(-1);
            artist->counts.directAlbums = counts["directAlbums"].toInt(-1);
            artist->counts.alsoAlbums = counts["alsoAlbums"].toInt(-1);
            artist->counts.alsoTracks = counts["alsoTracks"].toInt(-1);
        }
        artist->available = json["available"].toBool(true);
        if (json.contains("ratings") && json["ratings"].isObject())
        {
            auto ratings = json["ratings"].toObject();
            artist->ratings.week = ratings["week"].toInt(-1);
            artist->ratings.month = ratings["month"].toInt(-1);
            artist->ratings.day = ratings["day"].toInt(-1);
        }
        if (json.contains("links") && json["links"].isArray())
        {
            auto links = json["links"].toArray();
            artist->links.resize(links.count());
            for (int i = 0; i < links.count(); i++)
            {
                auto link = links[i].toObject();
                artist->links[i].title = link["title"].toString();
                artist->links[i].href = link["href"].toString();
                artist->links[i].type = link["type"].toString() == "social" ?
                            api::Artist::Link::Type::SOCIAL :
                            api::Artist::Link::Type::OFFICIAL;
                artist->links[i].socialNetwork = link["socialNetwork"].toString();
            }
        }
        artist->ticketsAvailable = json["ticketsAvailable"].toBool();
        artist->likesCount = json["likesCount"].toInt();
        if (json.contains("description") && json["description"].isObject())
        {
            auto description = json["description"].toObject();
            artist->description.text = description["text"].toString();
            artist->description.uri = description["uri"].toString();
        }
        if (json.contains("countries") && json["countries"].isArray())
        {
            auto countries = json["countries"].toArray();
            artist->countries.resize(countries.count());
            for (int i = 0; i < countries.count(); i++)
            {
                artist->countries[i] = countries[i].toString();
            }
        }
        if (json.contains("initDate") && json["initDate"].isString())
        {
            artist->initDate = QDate::fromString(json["initDate"].toString(), Qt::ISODate);
        }
        artist->enWikipediaLink = json["enWikipediaLink"].toString();
    }

    void deserialize(const QJsonObject &json, api::Episode *episode)
    {
        episode->available = json["available"].toBool(true);
        episode->availableAsRbt = json["availableAsRbt"].toBool();
        episode->availableForPremiumUsers = json["availableForPremiumUsers"].toBool();
        episode->rememberPosition = json["rememberPosition"].toBool();
        if (json.contains("albums") && json["albums"].isArray())
        {
            for (auto albumJson: json["albums"].toArray())
            {
                auto albumObj = albumJson.toObject();
                api::Podcast podcast(albumObj["id"].toInteger(-1));
                deserialize(albumObj, &podcast);
                episode->podcasts.append(podcast);
            }
        }
        episode->coverUri = json["coverUri"].toString();
        episode->title = json["title"].toString();
        if (json.contains("artists") && json["artists"].isArray())
        {
            for (auto artistJson: json["artists"].toArray())
            {
                auto artistObj = artistJson.toObject();
                api::Artist artist(artistObj["id"].toInteger(-1));
                deserialize(artistObj, &artist);
                episode->artists.append(artist);
            }
        }
        if (json.contains("regions") && json["regions"].isArray())
        {
            auto regions = json["regions"].toArray();
            episode->regions.resize(regions.count());
            for (int i = 0; i < regions.count(); i++)
            {
                episode->regions[i] = regions[i].toString();
            }
        }
        if (json.contains("publicationDate") && json["publicationDate"].isString())
        {
            episode->publicationDate = QDate::fromString(json["publicationDate"].toString(), Qt::ISODate);
        }
    }

    void deserialize(const QJsonObject &json, api::Playlist *playlist)
    {
        playlist->title = json["title"].toString();
        playlist->description = json["description"].toString();
        playlist->descriptionFormatted = json["descriptionFormatted"].toString();
        playlist->available = json["available"].toBool();
        playlist->collective = json["collective"].toBool();
        if (json.contains("cover") && json["cover"].isObject()) {
            auto cover = json["cover"].toObject();
            if (!cover.contains("error"))
            {
                playlist->coverUri = cover.contains("uri") ? cover["uri"].toString() :
                        cover.contains("items") && cover["items"].isArray() ? cover["items"].toArray()[0].toString() :
                        "";
            }
        }
        playlist->ogImage = json["ogImage"].toString();
        playlist->created = QDateTime::fromString(json["created"].toString(), Qt::ISODate);
        playlist->modified = QDateTime::fromString(json["modified"].toString(), Qt::ISODate);
        if (json.contains("backgroundColor") && json["backgroundColor"].isString())
        {
            playlist->backgroundColor = json["backgroundColor"].toString();
        }
        if (json.contains("textColor") && json["textColor"].isString())
        {
            playlist->textColor = json["textColor"].toString();
        }
        playlist->duration = QTime::fromMSecsSinceStartOfDay(json["durationMs"].toInt());
        playlist->banner = json["banner"].toBool();
        playlist->premiere = json["premiere"].toBool();
        playlist->kind = json["kind"].toInt(-1);
        if (json.contains("owner") && json["owner"].isObject())
        {
            auto owner = json["owner"].toObject();
            playlist->owner =
            {
                owner["uid"].toInteger(-1),
                owner["login"].toString(), owner["name"].toString(), owner["sex"].toString(),
                owner["verified"].toBool()
            };
        }
        if (json.contains("tags") && json["tags"].isArray())
        {
            auto tags = json["tags"].toArray();
            playlist->tags.resize(tags.count());
            for (int i = 0; i < tags.count(); i++)
            {
                auto tag = tags[i].toObject();
                playlist->tags[i] = { tag["id"].toString(), tag["value"].toString() };
            }
        }
        playlist->trackCount = json["trackCount"].toInt(-1);
        playlist->visibility = json["visibility"].toString() == "public" ? api::Playlist::Visibility::PUBLIC :
                                                                           api::Playlist::Visibility::PRIVATE;
        playlist->likesCount = json["likesCount"].toInt(-1);
    }

    void deserialize(const QJsonObject &json, api::Podcast *podcast)
    {

        podcast->title = json["title"].toString();
        podcast->contentWarning = json["contentWarning"].toString();
        podcast->year = json["year"].toInt(-1);
        if (json.contains("releaseDate") && json["releaseDate"].isString())
        {
            podcast->releaseDate = QDateTime::fromString(json["releaseDate"].toString(), Qt::ISODate).date();
        }
        podcast->coverUri = QUrl(json["coverUri"].toString());
        podcast->ogImage = QUrl(json["ogImage"].toString());
        podcast->genre = json["genre"].toString();
        podcast->trackCount = json["trackCount"].toInt(-1);
        podcast->recent = json["recent"].toBool();
        podcast->popular = json["veryImportant"].toBool();
        if (json.contains("labels") && json["labels"].isArray())
        {
            for (auto labelJson: json["labels"].toArray())
            {
                auto labelObj = labelJson.toObject();
                podcast->labels.append(api::Label { labelObj["id"].toInteger(-1), labelObj["name"].toString() });
            }
        }
        podcast->available = json["available"].toBool(true);
        podcast->availableForMobile = json["availableForMobile"].toBool();
        podcast->availablePartially = json["availablePartially"].toBool();
        if (json.contains("bests") && json["bests"].isArray())
        {
            for (auto bestJson: json["bests"].toArray())
            {
                podcast->bests.append(bestJson.toInteger(-1));
            }
        }
        if (json.contains("volumes") && json["volumes"].isArray())
        {
            auto volumesArray = json["volumes"].toArray();
            for (int i = 0; i < volumesArray.count(); i++)
            {
                if (volumesArray[i].isArray())
                {
                    auto volumeArray = volumesArray[i].toArray();
                    for (auto episodeJson: volumeArray)
                    {
                        auto episodeObj = episodeJson.toObject();
                        api::Episode track(episodeObj["id"].toInteger(-1));
                        deserialize(episodeObj, &track);
                        podcast->episodes.append(track);
                    }
                }
            }
        }
    }

    void deserialize(const QJsonObject &json, api::Track *track)
    {
        track->title = json["title"].toString();
        track->available = json["available"].toBool();
        track->availableAsRbt = json["availableAsRbt"].toBool();
        track->availableForPremiumUsers = json["availableForPremiumUsers"].toBool();
        track->availableFullWithoutPermission = json["availableFullWithoutPermission"].toBool();
        track->coverUri = json["coverUri"].toString();
        track->ogImage = json["ogImage"].toString();
        track->duration = QTime::fromMSecsSinceStartOfDay(json["durationMs"].toInt());
        track->fileSize = json["fileSize"].toInt(-1);
        track->lyricsAvailable = json["lyricsAvailable"].toBool();
        if (json.contains("lyricsInfo") && json["lyricsInfo"].isObject())
        {
            auto lyricsInfo = json["lyricsInfo"].toObject();
            track->lyricsInfo.hasAvailableSyncLyrics = lyricsInfo["hasAvailableSyncLyrics"].toBool();
            track->lyricsInfo.hasAvailableTextLyrics = lyricsInfo["hasAvailableTextLyrics"].toBool();
        }
        if (json.contains("major") && json["major"].isObject())
        {
            auto major = json["major"].toObject();
            track->major.id = major["id"].toInteger(-1);
            track->major.name = major["name"].toString();
        }
        track->previewDuration = QTime::fromMSecsSinceStartOfDay(json["previewDurationMs"].toInt());
        track->rememberPosition = json["rememberPosition"].toBool();
        if (json.contains("regions") && json["regions"].isArray())
        {
            auto regions = json["regions"].toArray();
            track->regions.resize(regions.count());
            for (int i = 0; i < regions.count(); i++)
            {
                track->regions[i] = regions[i].toString();
            }
        }
        if (json.contains("albums") && json["albums"].isArray())
        {
            for (auto albumJson: json["albums"].toArray())
            {
                auto albumObj = albumJson.toObject();
                api::Album podcast(albumObj["id"].toInteger(-1));
                deserialize(albumObj, &podcast);
                track->albums.append(podcast);
            }
        }
        if (json.contains("artists") && json["artists"].isArray())
        {
            for (auto artistJson: json["artists"].toArray())
            {
                auto artistObj = artistJson.toObject();
                api::Artist artist(artistObj["id"].toInteger(-1));
                deserialize(artistObj, &artist);
                track->artists.append(artist);
            }
        }
    }

    template<typename T>
    void deserializeSearchPartShared(const QJsonObject &json, api::SearchResult::Part<T> &part)
    {
        part.total = json["total"].toInt(-1);
        part.perPage = json["perPage"].toInt(-1);
        part.order = json["order"].toInt(-1);
    }

    void deserializeSearchResult(const QJsonObject &json, api::SearchResult &result)
    {
        if (json.contains("result"))
        {
            auto searchResult = json["result"].toObject();
            result.misspellCorrected = searchResult["misspellCorrected"].toBool();
            result.noCorrect = searchResult["nocorrect"].toBool();
            result.text = searchResult["text"].toString();
            result.misspellResult = searchResult["misspellResult"].toString();
            result.misspellOriginal = searchResult["misspellOriginal"].toString();

            if (searchResult.contains("best"))
            {

            }

            if (searchResult.contains("albums"))
            {
                auto albumsPart = searchResult["albums"].toObject();
                deserializeSearchPartShared(albumsPart, result.albums);
                if (albumsPart.contains("results"))
                {
                    auto albums = albumsPart["result"].toArray();
                    for (auto albumJson: albums)
                    {
                        auto albumObj = albumJson.toObject();
                        api::Album album(albumObj["id"].toInteger(-1));
                        deserialize(albumObj, &album);
                        result.albums.results.append(album);
                    }
                }
            }
            if (searchResult.contains("artists"))
            {
                auto artistsPart = searchResult["artists"].toObject();
                deserializeSearchPartShared(artistsPart, result.artists);
                if (artistsPart.contains("results"))
                {
                    auto artists = artistsPart["result"].toArray();
                    for (auto artistJson: artists)
                    {
                        auto artistObj = artistJson.toObject();
                        api::Artist artist(artistObj["id"].toInteger(-1));
                        deserialize(artistObj, &artist);
                        result.artists.results.append(artist);
                    }
                }
            }
            if (searchResult.contains("playlists"))
            {
                auto playlistsPart = searchResult["playlists"].toObject();
                deserializeSearchPartShared(playlistsPart, result.playlists);
                if (playlistsPart.contains("results"))
                {
                    auto playlists = playlistsPart["result"].toArray();
                    for (auto playlistJson: playlists)
                    {
                        auto playlistObj = playlistJson.toObject();
                        api::Playlist playlist(playlistObj["uid"].toInteger(-1));
                        deserialize(playlistObj, &playlist);
                        result.playlists.results.append(playlist);
                    }
                }
            }
            if (searchResult.contains("podcast_episodes"))
            {
                auto episodesPart = searchResult["podcast_episodes"].toObject();
                deserializeSearchPartShared(episodesPart, result.episodes);
                if (episodesPart.contains("results"))
                {
                    auto episodes = episodesPart["result"].toArray();
                    for (auto episodeJson: episodes)
                    {
                        auto episodeObj = episodeJson.toObject();
                        api::Episode episode(episodeObj["id"].toInteger(-1));
                        deserialize(episodeObj, &episode);
                        result.episodes.results.append(episode);
                    }
                }
            }
            if (searchResult.contains("podcasts"))
            {
                auto podcastsPart = searchResult["podcasts"].toObject();
                deserializeSearchPartShared(podcastsPart, result.podcasts);
                if (podcastsPart.contains("results"))
                {
                    auto podcasts = podcastsPart["result"].toArray();
                    for (auto podcastJson: podcasts)
                    {
                        auto podcastObj = podcastJson.toObject();
                        api::Podcast podcast(podcastObj["id"].toInteger(-1));
                        deserialize(podcastJson.toObject(), &podcast);
                        result.podcasts.results.append(podcast);
                    }
                }
            }
            if (searchResult.contains("tracks"))
            {
                auto tracksPart = searchResult["tracks"].toObject();
                deserializeSearchPartShared(tracksPart, result.tracks);
                if (tracksPart.contains("results"))
                {
                    auto tracks = tracksPart["result"].toArray();
                    for (auto trackJson: tracks)
                    {
                        auto trackObj = trackJson.toObject();
                        api::Track track(trackObj["id"].toInteger(-1));
                        deserialize(trackObj, &track);
                        result.tracks.results.append(track);
                    }
                }
            }
        }
    }

    void deserializeSearchSuggestions(const QJsonObject &json, api::SearchSuggestions &result)
    {
        if (json.contains("result"))
        {
            auto suggestResult = json["result"].toObject();
            if (suggestResult.contains("suggestions"))
            {
                auto suggestions = suggestResult["suggestions"].toArray();
                for (auto suggestions: suggestions)
                {
                    result.suggestions.append(suggestions.toString());
                }
            }
        }
    }

    QJsonDocument tryReadJsonResponse(QNetworkReply *reply)
    {
        QJsonParseError parseError;
        auto response = QJsonDocument::fromJson(reply->readAll(), &parseError);
        reply->deleteLater();
        if (parseError.error != QJsonParseError::NoError)
        {

        }

        if (response.isObject() && response.object().contains("error"))
        {

        }
        return response;
    }
}
