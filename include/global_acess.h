//
// Created by KoTz on 24/10/2025.
//

#ifndef AVALIACAODAPUC_GLOBAL_ACESS_H
#define AVALIACAODAPUC_GLOBAL_ACESS_H

#include  <QString>
#include  <idioma_ui.h>

namespace GLOBAL {
     extern   QString idioma;
     extern   bool is_aplica;
     extern   Ui::_windows_ * UI;
     extern   Ui::option   *_ui_option;
     extern   void init_global(Ui::_windows_ * windows);
     extern   void init_global(Ui::option  * option);
}


#endif //AVALIACAODAPUC_GLOBAL_ACESS_H