//
// Created by KoTz on 23/07/2025.
//

#ifndef DATAITENS_H
#define DATAITENS_H
#include <QRandomGenerator>
#include <string>
#include <vector>
#include <QString>


struct Oitem {
    uint id;
    QString nome = "";
    QString N1   = "";
    QString N2   = "";
    QString media = "";
    QString resultado = "";
    QString faltou_media = "";
    QString avaliacao_individual = "";

    bool operator < (const Oitem &other) const {
        return id < other.id;
    }
};


//item ObjetItem;

class ListDataItens {
  private :
    std::vector<Oitem> itens;
public :
    ListDataItens();
    void setitem(Oitem * objet);
    void setitem(std::vector<Oitem> objet);
    std::vector<Oitem> getitem();

};



#endif //DATAITENS_H
