//
// Created by KoTz on 25/07/2025.
//

#include "../include/FileManger.h"
#include <QDebug>


QByteArray FileManger::Load(QString path) {
    QByteArray data;
    if (path.isEmpty() == true) {
           return QByteArray();
      }
    QFile filew{path};
    if (filew.open(QFile::ReadOnly)) {
         data = filew.readAll();
         filew.close();
     }
    return data;
}

bool FileManger::save(QString path, QString data) {
    qint64 log = 0;
    if (path.isEmpty() == true && data.isEmpty() == true) {
        return false;
   }
     QFile filew{path};
    if (filew.open(QFile::WriteOnly)) {
         log = filew.write(data.toUtf8());
         filew.close();
     }
     if (log == -1) {
         return false;
     }
     return true;
}

FileManger::FileManger() {

}
