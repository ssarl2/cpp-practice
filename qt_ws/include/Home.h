#include "IMenuBarFactorySubscriber.h"
#include "MenuBarBase.h"

class Home : public QWidget, public MenuBarBase
{
public:
    explicit Home(int width, int height, QWidget* parent = 0);
    void signal() override;
    void slot() override;
    void menuBarUpdate() override;

private:
    QMenuBar* menu_bar_;
};