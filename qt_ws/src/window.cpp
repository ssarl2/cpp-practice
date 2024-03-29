#include "window.h"
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

void Window::createMenu()
{
    menu_bar_ = new QMenuBar;

    file_menu_ = new QMenu(tr("&File"), this);
    exit_action_ = file_menu_->addAction(tr("&Exit"));
    menu_bar_->addMenu(file_menu_);
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

    { // ID label
        QLabel *id_label = new QLabel("ID", wdg);
        UI::UISize id_label_size;

        id_label_size.width = 70;
        id_label_size.height = 30;
        id_label_size.x = 30;
        id_label_size.y = 30;

        id_label->setGeometry(id_label_size.x
                             ,id_label_size.y
                             ,id_label_size.width
                             ,id_label_size.height);
    }

    { // ID text edit
        UI::UISize id_te_size;

        id_te_size.width = window_size.width - 100*2;
        id_te_size.height = 30;
        id_te_size.x = 110;
        id_te_size.y = 30;

        id_te_ = new QTextEdit(wdg);
        id_te_->setGeometry(id_te_size.x
                           ,id_te_size.y
                           ,id_te_size.width
                           ,id_te_size.height);
    }

    { // App password label
        QLabel *app_pwd_label = new QLabel("App\npassword", wdg);
        UI::UISize app_pwd_label_size;

        app_pwd_label_size.width = 70;
        app_pwd_label_size.height = 45;
        app_pwd_label_size.x = 30;
        app_pwd_label_size.y = 62;

        app_pwd_label->setGeometry(app_pwd_label_size.x
                                  ,app_pwd_label_size.y
                                  ,app_pwd_label_size.width
                                  ,app_pwd_label_size.height);
    }

    { // App password text edit
        UI::UISize app_pwd_te_size;

        app_pwd_te_size.width = window_size.width - 100*2;
        app_pwd_te_size.height = 30;
        app_pwd_te_size.x = 110;
        app_pwd_te_size.y = 70;

        app_pwd_te_ = new QTextEdit(wdg);
        app_pwd_te_->setGeometry(app_pwd_te_size.x
                                ,app_pwd_te_size.y
                                ,app_pwd_te_size.width
                                ,app_pwd_te_size.height);
    }

    { // Receiver label
        QLabel *receiver_label = new QLabel("Receiver", wdg);
        UI::UISize receiver_label_size;

        receiver_label_size.width = 70;
        receiver_label_size.height = 30;
        receiver_label_size.x = 30;
        receiver_label_size.y = 110;

        receiver_label->setGeometry(receiver_label_size.x
                                   ,receiver_label_size.y
                                   ,receiver_label_size.width
                                   ,receiver_label_size.height);
    }

    { // Receiver text edit
        UI::UISize receiver_te_size;

        receiver_te_size.width = window_size.width - 100*2;
        receiver_te_size.height = 30;
        receiver_te_size.x = 110;
        receiver_te_size.y = 110;

        receiver_te_ = new QTextEdit(wdg);
        receiver_te_->setGeometry(receiver_te_size.x
                                 ,receiver_te_size.y
                                 ,receiver_te_size.width
                                 ,receiver_te_size.height);
    }

    { // Subject label
        QLabel *subject_label = new QLabel("Subject", wdg);
        UI::UISize subject_label_size;

        subject_label_size.width = 70;
        subject_label_size.height = 30;
        subject_label_size.x = 30;
        subject_label_size.y = 150;

        subject_label->setGeometry(subject_label_size.x
                                  ,subject_label_size.y
                                  ,subject_label_size.width
                                  ,subject_label_size.height);
    }

    { // Subject text edit
        UI::UISize subject_te_size;

        subject_te_size.width = window_size.width - 100*2;
        subject_te_size.height = 30;
        subject_te_size.x = 110;
        subject_te_size.y = 150;

        subject_te_ = new QTextEdit(wdg);
        subject_te_->setGeometry(subject_te_size.x
                                ,subject_te_size.y
                                ,subject_te_size.width
                                ,subject_te_size.height);
    }

    { // Content label
        QLabel *content_label = new QLabel("Content", wdg);
        UI::UISize content_label_size;

        content_label_size.width = 70;
        content_label_size.height = 30;
        content_label_size.x = 30;
        content_label_size.y = 190;

        content_label->setGeometry(content_label_size.x
                                  ,content_label_size.y
                                  ,content_label_size.width
                                  ,content_label_size.height);
    }

    { // Content text edit
        UI::UISize content_te_size;

        content_te_size.width = window_size.width - 100*2;
        content_te_size.height = 200;
        content_te_size.x = 110;
        content_te_size.y = 190;

        content_te_ = new QTextEdit(wdg);
        content_te_->setGeometry(content_te_size.x
                                ,content_te_size.y
                                ,content_te_size.width
                                ,content_te_size.height);
    }

    wdg->show();
    this->close();
}

void Window::slotSendEmail()
{
    std::cout << "Implement sending email here" << std::endl;

    std::string id = id_te_->toPlainText().toStdString();
    std::string app_pwd = app_pwd_te_->toPlainText().toStdString();
    std::string subject = subject_te_->toPlainText().toStdString();
    std::string receiver = receiver_te_->toPlainText().toStdString();
    std::string content = content_te_->toPlainText().toStdString();

    Email e;
    e.setAccount(id, app_pwd);
    e.setReceiver(receiver);
    e.setEmail(subject, content);
    bool succeed = e.sendEmail();
    if(succeed)
    {
        std::cout << "mail has sent" << std::endl;
    }
    else
    {
        std::cout << "mail has not sent" << std::endl;
    }

    id_te_->clear();
    app_pwd_te_->clear();
    receiver_te_->clear();
    subject_te_->clear();
    content_te_->clear();
}

void Window::createLayoutButton()
{
    UI::UISize layout_btn_size_ = UI::setUISize(80, 30, 0, 0, 0, 0);
    layout_btn_size_.x = 320;
    layout_btn_size_.y = 10;

    // Create and position the button
    QPushButton *layout_btn_ = new QPushButton("layout", this);
    layout_btn_->setGeometry(layout_btn_size_.x,
                             layout_btn_size_.y,
                             layout_btn_size_.width,
                             layout_btn_size_.height);

    connect(layout_btn_, SIGNAL(clicked()), this, SLOT(slotLayoutWindow()));
}

void Window::slotLayoutWindow()
{
    UI::UISize window_size;
    window_size.width = 500;
    window_size.height = 600;
    QWidget *wdg = new QWidget();
    wdg->setFixedSize(window_size.width, window_size.height);

    menu_bar_ = new QMenuBar;

    file_menu_ = new QMenu(tr("&File"), wdg);
    exit_action_ = file_menu_->addAction(tr("&Exit"));
    menu_bar_->addMenu(file_menu_);

    connect(exit_action_, &QAction::triggered, this, &QApplication::quit);

    main_layout_ = new QVBoxLayout;
    main_layout_->setMenuBar(menu_bar_);
    wdg->setLayout(main_layout_);

    form_group_box_ = new QGroupBox(tr("Form layout"));
    QFormLayout *layout = new QFormLayout;
    layout->addRow(new QLabel(tr("Line 1:")), new QLineEdit);
    layout->addRow(new QLabel(tr("Line 2, long text:")), new QComboBox);
    layout->addRow(new QLabel(tr("Line 3:")), new QSpinBox);
    form_group_box_->setLayout(layout);

    QPushButton *back_btn = new QPushButton("Back");

    main_layout_->addWidget(form_group_box_);
    main_layout_->addWidget(back_btn);

    connect(back_btn, SIGNAL(clicked()), wdg, SLOT(close()));
    connect(back_btn, SIGNAL(clicked()), this, SLOT(show()));

    wdg->show();
    this->close();
}