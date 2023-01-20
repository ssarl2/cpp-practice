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
    exit_btn_size_ = UI::setUISize(80, 30, 0, 10, 0, 10);
    exit_btn_size_.x = window_size_.width-exit_btn_size_.width-exit_btn_size_.margin_right;
    exit_btn_size_.y = window_size_.height-exit_btn_size_.height-exit_btn_size_.margin_bottom;

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

    checkable_btn_size_ = UI::setUISize(100, 30, 10, 0, 10, 0);
    checkable_btn_size_.x = checkable_btn_size_.margin_left;
    checkable_btn_size_.y = checkable_btn_size_.margin_top;

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
