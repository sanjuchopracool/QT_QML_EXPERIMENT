#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "Animals.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    const QMetaObject meta = Animal::staticMetaObject;
    qDebug() << meta.enumeratorCount();
    qDebug() << meta.enumeratorOffset();

    QMetaEnum enumObject1 = meta.enumerator(0);
    QMetaEnum enumObject2 = meta.enumerator(1);

    qDebug() << enumObject1.name();

    auto keyCount1 = enumObject1.keyCount();
    for( int i = 0; i < keyCount1; ++i )
        qDebug() << enumObject1.key(i);

    qDebug() << enumObject2.name();
    auto keyCount2 = enumObject2.keyCount();
    for( int i = 0; i < keyCount2; ++i )
        qDebug() << enumObject2.key(i);

    qDebug() << QVariant(Animal::Mammals).toString();
    qDebug() << QVariant::fromValue(Animal::Mammals).toString();

    QQmlApplicationEngine engine;

    qmlRegisterUncreatableType<Animal>("com.chops.sanjay", 1, 0, "Animal", "Should not create this");

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
