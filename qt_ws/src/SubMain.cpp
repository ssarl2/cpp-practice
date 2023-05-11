#include <QObject>
#include <QStackedLayout>
#include <QVBoxLayout>
#include <SubMain.h>

SubMain::SubMain(QWidget* parent) : QMainWindow(parent)
{
    QWidget*        content_widget = new QWidget;
    QStackedLayout* stacked_layout = new QStackedLayout();
    Home*           home           = new Home();
    ProgressBar*    pb             = new ProgressBar();
    Layout*         lo             = new Layout();
    Tab*            tb             = new Tab();

    MenuBarAction* mbp = new MenuBarAction();
    mbp->subscribe("goHome", pb);
    mbp->subscribe("goHome", lo);
    mbp->subscribe("goHome", tb);
    mbp->subscribe("changeBgColor", home);
    mbp->subscribe("changeBgColor", pb);
    mbp->subscribe("changeBgColor", lo);
    mbp->subscribe("changeBgColor", tb);
    mbp->subscribe("exitApp", home);
    mbp->subscribe("exitApp", pb);
    mbp->subscribe("exitApp", lo);
    mbp->subscribe("exitApp", tb);

    stacked_layout->addWidget(home);
    stacked_layout->addWidget(pb);
    stacked_layout->addWidget(lo);
    stacked_layout->addWidget(tb);

    content_widget->setLayout(stacked_layout);
    setCentralWidget(content_widget);

    QObject::connect(
        home->getProgressBarBtnObj(), &QPushButton::clicked, this,
        [=]() { stacked_layout->setCurrentIndex(1); });
    QObject::connect(
        home->getLayoutBtnObj(), &QPushButton::clicked, this,
        [=]() { stacked_layout->setCurrentIndex(2); });
    QObject::connect(
        home->getTabBtnObj(), &QPushButton::clicked, this,
        [=]() { stacked_layout->setCurrentIndex(3); });

    QObject::connect(
        pb->getGoHomeActionObj(), &QAction::triggered, this,
        [=]()
        {
            stacked_layout->setCurrentIndex(0);
            mbp->goHome();
        });
    QObject::connect(
        lo->getGoHomeActionObj(), &QAction::triggered, this,
        [=]()
        {
            stacked_layout->setCurrentIndex(0);
            mbp->goHome();
        });
    QObject::connect(
        tb->getGoHomeActionObj(), &QAction::triggered, this,
        [=]()
        {
            stacked_layout->setCurrentIndex(0);
            mbp->goHome();
        });

    QObject::connect(
        home->getChangeBgColorActionObj(), &QAction::triggered, this,
        [=]() { mbp->changeBgColor("normal"); });
    QObject::connect(
        pb->getChangeBgColorActionObj(), &QAction::triggered, this,
        [=]() { mbp->changeBgColor("blue"); });
    QObject::connect(
        lo->getChangeBgColorActionObj(), &QAction::triggered, this,
        [=]() { mbp->changeBgColor("yellow"); });
    QObject::connect(
        tb->getChangeBgColorActionObj(), &QAction::triggered, this,
        [=]() { mbp->changeBgColor("green"); });

    QObject::connect(
        home->getExitAppActionObj(), &QAction::triggered, this,
        [=]() { mbp->exitApp(); });
    QObject::connect(
        pb->getExitAppActionObj(), &QAction::triggered, this,
        [=]() { mbp->exitApp(); });
    QObject::connect(
        lo->getExitAppActionObj(), &QAction::triggered, this,
        [=]() { mbp->exitApp(); });
    QObject::connect(
        tb->getExitAppActionObj(), &QAction::triggered, this,
        [=]() { mbp->exitApp(); });
}
