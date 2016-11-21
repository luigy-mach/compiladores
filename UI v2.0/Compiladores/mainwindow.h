#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDebug>
#include <QString>
#include "analizador_lexico.hpp"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btn_cargar_archivo_clicked();

    void on_btn_Inicializar_clicked();

private:
    Ui::MainWindow *ui;
    Analizador_Lexico * analyzer;

};

#endif // MAINWINDOW_H
