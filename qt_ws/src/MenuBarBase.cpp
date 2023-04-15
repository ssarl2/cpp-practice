#include <MenuBarBase.h>
#include <QApplication>
#include <QObject>
#include <qglobal.h>

QMenuBar* MenuBarBase::createMenuBar(QWidget* widget)
{
    QMenuBar* menu_bar  = new QMenuBar(widget);

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