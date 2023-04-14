#ifndef __LAYOUT_H__
#define __LAYOUT_H__

#include <IMenuBarFactorySubscriber.h>
#include <MenuBarBase.h>
#include <QPushButton>

class Layout : public QWidget, public MenuBarBase
{
    Q_OBJECT
public:
    explicit Layout(QWidget* parent = 0);
    virtual ~Layout();
    void         menuBarUpdate(std::string event_type, std::string data) override;
    QAction*     getGoHomeActionObj();
    QAction*     getChangeBgColorActionObj();
    QPushButton* getBtnObj() const;

protected:
    void resizeEvent(QResizeEvent* event) override;

private:
    QMenuBar*    menu_bar_;
    QAction*     go_home_act_;
    QAction*     change_bg_act_;
    QPushButton* button_;
};

#endif //  __LAYOUT_H__
