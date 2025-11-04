//
// Created by kotz on 04/11/2025.
//

#ifndef AVALIACAODAPUC_INFOSYSTEMDEBUG_H
#define AVALIACAODAPUC_INFOSYSTEMDEBUG_H
#include <QDate>
#include <QString>
#include <nlohmann/json.hpp>


class InfoSystemDebug {
private :
    QString data;
    QString info;
    QString path;
    nlohmann::ordered_json json;
public :
     InfoSystemDebug();
     InfoSystemDebug(QString info,QString path);

     void set_object (InfoSystemDebug * info_debug);

     QString GetALL();
};


#endif //AVALIACAODAPUC_INFOSYSTEMDEBUG_H