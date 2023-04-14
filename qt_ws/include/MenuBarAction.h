#include <MenuBarPublisher.h>

class MenuBarAction : public MenuBarPublisher
{
public:
    MenuBarAction();
    void changeBgColor(std::string color);
    void exitApp();
    void goHome();
};