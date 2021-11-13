// Copyright, Burkhard Stubert (burkhard.stubert@embeddeduse.com)

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QString>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine appEngine;
    appEngine.addImportPath(u"qrc:/imports"_qs);
    appEngine.load(u"qrc:/main.qml"_qs);
    return app.exec();
}
