//
// Created by KoTz on 20/11/2025.
//

#ifndef AVALIACAODAPUC_INFOLOGDATA_H
#define AVALIACAODAPUC_INFOLOGDATA_H

#include <QString>


class DATA {
public :
     QString nome;
     QString erro;
     QString mensagem;
};
class info_log {
private :
    DATA data;
public :
    void DataErroJson(DATA data_ptr);
    QString GetMensagemErro();
    info_log();
};


#endif //AVALIACAODAPUC_INFOLOGDATA_H