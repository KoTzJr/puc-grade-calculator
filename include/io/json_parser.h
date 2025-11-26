//
// Created by KoTz on 20/11/2025.
//

#ifndef AVALIACAODAPUC_JSON_H
#define AVALIACAODAPUC_JSON_H
#include <nlohmann/json.hpp>
#include <QString>


class json_parser {

public :
     static nlohmann::json GetFileJson(QString Patch,QString Palavra_chave);
     json_parser();
};


#endif //AVALIACAODAPUC_JSON_H