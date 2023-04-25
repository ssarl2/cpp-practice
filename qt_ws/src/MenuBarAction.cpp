#include <MenuBarAction.h>
#include <sstream>

MenuBarAction::MenuBarAction()
{
}

/* Actually, this function that uses setStyleSheet under QWidget
 * cannot change background color. Because there is no background
 * QWidget itself. It applies only for the child 'Widgets''s background
 * Check it with border changes.
 */
void MenuBarAction::changeBgColor(std::string color)
{
    std::stringstream ss;
    ss << "color: " << color
       << ";border-style:solid;border-color:pink;border-width:4px;";
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