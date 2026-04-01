#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QObject>
#include <QFileInfo>
#include <QList>
#include <QTimer>

class fileManager : public QObject
{
    Q_OBJECT
public:
    fileManager(QObject *parent = nullptr);
    ~fileManager();

    void add(const QString& path);
    void remove(const QString& path);

signals:
    void exist(const QString& name, qint64 size);
    void notExist(const QString& name);
    void created(const QString& name, qint64 size);
    void deleted(const QString& name);
    void changed(const QString& name, qint64 size);

private:
    struct fileState {
        QString path;
        bool exists;
        qint64 size;

        fileState() : exists(false), size(0) {}
    };

    QList<fileState> files;
};

#endif // FILEMANAGER_H
