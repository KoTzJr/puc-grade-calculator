//
// Created by kotz on 19/09/2025.
//

// You may need to build the project (run Qt uic code generator) to get "ui_option.h" resolved

#include "ui/PreferenceSystem.h"

#include <QFileDialog>

#include "json_parser.h"
#include "ui_option.h"
#include "io/FileManager.h"
#include "utils/GlobalAccess.h"
#include "qwidget.h"
#include "UIManager.h"

option::option(QWidget *parent) : QMainWindow(parent), ui_option_(new Ui::option) {
    ui_option_->setupUi(this);
    GLOBAL::init_global(ui_option_);
    UI_FONT::text(GLOBAL::json,ui_option_);
    ui_option_->lineEdit->setEnabled(false);
   if (json_parser::GetFileJson(GLOBAL::PATCH_FILE::CONFIG,"config").is_null() == false) {
       auto get= QString::fromStdString(json_parser::GetFileJson(GLOBAL::PATCH_FILE::CONFIG,"config")).remove("'");
       ui_option_->lineEdit->setText(QUrl{get}.fileName());
   }
    if (GLOBAL::idioma == "Ingles") {
            setWindowTitle(QString::fromStdString(LanguageUI::getLanguageJsonValue("en","Sistema de Preferencia"))
            .remove(""));
        LanguageUI::updateLanguageUI(GLOBAL::idioma);
        ui_option_->comboBox->setCurrentIndex(1);
    }
    if (GLOBAL::idioma == "Português") {
        setWindowTitle(QString::fromStdString
            (LanguageUI::getLanguageJsonValue("Português","Preference System"))
            .remove(""));
        LanguageUI::updateLanguageUI(GLOBAL::idioma);
        ui_option_->comboBox->setCurrentIndex(0);
    }
}

void option::on_btn_search_paste_clicked() {
    QFileDialog fileDialog(this);
    fileDialog.setFileMode(QFileDialog::ExistingFile);
    QString fileName = fileDialog.getOpenFileName(this, tr("Open File"), "", tr("Arquivos JSON (*.json)"));
    if (fileName.isEmpty() == true) {
        return;
    }
    ui_option_->lineEdit->setText(QUrl(fileName).fileName());
    GLOBAL::PATCH_FILE::CONFIG = fileName;
}

void option::on_btn_aplicar_clicked() {

    Json json;
    auto idioma = ui_option_->comboBox->currentText();
    QString idi;
    QString Palavra_chave = "";
    UI_FONT::get(ui_option_->fontComboBox->currentText());
    if (idioma == "Ingles") {
        Palavra_chave = "Sistema de Preferencia";
        idi = "en";
    }
    if (idioma == "Português") {
        Palavra_chave = "PreferenceSystem";
        idi = "Português";
    }
    LanguageUI::updateLanguageUI(idioma);
    setWindowTitle(QString::fromStdString
            (LanguageUI::getLanguageJsonValue(idi,Palavra_chave))
            .remove(""));
}
void option::on_btn_salvar_clicked() {
    info_config_list config;
    config.idioma = ui_option_->comboBox->currentText();
    config.fonte  = ui_option_->fontComboBox->currentText();
    config.Theme  = ui_option_->Combox_tema->currentText();
    auto file_save = FileManger::save(GLOBAL::PATCH_FILE::CONFIG,config);
    if (file_save) {
        qDebug () << "Salvo com sucesso";
    }else {
        qDebug () << "Erro ao salvar";
    }
}

option::~option() {
    delete ui_option_;
}