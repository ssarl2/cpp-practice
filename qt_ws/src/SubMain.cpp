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

    MenuBarPublisher* mbp = new MenuBarPublisher();
    mbp->subscribe(home);
    mbp->subscribe(pb);
    // mbp->subscribe(lo);

    stacked_layout->addWidget(home);
    stacked_layout->addWidget(pb);
    stacked_layout->addWidget(lo);
    setLayout(stacked_layout);

    QObject::connect(
        pb->getHomeBtnObj(), &QPushButton::clicked, this,
        [=]()
        {
            stacked_layout->setCurrentIndex(0);
            mbp->notify("Hello there. It's from SubMain. I am moving to "
                        "Home from ProgressBar");
        });
    QObject::connect(
        home->getProgressBarBtnObj(), &QPushButton::clicked, this,
        [=]()
        {
            stacked_layout->setCurrentIndex(1);
            mbp->notify("Hello there. It's from SubMain. I am moving to "
                        "ProgressBar from Home");
        });
    QObject::connect(
        lo->getHomeBtnObj(), &QPushButton::clicked, this,
        [=]()
        {
            stacked_layout->setCurrentIndex(0);
            mbp->notify("Hello there. It's from SubMain. I am moving to "
                        "Home from Layout");
        });
    QObject::connect(
        home->getLayoutBtnObj(), &QPushButton::clicked, this,
        [=]()
        {
            stacked_layout->setCurrentIndex(2);
            mbp->notify("Hello there. It's from SubMain. I am moving to "
                        "Layout from Home");
        });
}
