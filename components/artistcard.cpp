#include "artistcard.h"
#include "ui_artistcard.h"

ArtistCard::ArtistCard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ArtistCard)
{
    ui->setupUi(this);
}

ArtistCard::~ArtistCard()
{
    delete ui;
}
