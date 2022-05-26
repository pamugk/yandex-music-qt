#include "playlist.h"

namespace api
    {
    Playlist::Playlist(qint64 id):id(id) { }

    qint64 Playlist::getId()
    {
        return id;
    }

    Entity::Type Playlist::getType()
    {
        return Entity::Type::PLAYLIST;
    }
}
