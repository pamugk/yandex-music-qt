#include "album.h"

namespace api
{
    Album::Album(long id): id(id) { }

    long Album::getId()
    {
        return id;
    }

    Entity::Type Album::getType()
    {
        return Entity::Type::ALBUM;
    }
}
