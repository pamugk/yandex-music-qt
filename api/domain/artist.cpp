#include "artist.h"

namespace api
{
Artist::Artist(long id): id(id) { }

    long Artist::getId()
    {
        return id;
    }

    Entity::Type Artist::getType()
    {
        return Entity::Type::ARTIST;
    }
}
