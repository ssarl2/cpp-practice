#include <Tab.h>

#include <QApplication>
#include <QDebug>

Tab::Tab(QWidget* parent) : QMainWindow(parent)
{
    menu_bar_      = createMenuBar(this);
    QMenu* menu1   = createMenu(menu_bar_, "Menu1");
    go_home_act_   = createAction(menu1, "GoHome");
    change_bg_act_ = createAction(menu1, "ChangeBgColor");
    exit_app_act_  = createAction(menu1, "Exit");

    content_widget_ = new QWidget(this);
}

Tab::~Tab()
{
    qDebug() << "Tab dtor";
}

void Tab::menuBarUpdate(std::string event_type, std::string data)
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

QAction* Tab::getGoHomeActionObj() const
{
    return go_home_act_;
}

QAction* Tab::getChangeBgColorActionObj() const
{
    return change_bg_act_;
}

QAction* Tab::getExitAppActionObj() const
{
    return exit_app_act_;
}

void Tab::resizeEvent(QResizeEvent* event)
{
    QWidget::resizeEvent(event);

    menu_bar_->resize(width(), 25);

    content_widget_->setGeometry(0, 25, width(), height() - 25);
}
