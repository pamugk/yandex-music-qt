#include "episode.h"

namespace api
{
    Episode::Episode(long id): id(id) {}

    long Episode::getId()
    {
        return id;
    }

    Entity::Type Episode::getType()
    {
        return Entity::Type::EPISODE;
    }
}
