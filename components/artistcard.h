#ifndef ARTISTCARD_H
#define ARTISTCARD_H

#include <QWidget>

namespace Ui {
class ArtistCard;
}

class ArtistCard : public QWidget
{
    Q_OBJECT

public:
    explicit ArtistCard(QWidget *parent = nullptr);
    ~ArtistCard();

private:
    Ui::ArtistCard *ui;
};

#endif // ARTISTCARD_H
