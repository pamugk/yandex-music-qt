#include "api/utils/json_serialization.h"
#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QtDebug>
#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , apiClient(new api::YandexMusic)
{
    ui->setupUi(this);

    searchSuggestionTimer.setSingleShot(true);
    searchSuggestionTimer.setInterval(500);
    connect(&searchSuggestionTimer, &QTimer::timeout,
            this, &MainWindow::searchSuggest);

    ui->searchSuggestionList->setWindowFlags(Qt::Popup);
    ui->searchSuggestionList->setFocusPolicy(Qt::NoFocus);
    ui->searchSuggestionList->setFocusProxy(ui->searchLineEdit);
    ui->searchSuggestionList->hide();
    ui->searchSuggestionList->installEventFilter(this);
}

bool MainWindow::eventFilter(QObject *obj, QEvent *ev)
{
    if (obj != ui->searchSuggestionList)
    {
        return false;
    }

    if (ev->type() == QEvent::MouseButtonPress)
    {
        ui->searchSuggestionList->hide();
        ui->searchLineEdit->setFocus();
        return true;
    }

    if (ev->type() == QEvent::KeyPress)
    {
        int key = static_cast<QKeyEvent*>(ev)->key();
        switch (key)
        {
            case Qt::Key_Up:
            case Qt::Key_Down:
            case Qt::Key_Home:
            case Qt::Key_End:
            case Qt::Key_PageUp:
            case Qt::Key_PageDown:
                break;
            default:
                ui->searchLineEdit->setFocus();
                ui->searchLineEdit->event(ev);
                break;
        }
    }

    return false;
}

MainWindow::~MainWindow()
{
    delete ui;
    delete apiClient;
}


void MainWindow::on_toggleNavBtn_toggled(bool checked)
{
    auto action = checked ?
                [](QPushButton *child)
                {
                    child->setText(child->property("origText").toString());
                    child->setProperty("origText", {});
                } :
                [](QPushButton *child)
                {
                    child->setProperty("origText", child->text());
                    child->setText("");
                };
    for (auto child: ui->navbar->findChildren<QPushButton *>(QString(), Qt::FindDirectChildrenOnly)) {
        action(child);
    }
}

void setAndUpdateProperty(QWidget *widget, const char *property, const QVariant value)
{
    widget->setProperty(property, value);
    widget->style()->unpolish(widget);
    widget->style()->polish(widget);
}

void activateButton(QPushButton *activatedButton, QList<QPushButton *> allButtons)
{
    for (auto deactivatedButton: allButtons) {
        setAndUpdateProperty(deactivatedButton, "active", false);
    }

    setAndUpdateProperty(activatedButton, "active", true);
}

void MainWindow::on_homeBtn_clicked()
{
    activateButton(ui->homeBtn, ui->navbar->findChildren<QPushButton *>(QString(), Qt::FindDirectChildrenOnly));
}


void MainWindow::on_podcastsBtn_clicked()
{
    activateButton(ui->podcastsBtn, ui->navbar->findChildren<QPushButton *>(QString(), Qt::FindDirectChildrenOnly));
}


void MainWindow::on_radioBtn_clicked()
{
    activateButton(ui->radioBtn, ui->navbar->findChildren<QPushButton *>(QString(), Qt::FindDirectChildrenOnly));
}


void MainWindow::on_searchLineEdit_textEdited(const QString &searchQuery)
{
    searchSuggestionTimer.stop();
    ui->searchSuggestionList->clear();
    ui->searchSuggestionList->hide();
    searchSuggestionTimer.start();
}

void MainWindow::searchSuggest()
{
    if (!ui->searchLineEdit->text().isEmpty())
    {
        searchSuggestionsReply = apiClient->findSearchSuggestions(ui->searchLineEdit->text());
        connect(searchSuggestionsReply, &QNetworkReply::errorOccurred, [this](QNetworkReply::NetworkError error){
            qDebug() << error << "\n";
            this->searchSuggestionsReply->deleteLater();
            this->searchSuggestionsReply = nullptr;
        });
        connect(searchSuggestionsReply, &QNetworkReply::finished, this, &MainWindow::onSearchSuggestionsResponse);
    }
}

void MainWindow::onSearchSuggestionsResponse()
{
    if (searchSuggestionsReply == nullptr)
    {
        return;
    }

    qDebug() << "Success\n";
    auto response = utils::tryReadJsonResponse(searchSuggestionsReply).object();
    searchSuggestionsReply = nullptr;
    api::SearchSuggestions searchSuggestions;
    utils::deserializeSearchSuggestions(response, searchSuggestions);
    for (auto suggestion: searchSuggestions.suggestions)
    {
        ui->searchSuggestionList->addItem(new QListWidgetItem(suggestion, ui->searchSuggestionList));
    }

    if (!searchSuggestions.suggestions.isEmpty())
    {
        ui->searchSuggestionList->move(ui->searchLineEdit->mapToGlobal(QPoint(0, ui->searchLineEdit->height())));
        ui->searchSuggestionList->setMinimumWidth(ui->searchLineEdit->width());
        ui->searchSuggestionList->setMaximumWidth(ui->searchLineEdit->width());
        ui->searchSuggestionList->setFocus();
        ui->searchSuggestionList->show();
    }
}


void MainWindow::on_searchSuggestionList_itemClicked(QListWidgetItem *item)
{
    ui->searchLineEdit->setText(item->text());
    ui->searchSuggestionList->clear();
    ui->searchSuggestionList->hide();
}


void MainWindow::on_searchLineEdit_returnPressed()
{
    if (!ui->searchLineEdit->text().isEmpty())
    {
        ui->searchSuggestionList->clear();
        ui->searchSuggestionList->hide();
        qDebug() << "Do search";
    }
}

