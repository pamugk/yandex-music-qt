#include "user.h"

namespace api
{
    User::User(qint64 id): id(id){ }
    
    qint64 User::getId()
    {
        return id;
    }
    
    Entity::Type User::getType()
    {
        return Entity::Type::USER;
    }
}
