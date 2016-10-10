#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_cargar_archivo_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open Source Code"), "/$HOME/WorkSpace/compiladores/UI v2.0/build-Compiladores-Desktop-Debug", tr("Files (*.txt)"));
    QFile file(fileName);

    file.open(QFile::ReadOnly | QFile::Text);

    QTextStream ReadFile(&file);
    ui->mostrar_texto->setText(ReadFile.readAll());

}

void MainWindow::on_btn_Inicializar_clicked()
{
    ui->mostrar_texto->clear();
    analyzer = new Analizador_Lexico();

    analyzer->analizar();


    QString fileName = "$HOME/WorkSpace/compiladores/UI\ v2.0/build-Compiladores-Desktop-Debug/procesado.txt";


    QFile file(fileName);

    file.open(QFile::ReadOnly | QFile::Text);

    QTextStream ReadFile(&file);

    ui->mostrar_texto->setText(ReadFile.readAll());
}

void MainWindow::on_btn_reiniciar_clicked()
{
    analyzer->reset();
    ui->mostrar_texto->clear();
}
