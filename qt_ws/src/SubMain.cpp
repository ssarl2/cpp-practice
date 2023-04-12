#include <QObject>
#include <QStackedLayout>
#include <QVBoxLayout>
#include <SubMain.h>

SubMain::SubMain(QWidget* parent) : QWidget(parent)
{
    QStackedLayout* stacked_layout = new QStackedLayout();
    Home*           home           = new Home();
    ProgressBar*    pb             = new ProgressBar();

    stacked_layout->addWidget(home);
    stacked_layout->addWidget(pb);
    setLayout(stacked_layout);

    QObject::connect(
        home->getProgressBarBtnObj(), &QPushButton::clicked, this,
        [=]() { stacked_layout->setCurrentIndex(1); });
    QObject::connect(
        pb->getHomeBtnObj(), &QPushButton::clicked, this,
        [=]() { stacked_layout->setCurrentIndex(0); });
}
