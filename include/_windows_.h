#ifndef _WINDOWS__H
#define _WINDOWS__H

#include <QMainWindow>
#include <QTimer>
#include "system_nota.h"
#include "_ui_.h"
#include  <ListDataItens.h>

#include "FileManger.h"
QT_BEGIN_NAMESPACE
namespace Ui { class _windows_; }
QT_END_NAMESPACE

class _windows_ : public QMainWindow {
    Q_OBJECT

    public:
    explicit _windows_(QWidget *parent = nullptr);
    ~_windows_() override;

private slots:
    void on_btn_add_clicked();
    void on_btn_remover_clicked();
    void Update();
    void Update_table_data();
    void on_actionAbrir_triggered();
    void on_actionNovo_triggered();
    void on_actionSalvar_triggered();
    void on_actionSalvar_como_triggered();
private:
    Ui::_windows_ *ui;
    QTimer *timer;
    system_nota *system_nota_;
    _ui_ *is;
    int i = 0;
    FileManger file;
    std::vector<Oitem>  sets;

    Oitem teste;
};

#endif //_WINDOWS__H