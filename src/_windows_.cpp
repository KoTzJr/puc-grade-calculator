//
// Created by KoTz on 10/06/2025.
//

// You may need to build the project (run Qt uic code generator) to get "ui__windows_.h" resolved

#include "../include/_windows_.h"
#include "ui__windows_.h"
#include <QVBoxLayout>
#include <fmt/printf.h>

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
    is->UI_init(this->ui);
    is->_botao_();
    system_nota_ = new system_nota(ui->tableWidget);
    this->timer = new QTimer(this);
    timer->setInterval(16);
    connect(timer, SIGNAL(timeout()), this, SLOT(Update()));
    timer->start();
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
