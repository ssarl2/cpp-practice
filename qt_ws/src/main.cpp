/*
* referred : https://wiki.qt.io/Qt_for_Beginners
* description : practice qt library
* created date : 18-01-2023
* author : Hyunbin
*/

#include <QApplication>
#include <QPushButton>

int main(int argc, char* argv[])
{
    QApplication app (argc, argv);

    QWidget window;
    window.setFixedSize(100, 50);

    QFont font("italic");

    QPushButton *button = new QPushButton("Hello World", &window);
    button->setGeometry(10, 10, 80, 30);

    window.show();

    QPushButton button1;
    QPushButton button2("Wow", &button1);
    button1.setText("Something something");
    button1.setToolTip("A tooltip");
    button1.setFont(font);
    button1.show();

    button2.show();
    
    return app.exec();
}