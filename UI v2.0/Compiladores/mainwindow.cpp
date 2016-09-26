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
        tr("Open Source Code"), "/home/cs03/compiladores/UI v2.0/Compiladores/archivos", tr("Files (*.txt)"));
    QFile file(fileName);

    file.open(QFile::ReadOnly | QFile::Text);

    QTextStream ReadFile(&file);
    ui->mostrar_texto->setText(ReadFile.readAll());

}

void MainWindow::on_btn_Inicializar_clicked()
{
    ui->mostrar_texto->clear();
    analyzer = new Analizador_Lexico();
    qDebug()<<"Antes de Analizar::\n";
    analyzer->analizar();
    qDebug()<<"Despues de Analizar::\n";
    QString fileName = "/home/cs03/compiladores/UI v2.0/Compiladores/procesado.txt";
    QFile file(fileName);

    file.open(QFile::ReadOnly | QFile::Text);

    QTextStream ReadFile(&file);
    ui->mostrar_texto->setText(ReadFile.readAll());
}
