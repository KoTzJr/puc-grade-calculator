/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui__windows_
{
public:
    QAction *actionAbrir;
    QAction *actionNovo;
    QAction *actionSalvar;
    QAction *actionSalvar_como;
    QAction *actionExportar;
    QAction *actionOpition;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QPushButton *btn_add;
    QPushButton *btn_remover;
    QTableWidget *tableWidget;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *lineEdit;
    QSpacerItem *horizontalSpacer;
    QLabel *info_arquivo;
    QLabel *label_3;
    QMenuBar *menuBar;
    QMenu *menuArquivos;
    QMenu *menuFerramentas;

    void setupUi(QMainWindow *_windows_)
    {
        if (_windows_->objectName().isEmpty())
            _windows_->setObjectName("_windows_");
        _windows_->resize(903, 561);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(_windows_->sizePolicy().hasHeightForWidth());
        _windows_->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        _windows_->setFont(font);
        _windows_->setTabShape(QTabWidget::TabShape::Rounded);
        actionAbrir = new QAction(_windows_);
        actionAbrir->setObjectName("actionAbrir");
        actionNovo = new QAction(_windows_);
        actionNovo->setObjectName("actionNovo");
        actionSalvar = new QAction(_windows_);
        actionSalvar->setObjectName("actionSalvar");
        actionSalvar_como = new QAction(_windows_);
        actionSalvar_como->setObjectName("actionSalvar_como");
        actionExportar = new QAction(_windows_);
        actionExportar->setObjectName("actionExportar");
        actionOpition = new QAction(_windows_);
        actionOpition->setObjectName("actionOpition");
        centralwidget = new QWidget(_windows_);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setFrameShape(QFrame::Shape::NoFrame);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setObjectName("horizontalLayout");
        label_2 = new QLabel(frame);
        label_2->setObjectName("label_2");

        horizontalLayout->addWidget(label_2);

        btn_add = new QPushButton(frame);
        btn_add->setObjectName("btn_add");
        btn_add->setIconSize(QSize(36, 36));

        horizontalLayout->addWidget(btn_add);

        btn_remover = new QPushButton(frame);
        btn_remover->setObjectName("btn_remover");

        horizontalLayout->addWidget(btn_remover);


        verticalLayout->addWidget(frame, 0, Qt::AlignmentFlag::AlignLeft);

        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 9)
            tableWidget->setColumnCount(9);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        tableWidget->setObjectName("tableWidget");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy1);
        tableWidget->setFont(font);
        tableWidget->setStyleSheet(QString::fromUtf8(""));
        tableWidget->setFrameShape(QFrame::Shape::NoFrame);
        tableWidget->setLineWidth(2);
        tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        tableWidget->setTabKeyNavigation(true);
        tableWidget->setSelectionMode(QAbstractItemView::SelectionMode::MultiSelection);
        tableWidget->setGridStyle(Qt::PenStyle::NoPen);
        tableWidget->setCornerButtonEnabled(false);
        tableWidget->setRowCount(0);
        tableWidget->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget->horizontalHeader()->setDefaultSectionSize(106);
        tableWidget->verticalHeader()->setVisible(true);

        verticalLayout->addWidget(tableWidget);

        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName("frame_2");
        frame_2->setFrameShape(QFrame::Shape::NoFrame);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label = new QLabel(frame_2);
        label->setObjectName("label");
        label->setFont(font);

        horizontalLayout_2->addWidget(label);

        lineEdit = new QLineEdit(frame_2);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setStyleSheet(QString::fromUtf8("border-radius : 40px;"));

        horizontalLayout_2->addWidget(lineEdit);

        horizontalSpacer = new QSpacerItem(700, 20, QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        info_arquivo = new QLabel(frame_2);
        info_arquivo->setObjectName("info_arquivo");

        horizontalLayout_2->addWidget(info_arquivo);

        label_3 = new QLabel(frame_2);
        label_3->setObjectName("label_3");
        label_3->setTextFormat(Qt::TextFormat::RichText);
        label_3->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout_2->addWidget(label_3, 0, Qt::AlignmentFlag::AlignLeft);


        verticalLayout->addWidget(frame_2, 0, Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        _windows_->setCentralWidget(centralwidget);
        menuBar = new QMenuBar(_windows_);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 903, 33));
        menuBar->setFont(font);
        menuArquivos = new QMenu(menuBar);
        menuArquivos->setObjectName("menuArquivos");
        menuFerramentas = new QMenu(menuBar);
        menuFerramentas->setObjectName("menuFerramentas");
        _windows_->setMenuBar(menuBar);

        menuBar->addAction(menuArquivos->menuAction());
        menuBar->addAction(menuFerramentas->menuAction());
        menuArquivos->addAction(actionNovo);
        menuArquivos->addAction(actionAbrir);
        menuArquivos->addAction(actionSalvar);
        menuArquivos->addAction(actionSalvar_como);
        menuFerramentas->addAction(actionOpition);

        retranslateUi(_windows_);

        QMetaObject::connectSlotsByName(_windows_);
    } // setupUi

    void retranslateUi(QMainWindow *_windows_)
    {
        _windows_->setWindowTitle(QCoreApplication::translate("_windows_", "Projeto Teste", nullptr));
        actionAbrir->setText(QCoreApplication::translate("_windows_", "Abrir", nullptr));
        actionNovo->setText(QCoreApplication::translate("_windows_", "Novo", nullptr));
        actionSalvar->setText(QCoreApplication::translate("_windows_", "Salvar", nullptr));
        actionSalvar_como->setText(QCoreApplication::translate("_windows_", "Salvar como", nullptr));
        actionExportar->setText(QCoreApplication::translate("_windows_", "Exportar", nullptr));
        actionOpition->setText(QCoreApplication::translate("_windows_", "op\303\247\303\265es", nullptr));
        label_2->setText(QString());
        btn_add->setText(QString());
        btn_remover->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("_windows_", "Nome", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("_windows_", "Aulas Previstas", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("_windows_", "Aulas Ministradas", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("_windows_", "Numero Presen\303\247a", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("_windows_", "N1", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("_windows_", "N2", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("_windows_", "Media", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("_windows_", "Resultado", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("_windows_", "Falta Media", nullptr));
        label->setText(QCoreApplication::translate("_windows_", "AI", nullptr));
        info_arquivo->setText(QString());
        label_3->setText(QString());
        menuArquivos->setTitle(QCoreApplication::translate("_windows_", "Arquivos", nullptr));
        menuFerramentas->setTitle(QCoreApplication::translate("_windows_", "Ferramentas", nullptr));
    } // retranslateUi

};

namespace Ui {
    class _windows_: public Ui__windows_ {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
