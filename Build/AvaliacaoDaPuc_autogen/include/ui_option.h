/********************************************************************************
** Form generated from reading UI file 'option.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTION_H
#define UI_OPTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_option
{
public:
    QWidget *centralwidget;
    QFrame *frame;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBox;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_tema;
    QComboBox *Combox_tema;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_fonte;
    QFontComboBox *fontComboBox;
    QPushButton *btn_search_paste;
    QPushButton *btn_aplicar;
    QPushButton *btn_salvar;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_2;

    void setupUi(QMainWindow *option)
    {
        if (option->objectName().isEmpty())
            option->setObjectName("option");
        option->resize(385, 190);
        centralwidget = new QWidget(option);
        centralwidget->setObjectName("centralwidget");
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(0, 0, 400, 216));
        frame->setFrameShape(QFrame::Shape::NoFrame);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        layoutWidget = new QWidget(frame);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 80, 141, 28));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        comboBox = new QComboBox(layoutWidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");

        horizontalLayout->addWidget(comboBox);

        layoutWidget1 = new QWidget(frame);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(10, 50, 131, 26));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_tema = new QLabel(layoutWidget1);
        label_tema->setObjectName("label_tema");

        horizontalLayout_2->addWidget(label_tema);

        Combox_tema = new QComboBox(layoutWidget1);
        Combox_tema->addItem(QString());
        Combox_tema->addItem(QString());
        Combox_tema->setObjectName("Combox_tema");

        horizontalLayout_2->addWidget(Combox_tema);

        layoutWidget2 = new QWidget(frame);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(80, 10, 214, 24));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget2);
        label_3->setObjectName("label_3");

        horizontalLayout_5->addWidget(label_3);

        lineEdit = new QLineEdit(layoutWidget2);
        lineEdit->setObjectName("lineEdit");

        horizontalLayout_5->addWidget(lineEdit);

        layoutWidget3 = new QWidget(frame);
        layoutWidget3->setObjectName("layoutWidget3");
        layoutWidget3->setGeometry(QRect(170, 50, 210, 26));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_fonte = new QLabel(layoutWidget3);
        label_fonte->setObjectName("label_fonte");

        horizontalLayout_6->addWidget(label_fonte);

        fontComboBox = new QFontComboBox(layoutWidget3);
        fontComboBox->setObjectName("fontComboBox");

        horizontalLayout_6->addWidget(fontComboBox);

        btn_search_paste = new QPushButton(frame);
        btn_search_paste->setObjectName("btn_search_paste");
        btn_search_paste->setGeometry(QRect(300, 10, 71, 24));
        btn_aplicar = new QPushButton(frame);
        btn_aplicar->setObjectName("btn_aplicar");
        btn_aplicar->setGeometry(QRect(10, 140, 75, 40));
        btn_aplicar->setMaximumSize(QSize(80, 40));
        btn_salvar = new QPushButton(frame);
        btn_salvar->setObjectName("btn_salvar");
        btn_salvar->setGeometry(QRect(90, 140, 75, 40));
        btn_salvar->setMaximumSize(QSize(80, 40));
        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(382, 216, 18, 18));
        frame_2->setMaximumSize(QSize(16777215, 90));
        frame_2->setFrameShape(QFrame::Shape::NoFrame);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_2 = new QVBoxLayout(frame_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        option->setCentralWidget(centralwidget);

        retranslateUi(option);

        QMetaObject::connectSlotsByName(option);
    } // setupUi

    void retranslateUi(QMainWindow *option)
    {
        option->setWindowTitle(QCoreApplication::translate("option", "option", nullptr));
        label->setText(QCoreApplication::translate("option", "idioma", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("option", "Portugu\303\252s", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("option", "Ingles", nullptr));

        label_tema->setText(QCoreApplication::translate("option", "Tema:", nullptr));
        Combox_tema->setItemText(0, QCoreApplication::translate("option", "Escuro", nullptr));
        Combox_tema->setItemText(1, QCoreApplication::translate("option", "Claro", nullptr));

        label_3->setText(QCoreApplication::translate("option", "Pastas padr\303\243o", nullptr));
        label_fonte->setText(QCoreApplication::translate("option", "Fonte: ", nullptr));
        btn_search_paste->setText(QCoreApplication::translate("option", "Procurar", nullptr));
        btn_aplicar->setText(QCoreApplication::translate("option", "Aplicar", nullptr));
        btn_salvar->setText(QCoreApplication::translate("option", "Salvar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class option: public Ui_option {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTION_H
