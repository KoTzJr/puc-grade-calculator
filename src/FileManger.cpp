//
// Created by KoTz on 25/07/2025.
//

#include "../include/FileManger.h"
#include "ListDataItens.h"

#define window_32 false
#define systemlinux false

#ifdef _WIN32
   window_32 true
#endif

#ifdef __linux__
    systemlinux true
#endif

#ifdef __APPLE__
    // macOS
#endif

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

void FileManger::Remove_linha(QString & path) {
    qDebug () << "windows " << window_32;
    auto get =  path.remove("file://");
    path = get;
}


_FILE_ FileManger::is_open(QString path) {
    Remove_linha(path);
    QFile file(path);
    bool is_open = file.open(QFile::Text | QFile::ReadOnly);
    _FILE_ obj = {is_open, path};
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
