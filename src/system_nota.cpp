//
// Created by KoTz on 28/06/2025.
//

#include "../include/system_nota.h"
#include <fmt/format.h>
#include <QRandomGenerator>



void system_nota::setN1(double n1) {
   this->N1 = n1;
}
void system_nota::setN2(double n2) {
    this->N2 = n2;
}
void system_nota::setNota_final(double nota_final) {
    this->nota_final = nota_final;
}

void system_nota::FormulaParaMedia(bool N1_Maior, bool N2_Maior, bool iguais,int row) {

    double N1 = this->N1, N2 = this->N2,NF = this->nota_final;
    QString is = "";
    auto items = this->item->item(row,5);

    if (N1_Maior == true) {
         QString str_n1 = "";
         for (double i = 0; i <= 10; i+=00.1) {
             Formula_Avaliacao(i, N2, NF);
             if (NF >= 6.0) {
                 str_n1 = QString::number(N1);
                 is = convertMultipleToDecimal(str_n1, QString::number(i));
                 items->setText("N1: " + str_n1 + " -> " + is);
                 return;
             }
         }
     }
     if (N2_Maior == true) {
             QString str_n2 = "";
             for (double i = 0; i <= 10.0; i+=00.1) {
                 Formula_Avaliacao(N1, i, NF);
                 if (NF >= 6) {
                     str_n2 = QString::number(N2);
                     is = convertMultipleToDecimal(str_n2, QString::number(i));
                     items->setText("N2: " + str_n2 + " -> " + is);
                     return;
                 }
             }
     }

    if (iguais == true) {
        for (double i =  N2; i <= 10; i+=00.1) {
            Formula_Avaliacao(i,i, NF);
            qDebug () << i;
            if (NF >= 6) {
                auto str = fmt::format("N1 ou N2 : {:-.1f} -> {:-.1f}",this->N1,i);
                items->setText(QString::fromStdString(str));
                return;
            }
        }

    }
}


// Converte um número para formato decimal
QString system_nota::convertToDecimalFormat(QString is) {
    const QString number = "123456789";
    if (is.isEmpty() == true) {
        return "";
    }
    for (auto &w: number) {
        if (w == is) {
            is = w + '.' + '0';
        }
    }
    return is;
}


// Converte múltiplos números para formato decimal 
QString system_nota::convertMultipleToDecimal(QString &is_1, QString is) {
    const QString number = "123456789";
    if (is.isEmpty() == true && is_1.isEmpty() == true) { return ""; }
    for (auto &w: number) {
        if (w == is) {
            is = w + '.' + '0';
        }
        if (w == is_1) {
            is_1 = w + '.' + '0';
        }
    }
    return is;
}

void system_nota::FaltouMedia(double n1, double n2, double NFs, int row) {
    bool n1_menor = false, n2_menor = false;

    // Se a nota final for maior ou igual a 6, limpa o texto e retorna
    if (NFs >= 6.0f) {
        qDebug() << "NF: " << NFs;
        item->item(row, 5)->setText("");
        return;
    }
    double NF = 0.0f;
    auto item = this->item->item(row, 5);

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
    QString SNF = convertToDecimalFormat(QString::number(NF));
    NF = SNF.toDouble();

    this->nota_final = NF;
}

/**
 * Verifica se o aluno foi aprovado ou reprovado com base na nota final
 * Se nota_final < 6.0: Reprovado (vermelho)
 * Se nota_final > 6.0: Aprovado (verde escuro) 
 * Se nota_final == 0: Campo vazio
 */
void system_nota::is_aprovado(int indexItem) {
    if (this->nota_final == 0) {
        return;
    }
    if (this->nota_final < 6.0 && this->nota_final > 0.0) {
        item->item(indexItem, 4)->setBackground(QColor(Qt::red));
        item->item(indexItem, 4)->setText("Reprovado");
    } else if (this->nota_final >= 6.0) {
        item->item(indexItem, 4)->setBackground(QColor(Qt::darkGreen));
        item->item(indexItem, 4)->setText("Aprovado");
    }
    if (this->nota_final == 0) {
        item->item(indexItem, 4)->setText("");
    }
}

/**
 * Verifica se os caracteres nas células n1 e n2 são válidos
 * Retorna false se encontrar letras em alguma das células
 * ou se ambas estiverem vazias
 * Retorna true se ambas contiverem números com ponto decimal
 */
bool system_nota::is_verifiqueCacterece(int pos) {
    int asvezes_pontos_n1 =0,asvezez_pontos_n2 =0;

    bool isalpha_n1 = false, isalpha_n2 = false;
    auto n1 = this->item->item(pos, 1);
    auto n2 = this->item->item(pos, 2);



    for (auto &s: n1->text().toStdString()) {
        if (isalpha(s)) {
            isalpha_n1 = true;
        }
    }

    for (auto &w: n2->text().toStdString()) {
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
    if (n1 != nullptr && n2 != nullptr) {
        if (n1->text().isEmpty() && n2->text().isEmpty()) {
            return false;
        }
        for (auto &i: n1->text()) {
            if (i == "-") {
                return false;
            }
            if (i == ".") {
                asvezes_pontos_n1++;
            }
        }
        for (auto &i: n2->text()) {
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

system_nota::system_nota():N1(0.0f),N2(0.0f),item(nullptr),media(0.0f),nota_final(0.0f){

}
system_nota::system_nota(QTableWidget *obj):N1(0.0f),N2(0.0f),item(nullptr),media(0.0f),nota_final(0.0f) {
     if (obj != nullptr) {
        this->item = obj;
     }
}
