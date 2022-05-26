#include "artist.h"

namespace api
{
Artist::Artist(qint64 id): id(id) { }

    qint64 Artist::getId()
    {
        return id;
    }

    Entity::Type Artist::getType()
    {
        return Entity::Type::ARTIST;
    }
}
