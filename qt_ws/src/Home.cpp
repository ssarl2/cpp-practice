#include <Home.h>

#include <QDebug>
#include <iostream>
#include <sstream>

Home::Home(QWidget* parent) : QWidget(parent)
{
    menu_bar_            = createMenuBar(this);
    QMenu*   test_menu   = createMenu(menu_bar_, "test_menu");
    QAction* test_action = createAction(test_menu, "test_action");

    progress_bar_btn_ = new QPushButton("Progress Bar", this);
    layout_btn_       = new QPushButton("Layout Bar", this);
}

Home::~Home()
{
    qDebug() << "Home dtor";
}

void Home::resizeEvent(QResizeEvent* event)
{
    QWidget::resizeEvent(event);
    std::stringstream ss;

    menu_bar_->resize(width(), 22);

    // progress bar button
    int pb_btn_width  = static_cast<int>(static_cast<double>(width()) * 0.2);
    int pb_btn_height = static_cast<int>(static_cast<double>(height()) * 0.12);
    int pb_btn_x      = static_cast<int>(static_cast<double>(width()) * 0.07);
    int pb_btn_y = static_cast<int>(static_cast<double>(height()) * 0.1) + 20;
    int pb_font_size =
        static_cast<int>(static_cast<double>(pb_btn_width) * 0.13);
    ss << "QPushButton {font-size:" << (pb_font_size > 0 ? pb_font_size : 1)
       << "px; background-color: blue;}";

    progress_bar_btn_->setStyleSheet(ss.str().c_str());
    progress_bar_btn_->move(pb_btn_x, pb_btn_y);
    progress_bar_btn_->resize(pb_btn_width, pb_btn_height);

    // layout button
    int lo_btn_width  = static_cast<int>(static_cast<double>(width()) * 0.2);
    int lo_btn_height = static_cast<int>(static_cast<double>(height()) * 0.12);
    int lo_btn_x      = static_cast<int>(static_cast<double>(width()) * 0.07) +
                   pb_btn_width + pb_btn_x + 20;
    int lo_btn_y = static_cast<int>(static_cast<double>(height()) * 0.1) + 20;
    int lo_font_size =
        static_cast<int>(static_cast<double>(lo_btn_width) * 0.16);
    ss << "QPushButton {font-size:" << (lo_font_size > 0 ? lo_font_size : 1)
       << "px; background-color: yellow;}";

    layout_btn_->setStyleSheet(ss.str().c_str());
    layout_btn_->move(lo_btn_x, lo_btn_y);
    layout_btn_->resize(lo_btn_width, lo_btn_height);
}

QPushButton* Home::getProgressBarBtnObj() const
{
    return progress_bar_btn_;
}

QPushButton* Home::getLayoutBtnObj() const
{
    return layout_btn_;
}

void Home::menuBarUpdate(std::string data)
{
    qDebug() << data.c_str();
    qDebug() << "Hello, it's Home here";
}