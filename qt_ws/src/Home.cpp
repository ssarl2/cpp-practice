#include "Home.h"

#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <iostream>

Home::Home(int width, int height, QWidget* parent) : QWidget(parent)
{
    setFixedSize(width, height);
    menu_bar_            = createMenuBar(this);
    QMenu*   test_menu   = createMenu(menu_bar_, "test_menu");
    QAction* test_action = createAction(test_menu, "test_action");
}

void Home::signal()
{
}

void Home::slot()
{
}

void Home::menuBarUpdate()
{
}