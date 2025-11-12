//
// Created by KoTz on 23/10/2025.
//

#ifndef AVALIACAODAPUC_IDIOMA_UI_H
#define AVALIACAODAPUC_IDIOMA_UI_H


#include <ui_MainWindow.h>
#include <nlohmann/json.hpp>
#include <ui_option.h>
#include <nlohmann/json_fwd.hpp>


enum TYPE_IDIOMA{
    IDIOMA_WINDOWS = 0,
    IDIOMA_OPTION = 1,
    IDIOMA_ALL    = 2
};


class LanguageUI {
public :
    LanguageUI();
    static void initialize_language_ui(nlohmann::json & get_json,Ui::_windows_ * ui_windows__,QString  & ui_language);
    static void updateLanguageUI(QString & language_key);
    static nlohmann::json getLanguageJsonValue(QString language_keys,QString language_key);
};


#endif //AVALIACAODAPUC_IDIOMA_UI_H