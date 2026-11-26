#include "mainwindow.h"
#include<QApplication>

int main(int argc,char* argv[])
{
    QApplication app(argc,argv);
    MainWindow windows;
    windows.show();
    return app.exec();
}