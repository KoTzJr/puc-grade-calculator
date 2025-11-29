//
// Created by kotz on 04/11/2025.
//

#ifndef AVALIACAODAPUC_INFO_WINDOW_H
#define AVALIACAODAPUC_INFO_WINDOW_H

#include <QMainWindow>


QT_BEGIN_NAMESPACE

namespace Ui {
    class info_window;
}

QT_END_NAMESPACE

class UI_LogWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit UI_LogWindow(QWidget *parent = nullptr);

    ~UI_LogWindow() override;

private:
    Ui::info_window *ui;
};


#endif //AVALIACAODAPUC_INFO_WINDOW_H