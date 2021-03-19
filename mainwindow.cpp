#include "mainwindow.h"
#include "ui_mainwindow.h"

bool mouseState;
bool mouseState2;
int nb_val = ligne * colone;

unsigned short tab[colone][ligne] = {0};

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label_3->setNum(0.00);
    ui->label_4->setNum(0.00);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_tableWidget_cellClicked(int row, int column)
{
    ui->tableWidget->setItem(row, column, new QTableWidgetItem);

    QFile fichier("pos.txt");
    QTextStream flux(&fichier);
    if (!fichier.open(QIODevice::Append | QIODevice::Text))
        return;
    flux.setCodec("UTF-8");

    if (mouseState == true)
    {
        ui->tableWidget->item(row, column)->setBackground(Qt::black);
        tab[row][column] = 1;
        flux <<  row << ";" << column << ":" << tab[row][column] << endl;

    }
    else if (mouseState2 == true)
    {
        ui->tableWidget->item(row, column)->setBackground(Qt::red);
        tab[row][column] = 2;
        flux <<  row << ";" << column << ":" << tab[row][column] << endl;

    }
    else
    {
        ui->tableWidget->item(row, column)->setBackground(Qt::white);
        tab[row][column] = 0;
        flux <<  row << ";" << column << ":" << tab[row][column] << endl;

    }
}

void MainWindow::on_checkBox_clicked(bool checked)
{
    mouseState = checked;
    mouseState2 = false;
}



void MainWindow::on_checkBox_2_clicked(bool checked)
{
    mouseState2 = checked;
    mouseState = false;
}

void MainWindow::on_pushButton_clicked(bool checked)
{

}

void MainWindow::on_pushButton_2_clicked(bool checked)
{
    ui->tableWidget->clearContents();

    QFile fichier("pos.txt");
    QTextStream flux(&fichier);
    if (!fichier.open(QIODevice::WriteOnly | QIODevice::Text))
        return;
    flux.setCodec("UTF-8");
    flux;
}



void MainWindow::on_doubleSpinBox_2_valueChanged(double arg1)
{
    ui->label_4->setNum(arg1/ligne);
    //C:/Users/Lenovo/Desktop/SNIR2/Projet/Robots pompiers/Travail/Mapping_qt/
    QFile fichier("pos.txt");
    QTextStream flux(&fichier);
    if (!fichier.open(QIODevice::Append | QIODevice::Text))
        return;
    flux.setCodec("UTF-8");
    flux << "L:" << arg1 << endl;
}

void MainWindow::on_doubleSpinBox_valueChanged(double arg1)
{
    ui->label_3->setNum(arg1/colone);
    QFile fichier("pos.txt");
    QTextStream flux(&fichier);
    if (!fichier.open(QIODevice::Append | QIODevice::Text))
        return;
    flux.setCodec("UTF-8");
    flux << "l:" << arg1 << endl;
}
