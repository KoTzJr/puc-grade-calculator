//
// Created by KoTz on 30/06/2025.
//

#include "ui/UIManager.h"

#include "GlobalAccess.h"

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
    ui->item(h, colune)->setBackground(QColor::fromRgb(44,44,44,44));
}
void ui_controller::TableWidget(Ui__windows_ *ui) {
    QFile filew{ui_styles_tabel_widget};
    if (ui != nullptr) {
        filew.open(QFile::ReadOnly);
        QString styleSheet = filew.readAll();
        ui->tableWidget->setStyleSheet(styleSheet);
    }
}

void ui_controller::Button(TYPE TY,Ui__windows_ * ui) {
    QFile filew{ui_styles_};
   if (TY == TYPE::MAIN_WINDOW) {
       if (filew.open(QFile::ReadOnly)) {
           QString styleSheet = filew.readAll();
           ui->btn_add->setStyleSheet(styleSheet);
           ui->btn_remover->setStyleSheet(styleSheet);
           filew.close();
       } else {
           qDebug() << "Erro ao abrir o arquivo de estilo:" << filew.errorString();
       }
   }
}
void UI_FONT::get(QString fonte) {
    text(fonte,nlohmann::json {},nullptr);
}

void UI_FONT::text(nlohmann::json json, Ui::option *ui) {
    if (ui != nullptr) {
        auto get = json["Fonte"];
        qDebug () << QString::fromStdString(get).remove("\\");
        ui->label_tema->setFont(QString::fromStdString(get).remove("\\"));
        ui->label_fonte->setFont(QString::fromStdString(get).remove("\\"));
        ui->comboBox->setFont(QString::fromStdString(get).remove("\\"));
        ui->fontComboBox->setFont(QString::fromStdString(get).remove("\\"));
        ui->Combox_tema->setFont(QString::fromStdString(get).remove("\\"));
        ui->lineEdit->setFont(QString::fromStdString(get).remove("\\"));
        ui->btn_search_paste->setFont(QString::fromStdString(get).remove("\\"));
        ui->btn_aplicar->setFont(QString::fromStdString(get).remove("\\"));
        ui->btn_salvar->setFont(QString::fromStdString(get).remove("\\"));
        ui->label->setFont(QString::fromStdString(get).remove("\\"));
    }
}

void UI_FONT::text(QString fonte,nlohmann::json json, Ui::option *ui) {
     int x;
    QString fonte_removido;
    if (fonte.isEmpty() == false,json.is_null() == true,ui == nullptr) {
       x = 1;
    }
    if (ui != nullptr && json.is_null() == false && fonte.isEmpty() == true) {
        x = 0;
    }
    if (x == 1) {
        auto get = json["Fonte"];
        fonte = QString::fromStdString(get).remove("\\");
    }
    ui->label_tema->setFont(fonte);
    ui->label_fonte->setFont(fonte);
    ui->comboBox->setFont(fonte);
    ui->fontComboBox->setFont(fonte);
    ui->Combox_tema->setFont(fonte);
    ui->lineEdit->setFont(fonte);
    ui->btn_search_paste->setFont(fonte);
    ui->btn_aplicar->setFont(fonte);
    ui->label->setFont(fonte);
}


 void UI_FONT::text(nlohmann::json json,Ui__windows_ * ui) {
    if (ui != nullptr) {
        auto get = json["Fonte"];
        qDebug () << QString::fromStdString(get).remove("\\");
        ui->btn_infoSystem->setFont(QFont(QString::fromStdString(get).remove("\\")));
        ui->menuArquivos->setFont(QFont(QString::fromStdString(get).remove("\\")));
        ui->menuFerramentas->setFont(QFont(QString::fromStdString(get).remove("\\")));
        ui->tableWidget->setFont(QFont(QString::fromStdString(get).remove("\\")));
    }
}

