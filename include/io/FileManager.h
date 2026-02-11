//
// Created by KoTz on 25/07/2025.
//

#ifndef FILEMANGER_H
#define FILEMANGER_H

#include <QFile>
#include "data/ListDataItems.h"
#include <nlohmann/json.hpp>
#include <fstream>
#include <QDebug>
#include "data/InfoConfig.h"
#include <QDir>
#include <qurl.h>
#include "data/ListDataItems.h"
#include "GlobalAccess.h"

typedef std::vector<Oitem> item_vector_array;
typedef Info_config info_config_list;

const std::string config_file = ".cfgVx";

enum OPTION {
    SAVE_FILE_JSON_ALUNO = 0,
    SAVE_FILE_JSON_Sistema = 1
};
enum TYPE_SAVE {
    SAVE_AS = 0,
    SAVE_LOCAL_FILE = 1

};

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
    static void initialize_file_manager();
    static _FILE_ is_open(QString path);
    static bool is_null_fileJson(QString patch);
    static bool Load(QString path,Json & get_json);
    static bool Load(const QString path,nlohmann::json & get_json, bool & open);
    static bool save(QString path,std::variant<item_vector_array,info_config_list> obj);
    FileManger();

};
#endif //FILEMANGER_H
