#ifndef USER_H
#define USER_H

#include "entity.h"

namespace api
{
    struct User final: public Entity
    {
        User(long id);
        long getId() override;
        Type getType() override;

    private:
        long id;
    };
}

#endif // USER_H
