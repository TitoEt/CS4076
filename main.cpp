#include "mainwindow.h"
#include <iostream>

#include <QApplication>

struct S{
    unsigned int b : 3;
};


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.showMaximized();
    return a.exec();

    S s = {6};
    ++s.b;
    std::cout << s.b << "\n";
    ++s.b;
    std::cout << s.b << "\n";
}
