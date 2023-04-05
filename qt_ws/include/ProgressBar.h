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
    void menuBarUpdate() override;
    // void closeEvent(QCloseEvent* event);
    QPushButton* getButtonObj() const;

private:
    QPushButton* button_;
};

#endif //  __PROGRESS_BAR_H__