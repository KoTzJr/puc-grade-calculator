//
// Created by KoTz on 25/07/2025.
//
#include <rapidcsv.h>
#include "io/FileManager.h"

#include "FileVx.h"
#include "json_parser.h"
#include <QMessageBox>


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
    QString get;

    // #ifdef _WIN32
    //
    // QMessageBox::information(nullptr,"E o windows","windows");
    //
    // #endif
    //
    // #ifdef __linux__
    //   QMessageBox::information(nullptr,"É Linux","linux");
    // #endif



    info_config_list info
    {
        "Português", // Idioma padrão
        "0.1", // Versão
        "Arial", // Fonte padrão
        "Claro" // Tema padrão
    };

    // Verifica se o diretório e o arquivo de configuração válido já existem
    if (std::filesystem::exists(path) == true && QFile{patch + "/config" + QString::fromStdString(config_file)}.exists() == true
        && is_null_fileJson(patch + "/config" + QString::fromStdString(config_file)) == false) {
        GLOBAL::PATCH_FILE::CONFIG = patch + "/config" + QString::fromStdString(config_file);
        return;
    }

    for (auto & i : std::filesystem::directory_iterator(path)) {
        if (i.path().string().find(config_file) != std::string::npos) {
            get = QString::fromStdString(i.path().string());
            QFile file(get);
            file.open(QFile::ReadWrite | QFile::Text);
            return;
        };
    }
    // Cria o diretório caso não exista
    std::filesystem::create_directories(patch.toStdString());
    // Salva o caminho na configuração global e escreve as configurações padrão
    GLOBAL::PATCH_FILE::CONFIG = patch + "/config" + QString::fromStdString(config_file);
    save(patch + "/config"+ QString::fromStdString(config_file), info);
}


bool FileManger::is_null_fileJson(QString path) {
     QFile file(path);
     file.open(QFile::ReadOnly | QFile::Text);
     nlohmann::json json = {};
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
        qDebug() << QObject::tr("Error reading file %1").arg(path);
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
bool FileManger::save(QString path, std::variant<item_vector_array, info_config_list> obj) {
    if (path.isEmpty() == true) {
        return false;
    }
    QFile filew(path);
    if (filew.exists() == true) {
        filew.remove();
    }
    nlohmann::ordered_json json_;

    std::fstream file(path.toStdString(),std::ios::app);
    if (file.is_open() == true) {
        if (std::holds_alternative<item_vector_array>(obj)) {
            if (std::get<item_vector_array>(obj).empty() == false) {
                nlohmann::ordered_json json = nlohmann::ordered_json::array();
                for (auto & value : std::get<item_vector_array>(obj)) {
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
            }
        }
        if (std::holds_alternative<info_config_list>(obj)) {
            // nlohmann::json json = {
            //     {"idioma" ,    std::get<info_config_list>(obj).idioma.toStdString()},
            //     {"config",     GLOBAL::PATCH_FILE::CONFIG.toStdString()},
            //     {"tema",       std::get<info_config_list>(obj).Theme.toStdString()},
            //     {"Fonte",      std::get<info_config_list>(obj).fonte.toStdString()},
            // };

           auto  json = json_parser::info_file(
                             INFO{std::get<info_config_list>(obj).idioma.toStdString(),
                                   GLOBAL::PATCH_FILE::CONFIG.toStdString(),
                                    std::get<info_config_list>(obj).Theme.toStdString(),
                                   std::get<info_config_list>(obj).fonte.toStdString()});
            file << json.dump(2);
        }
       auto value = FileVx::converteJsonFromFileVX(QString::fromStdString(path.toStdString()));
        if (value == 0 || value == -2 || value == -1) {
            return false;
        }
        if (value == 1 || value == 2) {
            return true;
        }
    }
    return false;
}
FileManger::FileManger() {}
