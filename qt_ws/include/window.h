#ifndef __WINDOW_H__
#define __WINDOW_H__

#include <QWidget>
#include <QPushButton>
#include <QProgressBar>
#include <QSlider>
#include "ui_size.h"


class Window : public QWidget
{
Q_OBJECT
public:
    explicit Window(int width, int height, QWidget *parent = 0);
    void createExitButton();
    void createCheckableButton();
    void createProgressBar();
signals:
    void checkableButtonCounterReached();
private slots:
    void slotCheckableButtonClicked(bool checked);
private:
    int checkable_btn_counter_;
    QPushButton *exit_btn_;
    QPushButton *checkable_btn_;
    QProgressBar *progress_bar_;
    QSlider *slider_;
    UI::UISize window_size_;
    UI::UISize exit_btn_size_;
    UI::UISize checkable_btn_size_;
    UI::UISize progress_bar_size_;
    UI::UISize slider_size_;
};

#endif // __WINDOW_H__