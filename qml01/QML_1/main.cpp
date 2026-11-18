#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include<iostream>

void start(QGuiApplication* app,QQmlApplicationEngine* engine)
{
    QObject::connect
    (
        engine,
        &QQmlApplicationEngine::objectCreationFailed,
        app,
        [](){ QCoreApplication::exit(-1); },
        Qt::QueuedConnection
    );

    engine->loadFromModule("QML_1", "Main");
    std::cout<<"system log:load success!"<<std::endl;
}

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    start(&app,&engine);

    return QGuiApplication::exec();
}
