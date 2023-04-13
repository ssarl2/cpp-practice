#include <MenuBarPublisher.h>

void MenuBarPublisher::subscribe(IMenuBarFactorySubscriber* sub)
{
    subscribers_.push_back(sub);
}

void MenuBarPublisher::unsubscribe(IMenuBarFactorySubscriber* sub)
{
    subscribers_.remove(sub);
}

void MenuBarPublisher::notify(std::string data)
{
    for (auto sub : subscribers_)
    {
        sub->menuBarUpdate(data);
    }
}