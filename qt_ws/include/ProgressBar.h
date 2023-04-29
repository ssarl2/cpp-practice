#ifndef __PROGRESS_BAR_H__
#define __PROGRESS_BAR_H__

#include <IMenuBarFactorySubscriber.h>
#include <MenuBarBase.h>
#include <QMainWindow>
#include <QPushButton>

class ProgressBar : public QMainWindow, public MenuBarBase
{
    Q_OBJECT
public:
    explicit ProgressBar(QWidget* parent = 0);
    virtual ~ProgressBar();
    void     menuBarUpdate(std::string event_type, std::string data) override;
    QAction* getGoHomeActionObj() const;
    QAction* getChangeBgColorActionObj() const;
    QAction* getExitAppActionObj() const;
    QPushButton* getBtnObj() const;

protected:
    void resizeEvent(QResizeEvent* event) override;

private:
    QMenuBar*    menu_bar_;
    QAction*     go_home_act_;
    QAction*     change_bg_act_;
    QAction*     exit_app_act_;
    QPushButton* button_;
};

#endif //  __PROGRESS_BAR_H__