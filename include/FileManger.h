//
// Created by KoTz on 25/07/2025.
//

#ifndef FILEMANGER_H
#define FILEMANGER_H

#include <QFile>
#include "ListDataItens.h"
#include <nlohmann/json.hpp>
#include <fstream>
#include <QDebug>

using Json = nlohmann::json;

class FileManger {
private :
    QFile file;
public :
    static bool Load(QString path,nlohmann::json & get_json);
    static bool save(QString path,std::vector<Oitem> obj);
    FileManger();

};



#endif //FILEMANGER_H
