#ifndef SEARCHPAGE_H
#define SEARCHPAGE_H

#include <QTabWidget>

namespace Ui {
class SearchPage;
}

class SearchPage : public QTabWidget
{
    Q_OBJECT

public:
    explicit SearchPage(QWidget *parent = nullptr);
    ~SearchPage();

private:
    Ui::SearchPage *ui;
};

#endif // SEARCHPAGE_H
