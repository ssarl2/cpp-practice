#include <ProgressBar.h>

#include <QApplication>
#include <QDebug>
#include <iostream>
#include <sstream>

ProgressBar::ProgressBar(QWidget* parent) : QMainWindow(parent)
{
    menu_bar_      = createMenuBar(this);
    QMenu* menu1   = createMenu(menu_bar_, "Menu1");
    go_home_act_   = createAction(menu1, "GoHome");
    change_bg_act_ = createAction(menu1, "ChangeBgColor");
    exit_app_act_  = createAction(menu1, "Exit");

    content_widget_ = new QWidget(this);

    pb_bar_ = new QProgressBar(content_widget_);
    pb_bar_->setRange(0, 100);
    pb_bar_->setValue(50);

    slider_ = new QSlider(content_widget_);
    slider_->setOrientation(Qt::Horizontal);
    slider_->setRange(0, 100);
    slider_->setValue(50);

    QObject::connect(
        slider_, SIGNAL(valueChanged(int)), pb_bar_, SLOT(setValue(int)));
}

ProgressBar::~ProgressBar()
{
    qDebug() << "Progressbar dtor";
}

void ProgressBar::resizeEvent(QResizeEvent* event)
{
    QWidget::resizeEvent(event);

    menu_bar_->resize(width(), 25);
    content_widget_->setGeometry(0, 25, width(), height() - 25);

    pb_bar_->setGeometry(10, height() / 5, width() - 20, height() / 5);
    slider_->setGeometry(10, height() / 3, width() - 20, height() / 3);
}

void ProgressBar::menuBarUpdate(std::string event_type, std::string data)
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

QAction* ProgressBar::getGoHomeActionObj() const
{
    return go_home_act_;
}

QAction* ProgressBar::getChangeBgColorActionObj() const
{
    return change_bg_act_;
}

QAction* ProgressBar::getExitAppActionObj() const
{
    return exit_app_act_;
}