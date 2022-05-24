#include "user.h"

namespace api
{
    User::User(long id): id(id){ }
    
    long User::getId()
    {
        return id;
    }
    
    Entity::Type User::getType()
    {
        return Entity::Type::USER;
    }
}
