#include <Layout.h>

#include <QDebug>
#include <iostream>
#include <sstream>

Layout::Layout(QWidget* parent) : QWidget(parent)
{
    menu_bar_    = createMenuBar(this);
    QMenu* menu1 = createMenu(menu_bar_, "Menu1");
    go_home_act_ = createAction(menu1, "GoHome");

    button_ = new QPushButton("Button", this);
}

Layout::~Layout()
{
    qDebug() << "Progressbar dtor";
}

QPushButton* Layout::getBtnObj() const
{
    return button_;
}

void Layout::resizeEvent(QResizeEvent* event)
{
    QWidget::resizeEvent(event);
    int width_btn  = static_cast<int>(static_cast<double>(width()) * 0.2);
    int height_btn = static_cast<int>(static_cast<double>(height()) * 0.12);
    int x_btn      = static_cast<int>(static_cast<double>(width()) * 0.07);
    int y_btn      = static_cast<int>(static_cast<double>(height()) * 0.1) + 20;
    int font_size  = static_cast<int>(static_cast<double>(width_btn) * 0.18);
    std::stringstream ss;
    ss << "QPushButton {font-size:" << font_size
       << "px; background-color: red;}";

    menu_bar_->resize(width(), 22);
    button_->setStyleSheet(ss.str().c_str());
    button_->move(x_btn, y_btn);
    button_->resize(width_btn, height_btn);
}

void Layout::menuBarUpdate(std::string data)
{
    qDebug() << data.c_str();
    qDebug() << "Hello, it's Home here";
}

QAction* Layout::getGoHomeActionObj()
{
    return go_home_act_;
}