#ifndef __SUBMAIN_H__
#define __SUBMAIN_H__

#include <Home.h>
#include <Layout.h>
#include <ProgressBar.h>
#include <MenuBarAction.h>
#include <QMainWindow>

class SubMain : public QMainWindow
{
    Q_OBJECT
public:
    explicit SubMain(QWidget* parent = 0);
};

#endif // __SUBMAIN_H__