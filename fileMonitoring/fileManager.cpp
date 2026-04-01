#include "fileManager.h"
#include <QFileInfo>
#include <QTimer>

fileManager::fileManager(QObject *parent)
    : QObject(parent)
{

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
