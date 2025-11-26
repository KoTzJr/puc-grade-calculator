//
// Created by KoTz on 20/11/2025.
//

#include "../../include/data/info_log.h"
#include "../../include/io/FileManager.h"


void info_log::DataErroJson(DATA data_ptr)
{
    data = data_ptr;
    data.nome = "Erro ao ler arquivo json";
}

QString info_log::GetMensagemErro() {

 return data.nome;
}

info_log::info_log() {

}

