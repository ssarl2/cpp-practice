#include <MenuBarPublisher.h>

class MenuBarAction : public MenuBarPublisher
{
public:
    MenuBarAction();
    void changeBackgroundColor();
    void exitApp();
    void goHome();
};