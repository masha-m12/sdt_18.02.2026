#include "logger.h"
#include <QDebug>
#include <iostream>

logger::logger(QObject *parent)
    : QObject(parent)
{
}

void logger::onExist(const QString &name, qint64 size)
{
    qDebug() << name << "exist, size" << size << "bytes";
}

void logger::onNotExist(const QString &name)
{
    qDebug() << name << "not exist";
}

void logger::onCreated(const QString &name, qint64 size)
{
    qDebug() << name << "created, size" << size << "bytes";
}

void logger::onDeleted(const QString &name)
{
    qDebug() << name << "deleted";
}

void logger::onChanged(const QString &name, qint64 size)
{
    qDebug() << name << "changed, size" << size << "bytes";
}
