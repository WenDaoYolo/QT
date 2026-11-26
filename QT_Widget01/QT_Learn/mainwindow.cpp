#include "mainwindow.h"

void MainWindow::WindowMessage(const char* str){  QMessageBox::information(this,"system Message",str); }

MainWindow::MainWindow(QWidget* parent):QMainWindow(parent)
{
    //1.
    setWindowTitle("hello world");
    resize(100,150);

    //2.
    QPushButton* b1=new QPushButton("Click me by 1",this);
    b1->setFixedWidth(120);
    b1->setFixedHeight(50);
    connect(b1,&QPushButton::clicked,this,[this]{MainWindow::WindowMessage("hi,this is 1");});

    //3.
    QPushButton* b2=new QPushButton("Click me by 2",this);
    b2->setFixedWidth(120);
    b2->setFixedHeight(50);
    connect(b2,&QPushButton::clicked,this,[this]{MainWindow::WindowMessage("hi,this is 2");});

    //4.
    QHBoxLayout* h_layout1=new QHBoxLayout;      //创建水平布局器(其中的部件按水平方式排列)
    h_layout1->addWidget(b1);                                //将按钮1加入布局器
    h_layout1->addWidget(b2);                                //将按钮2加入布局器
    QWidget* centralWidget = new QWidget(this);   //因为窗口继承的是QMainWindow，有特殊结构，所以不能直接在上面布局，需要创建一个部件，在部件上布局
    centralWidget->setLayout(h_layout1);             //将布局应用到父窗口的部件上
    this->setCentralWidget(centralWidget);             //将其设置为中央部件(垂直+水平对齐，会随窗口自动调整)，或者手动设置部件的位置

    //5.
    std::cout<<"create window success"<<std::endl;
}