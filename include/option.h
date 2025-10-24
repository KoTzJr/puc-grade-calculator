//
// Created by kotz on 19/09/2025.
//

#ifndef AVALIACAODAPUC_OPTION_H
#define AVALIACAODAPUC_OPTION_H

#include <QMainWindow>


QT_BEGIN_NAMESPACE

namespace Ui {
    class option;
}

QT_END_NAMESPACE

class option : public QMainWindow {
    Q_OBJECT

private slots:
    void on_btn_aplicar_clicked();
    void on_btn_salvar_clicked();

public:
    explicit option(QWidget *parent = nullptr);

    ~option() override;

private:
    Ui::option *ui_option_;
};


#endif //AVALIACAODAPUC_OPTION_H