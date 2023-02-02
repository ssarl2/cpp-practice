#ifndef __WINDOW_H__
#define __WINDOW_H__

#include <QWidget>
#include <QPushButton>
#include <QButtonGroup>
#include <QGroupBox>
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
    void createInfoButton();
    void createEmailButton();
    void createButtonGroupBox();
    void createProgressBar();
signals:
    void checkableButtonCounterReached();
private slots:
    void slotCheckableButtonClicked(bool checked);
    void customSLOT(int id);
    void slotEmailWindow();
    void slotSendEmail();
private:
    int checkable_btn_counter_;
    QPushButton *exit_btn_;
    QPushButton *checkable_btn_;
    QPushButton *info_btn_;
    QPushButton *email_btn_;
    QButtonGroup *btn_group_;
    QProgressBar *progress_bar_;
    QSlider *slider_;
    UI::UISize window_size_;
    UI::UISize exit_btn_size_;
    UI::UISize checkable_btn_size_;
    UI::UISize info_btn_size_;
    UI::UISize email_btn_size_;
    UI::UISize progress_bar_size_;
    UI::UISize slider_size_;
};

#endif // __WINDOW_H__