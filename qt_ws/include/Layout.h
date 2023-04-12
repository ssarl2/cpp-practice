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
    void         menuBarUpdate() override;
    QPushButton* getHomeBtnObj() const;

protected:
    void resizeEvent(QResizeEvent* event) override;

private:
    QMenuBar*    menu_bar_;
    QPushButton* home_btn_;
};


#endif //  __LAYOUT_H__