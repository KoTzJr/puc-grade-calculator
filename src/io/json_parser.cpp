//
// Created by KoTz on 20/11/2025.
//

#include "../../include/io/json_parser.h"
#include <QString>
#include <QFile>
#include <QDebug>


nlohmann::json json_parser::GetFileJson(QString Patch, QString Palavra_chave) {
    nlohmann::json json;
    QFile filew{Patch};
    filew.open(QFile::ReadOnly | QFile::Text);
    try {
        json = nlohmann::json::parse(filew.readAll().toStdString());
    }catch (nlohmann::json::exception & e) {
        qDebug () << e.what();

        return nlohmann::json {};
    }
    return json[Palavra_chave.toStdString()];
}
json_parser::json_parser() {

}
