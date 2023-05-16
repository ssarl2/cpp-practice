#include <Home.h>

#include <QApplication>
#include <QDebug>
#include <QGridLayout>
#include <iostream>
#include <sstream>

Home::Home(QWidget* parent) : QMainWindow(parent)
{
    menu_bar_      = createMenuBar(this);
    QMenu* menu1   = createMenu(menu_bar_, "Menu1");
    change_bg_act_ = createAction(menu1, "ChangeBgColor - Reset");
    exit_app_act_  = createAction(menu1, "Exit");

    content_widget_       = new QWidget(this);
    QGridLayout* g_layout = new QGridLayout(content_widget_);

    progress_bar_btn_ = new QPushButton("Progress Bar", this);
    layout_btn_       = new QPushButton("Layout", this);
    tab_btn_          = new QPushButton("Tab", this);

    g_layout->addWidget(progress_bar_btn_, 0, 0, 1, 1);
    g_layout->addWidget(layout_btn_, 0, 1, 1, 1);
    g_layout->addWidget(tab_btn_, 0, 2, 1, 1);

    content_widget_->setLayout(g_layout);
}

Home::~Home()
{
    qDebug() << "Home dtor";
}

void Home::menuBarUpdate(std::string event_type, std::string data)
{
    if (event_type == "changeBgColor")
    {
        setStyleSheet(data.c_str());
    }
    else if (event_type == "exitApp")
    {
        QApplication::quit();
    }
}

QAction* Home::getChangeBgColorActionObj() const
{
    return change_bg_act_;
}

QAction* Home::getExitAppActionObj() const
{
    return exit_app_act_;
}

QPushButton* Home::getProgressBarBtnObj() const
{
    return progress_bar_btn_;
}

QPushButton* Home::getLayoutBtnObj() const
{
    return layout_btn_;
}

QPushButton* Home::getTabBtnObj() const
{
    return tab_btn_;
}

void Home::resizeEvent(QResizeEvent* event)
{
    QWidget::resizeEvent(event);
    std::stringstream ss;

    menu_bar_->resize(width(), 25);

    content_widget_->setGeometry(0, 25, width(), height() - 25);

    // progress bar button
    int pb_font_size = static_cast<int>(
        static_cast<double>(progress_bar_btn_->width()) * 0.13);
    ss << "QPushButton {font-size:" << (pb_font_size > 0 ? pb_font_size : 1)
       << "px; background-color: blue;}";
    progress_bar_btn_->setStyleSheet(ss.str().c_str());

    // layout button
    int lo_font_size =
        static_cast<int>(static_cast<double>(layout_btn_->width()) * 0.16);
    ss << "QPushButton {font-size:" << (lo_font_size > 0 ? lo_font_size : 1)
       << "px; background-color: yellow;}";
    layout_btn_->setStyleSheet(ss.str().c_str());

    // tab button
    int tb_font_size =
        static_cast<int>(static_cast<double>(tab_btn_->width()) * 0.16);
    ss << "QPushButton {font-size:" << (tb_font_size > 0 ? tb_font_size : 1)
       << "px; background-color: green;}";
    tab_btn_->setStyleSheet(ss.str().c_str());
}
