#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>

#include "api/yandexmusic.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    bool eventFilter(QObject *obj, QEvent *ev) override;
    ~MainWindow();

private slots:
    void on_toggleNavBtn_toggled(bool checked);

    void on_homeBtn_clicked();

    void on_podcastsBtn_clicked();

    void on_radioBtn_clicked();

    void on_searchLineEdit_textEdited(const QString &query);

    void searchSuggest();

    void onSearchSuggestionsResponse();

    void on_searchSuggestionList_itemClicked(QListWidgetItem *item);

    void on_searchLineEdit_returnPressed();

private:
    Ui::MainWindow *ui;
    api::YandexMusic *apiClient;

    QTimer searchSuggestionTimer;

    // RESPONSES
    QNetworkReply *searchSuggestionsReply = nullptr;
};
#endif // MAINWINDOW_H
