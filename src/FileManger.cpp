//
// Created by KoTz on 25/07/2025.
//

#include "../include/FileManger.h"
#include "ListDataItens.h"


bool FileManger::Load(QString path,Json & get_json) {
    QFile file(path);
    std::filesystem::path p(path.toStdString());
    if (std::filesystem::exists(p) == false) {
        return false;
    }
    if (file.open(QFile::Text | QFile::ReadOnly)){}
    get_json = nlohmann::json::parse(file.readAll().toStdString());
    return true;
}

_FILE_ FileManger::is_open(QString path) {
    QFile file(path);
    auto get = file.open(QFile::ReadOnly);
    //fileIsOpen = get;
    _FILE_ obj = {get, path};
    return obj;
}
bool FileManger::save(QString path,std::vector<Oitem>  obj) {

    if (path.isEmpty() == true || obj.empty() == true) {
        return false;
    }
    if (obj.empty() == false) {
        std::fstream file(path.toStdString(),std::ios::app);
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
FileManger::FileManger() {

}
