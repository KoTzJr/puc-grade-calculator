//
// Created by KoTz on 28/06/2025.
//

#ifndef SYSTEM_NOTA_H
#define SYSTEM_NOTA_H

#include <QTableWidget>

#include "ListDataItens.h"

class system_nota {
private :
    QString Nome;
    double N1;
    double N2;
    int aula_prevista;
    int aula_ministradas;
    int numero_presenca;
    double result_presenca;
    double media;
    double nota_final;

    double IA;

QTableWidget *item;
public :
      void processGradeResult(int indexItem);
      bool is_verifiqueCacterece(int pos);
      void Formula_Avaliacao(double n1, double  n2, double  &NF,double  AI);
      void Formula_Avaliacao(double n1, double  n2, double  &NF);
      void FaltouMedia(double  n1,double  n2,double  NF,int row);

      void Quantidade_faltas(int index,QTableWidget *ui);

      void FormulaParaMedia(bool N1_Menor,bool N2_Menor, bool iguais,int row);

       void sets_todas_atividades(int aula_prevista,int aula_ministradas,int numero_presenca,double n1,double n2,double IA);
       void sets_todas_atividades(double n1,double n2,double IA);


       Oitem get_todas_() const;

       void clear_table();


      system_nota();
      system_nota(QTableWidget * obj);

};



#endif //SYSTEM_NOTA_H
