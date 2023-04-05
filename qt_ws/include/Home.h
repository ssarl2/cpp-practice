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
    void menuBarUpdate() override;
private slots:
    void openProgressBar();
    void comeBackHome();

protected:
    void resizeEvent(QResizeEvent* event) override;

private:
    void createLayout();
    void initWidgets();

    QWidget*        container_widget_;
    QMenuBar*       menu_bar_;
    QVBoxLayout*    layout_;
    QStackedWidget* stacked_widget_;
    ProgressBar*    pb_;
};

#endif //  __HOME_H__