#include <Layout.h>

#include <QApplication>
#include <QComboBox>
#include <QDebug>
#include <QDialogButtonBox>
#include <QFormLayout>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QPoint>
#include <QPushButton>
#include <QSpinBox>
#include <QVBoxLayout>
#include <iostream>

Layout::Layout(QWidget* parent) : QMainWindow(parent)
{
    menu_bar_      = createMenuBar(this);
    QMenu* menu1   = createMenu(menu_bar_, "Menu1");
    go_home_act_   = createAction(menu1, "GoHome");
    change_bg_act_ = createAction(menu1, "ChangeBgColor");
    exit_app_act_  = createAction(menu1, "Exit");

    content_widget_              = new QWidget(this);
    QVBoxLayout*      qvb_layout = new QVBoxLayout(content_widget_);
    QGroupBox*        qg_box     = new QGroupBox(tr("Form qf_layout"));
    QFormLayout*      qf_layout  = new QFormLayout;
    QDialogButtonBox* qd_btn_box = new QDialogButtonBox;
    QPushButton*      ok_btn     = qd_btn_box->addButton(QDialogButtonBox::Ok);
    QSpacerItem*      v_spacer   = new QSpacerItem(
        10, width(), QSizePolicy::Minimum, QSizePolicy::Expanding);
    qd_btn_box->addButton(QDialogButtonBox::Cancel);
    ok_btn->setText("Submit");
    qf_layout->addRow(new QLabel(tr("Line 1:")), new QLineEdit);
    qf_layout->addRow(new QLabel(tr("Line 2, long text:")), new QComboBox);
    qf_layout->addRow(new QLabel(tr("Line 3:")), new QSpinBox);
    qf_layout->addItem(v_spacer);
    qf_layout->addRow(qd_btn_box);

    qg_box->setLayout(qf_layout);
    qvb_layout->addWidget(qg_box);

    QObject::connect(
        qd_btn_box, &QDialogButtonBox::accepted, this,
        std::bind(&Layout::popUp, this, "Submitted!"));
    QObject::connect(
        qd_btn_box, &QDialogButtonBox::rejected, this,
        std::bind(&Layout::popUp, this, "Cancelled!"));
}

Layout::~Layout()
{
    qDebug() << "Layout dtor";
}

void Layout::resizeEvent(QResizeEvent* event)
{
    QWidget::resizeEvent(event);

    menu_bar_->resize(width(), 25);

    content_widget_->setGeometry(0, 25, width(), height() - 25);
}

void Layout::menuBarUpdate(std::string event_type, std::string data)
{
    if (event_type == "changeBgColor")
    {
        setStyleSheet(data.c_str());
    }
    else if (event_type == "exitApp")
    {
        QApplication::quit();
    }
}

QAction* Layout::getGoHomeActionObj() const
{
    return go_home_act_;
}

QAction* Layout::getChangeBgColorActionObj() const
{
    return change_bg_act_;
}

QAction* Layout::getExitAppActionObj() const
{
    return exit_app_act_;
}

void Layout::popUp(std::string msg)
{
    QPoint       q_pos  = mapToGlobal(pos());
    QWidget*     w      = new QWidget;
    QLabel*      label  = new QLabel(msg.c_str());
    QVBoxLayout* layout = new QVBoxLayout(w);
    layout->addWidget(label);
    w->show();
    w->move(
        q_pos.x() + (width() - w->width()) / 2,
        q_pos.y() + (height() - w->height()) / 2);
}