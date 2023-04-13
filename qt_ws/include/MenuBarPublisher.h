#ifndef __MENU_BAR_PUBLISHER_H__
#define __MENU_BAR_PUBLISHER_H__

#include <IMenuBarFactorySubscriber.h>

#include <list>

class MenuBarPublisher
{
public:
    void subscribe(IMenuBarFactorySubscriber* sub);
    void unsubscribe(IMenuBarFactorySubscriber* sub);
    void notify(std::string data);

private:
    std::list<IMenuBarFactorySubscriber*> subscribers_;
};

#endif // __MENU_BAR_PUBLISHER_H__
