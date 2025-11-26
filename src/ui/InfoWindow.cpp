//
// Created by kotz on 04/11/2025.
//

// You may need to build the project (run Qt uic code generator) to get "ui_info_window.h" resolved

#include "ui/InfoWindow.h"
#include <QLabel>
#include "utils/GlobalAccess.h"
#include "ui_InfoWindow.h"


info_window::info_window(QWidget *parent) : QMainWindow(parent), ui(new Ui::info_window) {
    ui->setupUi(this);
    QWidget *widget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(widget);
    QLabel *label = new QLabel(widget);

    for (auto & info : GLOBAL::ARRAY::log_array) {
        label->setText(info.GetMensagemErro());
        layout->addWidget(label);
    }
    ui->scrollArea->setWidget(widget);
    GLOBAL::ARRAY::log_array.clear();
}

info_window::~info_window() {
    delete ui;
}