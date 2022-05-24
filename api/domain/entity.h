#ifndef ENTITY_H
#define ENTITY_H

namespace api
{

    struct Entity
    {
        enum Type
        {
            ALBUM,
            ARTIST,
            EPISODE,
            PLAYLIST,
            PODCAST,
            TRACK,
            USER,
            VIDEO
        };

        virtual long getId() = 0;
        virtual Type getType() = 0;
    };
}

#endif // ENTITY_H
