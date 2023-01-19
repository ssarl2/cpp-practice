#ifndef __WINDOW_H__
#define __WINDOW_H__

#include <QWidget>
#include "ui_size.h"

class QPushButton;
class Window : public QWidget
{
public:
    explicit Window(int width, int height, QWidget *parent = 0);
    void createProgressBar();
private:
    QPushButton *m_button_;
    UI::UISize window_size_;
    UI::UISize exit_btn_size_;
    UI::UISize progress_bar_size_;
    UI::UISize slider_size_;
};

#endif // __WINDOW_H__