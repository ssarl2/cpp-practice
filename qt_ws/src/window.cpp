#include "window.h"
#include <QApplication>
#include <iostream>

Window::Window(int width, int height, QWidget *parent)
: QWidget(parent)
{
    window_size_.width = width;
    window_size_.height = height;

    // Set size of the window
    setFixedSize(window_size_.width, window_size_.height);
}

void Window::createExitButton()
{
    exit_btn_size_ = UI::setUISize(80, 30, 0, 0, 0, 0);
    exit_btn_size_.x = window_size_.width-exit_btn_size_.width-10;
    exit_btn_size_.y = window_size_.height-exit_btn_size_.height-10;

    // Create and position the button
    exit_btn_ = new QPushButton("Bye World", this);
    exit_btn_->setGeometry(exit_btn_size_.x, 
                           exit_btn_size_.y, 
                           exit_btn_size_.width, 
                           exit_btn_size_.height);
    exit_btn_->setToolTip("Oh, you found me");

    connect(exit_btn_, SIGNAL(clicked()), QApplication::instance(), SLOT(quit()));
}

void Window::createCheckableButton()
{
    checkable_btn_counter_ = 0;

    checkable_btn_size_ = UI::setUISize(120, 30, 0, 0, 0, 0);
    checkable_btn_size_.x = 10;
    checkable_btn_size_.y = 10;

    // Create and position the button
    checkable_btn_ = new QPushButton("World?", this);
    checkable_btn_->setGeometry(checkable_btn_size_.x, 
                               checkable_btn_size_.y, 
                               checkable_btn_size_.width, 
                               checkable_btn_size_.height);
    checkable_btn_->setCheckable(true);

    connect(checkable_btn_, SIGNAL(clicked(bool)), this, SLOT(slotCheckableButtonClicked(bool)));
    connect(this, SIGNAL(checkableButtonCounterReached()), QApplication::instance(), SLOT(quit()));
}

void Window::createInfoButton()
{
    info_btn_size_ = UI::setUISize(80, 30, 0, 0, 0, 0);
    info_btn_size_.x = 140;
    info_btn_size_.y = 10;

    info_btn_ = new QPushButton("Info", this);
    info_btn_->setGeometry(info_btn_size_.x,
                           info_btn_size_.y,
                           info_btn_size_.width,
                           info_btn_size_.height);

    connect(info_btn_, SIGNAL(clicked()), QApplication::instance(), SLOT(aboutQt()));
}

void Window::createEmailButton()
{
    email_btn_size_ = UI::setUISize(80, 30, 0, 0, 0, 0);
    email_btn_size_.x = 230;
    email_btn_size_.y = 10;

    email_btn_ = new QPushButton("Email", this);
    email_btn_->setGeometry(email_btn_size_.x,
                           email_btn_size_.y,
                           email_btn_size_.width,
                           email_btn_size_.height);

    connect(email_btn_, SIGNAL(clicked()), this, SLOT(slotEmailWindow()));
}

void Window::createButtonGroupBox()
{
    QGroupBox *btn_group_box = new QGroupBox("box", this);
    btn_group_box->setGeometry(window_size_.width/2 - 125, 60, 250, 30);

    QPushButton *btn_1 = new QPushButton("Apple", btn_group_box);
    QPushButton *btn_2 = new QPushButton("Banana", btn_group_box);
    QPushButton *btn_3 = new QPushButton("Carrot", btn_group_box);
    btn_1->setGeometry(0,0,80,30);
    btn_2->setGeometry(85,0,80,30);
    btn_3->setGeometry(170,0,80,30);

    btn_group_ = new QButtonGroup(btn_group_box);
    btn_group_->addButton(btn_1);
    btn_group_->addButton(btn_2);
    btn_group_->addButton(btn_3);

    btn_group_->setId(btn_1, 1);
    btn_group_->setId(btn_2, 2);
    btn_group_->setId(btn_3, 3);
    connect(btn_group_, SIGNAL(buttonClicked(int)), this, SLOT(customSLOT(int)));
}

void Window::createProgressBar()
{
    int progress_bar_side_margin = 10;
    int progress_bar_width = window_size_.width - progress_bar_side_margin * 2;
    progress_bar_size_ = UI::setUISize(progress_bar_width, 
                                       30, 
                                       0, 
                                       10, 
                                       progress_bar_side_margin, 
                                       progress_bar_side_margin);
    slider_size_ = UI::setUISize(progress_bar_size_.width, 
                                 progress_bar_size_.height, 
                                 0, 
                                 progress_bar_size_.margin_bottom, 
                                 progress_bar_size_.margin_left, 
                                 progress_bar_size_.margin_right);
    slider_size_.x = slider_size_.margin_left;
    slider_size_.y = window_size_.height-40-slider_size_.margin_bottom-slider_size_.height;
    progress_bar_size_.x = progress_bar_size_.margin_left;
    progress_bar_size_.y = slider_size_.y-progress_bar_size_.margin_bottom-progress_bar_size_.height;

    // Create a progress bar
    // with the range between 0 and 100, and a starting value of 0
    progress_bar_ = new QProgressBar(this);
    progress_bar_->setRange(0, 100);
    progress_bar_->setValue(50);
    progress_bar_->setGeometry(progress_bar_size_.x, 
                              progress_bar_size_.y, 
                              progress_bar_size_.width, 
                              progress_bar_size_.height);

    // Create a horizontal slider
    // with the range between 0 and 100, and a starting value of 0
    slider_ = new QSlider(this);
    slider_->setOrientation(Qt::Horizontal);
    slider_->setRange(0, 100);
    slider_->setValue(50);
    slider_->setGeometry(slider_size_.x, 
                        slider_size_.y, 
                        slider_size_.width, 
                        slider_size_.height);

    connect(slider_, SIGNAL(valueChanged(int)), progress_bar_, SLOT(setValue(int)));
}

void Window::slotCheckableButtonClicked(bool checked)
{
    QString text;

    if(checked)
    {
        text = "Pushed World";
        checkable_btn_counter_++;
    }
    else
    {
        text = "World is back";
    }

    if(checkable_btn_counter_ == 10)
    {
        emit checkableButtonCounterReached();
    }

    text += QString(" ") + QString::number(checkable_btn_counter_);
    checkable_btn_->setText(text);
}

void Window::customSLOT(int id)
{
    std::cout << "checked this id : " << id << std::endl;
}

void Window::slotEmailWindow()
{
    UI::UISize window_size;
    window_size.width = 500;
    window_size.height = 600;

    QWidget *wdg = new QWidget();
    wdg->setFixedSize(window_size.width, window_size.height);

    { // Cancel button
        UI::UISize cancel_btn_size;

        cancel_btn_size.width = 80;
        cancel_btn_size.height = 30;
        cancel_btn_size.x = window_size.width - cancel_btn_size.width - 10;
        cancel_btn_size.y = window_size.height - cancel_btn_size.height - 10;

        QPushButton *cancel_btn = new QPushButton("Cancel", wdg);
        cancel_btn->setGeometry(cancel_btn_size.x
                        ,cancel_btn_size.y
                        ,cancel_btn_size.width
                        ,cancel_btn_size.height);

        connect(cancel_btn, SIGNAL(clicked()), wdg, SLOT(close()));
        connect(cancel_btn, SIGNAL(clicked()), this, SLOT(show()));
    }

    { // Send button
        UI::UISize send_btn_size;

        send_btn_size.width = 80;
        send_btn_size.height = 30;
        send_btn_size.x = window_size.width - send_btn_size.width - 90 - 10;
        send_btn_size.y = window_size.height - send_btn_size.height - 10;

        QPushButton *send_btn = new QPushButton("Send", wdg);
        send_btn->setGeometry(send_btn_size.x
                        ,send_btn_size.y
                        ,send_btn_size.width
                        ,send_btn_size.height);

        connect(send_btn, SIGNAL(clicked()), this, SLOT(slotSendEmail()));
    }

    wdg->show();
    this->close();
}

void Window::slotSendEmail()
{
    std::cout << "Implement sending email here" << std::endl;
}