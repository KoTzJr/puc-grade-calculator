//
// Created by KoTz on 23/10/2025.
//

#include "ui/LanguageUI.h"
#include <ui_option.h>
#include <fmt/base.h>

#include "io/FileManager.h"
#include "utils/GlobalAccess.h"

LanguageUI::LanguageUI() {}

void LanguageUI::initialize_language_ui(Json & get_json ,Ui::_windows_ * ui,QString & ui_language ) {
    if (get_json.empty() == true) {
         return;
     }
    if (ui != nullptr) {
        QFile filew{GLOBAL::PATCH_FILE::language};
        filew.open(QFile::ReadOnly | QFile::Text);
         nlohmann::json json = nlohmann::json::parse(filew.readAll().toStdString());
         QString idioma = QString::fromStdString(get_json["idioma"]);
         ui_language = idioma;
         updateLanguageUI(idioma);
    }
    return;
}
nlohmann::json LanguageUI::getLanguageJsonValue(QString ui_language, QString language_key) {
    nlohmann::json json;
    if (ui_language.isEmpty() == true && language_key.isEmpty() == true) {
        return {};
    }
    if (ui_language == "Ingles") {
        ui_language = "en";
    }
    QFile filew{GLOBAL::PATCH_FILE::language};
    filew.open(QFile::ReadOnly | QFile::Text);
    try {
       json = nlohmann::json::parse(filew.readAll().toStdString());
    }catch (nlohmann::json::exception & e) {
    }
    return json[ui_language.toStdString()][language_key.toStdString()];
}

void LanguageUI::updateLanguageUI(QString & language_key) {
    QFile filew{GLOBAL::PATCH_FILE::language};
    filew.open(QFile::ReadOnly | QFile::Text);
    nlohmann::json json = nlohmann::json::parse(filew.readAll().toStdString());
        std::array<QString,5> menu_arquivo = {"","","","",""};
        std::array<QString,5> menu_ferramentas = {"","","","",""};
        std::array<QString,10> menu_option;
        std::array<QString,8> tabela_aluno = {"","","","","","","",""};



        if (language_key == "Ingles") {

            menu_arquivo[0] = QString::fromStdString(json["en"]["arquivo"]).remove('"');
            menu_arquivo[1] = QString::fromStdString(json["en"]["novo"]).remove('"');
            menu_arquivo[2] = QString::fromStdString(json["en"]["abrir"]).remove('"');
            menu_arquivo[3] = QString::fromStdString(json["en"]["salvar"]).remove('"');
            menu_arquivo[4] = QString::fromStdString(json["en"]["salvar como"]).remove('"');

            tabela_aluno[0]  = QString::fromStdString(json["en"]["nome"]).remove('"');
            tabela_aluno[1]  = QString::fromStdString(json["en"]["aulas previstas"]).remove('"');
            tabela_aluno[2]  = QString::fromStdString(json["en"]["aulas ministradas"]).remove('"');
            tabela_aluno[3]  = QString::fromStdString(json["en"]["numero presença"]).remove('"');
            tabela_aluno[4]  = QString::fromStdString(json["en"]["media"]).remove('"');
            tabela_aluno[5]  = QString::fromStdString(json["en"]["resultado"]).remove('"');
            tabela_aluno[6]  = QString::fromStdString(json["en"]["falta media"]).remove('"');

            menu_ferramentas[0]   =  QString::fromStdString(json["en"]["ferramentas"]).remove('"');
            menu_ferramentas[1]   =  QString::fromStdString(json["en"]["Sistema de Preferencia"]).remove('"');

            menu_option[0] =  QString::fromStdString(json["en"]["idioma"]).remove('"');
            menu_option[1] =  QString::fromStdString(json["en"]["aplicar"]).remove('"');
            menu_option[2] =  QString::fromStdString(json["en"]["salvar"]).remove('"');
            menu_option[3] =  QString::fromStdString(json["en"]["Tema"]).remove('"');
            menu_option[4] =  QString::fromStdString(json["en"]["Fonte"]).remove('"');

        }
        if (language_key == "Português") {

            menu_arquivo[0] = QString::fromStdString(json["Português"]["file"]).remove('"');
            menu_arquivo[1] = QString::fromStdString(json["Português"]["new"]).remove('"');
            menu_arquivo[2] = QString::fromStdString(json["Português"]["open"]).remove('"');
            menu_arquivo[3] = QString::fromStdString(json["Português"]["save"]).remove('"');
            menu_arquivo[4] = QString::fromStdString(json["Português"]["save as"]).remove('"');

            tabela_aluno[0]  = QString::fromStdString(json["Português"]["name"]).remove('"');
            tabela_aluno[1]  = QString::fromStdString(json["Português"]["planned classes"]).remove('"');
            tabela_aluno[2]  = QString::fromStdString(json["Português"]["taught classes"]).remove('"');
            tabela_aluno[3]  = QString::fromStdString(json["Português"]["attendance count"]).remove('"');
            tabela_aluno[4]  = QString::fromStdString(json["Português"]["average"]).remove('"');
            tabela_aluno[5]  = QString::fromStdString(json["Português"]["result"]).remove('"');
            tabela_aluno[6]  = QString::fromStdString(json["Português"]["needed avg"]).remove('"');


            menu_ferramentas[0]   =  QString::fromStdString(json["Português"]["tools"]).remove('"');
            menu_ferramentas[1]   =  QString::fromStdString(json["Português"]["PreferenceSystem"]).remove('"');


            menu_option[0] =  QString::fromStdString(json["Português"]["language"]).remove('"');
            menu_option[1] =  QString::fromStdString(json["Português"]["apply"]).remove('"');
            menu_option[2] =  QString::fromStdString(json["Português"]["save"]).remove('"');
            menu_option[3] =  QString::fromStdString(json["Português"]["theme"]).remove('"');
            menu_option[4] =  QString::fromStdString(json["Português"]["Font"]).remove('"');
        }
            GLOBAL::UI->menuArquivos->setTitle(menu_arquivo[0]);
            GLOBAL::UI->actionNovo->setText(menu_arquivo[1]);
            GLOBAL::UI->actionAbrir->setText(menu_arquivo[2]);
            GLOBAL::UI->actionSalvar->setText( menu_arquivo[3]);
            GLOBAL::UI->actionSalvar_como->setText(menu_arquivo[4]);

            GLOBAL::UI->tableWidget->setHorizontalHeaderLabels({
                tabela_aluno[0],
                tabela_aluno[1],
                tabela_aluno[2],
                tabela_aluno[3],
                   "N1",
                   "N2",
                tabela_aluno[4],
                tabela_aluno[5],
                tabela_aluno[6]
            });

            GLOBAL::UI->menuFerramentas->setTitle(menu_ferramentas[0]);
            GLOBAL::UI->actionOpition->setText(menu_ferramentas[1]);;

          if (GLOBAL::_ui_option != nullptr) {
               GLOBAL::_ui_option->label->setText(menu_option[0]);
               GLOBAL::_ui_option->btn_aplicar->setText(menu_option[1]);
               GLOBAL::_ui_option->btn_salvar->setText(menu_option[2]);
               GLOBAL::_ui_option->label_tema->setText(menu_option[3]);
          }
    }

