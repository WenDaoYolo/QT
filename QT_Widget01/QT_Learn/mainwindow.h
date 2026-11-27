#pragma  once
#include<QMainWindow>
#include<iostream>
#include<QPushButton>
#include<QMessageBox>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QLineEdit>
#include<QListWidget>
#include<QPixmap>
#include<QLabel>

class MainWindow:public QMainWindow
{
    private:
        void WindowMessage(const char* str);

    public:
        MainWindow(QWidget* parent=nullptr);
};