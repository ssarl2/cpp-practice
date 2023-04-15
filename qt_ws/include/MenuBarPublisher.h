#ifndef __MENU_BAR_PUBLISHER_H__
#define __MENU_BAR_PUBLISHER_H__

#include <IMenuBarFactorySubscriber.h>

#include <map>

class MenuBarPublisher
{
public:
    void subscribe(std::string event_type, IMenuBarFactorySubscriber* sub);
    void unsubscribe(std::string event_type, IMenuBarFactorySubscriber* sub);

protected:
    void notify(std::string event_type, std::string data);

private:
    std::multimap<std::string, IMenuBarFactorySubscriber*> subscribers_;
};

#endif // __MENU_BAR_PUBLISHER_H__
