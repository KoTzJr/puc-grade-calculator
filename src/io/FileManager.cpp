//
// Created by KoTz on 25/07/2025.
//

#include "io/FileManager.h"

/**
 * Inicializa o sistema de gerenciamento de arquivos configurando diretórios e arquivo de configuração
 * 
 * Esta função:
 * 1. Cria um diretório para a aplicação na pasta Documentos do usuário
 * 2. Verifica se o arquivo config.json existe e é válido
 * 3. Se o arquivo de configuração não existir ou for inválido, cria um novo com configurações padrão
 */
void FileManger::initialize_file_manager() {
    // Define o caminho para a pasta da aplicação no diretório Documentos do usuário
    QString patch = QDir::homePath() + "/Documents/PUCSimulador";
    std::filesystem::path path = patch.toStdString();

    // Verifica se o diretório e o arquivo de configuração válido já existem
    if (std::filesystem::exists(path) == true && QFile{patch + "/config.json"}.exists() == true
        && is_null_fileJson(patch + "/config.json") == false) {
        GLOBAL::PATCH_FILE::CONFIG = patch + "/config.json";
        return;
    }
    // Cria o diretório caso não exista
    std::filesystem::create_directories(patch.toStdString());
    std::ofstream file(patch.toStdString() + "/config.json");

    // Define as configurações padrão
    info_config_list info
    {
        "Português", // Idioma padrão
        "0.1", // Versão
        "Arial", // Fonte padrão
        "Claro" // Tema padrão
    };

    // Salva o caminho na configuração global e escreve as configurações padrão
    GLOBAL::PATCH_FILE::CONFIG = patch + "/config.json";
    save(patch + "/config.json", info);
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
bool FileManger::save(QString path,info_config_list info) {
    if (path.isEmpty()) {
        return false;
    }
    QFile filew(path);
    if (filew.exists() == true) {
        filew.remove();
    }
      std::fstream file(path.toStdString(),std::ios::app);
       auto idioma =  info.idioma;
       auto config =  GLOBAL::PATCH_FILE::CONFIG;
       auto tema   =  info.Theme;
       auto fonte  =  info.fonte;
        nlohmann::json json = {
            {"idioma" , idioma.toStdString()},
            {"config",  config.toStdString()},
            {"tema",    tema.toStdString()},
            {"Fonte",   fonte.toStdString()},
        };
        file << json.dump(2);
    if (file.is_open()) {
        file.close();
        return true;
    }
    if (file.fail()) {
        return false;
    }

    return  false;
}
// bool FileManger::save(QString path,  obj) {
//     if (path.isEmpty() == true) {
//         return false;
//     }
//     QFile filew(path);
//     if (filew.exists() == true) {
//         filew.remove();
//     }
//     std::fstream file(path.toStdString(),std::ios::app);
//
//        nlohmann::json json = {
//            {}
//        };
//        file << json.dump(2);
// }


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
