//
// Created by KoTz on 24/10/2025.
//

#ifndef AVALIACAODAPUC_GLOBAL_ACESS_H
#define AVALIACAODAPUC_GLOBAL_ACESS_H

#include  <QString>
#include  "ui/LanguageUI.h"
#include  "ui/PreferenceSystem.h"
#include  "utils/InfoSystemDebug.h"
#include <QDir>
namespace GLOBAL {
     extern   QString idioma;
     extern   bool is_aplica;
     extern   Ui::_windows_ * UI;
     extern   Ui::option   *_ui_option;
     namespace PATCH_FILE {
          const    QString Data = QDir::homePath() + "/Documents/PUCSimulador/data.json";
          const    QString language = "C:\\Users\\KoTz\\Documents\\GitHub\\puc-grade-calculator\\idioma.json";
          const    QString config = QDir::homePath() + "/Documents/PUCSimulador/config.json";
     }

     extern   void init_global(Ui::_windows_ * windows);
     extern   void init_global(Ui::option  * option);
     namespace ARRAY {
          extern   std::vector<InfoSystemDebug> info_debugs;
     }
}


#endif //AVALIACAODAPUC_GLOBAL_ACESS_H