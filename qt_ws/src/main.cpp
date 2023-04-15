/*
 * referred : https://wiki.qt.io/Qt_for_Beginners
 * description : practice qt library
 * created date : 18-01-2023
 * author : Hyunbin
 */

#include <QApplication>
#include <SubMain.h>
int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    SubMain sm;
    sm.show();

    return app.exec();
}