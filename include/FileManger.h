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

struct  _FILE_ {
    bool isFileOpen   = false;
     QString fileName = "";
};

class FileManger {
private :
    QFile file;
    static bool fileIsOpen;
public :

    static void Remove_linha(QString & path);
    static _FILE_ is_open(QString path);
    static bool Load(QString path,nlohmann::json & get_json);
    static bool save(QString path,std::vector<Oitem> obj);
    FileManger();

};



#endif //FILEMANGER_H
