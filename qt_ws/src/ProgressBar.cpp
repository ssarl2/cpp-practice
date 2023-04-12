#include <ProgressBar.h>

#include <QDebug>
#include <QPushButton>
#include <iostream>
#include <sstream>

ProgressBar::ProgressBar(QWidget* parent) : QWidget(parent)
{
    qDebug() << "Progressbar ctor";
    menu_bar_            = createMenuBar(this);
    QMenu*   test_menu   = createMenu(menu_bar_, "test_menu");
    QAction* test_action = createAction(test_menu, "test_action");

    home_btn_ = new QPushButton("my_button", this);
    home_btn_->move(20, 40);
    home_btn_->setStyleSheet("background-color: red;");
}

ProgressBar::~ProgressBar()
{
    qDebug() << "Progressbar dtor";
}

QPushButton* ProgressBar::getHomeBtnObj() const
{
    return home_btn_;
}

void ProgressBar::resizeEvent(QResizeEvent* event)
{
    QWidget::resizeEvent(event);
    int width_btn  = static_cast<int>(static_cast<double>(width()) * 0.2);
    int height_btn = static_cast<int>(static_cast<double>(height()) * 0.2);
    int x_btn      = static_cast<int>(static_cast<double>(width()) * 0.07);
    int y_btn      = static_cast<int>(static_cast<double>(height()) * 0.1) + 20;
    int font_size  = static_cast<int>(static_cast<double>(width_btn) * 0.18);
    std::stringstream ss;
    ss << "QPushButton {font-size:" << font_size
       << "px; background-color: red;}";
    home_btn_->setStyleSheet(ss.str().c_str());
    home_btn_->move(x_btn, y_btn);
    home_btn_->resize(width_btn, height_btn);
}

void ProgressBar::menuBarUpdate()
{
}