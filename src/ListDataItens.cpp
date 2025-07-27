//
// Created by KoTz on 23/07/2025.
//

#include "../include/ListDataItens.h"
#include <QSaveFile>

ListDataItens::ListDataItens() {

}
void ListDataItens::setitem(Oitem * objet) {
    if (objet == nullptr) {
        return;
    }
    this->itens.push_back(*objet);
}
void ListDataItens::setitem(std::vector<Oitem> objet) {
    this->itens = objet;
}
std::vector<Oitem> ListDataItens::getitem() {
    return this->itens;
}
