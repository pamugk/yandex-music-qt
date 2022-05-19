#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
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

