//
// Created by KoTz on 30/06/2025.
//

#include "../include/_ui_.h"

void  _ui_::UI_init(Ui::_windows_ *ui) {
    if (ui != nullptr) {
        this->ui = ui;
    }
}

void _ui_::_botao_() {
    QFile filew{ui_styles_};


    if (filew.open(QFile::ReadOnly)) {
        QString styleSheet = filew.readAll();
        ui->btn_add->setStyleSheet(styleSheet);
        ui->btn_remover->setStyleSheet(styleSheet);
        ui->tableWidget->setStyleSheet(styleSheet);
        filew.close();
    } else {
        qDebug() << "Erro ao abrir o arquivo de estilo:" << filew.errorString();
    }
}
