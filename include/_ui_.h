#ifndef _UI__H
#define _UI__H

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMainWindow>
#include <QFile>
#include <..//include/ui__windows_.h>
#include <QDir>

const QString ui_styles_ = QDir::homePath() + "/Documents/GitHub/puc-grade-calculator/styles/ui_styles.qss";

QT_BEGIN_NAMESPACE
namespace Ui { class _windows_; }
QT_END_NAMESPACE

class _ui_ {
private:
    Ui::_windows_ *ui;
public:
    void UI_init(Ui::_windows_ *ui);
    void _botao_();
};

#endif //_UI__H