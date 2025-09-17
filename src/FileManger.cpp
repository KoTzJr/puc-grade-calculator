//
// Created by KoTz on 25/07/2025.
//

#include "../include/FileManger.h"
#include "ListDataItens.h"


bool FileManger::Load(QString path,Json & objs) {
    QFile file(path);
    if (file.open(QFile::Text | QFile::ReadOnly)){}
    nlohmann::json obj = nlohmann::json::parse(file.readAll().toStdString());
    objs = obj;
    return true;
}

bool FileManger::save(QString path,std::vector<Oitem>  obj) {
    if (path.isEmpty() == true || obj.empty() == true) {
        return false;
    }
     if (std::filesystem::exists(path.toStdString())) {
         std::remove(path.toStdString().c_str());
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

     int valor = 10;
     auto valor_ = 10; // inteiro
    return false;
}
FileManger::FileManger() {

}
