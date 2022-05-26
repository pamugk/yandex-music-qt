#ifndef USER_H
#define USER_H

#include "entity.h"

namespace api
{
    struct User final: public Entity
    {
        User(qint64 id);
        qint64 getId() override;
        Type getType() override;

    private:
        qint64 id;
    };
}

#endif // USER_H
