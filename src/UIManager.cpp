//
// Created by KoTz on 30/06/2025.
//

#include "../include/UIManager.h"

void Style_Table::Style::table_result(QTableWidget *ui,int index,int ps) {
     if (ui != nullptr) {
         if (ps == 0) {
             ui->item(index,7)->setText("Reprovado por falta");
             ui->item(index,7)->setBackground(QColor(Qt::red));
         }

         if (ps == 1) {
             ui->item(index,7)->setText("Aprovado");
             ui->item(index,7)->setBackground(QColor(Qt::darkGreen));

         }

         if (ps == 2) {
             ui->item(index,7)->setText("Reprovado");
             ui->item(index,7)->setBackground(QColor(Qt::red));
         }
     }
    return;
}


void Style_Table::Style::clear_table(QTableWidget *ui,int h,int colune) {
    ui->item(h,colune)->setText("");
    ui->item(h, colune)->setBackground(QColor(""));
}


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
