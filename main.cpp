#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <squareobject.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    qmlRegisterType<SquareObject>("SquareObject",1 , 0, "SquareObjectInfo");
    const QUrl url(u"qrc:/QtApp/Main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
        &app, []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
