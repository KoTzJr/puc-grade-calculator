//
// Created by KoTz on 20/11/2025.
//

#include "../../include/data/DataInfoLog.h"
#include "../../include/io/FileManager.h"


void DataInfoLog::DataErroJson(DATA data_ptr)
{
    data = data_ptr;
    data.nome = "Erro ao ler arquivo json";
}

QString DataInfoLog::GetMensagemErro() {

 return data.nome;
}

DataInfoLog::DataInfoLog() {

}

