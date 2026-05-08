#ifndef LOGGER_H
#define LOGGER_H

#include <QObject>
#include <QString>

class logger: public QObject
{
    Q_OBJECT

public:
    logger(QObject *parent = nullptr);

public slots:
    void onExist(const QString& name, qint64 size);
    void onNotExist(const QString& name);
    void onCreated(const QString& name, qint64 size);
    void onDeleted(const QString& name);
    void onChanged(const QString& name, qint64 size);
};

#endif // LOGGER_H
