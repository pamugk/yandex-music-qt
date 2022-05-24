#include "playlist.h"

namespace api
    {
    Playlist::Playlist(long id):id(id) { }

    long Playlist::getId()
    {
        return id;
    }

    Entity::Type Playlist::getType()
    {
        return Entity::Type::PLAYLIST;
    }
}
