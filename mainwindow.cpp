#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "neurona.h"
#include "QSpinBox"
#include <QPlainTextEdit>
#include<QDebug>
#include<QString>
#include<QFileDialog>
#include<QTableView>
#include<QTableWidget>
#include<list>
#include<QLineEdit>

AdministradorNeuronas list;
QString neuro;
int ta,i=0;


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


void MainWindow::on_agregarFinal_clicked()
{
    Neurona neurona(ui->id->value(),ui->volt->value(),ui->pos_x->value(),ui->pos_y->value(),ui->red->value(),
                    ui->green->value(),ui->blue->value());
    list.agregar_final(neurona);
    list.mostrar();
}


void MainWindow::on_agregarInicio_clicked()
{
    Neurona neurona(ui->id->value(),ui->volt->value(),ui->pos_x->value(),ui->pos_y->value(),ui->red->value(),
                    ui->green->value(),ui->blue->value());
    list.agregar_inicio(neurona);
    list.mostrar();

}


void MainWindow::on_bmostrar_clicked()
{
    ta=list.tam();
    list.mostrar();
    neuro = (list.imprimir()).c_str();
    ui->seeBox->setPlainText(neuro);

    ui->tableWidget->setColumnCount(1);
    ui->tableWidget->setRowCount(list.tam());
    //QTableWidgetItem *Myitem= new QTableWidgetItem(list.imprimir().c_str());
    for(i; i<ta;i++)
    {
        QTableWidgetItem *Myitem= new QTableWidgetItem(list.obtener_neurona_en_posicion(i).c_str());
        ui->tableWidget->setItem(i,1,Myitem);

    }

}


void MainWindow::on_seeBox_blockCountChanged(int newBlockCount)
{

}


void MainWindow::on_actionguardar_triggered()
{
    list.guardar_en_archivo("neuronas.txt");
    //QString FileName = QFileDialog::getOpenFileName(this,tr("Open File"), "/home", tr("Images(*.txt)"));
}


void MainWindow::on_actionCargar_triggered()
{
    QString FileName = QFileDialog::getOpenFileName(this,tr("Open File"), "/home", tr("Images(*.txt)"));
    list.cargar_desde_archivo(FileName.toStdString());
}



void MainWindow::on_busId_clicked()
{

    ui->tableWidget->setColumnCount(1);
    ui->tableWidget->setRowCount(1);
    QTableWidgetItem *Myitem= new QTableWidgetItem(list.encontrar_neurona_por_id(ui->lineId->text().toStdString()).c_str());
    ui->tableWidget->setItem(0,0,Myitem);
}

