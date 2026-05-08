#include "fileManager.h"
#include <QFileInfo>
#include <QTimer>

fileManager::fileManager(QObject *parent)
    : QObject(parent)
{
    timer.setInterval(100);
    connect(&timer, &QTimer::timeout, this, &fileManager::checkFiles);
    timer.start();
}

fileManager::~fileManager() {

}

void fileManager::add(const QString& path)
{
    for (const auto& file : files) {
        if (file.path == path) {
            return;
        }
    }

    fileState newFile;
    newFile.path = path;

    QFileInfo info(path);
    newFile.exists = info.exists();

    if (newFile.exists) {
        newFile.size = info.size();
    }
    else {
        newFile.size = 0;
    }

    files.append(newFile);

    if (newFile.exists) {
        emit exist(path, newFile.size);
    }
    else {
        emit notExist(path);
    }
}

void fileManager::remove(const QString& path)
{
    for (int i = 0; i < files.size(); ++i) {
        if (files[i].path == path) {
            files.removeAt(i);
            break;
        }
    }
}

void fileManager::checkFiles()
{
    for (int i = 0; i < files.size(); ++i)
    {
        QFileInfo info(files[i].path);

        bool currentExists = false;
        qint64 currentSize = 0;

        if (info.exists() && info.isFile())
        {
            currentExists = true;
            currentSize = info.size();
        }
        else
        {
            currentExists = false;
            currentSize = 0;
        }

        if (!files[i].exists && currentExists)
        {
            emit created(files[i].path, currentSize);
        }

        else if (files[i].exists && !currentExists)
        {
            emit deleted(files[i].path);
        }

        else if (files[i].exists && currentExists)
        {
            if (files[i].size != currentSize)
            {
                emit changed(files[i].path, currentSize);
            }
        }

        files[i].exists = currentExists;
        files[i].size = currentSize;
    }
}
