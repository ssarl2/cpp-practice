#include "IMenuBarFactorySubscriber.h"

class MenuBarBase : public IMenuBarFactorySubscriber
{
public:
    QMenuBar* createMenuBar(QWidget* widget) override;
    QMenu*    createMenu(QMenuBar* menu_bar, std::string menu_name) override;
    QAction*  createAction(QMenu* menu, std::string action_name) override;
};