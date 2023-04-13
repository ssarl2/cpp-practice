#include <QObject>
#include <QStackedLayout>
#include <QVBoxLayout>
#include <SubMain.h>

SubMain::SubMain(QWidget* parent) : QWidget(parent)
{
    QStackedLayout* stacked_layout = new QStackedLayout();
    Home*           home           = new Home();
    ProgressBar*    pb             = new ProgressBar();
    Layout*         lo             = new Layout();

    MenuBarAction* mbp = new MenuBarAction();
    mbp->subscribe("changeBackgroundColor", home);
    mbp->subscribe("exitApp", home);
    mbp->subscribe("goHome", pb);
    mbp->subscribe("goHome", lo);

    stacked_layout->addWidget(home);
    stacked_layout->addWidget(pb);
    stacked_layout->addWidget(lo);
    setLayout(stacked_layout);

    QObject::connect(
        pb->getHomeBtnObj(), &QPushButton::clicked, this,
        [=]()
        {
            stacked_layout->setCurrentIndex(0);
            mbp->goHome();
        });
    QObject::connect(
        home->getProgressBarBtnObj(), &QPushButton::clicked, this,
        [=]()
        {
            stacked_layout->setCurrentIndex(1);
            mbp->changeBackgroundColor();
        });
    QObject::connect(
        lo->getHomeBtnObj(), &QPushButton::clicked, this,
        [=]()
        {
            stacked_layout->setCurrentIndex(0);
            mbp->goHome();
        });
    QObject::connect(
        home->getLayoutBtnObj(), &QPushButton::clicked, this,
        [=]()
        {
            stacked_layout->setCurrentIndex(2);
            mbp->exitApp();
        });
}
