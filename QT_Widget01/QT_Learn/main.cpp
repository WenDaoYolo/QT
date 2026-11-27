#include "mainwindow.h"
#include<QApplication>

int main(int argc,char* argv[])
{
    QApplication app(argc,argv);            //创建应用程序实例
    MainWindow windows;                      //创建主窗口
    windows.show();                              //显示主窗口
    return app.exec();                             //主函数返回应用程序的exec方法进行应用程序的主事件循环
}