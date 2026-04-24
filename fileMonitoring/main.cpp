#include <QCoreApplication>

#include "fileManager.h"
#include "logger.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    fileManager manager;
    logger log;

    QObject::connect(&manager, &fileManager::exist, &log, &logger::onExist);
    QObject::connect(&manager, &fileManager::notExist, &log, &logger::onNotExist);

    manager.add("test.txt");

    return a.exec();
}
