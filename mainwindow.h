#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Matriz.h>
#include <QMessageBox>

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
    void on_pushButtonCriar_clicked();

    void on_actionNovo_Jogo_triggered();

    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::MainWindow *ui;
    TP2::Matriz *matriz;
    TP2::Peca pecaPreta;
    TP2::Peca pecaBranca;
    int aux=0;
    int linha1;
    int linha2;
    int linha3;
    int linha4;
    int linha5;
    int linha6;
    int linha7;
};

#endif // MAINWINDOW_H
