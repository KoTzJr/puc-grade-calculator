//
// Created by kotz on 22/10/2025.
//

#ifndef AVALIACAODAPUC_INFO_CONFIG_H
#define AVALIACAODAPUC_INFO_CONFIG_H

#include  <QString>
#include "nlohmann/json.hpp"


class Info_config {
    QString idioma;
    QString version;
public :
    void set_idioma(QString idioma);
    QString get_idioma() const;
    QString get_version() const;

    Info_config();
    Info_config(QString idioma,QString version);
};


#endif //AVALIACAODAPUC_INFO_CONFIG_H