#include "video.h"

namespace api
{
    Video::Video(long id): id(id) { }
    
    long Video::getId()
    {
        return id;
    }
    
    Entity::Type Video::getType()
    {
        return Entity::Type::VIDEO;
    }
}
