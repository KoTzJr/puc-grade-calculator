//
// Created by KoTz on 24/10/2025.
//

#ifndef AVALIACAODAPUC_GLOBAL_ACESS_H
#define AVALIACAODAPUC_GLOBAL_ACESS_H

#include  <QString>
#include  "ui/LanguageUI.h"
#include  "ui/PreferenceSystem.h"

#include <QDir>

#include "info_log.h"

namespace GLOBAL {
     extern   QString idioma;
     extern   bool is_aplica;
     extern   Ui::_windows_ * UI;
     extern   Ui::option   *_ui_option;
     namespace PATCH_FILE {
          const    QString DATA = QDir::homePath() + "/Documents/PUCSimulador/data.json";
          const    QString LANGUAGE = "C:\\Users\\KoTz\\Documents\\GitHub\\puc-grade-calculator\\idioma.json";
          inline   QString CONFIG;
     }

     extern   void init_global(Ui::_windows_ * windows);
     extern   void init_global(Ui::option  * option);
     namespace ARRAY {
         extern std::vector<info_log> log_array;
     }
}


#endif //AVALIACAODAPUC_GLOBAL_ACESS_H