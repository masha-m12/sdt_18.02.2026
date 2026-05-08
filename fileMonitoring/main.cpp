#include <QCoreApplication>
#include <QDebug>
#include "fileManager.h"
#include "logger.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    fileManager manager;
    logger log;

    QObject::connect(&manager, &fileManager::exist, &log, &logger::onExist);
    QObject::connect(&manager, &fileManager::notExist, &log, &logger::onNotExist);
    QObject::connect(&manager, &fileManager::created, &log, &logger::onCreated);
    QObject::connect(&manager, &fileManager::deleted, &log, &logger::onDeleted);
    QObject::connect(&manager, &fileManager::changed, &log, &logger::onChanged);

    manager.add("test.txt");

    return a.exec();
}
