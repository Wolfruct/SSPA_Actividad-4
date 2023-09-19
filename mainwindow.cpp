#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <iostream>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pushButton_clicked()
{
    this->generar_texto();
}


void MainWindow::generar_texto()
{
    ui->plainTextEdit->clear();

    if(lista.get_lista_beg() != NULL)
    {
        neurona *aux = lista.get_lista_beg();
        while(aux != NULL)
        {
            QString aux_qstr = QString("ID: %1\nVoltaje: %2\n Posicion x: %3\nPosicion y: %4\nRed: %5\nGreen: %6\nBlue: %7\n---------------").arg(aux->get_id()).arg(aux->get_voltaje()).arg(aux->get_posicion_x()).arg(aux->get_posicion_y()).arg(aux->get_red()).arg(aux->get_green()).arg(aux->get_blue());
            ui->plainTextEdit->appendPlainText(aux_qstr);
            aux = aux->get_sig_neurona();
        }
    }
}

void MainWindow::obtener_datos(int indicador)
{
    neurona *aux = new neurona();

    aux->set_all(ui->spinBox->value(),ui->doubleSpinBox->value(),ui->spinBox_2->value(),ui->spinBox_3->value(),ui->spinBox_4->value(),ui->spinBox_5->value(),ui->spinBox_6->value());

    if(indicador == 0)
        lista.agregar_inicio(aux);
    if(indicador == 1)
        lista.agregar_final(aux);

}


void MainWindow::on_pushButton_2_clicked()
{
    obtener_datos(0);
}


void MainWindow::on_pushButton_3_clicked()
{
    obtener_datos(1);
}

