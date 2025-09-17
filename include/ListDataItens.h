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
    QString name;
    int planned_classes;
    int taught_classes;
    int attendance_count;
    double N1;
    double N2;
    double IA;

    bool operator < (const Oitem &other) const {
        return id < other.id;
    }

     Oitem ();
     Oitem(QString nome ,int aula_prevista,int aula_ministradas,int numero_presenca, double N1,double N2);
};

#endif //DATAITENS_H
