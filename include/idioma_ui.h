//
// Created by KoTz on 23/10/2025.
//

#ifndef AVALIACAODAPUC_IDIOMA_UI_H
#define AVALIACAODAPUC_IDIOMA_UI_H


#include <ui__windows_.h>
#include <nlohmann/json.hpp>
#include <ui_option.h>


enum TYPE_IDIOMA{
    IDIOMA_WINDOWS = 0,
    IDIOMA_OPTION = 1,
    IDIOMA_ALL    = 2
};


class idioma_ui {
public :
    idioma_ui();
    static void set_ui_idioma(nlohmann::json & get_json,Ui::_windows_ * ui,QString  & ui_language);
    static void v_idioma(QString & ui_language);
};


#endif //AVALIACAODAPUC_IDIOMA_UI_H