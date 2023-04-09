#include "IMenuBarFactorySubscriber.h"

#include <list>

class MenuBarPublisher
{
public:
    MenuBarPublisher();
    void subscribe(IMenuBarFactorySubscriber* subscriber);
    void unsubscribe(IMenuBarFactorySubscriber* subscriber);
    void notify();

private:
    std::list<IMenuBarFactorySubscriber*> list_subscriber_;
};