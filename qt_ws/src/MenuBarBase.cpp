#include <MenuBarBase.h>
#include <QApplication>
#include <QObject>
#include <qglobal.h>

QMenuBar* MenuBarBase::createMenuBar(QWidget* widget)
{
    QMenuBar* menu_bar  = new QMenuBar(widget);
    QMenu*    file_menu = new QMenu(QObject::tr("&File"), menu_bar);
    QAction*  exit_action;

    menu_bar->addMenu(file_menu);
    exit_action = file_menu->addAction(QObject::tr("&Exit"));

    QObject::connect(
        exit_action, SIGNAL(triggered()), QApplication::instance(),
        SLOT(quit()));

    return menu_bar;
}

QMenu* MenuBarBase::createMenu(QMenuBar* menu_bar, std::string menu_name)
{
    menu_name   = "&" + menu_name;
    QMenu* menu = new QMenu(QObject::tr(menu_name.c_str()), menu_bar);
    menu_bar->addMenu(menu);

    return menu;
}

QAction* MenuBarBase::createAction(QMenu* menu, std::string action_name)
{
    action_name     = "&" + action_name;
    QAction* action = menu->addAction(QObject::tr(action_name.c_str()));

    return action;
}