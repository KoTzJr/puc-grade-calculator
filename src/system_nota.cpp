//
// Created by KoTz on 28/06/2025.
//

#include "../include/system_nota.h"
#include <fmt/format.h>
#include "../include/_ui_.h"

void system_nota::FormulaParaMedia(bool N1_menor, bool n2_menor, bool iguais,int row) {

    double N1 = this->N1, N2 = this->N2,NF = this->nota_final;
    QString is = "";
    auto items = this->item->item(row,8);

    if (N1_menor == true) {
         for (double i = 0; i <= 10; i+=00.1) {
             Formula_Avaliacao(i, N2, NF);
             if (NF >= 6.0) {
                 items->setText(QString::fromStdString(fmt::format("N1 : {:-.1f} -> {:-.1f}",N1,i)));
                 return;
             }
             else {
                 items->setText("Não é possivel alcancar acima 6.0 do N1");
             }
         }
     }
     if (n2_menor == true) {
             QString str_n2 = "";
             for (double i = 0; i <= 10; i+=00.1) {
                 Formula_Avaliacao(N1, i, NF);
                 if (NF >= 6) {
                     items->setText(QString::fromStdString(fmt::format("N2: {:-.1f} -> {:-.1f}",N2,i)));
                     return;
                 }
                 else {
                         items->setText("Não é possivel alcancar acima 6.0 do N2");
                 }
             }
     }
    if (iguais == true) {
        for (double i =  N2; i <= 10; i+=00.1) {
            Formula_Avaliacao(i,i, NF);
            if (NF >= 6) {
                auto str = fmt::format("N1 ou N2 : {:-.1f} -> {:-.1f}",this->N1,i);
                items->setText(QString::fromStdString(str));
                return;
            }
        }

    }
}

void  system_nota::sets_todas_atividades(double n1,double n2,double IA) {
    this->N1 = n1;
    this->N2 = n2;

    this->IA = IA;
}

void system_nota::sets_todas_atividades(int aula_prevista, int aula_ministradas, int numero_presenca,double n1,double n2,double IA) {
    this->aula_ministradas = aula_ministradas;
    this->aula_prevista    = aula_prevista;
    this->numero_presenca  = numero_presenca;

    this->N1 = n1;
    this->N2 = n2;

    this->IA = IA;
}

void  system_nota::Quantidade_faltas(int index,QTableWidget *ui) {
    if (ui == nullptr) {
        return;
    }
     if (ui->item(index, 2)->text().isEmpty() == true ||
         ui->item(index, 3)->text().isEmpty() == true) {
         return;
     }
     this->result_presenca = 0.0f;
     this->result_presenca = (double)this->numero_presenca/(double)this->aula_ministradas*100;
}

void system_nota::FaltouMedia(double n1, double n2, double NFs, int row) {
    bool n1_menor = false, n2_menor = false;

    // Se a nota final for maior ou igual a 6, limpa o texto e retorna

    if (NFs >= 6.0  || NFs >= 6.00 || NFs>= 6.0-1e-9) {
        item->item(row, 8)->setText("");  // limopar
        return;
    }
    auto item = this->item->item(row, 8);

    // Se o item for nulo, retorna
    if (item == nullptr) {
        return;
    }
    // Se ambas as notas forem zero, retorna
    if (n1 == 0.0f && n2 == 0.0f) {
        return;
    }

    // Verifica qual nota é menor
    if (n1 > n2) {
        n2_menor = true;
    }
    if (n2 > n1) {
        n1_menor = true;
    }

    this->FormulaParaMedia(n1_menor,n2_menor,n1 == n2,row);
}
/**
 * Calcula a nota final usando a fórmula: NF = 0.4*n1 + 0.6*n2
 * Se houver AI (Avaliação Individual), soma ao n2
 * @param n1 Nota 1
 * @param n2 Nota 2 
 * @param NF Nota Final (retornado por referência)
 * @param AI Avaliação Individual (opcional)
 */
void system_nota::Formula_Avaliacao(double n1, double n2 , double  &NF, double  AI) {
    if (n1 > 10.0 || n2 > 10.0) {
        return;
    }

    if (AI != 0.0f) {
        n2 = n2 + AI;
    }
    NF = 0.4 * n1 + 0.6 * n2;
    if (NF == 0.0f) {
        return;
    }
    this->nota_final = NF;
}

Oitem system_nota::get_todas_() const {
     return Oitem(this->Nome,this->aula_prevista,this->aula_ministradas,this->numero_presenca,this->N1,this->N2);
}
/**
 * Sobrecarga do método Formula_Avaliacao sem o parâmetro AI
 * Calcula a nota final usando a fórmula: NF = 0.4*n1 + 0.6*n2
 * @param n1 Nota 1
 * @param n2 Nota 2
 * @param NF Nota Final (retornado por referência)
 */
void system_nota::Formula_Avaliacao(double  n1, double  n2, double  &NF) {
    if (n1 >= 10.0 || n2 >= 10.0) {
        return;
    }
    NF = 0.4 * n1 + 0.6 * n2;
    if (NF == 0.0f) {
        return;
    }
    const auto get = fmt::format("{:-.2f}",NF);
    NF = QString::fromStdString(get).toDouble();
    this->nota_final = NF;
}

/**
 * Limpa todas as variáveis do sistema, resetando-as para seus valores iniciais
 * - Notas N1, N2 e nota final são zeradas
 * - Contadores de aula e presenças são zerados 
 * - Médias e resultados são zerados
 * - Nota de IA (Avaliação Individual) é zerada
 */
void system_nota::clear_table() {
    N1 = 0.0f;
    N2 = 0.0f;
    aula_prevista = 0;
    aula_ministradas = 0;
    numero_presenca = 0;
    result_presenca = 0.0f;
    media = 0.0f;
    nota_final = 0.0f;
    IA = 0.0f;
}

/**
 * Processa o resultado da nota final (NF) e atualiza a tabela com o status do aluno
 * - Se NF == 0, retorna sem alterações
 * - Se NF <= 75, reprovado por falta
 * - Se NF >= 6, aprovado
 * - Se 0 < NF < 6, reprovado
 * @param indexItem Índice da linha na tabela
 */
void system_nota::processGradeResult(int indexItem) {
    double NF = 0.0f;
    Formula_Avaliacao(this->N1, this->N2, NF, this->IA);

    Style_Table::Style::clear_table(item, indexItem, 7);
    this->item->item(indexItem, 6)->setText(QString::number(NF));
    Quantidade_faltas(indexItem, this->item);
    FaltouMedia(this->N1, this->N2, NF, indexItem);

    if (NF == 0.0f ) {
        return;
    }
    if (NF >= 6.0 || NF >= 6 || NF >= 6.0 - 1e-9) {
        Style_Table::Style::table_result(item, indexItem, 1);
        qDebug () << "teste";

    }else if (NF < 6.0-1e-9 && NF > 0.0- 1e-9) {
        Style_Table::Style::table_result(item, indexItem, 2);
        qDebug () << "teste_2";
    }
    if (result_presenca != 0.0 || result_presenca != 0.0f) {
        if (this->result_presenca <= 75.0 - 1e-9 && this->result_presenca >= 0.0- 1e-9) {
            Style_Table::Style::table_result(item, indexItem, 0);
            qDebug () << "teste_3";
        }
    }
}

/**
 * Verifica se os caracteres nas células n1 e n2 são válidos
 * Retorna false se encontrar letras em alguma das células
 * ou se ambas estiverem vazias
 * Retorna true se ambas contiverem números com ponto decimal
 */
bool system_nota::is_verifiqueCacterece(int pos){
    int asvezes_pontos_n1 =0,asvezez_pontos_n2 =0;

    bool isalpha_n1 = false, isalpha_n2 = false;
    auto firstInput_n1 = this->item->item(pos, 4);
    auto firstInput_n2 = this->item->item(pos, 5);

    for (auto &s: firstInput_n1->text().toStdString()) {
        if (isalpha(s)) {
            isalpha_n1 = true;
        }
    }

    for (auto &w: firstInput_n2->text().toStdString()) {
        if (isalpha(w)) {
            isalpha_n2 = true;
        }
    }

    if (isalpha_n1 == true && isalpha_n2 == true ||
        isalpha_n1 == true && isalpha_n2 == false
        || isalpha_n1 == false && isalpha_n2 == true) {
        return false;
    }

    bool nbr = false, nb1 = false;
    if (firstInput_n1 != nullptr && firstInput_n2 != nullptr) {
        if (firstInput_n1->text().isEmpty() && firstInput_n2->text().isEmpty()) {
            return false;
        }
        for (auto &i: firstInput_n1->text()) {
            if (i == "-") {
                return false;
            }
            if (i == ".") {
                asvezes_pontos_n1++;
            }
        }
        for (auto &i: firstInput_n2->text()) {
            if (i == "-") {
                return false;
            }
            if (i == ".") {
                asvezez_pontos_n2++;
            }
        }
        if (asvezes_pontos_n1 > 1 || asvezez_pontos_n2 > 1) {
            return false;
        }
        if (asvezes_pontos_n1 == 1 && asvezez_pontos_n2 == 1) {
            nb1 = true;
            nbr = true;
        }

        return nbr && nb1;
    }
    return false;
}

system_nota::system_nota():N1(0.0f),N2(0.0f),item(nullptr),media(0.0f),nota_final(0.0f),aula_ministradas(0),aula_prevista(0),numero_presenca(0){

}
system_nota::system_nota(QTableWidget *obj):N1(0.0f),N2(0.0f),item(nullptr),media(0.0f),nota_final(0.0f),aula_ministradas(0),aula_prevista(0),numero_presenca(0){
     if (obj != nullptr) {
        this->item = obj;
     }
}
