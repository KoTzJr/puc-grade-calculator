//
// Created by KoTz on 24/10/2025.
//

#include "global_acess.h"


namespace GLOBAL {
    QString idioma;
    bool is_aplica;
    Ui::_windows_ * UI;
    Ui::option    *_ui_option;
    void init_global(Ui::_windows_ * windows) {
        if (windows != nullptr) {
            UI = windows;
        }
    }
    void init_global( Ui::option  * option) {
        if (option != nullptr) {
            _ui_option = option;
        }
    }
}
