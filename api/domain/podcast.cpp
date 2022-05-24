#include "podcast.h"

namespace api
{
    Podcast::Podcast(long id): id(id) { }
    
    long Podcast::getId()
    {
        return id;
    }
    
    Entity::Type Podcast::getType()
    {
        return Entity::Type::PODCAST;
    }
}
