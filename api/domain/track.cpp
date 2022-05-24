#include "track.h"

namespace api
{
    Track::Track(long id): id(id) { }
    
    long Track::getId()
    {
        return id;
    }
    
    Entity::Type Track::getType()
    {
        return Entity::Type::TRACK;
    }
}
