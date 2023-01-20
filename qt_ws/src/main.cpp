/*
* referred : https://wiki.qt.io/Qt_for_Beginners
* description : practice qt library
* created date : 18-01-2023
* author : Hyunbin
*/

#include <QApplication>
#include "window.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    Window window1(500, 250);
    window1.createExitButton();
    window1.createCheckableButton();
    window1.createProgressBar();
    window1.createInfoButton();
    window1.show();

    return app.exec();
}