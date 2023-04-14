#include <MenuBarPublisher.h>
#include <QDebug>
void MenuBarPublisher::subscribe(
    std::string event_type, IMenuBarFactorySubscriber* sub)
{
    subscribers_.insert({event_type, sub});
}

void MenuBarPublisher::unsubscribe(
    std::string event_type, IMenuBarFactorySubscriber* sub)
{
    auto it = subscribers_.find(event_type);
    if (it != subscribers_.end() && it->second == sub)
    {
        subscribers_.erase(it);
    }
}

void MenuBarPublisher::notify(std::string event_type, std::string data)
{
    for (auto sub : subscribers_)
    {
        if (sub.first == event_type)
        {
            sub.second->menuBarUpdate(event_type, data);
        }
    }
}