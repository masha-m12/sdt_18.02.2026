#ifndef FILE_H
#define FILE_H

#include <QObject>
#include <QString>
#include <QFileInfo>

class file {
public:
    file(QString& path);
    QString getPath();
    size_t getSize();
    void update();

private:
    size_t size;
    QString name;
    QString path;

signals:
    void exist(const QString& name, size_t size);
    void notExist(const QString& name, size_t size);
    void created(const QString& name, size_t size);
    void deleted(const QString& name);
    void changed(const QString& name, size_t size);
};

#endif // FILE_H
