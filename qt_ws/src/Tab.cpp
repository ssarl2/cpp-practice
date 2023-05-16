#include <Tab.h>

#include <QApplication>
#include <QDebug>
#include <sstream>

Tab::Tab(QWidget* parent) : QMainWindow(parent)
{
    menu_bar_      = createMenuBar(this);
    QMenu* menu1   = createMenu(menu_bar_, "Menu1");
    go_home_act_   = createAction(menu1, "GoHome");
    change_bg_act_ = createAction(menu1, "ChangeBgColor");
    exit_app_act_  = createAction(menu1, "Exit");

    content_widget_ = new QWidget(this);

    tab_widget_   = new QTabWidget(content_widget_);
    QWidget* tab2 = new QWidget();
    QWidget* tab1 = new QWidget();
    tab_widget_->addTab(tab1, "Tab1");
    tab_widget_->addTab(tab2, "Tab2");

    te1_ = new QTextEdit(tab1);
    te2_ = new QTextEdit(tab2);
    te1_->setText("This is Tab1");
    te2_->setText("This is Tab2");
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

    int tb_width =
        static_cast<int>(static_cast<double>(content_widget_->width()) * 0.8);
    int tb_height =
        static_cast<int>(static_cast<double>(content_widget_->height()) * 0.8);
    int tb_x =
        static_cast<int>(static_cast<double>(content_widget_->width()) * 0.1);
    int tb_y =
        static_cast<int>(static_cast<double>(content_widget_->height()) * 0.1);
    tab_widget_->setGeometry(tb_x, tb_y, tb_width, tb_height);

    std::stringstream ss;

    // text editor
    int te_width     = static_cast<int>(static_cast<double>(width()) * 0.2);
    int te_height    = static_cast<int>(static_cast<double>(height()) * 0.12);
    int te_x         = static_cast<int>(static_cast<double>(width()) * 0.07);
    int te_y         = static_cast<int>(static_cast<double>(height()) * 0.1);
    int te_font_size = static_cast<int>(static_cast<double>(te_width) * 0.13);
    ss << "QTextEdit {font-size:" << (te_font_size > 0 ? te_font_size : 1)
       << "px;}";

    te1_->setStyleSheet(ss.str().c_str());
    te1_->move(te_x, te_y);
    te1_->resize(te_width, te_height);

    te2_->setStyleSheet(ss.str().c_str());
    te2_->move(te_x, te_y);
    te2_->resize(te_width, te_height);
}
