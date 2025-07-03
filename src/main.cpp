#include <QApplication>
#include <QPushButton>
#include "../include/_windows_.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    _windows_ janela;
    janela.show();
    return QApplication::exec();
}