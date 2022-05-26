#include "album.h"

namespace api
{
    Album::Album(qint64 id): id(id) { }

    qint64 Album::getId()
    {
        return id;
    }

    Entity::Type Album::getType()
    {
        return Entity::Type::ALBUM;
    }

    Track::Track(qint64 id): id(id) { }

    qint64 Track::getId()
    {
        return id;
    }

    Entity::Type Track::getType()
    {
        return Entity::Type::TRACK;
    }
}
