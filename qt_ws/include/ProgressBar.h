#ifndef __PROGRESS_BAR_H__
#define __PROGRESS_BAR_H__

#include <IMenuBarFactorySubscriber.h>
#include <MenuBarBase.h>
#include <QCloseEvent>
#include <QPushButton>

class ProgressBar : public QWidget, public MenuBarBase
{
    Q_OBJECT
public:
    explicit ProgressBar(QWidget* parent = 0);
    virtual ~ProgressBar();
    void         menuBarUpdate() override;
    QPushButton* getHomeBtnObj() const;

protected:
    void resizeEvent(QResizeEvent* event) override;

private:
    QPushButton* home_btn_;
    QMenuBar*    menu_bar_;
};

#endif //  __PROGRESS_BAR_H__