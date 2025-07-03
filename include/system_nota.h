//
// Created by KoTz on 28/06/2025.
//

#ifndef SYSTEM_NOTA_H
#define SYSTEM_NOTA_H

#include <QTableWidget>

class system_nota {
private :
    double N1;
    double N2;
    double media;
    double nota_final;
QTableWidget *item;
private :
    QString convertMultipleToDecimal(QString & is,QString is1);
    QString convertToDecimalFormat(QString is);
public :
      void is_aprovado(int indexItem);
      bool is_verifiqueCacterece(int pos);
      void Formula_Avaliacao(double n1, double  n2, double  &NF,double  AI);
      void Formula_Avaliacao(double n1, double  n2, double  &NF);
      void FaltouMedia(double  n1,double  n2,double  NF,int row);

      void FormulaParaMedia(bool N1_Menor,bool N2_Menor, bool iguais,int row);

       void setN1(double n1);
       void setN2(double n2);
       void setNota_final(double nota_final);

      system_nota();
      system_nota(QTableWidget * obj);

};



#endif //SYSTEM_NOTA_H
