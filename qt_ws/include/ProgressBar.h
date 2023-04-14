#ifndef __PROGRESS_BAR_H__
#define __PROGRESS_BAR_H__

#include <IMenuBarFactorySubscriber.h>
#include <MenuBarBase.h>
#include <QPushButton>

class ProgressBar : public QWidget, public MenuBarBase
{
    Q_OBJECT
public:
    explicit ProgressBar(QWidget* parent = 0);
    virtual ~ProgressBar();
    void         menuBarUpdate(std::string data) override;
    QAction*     getGoHomeActionObj();
    QPushButton* getBtnObj() const;

protected:
    void resizeEvent(QResizeEvent* event) override;

private:
    QMenuBar*    menu_bar_;
    QAction*     go_home_act_;
    QPushButton* button_;
};

#endif //  __PROGRESS_BAR_H__