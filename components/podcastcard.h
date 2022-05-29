#ifndef PODCASTCARD_H
#define PODCASTCARD_H

#include <QWidget>

namespace Ui {
class PodcastCard;
}

class PodcastCard : public QWidget
{
    Q_OBJECT

public:
    explicit PodcastCard(QWidget *parent = nullptr);
    ~PodcastCard();

private:
    Ui::PodcastCard *ui;
};

#endif // PODCASTCARD_H
