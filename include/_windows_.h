#ifndef _WINDOWS__H
#define _WINDOWS__H

#include <QTimer>
#include "system_nota.h"
#include "_ui_.h"
#include  <ListDataItens.h>
#include "option.h"
#include <string>
#include <fmt/core.h>
#include <QFileDialog>
#include "../include/_windows_.h"
#include "../include/ListDataItens.h"
#include "GlobalVariables.h"
#include "../cmake-build-debug/AvaliacaoDaPuc_autogen/include/ui__windows_.h"


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

    void on_actionOpition_triggered();

    void info_save(QString patch,int x);
private:
    Ui::_windows_ *ui;
    QTimer *timer;
    system_nota *system_nota_;
    _ui_ *is;
    int i = 0;
    FileManger file;
    std::vector<Oitem>  sets;

    QString patch_load;
    //Oitem teste;

    _FILE_ info_file;

    bool is_open;

};

#endif //_WINDOWS__H