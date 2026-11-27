#include "mainwindow.h"

void MainWindow::WindowMessage(const char* str)
{
    std::cout<<"button is onclicked!"<<std::endl;
    QMessageBox::information(this,"system Message",str);                     //消息提示框，是模态的
}

void MainWindow::PopHint()
{
    QDialog* d1=new QDialog(this);                                                         //创建对话框
    d1->setWindowTitle("Child Window");                                                 //设置窗口标题
    d1->setFixedSize(300,200);                                                                //设置对话框固定大小
    QLabel* hint=new QLabel("这是一个新窗口",this);                                //为对话框添加标签和布局
    QHBoxLayout* lbox=new QHBoxLayout;
    lbox->addWidget(hint);
    d1->setLayout(lbox);

    d1->setModal(false);                                                                          //true：模态，阻塞主窗口，必须等对话框关闭后才能响应主窗口事件，调用exec()进入事件循环
                                                                                                               //false：非模态，不阻塞主窗口，可同时响应主窗口和对话框的事件，调用show()方法来独立显示
    d1->show();
}

MainWindow::MainWindow(QWidget* parent):QMainWindow(parent)
{
    //1.
    setWindowTitle("Calculate V1.0");                                                               //窗口标题
    resize(700,200);                                                                                         //窗口的默认大小(可调整)
    this->setFixedSize(700,200);                                                                      //窗口的默认大小(最大化、宽高不可调整，优先级更高)
    this->setStyleSheet("color:white;");                                                           //设置窗口中全局部件的样式(类 css机制语法，文本色)

    //2.
    QPushButton* b1=new QPushButton("Click me by one",this);
    //b1->setFixedWidth(120);
    //b1->setFixedHeight(50);
    b1->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);           //设置按钮大小的策略，自动扩展并随主窗口变化
    connect(b1,&QPushButton::clicked,this,[this]{MainWindow::WindowMessage("Hi，This is one");}); //连接信号槽，信号触发方式为单击按钮
    QString style1="QPushButton{background-color:#0ae;}";                         //预定义样式(类css机制语法，背景色)
    QString style2="QLabel{color:red;}";                                                        //预定义样式(类css机制语法，字体色)

    //3.
    QPushButton* b2=new QPushButton("Click me by two",this);
    b2->setStyleSheet(style1);                                                                        //设置单个部件的样式(使用预定义样式)
    b2->setFixedWidth(120);
    b2->setFixedHeight(50);
    connect(b2,&QPushButton::clicked,this,[this]{MainWindow::PopHint();});  //连接信号槽，信号触发方式为单击按钮

    //4.
    QLineEdit* l1=new QLineEdit(this);                                                             //输入框

    //5.
    QLabel* Ll1=new QLabel("计算器软件",this);                                               //文本标签1
    Ll1->setStyleSheet(style2);
    QLabel* Ll2=new QLabel("计算器硬件",this);                                               //文本标签2
    Ll2->setStyleSheet(style2);

    //6.
    QListWidget* L1=new QListWidget(this);
    L1->addItem("开始");
    L1->addItem("单步");
    L1->addItem("连续");
    L1->addItem("后退");
    L1->addItem("暂停");
    L1->addItem("结束");

    //7.QPixmap p1("....");                                          //加载图像文件

    //8.
    QHBoxLayout* h_layout1=new QHBoxLayout;      //创建水平布局器(其中的部件按水平方式排列)
    QVBoxLayout* v_layout1=new QVBoxLayout;       //创建垂直布局器(其中的部件按垂直方式排列)
    h_layout1->addWidget(b1);                                //将按钮1加入水平布局器
    h_layout1->addWidget(b2);                                //将按钮2加入水平布局器
    h_layout1->addWidget(l1);
    h_layout1->addWidget(L1);
    v_layout1->addWidget(Ll1);                                //将标签加入垂直布局器
    v_layout1->addWidget(Ll2);                                //将标签加入垂直布局器
    h_layout1->addLayout(v_layout1);                    //布局器的嵌套，将垂直布局器作为部件加入水平布局器
    h_layout1->addWidget(Ll1);
    QWidget* centralWidget = new QWidget(this);    //因为窗口继承的是QMainWindow，特殊结构，所以不能直接在上面布局，需创建一个部件，在部件上布局，若继承普通的QWidget或Dialog则可直接布局
    centralWidget->setLayout(h_layout1);              //将布局应用到父窗口的中央部件上
    this->setCentralWidget(centralWidget);              //将其设置为中央部件(垂直+水平对齐，会随窗口自动调整)，或者手动设置部件的位置

    //9.
    std::cout<<"create window success"<<std::endl;
}