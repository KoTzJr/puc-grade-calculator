//
// Created by Valter on 13/01/2026.
//

#ifndef AVALIACAODAPUC_FILEEXTENSAO_H
#define AVALIACAODAPUC_FILEEXTENSAO_H

#include <QFile>
#include <fstream>
#include <istream>
#include  <QDebug>
#include <ostream>
#include <qurl.h>


class FileVx {

public :
    FileVx();
    static int converteJsonFromFileVX(QString Patch);
};


#endif //AVALIACAODAPUC_FILEEXTENSAO_H