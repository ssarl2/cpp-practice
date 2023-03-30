#include "IMenuBarFactorySubscriber.h"

#include <QWidget>

class Home : public QWidget, public IMenuBarFactorySubscriber
{
Q_OBJECT
public:
    explicit Home(int width, int height, QWidget *parent = 0);
    void signal() override;
    void slot() override;
    void menuBarUpdate() override;
    void goHome () override;
    void exitApp() override;
};