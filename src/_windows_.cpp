//
// Created by KoTz on 10/06/2025.
//

// You may need to build the project (run Qt uic code generator) to get "ui__windows_.h" resolved


#include "../include/_windows_.h"
#include "../cmake-build-debug/AvaliacaoDaPuc_autogen/include/ui__windows_.h"
#include "info_window.h"

void _windows_::on_btn_infoSystem_clicked() {
     info_window *info = new info_window(this);
     info->show();
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
    GLOBAL::init_global(ui);
    is->UI_init(this->ui); // Inicializa a interface do usuário passando o ponteiro ui para a classe _ui_
    is->_botao_();
    FileManger::Load("C:\\Users\\KoTz\\Documents\\GitHub\\puc-grade-calculator\\cmake-build-debug-visual-studio\\config.json",system_json);
    idioma_ui::set_ui_idioma(system_json,this->ui,GLOBAL::idioma);
    system_nota_ = new system_nota(ui->tableWidget);
    this->timer = new QTimer(this);
    timer->setInterval(16);
    connect(timer, SIGNAL(timeout()), this, SLOT(Update()));
    timer->start();
}
void _windows_::info_save(QString get,int x) {
    bool is_file_save = false;

   if (ui->tableWidget->rowCount() == 0) {
       return;
   }
    for (int index_item = 0; index_item < ui->tableWidget->rowCount(); index_item++) {
        auto nome = ui->tableWidget->item(index_item, 0)->text();
        auto aula_prevista = ui->tableWidget->item(index_item, 1)->text().toInt();
        auto aula_ministradas = ui->tableWidget->item(index_item, 2)->text().toInt();
        auto numero_presenca = ui->tableWidget->item(index_item, 3)->text().toInt();
        auto N1 = ui->tableWidget->item(index_item, 4)->text().toDouble();
        auto N2 = ui->tableWidget->item(index_item, 5)->text().toDouble();
        sets.push_back(Oitem(nome,aula_prevista,aula_ministradas,numero_presenca,N1,N2));
    }
    ui->label_3->clear();
    if (info_file.fileName.isEmpty() == false && is_open == true) {
        QFile outputFile(info_file.fileName);
        if (outputFile.exists() == true) {
            outputFile.remove();
        }
        is_file_save = FileManger::save(info_file.fileName,sets) ;
        x = -9;
    }
   if (x == 0) {
        is_file_save = FileManger::save(get,sets) ;
   }
    if (x == 1) {
        is_file_save = FileManger::save("data.json",sets) ;
    }
    if (is_file_save) {
        ui->label_3->setText("Salvo !");
    }
    else {
        ui->label_3->setText("Falha de salvamento");
    }
    sets.clear();

}

void _windows_::on_actionOpition_triggered() {
    op = new option(this);
    op->show();
}



void _windows_::on_actionSalvar_como_triggered() {

    QFileDialog *fileDialog = new QFileDialog(this);
    auto selectedFile = fileDialog->getSaveFileName(this,"Salvar o arquivo","","");

    std::string filePath = selectedFile.toStdString();
    if (filePath.find(".json") == std::string::npos) {
         filePath = filePath += ".json";
         selectedFile = QString::fromStdString(filePath);
    }
    if (selectedFile!= nullptr && filePath.find(".json") != std::string::npos) {
         info_save(selectedFile,0);

    }else {
        ui->label_3->setText("Falha de salvamento necessario Json ");
    }
    if (fileDialog != nullptr) {
        delete fileDialog;
    }
}
/**
 * Remove as aspas duplas (") de uma string
 * @param str String de entrada a ter as aspas removidas
 * @return String sem aspas duplas ou string vazia se a entrada for vazia
 */
QString removeDoubleQuotes(QString str) {
    if (str.isEmpty() == true) {
        return QString();
    }
    return str.remove('"');
}

/**
 * Função chamada quando a opção "Salvar" é acionada
 * Salva os dados da tabela em um arquivo texto formatado
 * com id, nome e notas de cada aluno
 */
void _windows_::on_actionSalvar_triggered() {
     info_save("",1);
}
/**
 * Função chamada quando a opção "Abrir" é acionada
 * Abre uma janela de diálogo para selecionar um arquivo .txt
 * e carrega seu conteúdo na tabela, populando nome e notas
 */
void _windows_::on_actionAbrir_triggered() {
    FileManger file;
    bool is_file_aluno = false;
    QFileDialog *newDialog = new QFileDialog(this);
    auto openFileUrl = newDialog->getOpenFileUrl(this, "Abrir JSON", QUrl(), "Arquivos JSON (*.json)");
    nlohmann::json get_json = {};

    if (ui->tableWidget->rowCount() > 0) {
        for (int i = ui->tableWidget->rowCount()+1; i >= 0;i--) {
           ui->tableWidget->removeRow(i);
        }
    }
    bool isLoadSuccessful = false;
    if (openFileUrl.isValid() == true) {
        isLoadSuccessful = FileManger::Load(openFileUrl.toLocalFile(),get_json,is_open);
    }
     if (isLoadSuccessful == false) {
        return;
     }
        for (int a = 0; a < get_json.size();a++){
            ui->tableWidget->insertRow(0);
        }

    for (int b = 0; b < ui->tableWidget->rowCount();b++) {
        for (int a = 0; a < ui->tableWidget->columnCount();a++) {
            if (ui->tableWidget->item(b,a) == nullptr) {
                ui->tableWidget->setItem(b,a,new QTableWidgetItem());
            }
        }
    }

    try {
        int index = 0;
        for (auto & value : get_json ) {
            if (value.at("nome").is_string() == true
                    && value.at("aulas previstas").is_number() == true
                    && value.at("aulas ministradas").is_number() == true
                    && value.at("numero presenca").is_number() == true
                    && value.at("N1").is_number() == true
                    && value.at("N2").is_number() == true)
                {
                    auto nome =  to_string(value.at("nome"));
                    auto aulas_previstas = to_string(value.at("aulas previstas"));
                    auto aulas_ministradas = to_string(value.at("aulas ministradas"));
                    auto numeros_preseca = to_string(value.at("numero presenca"));
                    auto N1 = to_string(value.at("N1"));
                    auto N2 = to_string(value.at("N2"));
                    ui->tableWidget->item(index,0)->setText(removeDoubleQuotes(QString::fromStdString(nome)));
                    ui->tableWidget->item(index,1)->setText(removeDoubleQuotes(QString::fromStdString(aulas_previstas)));
                    ui->tableWidget->item(index,2)->setText(removeDoubleQuotes(QString::fromStdString(aulas_ministradas)));
                    ui->tableWidget->item(index,3)->setText(removeDoubleQuotes(QString::fromStdString(numeros_preseca)));
                    ui->tableWidget->item(index,4)->setText(removeDoubleQuotes(QString::fromStdString(N1)));
                    ui->tableWidget->item(index,5)->setText(removeDoubleQuotes(QString::fromStdString(N2)));
                    index++;
                is_file_aluno = true;
            }
        }

    }catch (std::exception &e) {
        qDebug() << e.what();
    }
    if (is_file_aluno == true) {
         QString info = "Arquivo aberto: "+ openFileUrl.fileName();
         GLOBAL::ARRAY::info_debugs.push_back(InfoSystemDebug{info,""});
         ui->info_arquivo->setText("Arquivo aberto: "+ openFileUrl.fileName());
         info_file.fileName = openFileUrl.toLocalFile();
         info_file.isFileOpen = is_open;
    }
    delete newDialog;
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
   bool is_Selected = false;
   auto i =  ui->tableWidget->selectedItems();
    if (i.isEmpty() == false) {
        if (i.at(1)->tableWidget() == nullptr) {
            return;
        }
        auto index =  i.at(1)->row();
        ui->tableWidget->removeRow(index);
        is_Selected = true;
    }
    if (is_Selected == false) {
        ui->tableWidget->removeRow(ui->tableWidget->rowCount() - 1);
    }

}
