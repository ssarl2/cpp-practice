#ifndef __LAYOUT_H__
#define __LAYOUT_H__

#include <IMenuBarFactorySubscriber.h>
#include <MenuBarBase.h>
#include <QComboBox>
#include <QFormLayout>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QMainWindow>
#include <QPushButton>
#include <QSpinBox>

class Layout : public QMainWindow, public MenuBarBase
{
    Q_OBJECT
public:
    explicit Layout(QWidget* parent = 0);
    virtual ~Layout();
    void     menuBarUpdate(std::string event_type, std::string data) override;
    QAction* getGoHomeActionObj() const;
    QAction* getChangeBgColorActionObj() const;
    QAction* getExitAppActionObj() const;
    QPushButton* getBtnObj() const;

protected:
    void resizeEvent(QResizeEvent* event) override;
private slots:
    void popUp(std::string msg);
private:
    QMenuBar*    menu_bar_;
    QAction*     go_home_act_;
    QAction*     change_bg_act_;
    QAction*     exit_app_act_;
    QPushButton* button_;
    QWidget*     content_widget_;
};

#endif //  __LAYOUT_H__
