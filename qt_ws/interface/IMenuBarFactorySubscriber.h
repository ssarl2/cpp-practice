
class IMenuBarFactorySubscriber
{
public:
    virtual void signal()        = 0;
    virtual void slot()          = 0;
    virtual void menuBarUpdate() = 0;
    virtual void goHome()        = 0;
    virtual void exitApp()       = 0;
};