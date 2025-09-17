//
// Created by KoTz on 26/07/2025.
//

#include "../include/SearchStrRegex.h"

#include <iostream>
#include <qregularexpression.h>
#include <QString>
#include <regex>
#include <boost/regex.hpp>
#include <boost/algorithm/string.hpp>

std::vector<std::string> SearchStrRegex::search_nome(std::string text_file) {
    if (text_file.empty()) {
        return std::vector<std::string>();
    }
    //busca nomes no arquivo de texto usando regex que combina com palavras começando com letra maiúscula
    std::vector<std::string> nomes;
    boost::regex re("\\b(?!(?:Nome|id|N1|N2)\\b)[A-Z][a-zà-ú]+(\\s+[a-zà-ú]+)*\\b", boost::regex::perl);
    boost::sregex_iterator it(text_file.begin(), text_file.end(), re);
    boost::sregex_iterator end;
    std::string nome = "";
    for (int a = 0; it != end; ++it) {
        boost::smatch match = *it;
        nome = match.str();
        nomes.push_back(nome);
    }
    return nomes;
}

void SearchStrRegex::search_N1_N2(std::string text_file,
                                  std::vector<std::string> &n1, std::vector<std::string> &n2) {
    if (text_file.empty()) {
        return;
    }
    boost::regex *re = nullptr;
    // Busca valores de N1 usando regex que combina com N1: seguido de números
    re = new boost::regex("N1\\s*:\\s*(\\d+(?:\\.\\d+)?)", boost::regex::perl);
    boost::sregex_iterator it(text_file.begin(), text_file.end(), *re);
    boost::sregex_iterator end;
    std::string matchedString = "", n2String = "";
    QString i1 = "", i2 = "";
    for (; it != end; ++it) {
        boost::smatch match = *it;
        matchedString = match.str();
        QString get = QString::fromStdString(matchedString);
        if (matchedString.find("N1: ") == -1) {
            get.remove("N1");
            i1 = get.remove(":");
            n1.push_back(i1.toStdString());
        }
    }
    delete re;
    // Busca valores de N2 usando regex que combina com N2: seguido de números
    re = new boost::regex("N2\\s*:\\s*(\\d+(?:\\.\\d+)?)", boost::regex::perl);
    boost::sregex_iterator it_1(text_file.begin(), text_file.end(), *re);
    boost::sregex_iterator ends;
    for (; it_1 != ends; ++it_1) {
        boost::smatch match = *it_1;
        n2String = match.str();
        QString get = QString::fromStdString(n2String);
        if (n2String.find("N2: ") == -1) {
            get.remove("N2");
            i2 = get.remove(":");
            n2.push_back(i2.toStdString());
        }
    }
    delete re;
}
SearchStrRegex::SearchStrRegex() {}
