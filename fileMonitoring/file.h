#ifndef FILE_H
#define FILE_H

#include <QObject>
#include <QString>
#include <QFileInfo>

class file : public QObject {
public:
    file(const QString& path, QObject *parent = nullptr);
    QString getPath() const;
    qint64 getSize() const;
    bool exists() const;
    void update();

private:
    QFileInfo fileInfo;
    qint64 size;
    QString name;
    QString path;
    bool lastExists;

signals:
    void exist(const QString& name, qint64 size);
    void notExist(const QString& name);
    void created(const QString& name, qint64 size);
    void deleted(const QString& name);
    void changed(const QString& name, qint64 size);
};

#endif // FILE_H
