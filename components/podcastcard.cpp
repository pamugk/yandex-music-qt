#include "podcastcard.h"
#include "ui_podcastcard.h"

PodcastCard::PodcastCard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PodcastCard)
{
    ui->setupUi(this);
}

PodcastCard::~PodcastCard()
{
    delete ui;
}
