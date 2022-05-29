#include "playlistcard.h"
#include "ui_playlistcard.h"

PlaylistCard::PlaylistCard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlaylistCard)
{
    ui->setupUi(this);
}

PlaylistCard::~PlaylistCard()
{
    delete ui;
}
