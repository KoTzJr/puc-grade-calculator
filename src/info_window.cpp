//
// Created by kotz on 04/11/2025.
//

// You may need to build the project (run Qt uic code generator) to get "ui_info_window.h" resolved

#include "../include/info_window.h"

#include <QLabel>

#include "global_acess.h"
#include "ui_info_window.h"


info_window::info_window(QWidget *parent) : QMainWindow(parent), ui(new Ui::info_window) {
    ui->setupUi(this);
    QWidget *widget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(widget);
    QLabel *label = new QLabel(widget);
    //QFrame *frame = new QFrame(widget);

    for (auto & info : GLOBAL::ARRAY::info_debugs) {
        label->setText(info.GetALL());
        layout->addWidget(label);
    }
    ui->scrollArea->setWidget(widget);
}

info_window::~info_window() {
    delete ui;
}