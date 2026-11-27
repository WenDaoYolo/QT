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
#include<QDialog>

class MainWindow:public QMainWindow
{
    private:
        void WindowMessage(const char* str);
        void PopHint();

    public:
        MainWindow(QWidget* parent=nullptr);
};