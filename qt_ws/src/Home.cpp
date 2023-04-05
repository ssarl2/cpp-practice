#include <Home.h>

#include <QApplication>
#include <QDebug>
#include <QLabel>
#include <QPushButton>
#include <QStyleOptionButton>
#include <iostream>

Home::Home(QWidget* parent) : QWidget(parent)
{
    menu_bar_            = createMenuBar(this);
    QMenu*   test_menu   = createMenu(menu_bar_, "test_menu");
    QAction* test_action = createAction(test_menu, "test_action");

    container_widget_ = new QWidget(this);
    container_widget_->setFixedSize(width(), height());
    container_widget_->move(10, 20);
    QVBoxLayout* layout = new QVBoxLayout(container_widget_);
    stacked_widget_     = new QStackedWidget(this);
    stacked_widget_->move(0, menu_bar_->height());
    stacked_widget_->setStyleSheet("background-color: yellow;");
    stacked_widget_->setFixedSize(width(), height());

    stacked_widget_->addWidget(container_widget_);

    QPushButton* progress_bar_btn =
        new QPushButton("ProgressBar", container_widget_);

    layout->addWidget(progress_bar_btn);

    progress_bar_btn->move(20, 50);
    progress_bar_btn->setStyleSheet("background-color: blue;");

    qDebug() << "before" << stacked_widget_->count()
             << stacked_widget_->currentIndex();

    qDebug() << menu_bar_->width() << menu_bar_->height();

    pb_ = new ProgressBar;
    stacked_widget_->addWidget(pb_);

    QObject::connect(
        progress_bar_btn, &QPushButton::clicked, this, &Home::openProgressBar);
    QObject::connect(pb_, &QObject::destroyed, this, &Home::comeBackHome);
}

void Home::resizeEvent(QResizeEvent* event)
{
    QWidget::resizeEvent(event);
    container_widget_->setFixedSize(width(), height());
    stacked_widget_->setFixedSize(width(), height());
}

void Home::menuBarUpdate()
{
}

void Home::createLayout()
{
    container_widget_ = new QWidget(this);
    stacked_widget_   = new QStackedWidget(this);
    stacked_widget_->addWidget(container_widget_);

    QPushButton* progress_bar_btn =
        new QPushButton("ProgressBar", container_widget_);

    progress_bar_btn->move(20, 50);
    progress_bar_btn->setStyleSheet("background-color: blue;");

    qDebug() << "before" << stacked_widget_->count()
             << stacked_widget_->currentIndex();

    pb_ = new ProgressBar;
    stacked_widget_->addWidget(pb_);

    QObject::connect(
        progress_bar_btn, &QPushButton::clicked, this, &Home::openProgressBar);
}

void Home::openProgressBar()
{
    pb_->setFixedSize(width(), height());

    stacked_widget_->setCurrentIndex(1);
    QObject::connect(
        pb_->getButtonObj(), &QPushButton::clicked, this, &Home::comeBackHome);
}

void Home::comeBackHome()
{
    stacked_widget_->setCurrentIndex(0);
}