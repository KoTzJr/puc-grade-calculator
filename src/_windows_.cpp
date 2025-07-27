//
// Created by KoTz on 10/06/2025.
//

// You may need to build the project (run Qt uic code generator) to get "ui__windows_.h" resolved

#include "../include/_windows_.h"
#include "ui__windows_.h"
#include <fmt/printf.h>
#include "../include/ListDataItens.h"
#include  <QFileDialog>
#include <iostream>
#include <regex>
#include <boost/regex.hpp>
#include <boost/algorithm/string.hpp>
#include <SearchStrRegex.h>
#include <GlobalVariables.h>

namespace Global {
    Oitem itemTable;
    ListDataItens list_data_itens;
}


void _windows_::AtualizarNotasTabela() {
    // Nota final inicializada com zero
    double NF = 0.0;
    if (ui->tableWidget->rowCount() > 0) {
        for (int a = 0; a < ui->tableWidget->rowCount(); a++) {
            // Obtém os items das colunas de nota 1 e 2
            auto n1 = ui->tableWidget->item(a, 1);
            auto n2 = ui->tableWidget->item(a, 2);

            if (system_nota_->is_verifiqueCacterece(a)) {
                // Converte o texto das notas para double
                auto f_n1 = n1->text().toDouble();
                auto f_n2 = n2->text().toDouble();
                // Calcula a nota final
                system_nota_->Formula_Avaliacao(f_n1, f_n2, NF, ui->lineEdit->text().toFloat());
                // Atualiza a nota final na tabela
                this->system_nota_->setN1(f_n1);
                this->system_nota_->setN2(f_n2);
                this->system_nota_->setNota_final(NF);

                ui->tableWidget->item(a, 3)->setText(QString::number(NF));
                ui->tableWidget->item(a, 3)->setFlags(Qt::ItemIsEnabled);
                ui->tableWidget->item(a, 4)->setFlags(Qt::ItemIsEnabled);
                // Verifica aprovação e falta para atingir média
                this->system_nota_->is_aprovado(a);
                this->system_nota_->FaltouMedia(f_n1, f_n2, NF, a);
            }
        }
    } else {
        return;
    }
}

/**
* Função que atualiza as notas na tabela
* Chamada periodicamente pelo timer para manter 
* a interface atualizada
*/
void _windows_::Update() {
    AtualizarNotasTabela();
}

/**
 * Construtor da classe _windows_
 * Inicializa a interface gráfica, configura botões e timer
 * para atualização automática das notas
 * @param parent Widget pai (opcional)
 */
_windows_::_windows_(QWidget *parent) : QMainWindow(parent), ui(new Ui::_windows_) {
    ui->setupUi(this);
    this->is = new _ui_;
    is->UI_init(this->ui); // Inicializa a interface do usuário passando o ponteiro ui para a classe _ui_
    is->_botao_();
    system_nota_ = new system_nota(ui->tableWidget);
    this->timer = new QTimer(this);
    timer->setInterval(16);
    connect(timer, SIGNAL(timeout()), this, SLOT(Update()));
    timer->start();
}

void _windows_::on_actionSalvar_como_triggered() {
    ui->label_3->clear();
    if (ui->tableWidget->rowCount() == 0 && ui->tableWidget->columnCount() == 0) {
        return;
    }
    QFileDialog *newDialog = new QFileDialog(this);
    auto i = newDialog->getSaveFileUrl(this, "", QUrl(), "Text files (*.txt);");
    FileManger file;
    std::string text = "";
    DataTable(sets);
    for (auto &s: sets) {
        text += fmt::format(" id : {} \n Nome : {} \n N1 : {} \n N2 : {} \n==========\n\n", s.id, s.nome.toStdString(),
                            s.N1.toStdString(), s.N2.toStdString());
    }
    auto get = file.save(i.url(QUrl::PreferLocalFile), QString::fromStdString(text));

    if (get == true) {
        ui->label_3->setText("salvado com sucesso !");
    }else {
        ui->label_3->setText("não foi possivel salvar o arquivo !");
    }
   // ui->label_3->clear();
    _sleep(400);
}

/**
 * Função chamada quando a opção "Salvar" é acionada
 * Salva os dados da tabela em um arquivo texto formatado
 * com id, nome e notas de cada aluno
 */
void _windows_::on_actionSalvar_triggered() {
    ui->label_3->clear();
    FileManger file;
    std::string text = "";
    DataTable(sets);
    for (auto &s: sets) {
        text += fmt::format(" id : {} \n Nome : {} \n N1 : {} \n N2 : {} \n==========\n\n", s.id, s.nome.toStdString(),
                            s.N1.toStdString(), s.N2.toStdString());
    }
   auto get = file.save("data.txt", QString::fromStdString(text));

    if (get == true) {
        ui->label_3->setText("salvado com sucesso !");
    }else {
        ui->label_3->setText("não foi possivel salvar o arquivo !");
    }
}
/**
 * Função chamada quando a opção "Abrir" é acionada
 * Abre uma janela de diálogo para selecionar um arquivo .txt
 * e carrega seu conteúdo na tabela, populando nome e notas
 */
void _windows_::on_actionAbrir_triggered() {
    FileManger file;
    QFileDialog *newDialog = new QFileDialog(this);
    auto Get = newDialog->getOpenFileUrl(this, "", QUrl(), "Text files (*.txt);");
    auto i = file.Load(Get.toLocalFile());

    std::string str = i.toStdString();
    std::vector<std::string> vector_N1, vector_N2;
    auto vector_nome = SearchStrRegex::search_nome(str);
    SearchStrRegex::search_N1_N2(str, vector_N1, vector_N2);
    for (int a = 0; a < vector_nome.size(); a++) {
        ui->tableWidget->insertRow(0);
    }
    for (int b = 0; b < ui->tableWidget->rowCount(); b++) {
        for (int a = 0; a < ui->tableWidget->columnCount(); a++) {
            if (ui->tableWidget->item(b, a) == nullptr) {
                ui->tableWidget->setItem(b, a, new QTableWidgetItem);
            }
        }
    }
    for (int a = 0; a < ui->tableWidget->rowCount(); a++) {
        if (vector_nome.size() > 0 && a < vector_nome.size()) {
            ui->tableWidget->item(a, 0)->setText(QString::fromStdString(vector_nome[a]));
            ui->tableWidget->item(a, 1)->setText(QString::fromStdString(vector_N1[a]));
            ui->tableWidget->item(a, 2)->setText(QString::fromStdString(vector_N2[a]));
        }
    }
}


/**
 * Função chamada quando a opção "Novo" é acionada
 * Cria uma nova janela do programa como filha da janela atual
 */
void _windows_::on_actionNovo_triggered() {
    _windows_ *janela = new _windows_(this);
    janela->show();
}

void _windows_::DataTable(std::vector<Oitem> & obj) {

    for (int a = 0; a < ui->tableWidget->rowCount(); a++) {
        Global::itemTable.id = a;
        Global::itemTable.nome  = ui->tableWidget->item(a, 0)->text();
        Global::itemTable.N1    = ui->tableWidget->item(a, 1)->text();
        Global::itemTable.N2    = ui->tableWidget->item(a, 2)->text();
        Global::itemTable.media = ui->tableWidget->item(a, 3)->text();
        obj.push_back(Global::itemTable);
    }
}

_windows_::~_windows_() {
    delete ui;
}
/**
 * Função chamada quando o botão "Add" é clicado
 * Adiciona uma nova linha na tabela e inicializa suas células
 * com QTableWidgetItems vazios
 */
void _windows_::on_btn_add_clicked() {

    if (ui->tableWidget->rowCount() >= 10) {
        return;
    }

    ui->tableWidget->insertRow(0);
    for (int b = 0; b < ui->tableWidget->rowCount();b++) {
        for (int a = 0; a < ui->tableWidget->columnCount();a++) {
             if (ui->tableWidget->item(b,a) == nullptr) {
                 ui->tableWidget->setItem(b,a,new QTableWidgetItem);
             }
        }
    }
    ui->tableWidget->item(0,3)->setFlags(Qt::ItemIsEnabled);
    ui->tableWidget->item(0,4)->setFlags(Qt::ItemIsEnabled);
    ui->tableWidget->item(0,5)->setFlags(Qt::ItemIsEnabled);
    i++;
}
/**
 * Função chamada quando o botão "Remover" é clicado
 * Remove a última linha da tabela
 */
void _windows_::on_btn_remover_clicked() {

    ui->tableWidget->removeRow(ui->tableWidget->rowCount() - 1);
}
