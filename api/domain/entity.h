#ifndef ENTITY_H
#define ENTITY_H

#include <concepts>
 #include <QtGlobal>

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

        virtual qint64 getId() = 0;
        virtual Type getType() = 0;
    };

    template<typename T>
    concept DomainClass = std::is_base_of<Entity, T>::value;
}

#endif // ENTITY_H
