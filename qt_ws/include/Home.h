#ifndef __HOME_H__
#define __HOME_H__

#include <IMenuBarFactorySubscriber.h>
#include <MenuBarBase.h>
#include <QPushButton>

class Home : public QWidget, public MenuBarBase
{
    Q_OBJECT
public:
    explicit Home(QWidget* parent = 0);
    virtual ~Home();
    void         menuBarUpdate(std::string data) override;
    QAction*     getMenuBarActionObj();
    QPushButton* getProgressBarBtnObj() const;
    QPushButton* getLayoutBtnObj() const;

protected:
    void resizeEvent(QResizeEvent* event) override;

private:
    QMenuBar*    menu_bar_;
    QAction*     test_act_;
    QPushButton* progress_bar_btn_;
    QPushButton* layout_btn_;
};

#endif //  __HOME_H__