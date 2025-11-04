#ifndef _WINDOWS__H
#define _WINDOWS__H

#include <QTimer>
#include "core/GradeSystem.h"
#include "ui/UIManager.h"
#include "data/ListDataItems.h"
#include "ui/PreferenceSystem.h"
#include <string>
#include <fmt/core.h>
#include <QFileDialog>
#include "ui_MainWindow.h"
#include "io/FileManager.h"
#include "utils/GlobalAccess.h"
#include "ui/LanguageUI.h"

QT_BEGIN_NAMESPACE
namespace Ui { class _windows_; }
QT_END_NAMESPACE

class _windows_ : public QMainWindow  {
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


    void on_btn_infoSystem_clicked();

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
    _FILE_ info_file;
     option *op;
    nlohmann::json system_json;

    bool is_open;

};
#endif //_WINDOWS__H