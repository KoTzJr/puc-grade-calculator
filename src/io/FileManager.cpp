//
// Created by KoTz on 25/07/2025.
//

#include "io/FileManager.h"

void FileManger::initialize_file_manager() {
    QString patch =  QDir::homePath() + "/Documents/PUCSimulador";
    std::filesystem::path path = patch.toStdString();

    if (std::filesystem::exists(path) == true && QFile{patch + "/config.json"}.exists() == true
        && is_null_fileJson(patch + "/config.json") == false)
    {
        return;
    }
    std::filesystem::create_directories(patch.toStdString());
    std::ofstream file(patch.toStdString() + "/config.json");
    save(patch + "/config.json",Info_config{"Português"});
}


bool FileManger::is_null_fileJson(QString path) {
     QFile file(path);
     file.open(QFile::ReadOnly | QFile::Text);
     nlohmann::json json;
    try {
        json = nlohmann::json::parse(file.readAll().toStdString());
    }catch (nlohmann::json::exception & e) {
        return true;
    }
     return false;
}


bool FileManger::Load(QString path,Json & get_json) {
    if (path.isEmpty() == true) {
        return false;
    }
    QFile file(path);
    if (file.exists() == false) {
        return false;
    }
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    try {
        get_json = nlohmann::json::parse(file.readAll().toStdString());

    }catch (nlohmann::json::exception & e) {

    }
    return true;
}

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
    QFile filew(path);
    if (filew.exists() == true) {
        filew.remove();
    }
      std::fstream file(path.toStdString(),std::ios::app);
       auto idioma = info.idioma;
        nlohmann::json json = {
            {"idioma" ,idioma.toStdString()}
        };
        file << json.dump(0);
    if (file.is_open()) {
        file.close();
        return true;
    }
    if (file.fail()) {
        return false;
    }

    return  false;
}
bool FileManger::save(QString path,std::vector<Oitem> obj) {

    if (path.isEmpty() == true || obj.empty() == true) {
        return false;
    }
    QFile filew(path);
    if (filew.exists() == true) {
        filew.remove();
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
       }
           file << json.dump(4);
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
FileManger::FileManger() {}
