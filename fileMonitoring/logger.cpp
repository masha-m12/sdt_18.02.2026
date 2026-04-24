#include "logger.h"
#include <iostream>

logger::logger(QObject *parent)
    : QObject(parent)
{
}

void logger::onExist(const QString &name, qint64 size)
{
    std::cout << name.toStdString() << " exist, size " << size << " bytes\n";
}

void logger::onNotExist(const QString &name)
{
    std::cout << name.toStdString() << " not exist\n";
}
