//
// Created by KoTz on 10/06/2025.
//

// You may need to build the project (run Qt uic code generator) to get "ui__windows_.h" resolved

#include <string>
#include <boost/regex.hpp>
#include <fmt/core.h>
#include <QFileDialog>
#include "../include/_windows_.h"
#include "../include/ListDataItens.h"
#include "SearchStrRegex.h"
#include "GlobalVariables.h"

namespace Global {
    Oitem itemTable;
}


void _windows_::Update_table_data() {

    if (ui->tableWidget->rowCount() == 0 && ui->tableWidget->columnCount() == 0) {
        return;
    }
    if (ui->tableWidget->rowCount() > 0) {
        for (int index_item = 0; index_item < ui->tableWidget->rowCount(); index_item++) {

            auto N1 = ui->tableWidget->item(index_item, 4)->text().toDouble();
            auto N2 = ui->tableWidget->item(index_item, 5)->text().toDouble();;
            auto IA = ui->lineEdit->text().toFloat();
            auto aula_ministrava = ui->tableWidget->item(index_item, 2)->text().toInt();
            auto aula_presenca = ui->tableWidget->item(index_item, 3)->text().toInt();
            this->system_nota_->sets_todas_atividades(0,aula_ministrava,aula_presenca,N1,N2,IA);

            if (system_nota_->is_verifiqueCacterece(index_item))
            {
                this->system_nota_->processGradeResult(index_item);
            }
            this->system_nota_->clear_table();
        }
    }
}

/**
* Função que atualiza as notas na tabela
* Chamada periodicamente pelo timer para manter 
* a interface atualizada
*/
void _windows_::Update() {
    Update_table_data();
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

}

/**
 * Função chamada quando a opção "Salvar" é acionada
 * Salva os dados da tabela em um arquivo texto formatado
 * com id, nome e notas de cada aluno
 */
void _windows_::on_actionSalvar_triggered() {

    for (int index_item = 0; index_item < ui->tableWidget->rowCount(); index_item++) {

        auto nome = ui->tableWidget->item(index_item, 0)->text();
        auto aula_prevista = ui->tableWidget->item(index_item, 1)->text().toInt();
        auto aula_ministradas = ui->tableWidget->item(index_item, 2)->text().toInt();
        auto numero_presenca = ui->tableWidget->item(index_item, 3)->text().toInt();
        auto N1 = ui->tableWidget->item(index_item, 4)->text().toDouble();
        auto N2 = ui->tableWidget->item(index_item, 5)->text().toDouble();

        sets.push_back(Oitem(nome,aula_prevista,aula_ministradas,numero_presenca,N1,N2));
    }

   auto  is_file_save = FileManger::save("data.json",sets) ;
    if (is_file_save) {
        ui->label_3->setText("foi criado com sucesso");
    }
    else {
        ui->label_3->setText("não foi criado com sucesso");
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
    auto Get = newDialog->getOpenFileUrl(this, "", QUrl(), "Text files (*.json);");
    qDebug () << Get.toLocalFile();

    nlohmann::json obj = {};
    FileManger::Load(Get.toLocalFile(),obj);

     for (int a = 0; a < obj.size(); a++) {
         ui->tableWidget->insertRow(0);
     }
         for (int b = 0; b < ui->tableWidget->rowCount();b++) {
             for (int a = 0; a < ui->tableWidget->columnCount();a++) {
                 if (ui->tableWidget->item(b,a) == nullptr) {
                     ui->tableWidget->setItem(b,a,new QTableWidgetItem);
                 }
                 ui->tableWidget->item(b,4)->setText(QString::fromStdString(obj[a]["N1"]));
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
/**
 * Destrutor da classe _windows_
 * Libera a memória alocada para o objeto ui
 */
_windows_::~_windows_() {
    delete ui;
}

/**
 * Função chamada quando o botão "Add" é clicado
 * Adiciona uma nova linha na tabela e inicializa suas células
 * com QTableWidgetItems vazios
 */
void _windows_::on_btn_add_clicked() {

    if (ui->tableWidget->rowCount() >= 12) {
        return;
    }

    ui->tableWidget->insertRow(0);
    for (int b = 0; b < ui->tableWidget->rowCount();b++) {
        for (int a = 0; a < ui->tableWidget->columnCount();a++) {
             if (ui->tableWidget->item(b,a) == nullptr) {
                 ui->tableWidget->setItem(b,a,new QTableWidgetItem);
                 QStringList labels;
                 labels << "";
                 ui->tableWidget->setVerticalHeaderLabels(labels);

             }
        }
    }

    ui->tableWidget->item(0,6)->setFlags(Qt::ItemIsEnabled);
    ui->tableWidget->item(0,7)->setFlags(Qt::ItemIsEnabled);
    ui->tableWidget->item(0,8)->setFlags(Qt::ItemIsEnabled);

    i++;
}
/**
 * Função chamada quando o botão "Remover" é clicado
 * Remove a última linha da tabela
 */
void _windows_::on_btn_remover_clicked() {

    ui->tableWidget->removeRow(ui->tableWidget->rowCount() - 1);
}
