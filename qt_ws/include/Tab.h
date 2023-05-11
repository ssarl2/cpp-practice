#ifndef __TAB_H__
#define __TAB_H__

#include <IMenuBarFactorySubscriber.h>
#include <MenuBarBase.h>

#include <QMainWindow>
#include <QTabWidget>
#include <QTextEdit>

class Tab : public QMainWindow, public MenuBarBase
{
    Q_OBJECT
public:
    explicit Tab(QWidget* parent = 0);
    virtual ~Tab();
    void     menuBarUpdate(std::string event_type, std::string data) override;
    QAction* getGoHomeActionObj() const;
    QAction* getChangeBgColorActionObj() const;
    QAction* getExitAppActionObj() const;

protected:
    void resizeEvent(QResizeEvent* event) override;

private:
    QMenuBar*   menu_bar_;
    QAction*    go_home_act_;
    QAction*    change_bg_act_;
    QAction*    exit_app_act_;
    QWidget*    content_widget_;
    QTabWidget* tab_widget_;
    QTextEdit*  te1_;
    QTextEdit*  te2_;
};

#endif // __TAB_H__