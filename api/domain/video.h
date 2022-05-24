#ifndef VIDEO_H
#define VIDEO_H

#include "entity.h"

namespace api
{
    struct Video final: public Entity
    {
        Video(long id);
        long getId() override;
        Type getType() override;
    private:
        long id;
    };
}

#endif // VIDEO_H
