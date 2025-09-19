#ifndef _UI__H
#define _UI__H

#include <..//include/ui__windows_.h>
#include <QDir>

const QString ui_styles_ = QDir::homePath() + "/Documents/GitHub/puc-grade-calculator/styles/ui_styles.qss";
const QString ui_styles__ =  "/home/kotz/Documentos/GitHub/puc-grade-calculator/styles/ui_styles.qss";


QT_BEGIN_NAMESPACE
namespace Ui { class _windows_; class Style;}
QT_END_NAMESPACE

namespace Style_Table {
        class Style {
        public :
            static void table_result(QTableWidget *ui,int index,int pos);
            static void clear_table(QTableWidget *ui,int h,int colune);
    };

}

class _ui_ {
private:
    Ui::_windows_ *ui;
public:
    void UI_init(Ui::_windows_ *ui);
    void _botao_();

};

#endif //_UI__H