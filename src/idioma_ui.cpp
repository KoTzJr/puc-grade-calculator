//
// Created by KoTz on 23/10/2025.
//

#include "idioma_ui.h"
#include <PreferenceSystem.h>
#include <ui_option.h>
#include "FileManger.h"
#include "global_acess.h"

idioma_ui::idioma_ui() {

}

void idioma_ui::set_ui_idioma(Json & get_json ,Ui::_windows_ * ui,QString & ui_language ) {
    if (get_json.empty() == true) {
         return;
     }
    if (ui != nullptr) {
        QFile filew{"C:\\Users\\KoTz\\Documents\\GitHub\\puc-grade-calculator\\idioma.json"};
        filew.open(QFile::ReadOnly | QFile::Text);
         nlohmann::json json = nlohmann::json::parse(filew.readAll().toStdString());
         QString idioma = QString::fromStdString(get_json["idioma"]);
         ui_language = idioma;
         v_idioma(idioma);
    }
    return;
}
void idioma_ui::v_idioma(QString & ui_language) {
    QFile filew{"C:\\Users\\KoTz\\Documents\\GitHub\\puc-grade-calculator\\idioma.json"};
    filew.open(QFile::ReadOnly | QFile::Text);
    nlohmann::json json = nlohmann::json::parse(filew.readAll().toStdString());
        std::array<QString,5> menu_arquivo = {"","","","",""};
        std::array<QString,5> menu_ferramentas = {"","","","",""};
        std::array<QString,5> menu_option = {"","","","",""};
        std::array<QString,8> tabela_aluno = {"","","","","","","",""};
        if (ui_language == "Ingles") {

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
            menu_ferramentas[1]   =  QString::fromStdString(json["en"]["opção"]).remove('"');

            menu_option[0] =  QString::fromStdString(json["en"]["idioma"]).remove('"');
            menu_option[1] =  QString::fromStdString(json["en"]["aplicar"]).remove('"');
            menu_option[2] =  QString::fromStdString(json["en"]["salvar"]).remove('"');


        }
        if (ui_language == "Portugues") {
            menu_arquivo[0] = QString::fromStdString(json["Portugues"]["file"]).remove('"');
            menu_arquivo[1] = QString::fromStdString(json["Portugues"]["new"]).remove('"');
            menu_arquivo[2] = QString::fromStdString(json["Portugues"]["open"]).remove('"');
            menu_arquivo[3] = QString::fromStdString(json["Portugues"]["save"]).remove('"');
            menu_arquivo[4] = QString::fromStdString(json["Portugues"]["save as"]).remove('"');

            tabela_aluno[0]  = QString::fromStdString(json["Portugues"]["name"]).remove('"');
            tabela_aluno[1]  = QString::fromStdString(json["Portugues"]["planned classes"]).remove('"');
            tabela_aluno[2]  = QString::fromStdString(json["Portugues"]["taught classes"]).remove('"');
            tabela_aluno[3]  = QString::fromStdString(json["Portugues"]["attendance count"]).remove('"');
            tabela_aluno[4]  = QString::fromStdString(json["Portugues"]["average"]).remove('"');
            tabela_aluno[5]  = QString::fromStdString(json["Portugues"]["result"]).remove('"');
            tabela_aluno[6]  = QString::fromStdString(json["Portugues"]["needed avg"]).remove('"');


            menu_ferramentas[0]   =  QString::fromStdString(json["Portugues"]["tools"]).remove('"');
            menu_ferramentas[1]   =  QString::fromStdString(json["Portugues"]["option"]).remove('"');


            menu_option[0] =  QString::fromStdString(json["Portugues"]["language"]).remove('"');
            menu_option[1] =  QString::fromStdString(json["Portugues"]["apply"]).remove('"');
            menu_option[2] =  QString::fromStdString(json["Portugues"]["save"]).remove('"');
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
          }
    }

