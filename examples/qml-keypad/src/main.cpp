// Copyright, Burkhard Stubert (burkhard.stubert@embeddeduse.com)

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QString>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine appEngine;
    appEngine.load(QStringLiteral("qrc:/main.qml"));
    return app.exec();
}
