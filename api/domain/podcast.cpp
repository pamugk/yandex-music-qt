#include "podcast.h"

namespace api
{
    Podcast::Podcast(qint64 id): id(id) { }
    
    qint64 Podcast::getId()
    {
        return id;
    }
    
    Entity::Type Podcast::getType()
    {
        return Entity::Type::PODCAST;
    }

    Episode::Episode(qint64 id): id(id) {}

    qint64 Episode::getId()
    {
        return id;
    }

    Entity::Type Episode::getType()
    {
        return Entity::Type::EPISODE;
    }
}
