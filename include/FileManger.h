//
// Created by KoTz on 25/07/2025.
//

#ifndef FILEMANGER_H
#define FILEMANGER_H

#include <QSaveFile>
#include <QFile>

class FileManger {
private :
    QFile file;
public :
    QByteArray Load(QString path);
    bool save(QString path,QString data);
    FileManger();

};



#endif //FILEMANGER_H
