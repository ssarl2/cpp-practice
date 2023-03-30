/*
 * referred : https://wiki.qt.io/Qt_for_Beginners
 * description : practice qt library
 * created date : 18-01-2023
 * author : Hyunbin
 */

#include "window.h"
#include "Home.h"
#include <QApplication>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    // Window window1(500, 250);
    // window1.createExitButton();
    // window1.createCheckableButton();
    // window1.createProgressBar();
    // window1.createInfoButton();
    // window1.createEmailButton();
    // window1.createButtonGroupBox();
    // window1.createLayoutButton();
    // window1.show();

    Home home(500,250);
    home.show();

    return app.exec();
}