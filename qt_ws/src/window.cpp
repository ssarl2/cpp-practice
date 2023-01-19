#include "window.h"
#include <QApplication>
#include <QPushButton>
#include <QProgressBar>
#include <QSlider>

Window::Window(int width, int height, QWidget *parent)
: QWidget(parent)
{
    window_size_.width = width;
    window_size_.height = height;

    exit_btn_size_ = UI::setUISize(80, 30, 0, 10, 0, 10);
    exit_btn_size_.x = window_size_.width-exit_btn_size_.width-exit_btn_size_.margin_bottom;
    exit_btn_size_.y = window_size_.height-exit_btn_size_.height-exit_btn_size_.margin_bottom;

    // Set size of the window
    setFixedSize(window_size_.width, window_size_.height);

    // Create and position the button
    m_button_ = new QPushButton("Bye World", this);
    m_button_->setGeometry(exit_btn_size_.x, 
                           exit_btn_size_.y, 
                           exit_btn_size_.width, 
                           exit_btn_size_.height);
    m_button_->setToolTip("Oh, you found me");

    connect(m_button_, SIGNAL(clicked()), QApplication::instance(), SLOT(quit()));
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
    slider_size_.y = exit_btn_size_.y-slider_size_.margin_bottom-slider_size_.height;
    progress_bar_size_.x = progress_bar_size_.margin_left;
    progress_bar_size_.y = slider_size_.y-progress_bar_size_.margin_bottom-progress_bar_size_.height;

    // Create a progress bar
    // with the range between 0 and 100, and a starting value of 0
    QProgressBar *progress_bar = new QProgressBar(this);
    progress_bar->setRange(0, 100);
    progress_bar->setValue(50);
    progress_bar->setGeometry(progress_bar_size_.x, 
                              progress_bar_size_.y, 
                              progress_bar_size_.width, 
                              progress_bar_size_.height);

    // Create a horizontal slider
    // with the range between 0 and 100, and a starting value of 0
    QSlider *slider = new QSlider(this);
    slider->setOrientation(Qt::Horizontal);
    slider->setRange(0, 100);
    slider->setValue(50);
    slider->setGeometry(slider_size_.x, 
                        slider_size_.y, 
                        slider_size_.width, 
                        slider_size_.height);

    connect(slider, SIGNAL(valueChanged(int)), progress_bar, SLOT(setValue(int)));
}