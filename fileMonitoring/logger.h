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
};

#endif // LOGGER_H
