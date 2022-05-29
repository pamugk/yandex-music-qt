#ifndef PLAYLISTCARD_H
#define PLAYLISTCARD_H

#include <QWidget>

namespace Ui {
class PlaylistCard;
}

class PlaylistCard : public QWidget
{
    Q_OBJECT

public:
    explicit PlaylistCard(QWidget *parent = nullptr);
    ~PlaylistCard();

private:
    Ui::PlaylistCard *ui;
};

#endif // PLAYLISTCARD_H
