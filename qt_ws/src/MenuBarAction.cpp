#include <MenuBarAction.h>
#include <sstream>

MenuBarAction::MenuBarAction()
{
}

void MenuBarAction::changeBgColor(std::string color)
{
    std::stringstream ss;
    ss << "background-color: " << color << ";";
    notify("changeBgColor", ss.str());
}

void MenuBarAction::exitApp()
{
    notify("exitApp", "It's from exitApp");
}

void MenuBarAction::goHome()
{
    notify("goHome", "It's from goHome");
}