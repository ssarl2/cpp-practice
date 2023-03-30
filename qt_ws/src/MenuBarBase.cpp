#include <MenuBarBase.h>

QMenuBar* MenuBarBase::createMenuBar(QWidget* widget)
{
    QMenuBar* menu_bar  = new QMenuBar(widget);
    QMenu*    file_menu = new QMenu(tr("&File"), menu_bar);
    QAction*  exit_action;

    menu_bar->addMenu(file_menu);
    exit_action = file_menu->addAction(tr("&Exit"));

    return menu_bar;
}

QMenu* MenuBarBase::createMenu(QMenuBar* menu_bar, std::string menu_name)
{
    menu_name   = "&" + menu_name;
    QMenu* menu = new QMenu(tr(menu_name.c_str()), menu_bar);
    menu_bar->addMenu(menu);

    return menu;
}

QAction* MenuBarBase::createAction(QMenu* menu, std::string action_name)
{
    action_name     = "&" + action_name;
    QAction* action = menu->addAction(tr(action_name.c_str()));

    return action;
}