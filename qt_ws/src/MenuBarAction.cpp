#include <MenuBarAction.h>

MenuBarAction::MenuBarAction()
{
}

void MenuBarAction::changeBackgroundColor()
{
    notify("changeBackgroundColor", "It's from changeBackgroundColor");
}

void MenuBarAction::exitApp()
{
    notify("exitApp", "It's from exitApp");
}

void MenuBarAction::goHome()
{
    notify("goHome", "It's from goHome");
}