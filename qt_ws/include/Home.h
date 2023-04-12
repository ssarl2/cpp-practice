#ifndef __HOME_H__
#define __HOME_H__

#include <IMenuBarFactorySubscriber.h>
#include <MenuBarBase.h>
#include <ProgressBar.h>
#include <QLabel>
#include <QResizeEvent>
#include <QStackedLayout>
#include <QStackedWidget>
#include <QVBoxLayout>

class Home : public QWidget, public MenuBarBase
{
    Q_OBJECT
public:
    explicit Home(QWidget* parent = 0);
    virtual ~Home();
    void         menuBarUpdate() override;
    QPushButton* getProgressBarBtnObj();

protected:
    void resizeEvent(QResizeEvent* event) override;

    QWidget*        container_widget_;
    QMenuBar*       menu_bar_;
    QVBoxLayout*    layout_;
    QStackedLayout* stacked_widget_;
    ProgressBar*    pb_;
    QPushButton*    progress_bar_btn_;
};

#endif //  __HOME_H__