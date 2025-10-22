//
// Created by KoTz on 25/07/2025.
//

#include "../include/FileManger.h"

#include <qurl.h>

#include "ListDataItens.h"

bool FileManger::Load(const QString path,Json & get_json,bool & is_open) {

    if (path.isEmpty() == true) {
        return false;
    }
      QFile file(path);
      file.open(QFile::ReadWrite | QFile::WriteOnly  | QFile::Text);
      is_open = file.isOpen();
      get_json = nlohmann::json::parse(file.readAll().toStdString());
      return true;
}

_FILE_ FileManger::is_open(QString path) {
    QFile file(path);
    bool is_open = file.open(QFile::Text | QFile::ReadOnly);
    _FILE_ obj = {is_open, path};
    return obj;
}
bool FileManger::save(QString path,Info_config info) {
    if (path.isEmpty()) {
        return false;
    }
    std::fstream file(path.toStdString(),std::ios::app);

        nlohmann::ordered_json json = {
            {"idioma",},
            {"version",}

        };


    if (file.is_open()) {
        file.close();
        return true;
    }
    if (file.fail()) {
        return false;
    }
}
bool FileManger::save(QString path,std::vector<Oitem> obj) {

    if (path.isEmpty() == true || obj.empty() == true) {
        return false;
    }
    std::fstream file(path.toStdString(),std::ios::app);
       if (obj.empty() == false) {
           nlohmann::ordered_json json = nlohmann::ordered_json::array();
           for (auto & value : obj) {
               nlohmann::ordered_json basic_json = {
                   {"nome",value.name.toStdString()},
                   {"aulas previstas",value.planned_classes},
                   {"aulas ministradas",value.taught_classes},
                   {"numero presenca",value.attendance_count},
                   {"N1",value.N1},
                   {"N2",value.N2},
               };
               json.push_back(basic_json);
           file << json.dump(4);
       }
           if (file.is_open()) {
               file.close();
               return true;
           }
           if (file.fail()) {
               return false;
           }
   }
    return false;
}
FileManger::FileManger() {

}
