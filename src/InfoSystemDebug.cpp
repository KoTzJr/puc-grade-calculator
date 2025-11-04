//
// Created by kotz on 04/11/2025.
//

#include "../include/InfoSystemDebug.h"

#include "FileManager.h"


InfoSystemDebug::InfoSystemDebug() {


}
InfoSystemDebug::InfoSystemDebug(QString info, QString path) {
       QDateTime date = QDateTime::currentDateTime();
       data = date.toString("dd/MM/yyyy hh:mm:ss");
       this->info = info;
}
void InfoSystemDebug::set_object(InfoSystemDebug *info_debug) {
      if (info_debug != nullptr) {
          info = info_debug->info;
          data = info_debug->data;
          path = info_debug->path;
      }
}
QString InfoSystemDebug::GetALL() {
     json = {
         {"DATE",data.toStdString()},
         {"INFO",info.toStdString()},
         {"PATH",path.toStdString()}
     };


    return data + "\n\n\n\r" + this->info + "\n" + path;
}

