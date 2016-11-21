/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *btn_cargar_archivo;
    QSpacerItem *verticalSpacer;
    QPushButton *btn_Inicializar;
    QSpacerItem *verticalSpacer_2;
    QPushButton *btn_reiniciar;
    QTextEdit *mostrar_texto;
    QMenuBar *menuBar;
    QMenu *menuAnalizador_Lexico;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(548, 415);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(340, 50, 160, 241));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        btn_cargar_archivo = new QPushButton(verticalLayoutWidget);
        btn_cargar_archivo->setObjectName(QStringLiteral("btn_cargar_archivo"));

        verticalLayout->addWidget(btn_cargar_archivo);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        btn_Inicializar = new QPushButton(verticalLayoutWidget);
        btn_Inicializar->setObjectName(QStringLiteral("btn_Inicializar"));

        verticalLayout->addWidget(btn_Inicializar);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        btn_reiniciar = new QPushButton(verticalLayoutWidget);
        btn_reiniciar->setObjectName(QStringLiteral("btn_reiniciar"));

        verticalLayout->addWidget(btn_reiniciar);

        mostrar_texto = new QTextEdit(centralWidget);
        mostrar_texto->setObjectName(QStringLiteral("mostrar_texto"));
        mostrar_texto->setGeometry(QRect(40, 30, 251, 281));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 548, 29));
        menuAnalizador_Lexico = new QMenu(menuBar);
        menuAnalizador_Lexico->setObjectName(QStringLiteral("menuAnalizador_Lexico"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuAnalizador_Lexico->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        btn_cargar_archivo->setText(QApplication::translate("MainWindow", "Cargar \n"
" Archivo", 0));
        btn_Inicializar->setText(QApplication::translate("MainWindow", "Iniciar\n"
"Analisis Lexico", 0));
        btn_reiniciar->setText(QApplication::translate("MainWindow", "Reiniciar", 0));
        menuAnalizador_Lexico->setTitle(QApplication::translate("MainWindow", "Analizador Lexico", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
