/*
 * referred : https://wiki.qt.io/Qt_for_Beginners
 * description : practice qt library
 * created date : 18-01-2023
 * author : Hyunbin
 */

#include <Home.h>
#include <ProgressBar.h>
#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QStackedWidget>
#include <SubMain.h>
#include <window.h>
int main(int argc, char* argv[])
{
    //     QApplication app(argc, argv);

    // // Create a QStackedWidget
    // QStackedWidget stackedWidget;

    // // Create some widgets to be added to the stack
    // QPushButton *button1 = new QPushButton("Button 1");
    // QLabel *label1 = new QLabel("Label 1");
    // QPushButton *button2 = new QPushButton("Button 2");
    // QLabel *label2 = new QLabel("Label 2");

    // // Add the widgets to the stack
    // stackedWidget.addWidget(button1);
    // stackedWidget.addWidget(label1);
    // stackedWidget.addWidget(button2);
    // stackedWidget.addWidget(label2);

    // // Set the current widget to be displayed
    // stackedWidget.setCurrentIndex(0);

    // // Connect the button clicks to the function that switches the current
    // widget QObject::connect(button1, &QPushButton::clicked,
    // [&stackedWidget]() {
    //     stackedWidget.setCurrentIndex(2);
    // });
    // QObject::connect(button2, &QPushButton::clicked, [&stackedWidget]() {
    //     stackedWidget.setCurrentIndex(0);
    // });

    // // Show the stacked widget
    // stackedWidget.show();

    QApplication app(argc, argv);

    // Home home;
    // home.show();
    SubMain sm;
    sm.show();

    return app.exec();
}