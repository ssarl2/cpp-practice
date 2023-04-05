#include <ProgressBar.h>

#include <QDebug>
#include <QPushButton>
#include <iostream>

ProgressBar::ProgressBar(QWidget* parent)
    : QWidget(parent)
{
    qDebug() << "Progressbar ctor";
    button_ = new QPushButton("my_button", this);
    button_->move(20, 40);
    button_->setStyleSheet("background-color: red;");
}

ProgressBar::~ProgressBar()
{
    qDebug() << "Progressbar dtor";
}

QPushButton* ProgressBar::getButtonObj() const
{
    return button_;
}

// void ProgressBar::closeEvent(QCloseEvent* event)
// {
//     QWidget::closeEvent(event);
//     deleteLater();
// }

void ProgressBar::menuBarUpdate()
{
}