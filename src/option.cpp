//
// Created by kotz on 19/09/2025.
//

// You may need to build the project (run Qt uic code generator) to get "ui_option.h" resolved

#include "../include/option.h"
#include "ui_option.h"


option::option(QWidget *parent) : QMainWindow(parent), ui(new Ui::option) {
    ui->setupUi(this);
}

option::~option() {
    delete ui;
}