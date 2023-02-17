#ifndef __WINDOW_H__
#define __WINDOW_H__

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QButtonGroup>
#include <QGroupBox>
#include <QProgressBar>
#include <QSlider>
#include <QLabel>
#include <QTextEdit>
#include "ui_size.h"
#include "email.h"

#include <QFormLayout>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QComboBox>
#include <QSpinBox>

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
    void createMenu();
    void createLayoutButton();
signals:
    void checkableButtonCounterReached();
private slots:
    void slotCheckableButtonClicked(bool checked);
    void customSLOT(int id);
    void slotEmailWindow();
    void slotSendEmail();
    void slotLayoutWindow();
private:
    int checkable_btn_counter_;
    QPushButton *exit_btn_;
    QPushButton *checkable_btn_;
    QPushButton *info_btn_;
    QPushButton *email_btn_;
    QButtonGroup *btn_group_;
    QProgressBar *progress_bar_;
    QSlider *slider_;
    QTextEdit *id_te_;
    QTextEdit *app_pwd_te_;
    QTextEdit *receiver_te_;
    QTextEdit *subject_te_;
    QTextEdit *content_te_;
    UI::UISize window_size_;
    UI::UISize exit_btn_size_;
    UI::UISize checkable_btn_size_;
    UI::UISize info_btn_size_;
    UI::UISize email_btn_size_;
    UI::UISize progress_bar_size_;
    UI::UISize slider_size_;

    QVBoxLayout *main_layout_;
    QGroupBox *form_group_box_;
    QMenu *file_menu_;
    QMenuBar *menu_bar_;
    QAction *exit_action_;
};

#endif // __WINDOW_H__