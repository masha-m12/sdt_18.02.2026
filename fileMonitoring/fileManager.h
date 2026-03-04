#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "file.h"

class fileManager {
public:

    void add(QString& path);
    void remove(QString& path);

    ~fileManager();

private:

};

#endif // FILEMANAGER_H
