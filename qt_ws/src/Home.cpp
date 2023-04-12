#include <Home.h>

#include <QApplication>
#include <QDebug>
#include <QLabel>
#include <QPushButton>
#include <QStyleOptionButton>
#include <iostream>
#include <sstream>

Home::Home(QWidget* parent) : QWidget(parent)
{
    menu_bar_            = createMenuBar(this);
    QMenu*   test_menu   = createMenu(menu_bar_, "test_menu");
    QAction* test_action = createAction(test_menu, "test_action");

    progress_bar_btn_ = new QPushButton("Progress Bar", this);
}

Home::~Home()
{
    qDebug() << "Home dtor";
}

void Home::resizeEvent(QResizeEvent* event)
{
    QWidget::resizeEvent(event);
    int width_btn  = static_cast<int>(static_cast<double>(width()) * 0.2);
    int height_btn = static_cast<int>(static_cast<double>(height()) * 0.12);
    int x_btn      = static_cast<int>(static_cast<double>(width()) * 0.07);
    int y_btn      = static_cast<int>(static_cast<double>(height()) * 0.1) + 20;
    int font_size  = static_cast<int>(static_cast<double>(width_btn) * 0.13);
    std::stringstream ss;
    ss << "QPushButton {font-size:" << (font_size > 0 ? font_size : 1)
       << "px; background-color: blue;}";

    menu_bar_->resize(width(), 22);
    progress_bar_btn_->setStyleSheet(ss.str().c_str());
    progress_bar_btn_->move(x_btn, y_btn);
    progress_bar_btn_->resize(width_btn, height_btn);
}

QPushButton* Home::getProgressBarBtnObj()
{
    return progress_bar_btn_;
}

void Home::menuBarUpdate()
{
}