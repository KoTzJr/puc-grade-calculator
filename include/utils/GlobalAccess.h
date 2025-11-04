//
// Created by KoTz on 24/10/2025.
//

#ifndef AVALIACAODAPUC_GLOBAL_ACESS_H
#define AVALIACAODAPUC_GLOBAL_ACESS_H

#include  <QString>
#include  <LanguageUI.h>
#include  "InfoSystemDebug.h"

namespace GLOBAL {
     extern   QString idioma;
     extern   bool is_aplica;
     extern   Ui::_windows_ * UI;
     extern   Ui::option   *_ui_option;
     extern   void init_global(Ui::_windows_ * windows);
     extern   void init_global(Ui::option  * option);
     namespace ARRAY {
          extern   std::vector<InfoSystemDebug> info_debugs;
     }
}


#endif //AVALIACAODAPUC_GLOBAL_ACESS_H