#ifndef __I_MENU_BAR_FACTORY_SUBSCRIBER_H__
#define __I_MENU_BAR_FACTORY_SUBSCRIBER_H__

#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QWidget>
#include <string>
class IMenuBarFactorySubscriber
{
public:
    virtual QMenuBar* createMenuBar(QWidget* widget)                     = 0;
    virtual void menuBarUpdate(std::string event_type, std::string data) = 0;

private:
    virtual QMenu*   createMenu(QMenuBar* menu_bar, std::string menu_name) = 0;
    virtual QAction* createAction(QMenu* menu, std::string action_name)    = 0;
};

#endif // __I_MENU_BAR_FACTORY_SUBSCRIBER_H__