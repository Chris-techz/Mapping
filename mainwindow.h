#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <QFile>
#include <QTextStream>

#define colone 25
#define ligne 25

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);

private slots:

    void on_tableWidget_cellClicked(int row, int column);

    void on_checkBox_clicked(bool checked);

    void on_checkBox_2_clicked(bool checked);

    void on_pushButton_clicked(bool checked);

    void on_pushButton_2_clicked(bool checked);

    void on_doubleSpinBox_2_valueChanged(double arg1);

    void on_doubleSpinBox_valueChanged(double arg1);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
