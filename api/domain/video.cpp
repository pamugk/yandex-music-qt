#include "video.h"

namespace api
{
    Video::Video() { }
    
    qint64 Video::getId()
    {
        return -1;
    }
    
    Entity::Type Video::getType()
    {
        return Entity::Type::VIDEO;
    }
}
