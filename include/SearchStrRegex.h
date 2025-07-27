//
// Created by KoTz on 26/07/2025.
//

#ifndef SEARCHSTRREGEX_H
#define SEARCHSTRREGEX_H

#include <boost/regex.h>
#include <vector>
#include <string>

struct  SearchStrRegex {
     static std::vector<std::string> search_nome(std::string text_file);
     static void search_N1_N2(std::string text_file,
                       std::vector<std::string> & n1,
                       std::vector<std::string> & n2);
     SearchStrRegex();
};



#endif //SEARCHSTRREGEX_H
