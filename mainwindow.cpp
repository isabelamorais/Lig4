#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton_1->setVisible(false);
    ui->pushButton_2->setVisible(false);
    ui->pushButton_3->setVisible(false);
    ui->pushButton_4->setVisible(false);
    ui->pushButton_5->setVisible(false);
    ui->pushButton_6->setVisible(false);
    ui->pushButton_7->setVisible(false);
    ui->tableWidget->setEnabled(false);
    ui->tableWidget->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete matriz;
}

void MainWindow::on_pushButtonCriar_clicked()
{
    try{
        QString jogador1 = ui->lineEditJogador1->text();
        QString jogador2 = ui->lineEditJogador2->text();

        matriz = new TP2::Matriz(7,7);

        linha1 = matriz->getLinhas() - 1;
        linha2 = matriz->getLinhas() - 1;
        linha3 = matriz->getLinhas() - 1;
        linha4 = matriz->getLinhas() - 1;
        linha5 = matriz->getLinhas() - 1;
        linha6 = matriz->getLinhas() - 1;
        linha7 = matriz->getLinhas() - 1;

        pecaPreta.setNome(jogador1);
        pecaPreta.setCor("P");

        pecaBranca.setNome(jogador2);
        pecaBranca.setCor("B");

        ui->tableWidget->setVisible(true);

        ui->pushButton_1->setVisible(true);
        ui->pushButton_2->setVisible(true);
        ui->pushButton_3->setVisible(true);
        ui->pushButton_4->setVisible(true);
        ui->pushButton_5->setVisible(true);
        ui->pushButton_6->setVisible(true);
        ui->pushButton_7->setVisible(true);

        QString rodada = "Jogador 1: " + jogador1;

        ui->labelJogador->setText(rodada);

        ui->lineEditJogador1->setEnabled(false);
        ui->lineEditJogador2->setEnabled(false);
        ui->pushButtonCriar->setEnabled(false);
    }catch(QString &erro){
        QMessageBox::information(this, "ERRO", erro);
    }
}

void MainWindow::on_actionNovo_Jogo_triggered()
{
    try{
        aux = 0;

        delete matriz;

        matriz = 0;

        ui->tableWidget->clear();

        ui->labelJogador->clear();

        ui->centralWidget->setEnabled(true);

        ui->pushButton_1->setVisible(false);
        ui->pushButton_2->setVisible(false);
        ui->pushButton_3->setVisible(false);
        ui->pushButton_4->setVisible(false);
        ui->pushButton_5->setVisible(false);
        ui->pushButton_6->setVisible(false);
        ui->pushButton_7->setVisible(false);
        ui->tableWidget->setVisible(false);

        ui->lineEditJogador1->setEnabled(true);
        ui->lineEditJogador1->clear();
        ui->lineEditJogador2->clear();
        ui->lineEditJogador2->setEnabled(true);
        ui->pushButtonCriar->setEnabled(true);
    }catch(QString &erro){
        QMessageBox::information(this, "ERRO", erro);
    }
}

void MainWindow::on_pushButton_1_clicked()
{
    try{
        aux++;

        if(aux%2!=0){
            if(linha1>=0){
                QTableWidgetItem *item = new QTableWidgetItem(pecaPreta.getCor());
                ui->tableWidget->setItem(linha1,0,item);
                matriz->setElemento(linha1,0,pecaPreta);
                if(matriz->vitoria(linha1,0,pecaPreta)){
                    QMessageBox::information(this, "Vitoria de: ", pecaPreta.getNome());
                    ui->centralWidget->setEnabled(false);
                }
                linha1--;
            }
            else
                QMessageBox::information(this, "ERRO", "Coluna cheia");

            QString rodada = "Jogador 2: " + pecaBranca.getNome();
            ui->labelJogador->setText(rodada);
        }
        else{
            if(linha1>=0){
                QTableWidgetItem *item = new QTableWidgetItem(pecaBranca.getCor());
                ui->tableWidget->setItem(linha1,0,item);
                matriz->setElemento(linha1,0,pecaBranca);
                if(matriz->vitoria(linha1,0,pecaBranca)){
                    QMessageBox::information(this, "Vitoria de: ", pecaBranca.getNome());
                    ui->centralWidget->setEnabled(false);
                }
                linha1--;
            }
            else
                QMessageBox::information(this, "ERRO", "Coluna cheia");

            QString rodada = "Jogador 1: " + pecaPreta.getNome();
            ui->labelJogador->setText(rodada);
        }
    }catch(QString &erro){
        QMessageBox::information(this, "ERRO", erro);
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    try{
        aux++;

        if(aux%2!=0){
            if(linha2>=0){
                QTableWidgetItem *item = new QTableWidgetItem(pecaPreta.getCor());
                ui->tableWidget->setItem(linha2,1,item);
                matriz->setElemento(linha2,1,pecaPreta);
                if(matriz->vitoria(linha2,1,pecaPreta)){
                    QMessageBox::information(this, "Vitoria de: ", pecaPreta.getNome());
                    ui->centralWidget->setEnabled(false);
                }
                linha2--;
            }
            else
                QMessageBox::information(this, "ERRO", "Coluna cheia");

            QString rodada = "Jogador 2: " + pecaBranca.getNome();
            ui->labelJogador->setText(rodada);
        }
        else{
            if(linha2>=0){
                QTableWidgetItem *item = new QTableWidgetItem(pecaBranca.getCor());
                ui->tableWidget->setItem(linha2,1,item);
                matriz->setElemento(linha2,1,pecaBranca);
                if(matriz->vitoria(linha2,1,pecaBranca)){
                    QMessageBox::information(this, "Vitoria de: ", pecaBranca.getNome());
                    ui->centralWidget->setEnabled(false);
                }
                linha2--;
            }
            else
                QMessageBox::information(this, "ERRO", "Coluna cheia");

            QString rodada = "Jogador 1: " + pecaPreta.getNome();
            ui->labelJogador->setText(rodada);
        }
    }catch(QString &erro){
        QMessageBox::information(this, "ERRO", erro);
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    try{
        aux++;

        if(aux%2!=0){
            if(linha3>=0){
                QTableWidgetItem *item = new QTableWidgetItem(pecaPreta.getCor());
                ui->tableWidget->setItem(linha3,2,item);
                matriz->setElemento(linha3,2,pecaPreta);
                if(matriz->vitoria(linha3,2,pecaPreta)){
                    QMessageBox::information(this, "Vitoria de: ", pecaPreta.getNome());
                    ui->centralWidget->setEnabled(false);
                }
                linha3--;
            }
            else
                QMessageBox::information(this, "ERRO", "Coluna cheia");

            QString rodada = "Jogador 2: " + pecaBranca.getNome();
            ui->labelJogador->setText(rodada);
        }
        else{
            if(linha3>=0){
                QTableWidgetItem *item = new QTableWidgetItem(pecaBranca.getCor());
                ui->tableWidget->setItem(linha3,2,item);
                matriz->setElemento(linha3,2,pecaBranca);
                if(matriz->vitoria(linha3,2,pecaBranca)){
                    QMessageBox::information(this, "Vitoria de: ", pecaBranca.getNome());
                    ui->centralWidget->setEnabled(false);
                }
                linha3--;
            }
            else
                QMessageBox::information(this, "ERRO", "Coluna cheia");

            QString rodada = "Jogador 1: " + pecaPreta.getNome();
            ui->labelJogador->setText(rodada);
        }
    }catch(QString &erro){
        QMessageBox::information(this, "ERRO", erro);
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    try{
        aux++;

        if(aux%2!=0){
            if(linha4>=0){
                QTableWidgetItem *item = new QTableWidgetItem(pecaPreta.getCor());
                ui->tableWidget->setItem(linha4,3,item);
                matriz->setElemento(linha4,3,pecaPreta);
                if(matriz->vitoria(linha4,3,pecaPreta)){
                    QMessageBox::information(this, "Vitoria de: ", pecaPreta.getNome());
                    ui->centralWidget->setEnabled(false);
                }
                linha4--;
            }
            else
                QMessageBox::information(this, "ERRO", "Coluna cheia");

            QString rodada = "Jogador 2: " + pecaBranca.getNome();
            ui->labelJogador->setText(rodada);
        }
        else{
            if(linha4>=0){
                QTableWidgetItem *item = new QTableWidgetItem(pecaBranca.getCor());
                ui->tableWidget->setItem(linha4,3,item);
                matriz->setElemento(linha4,3,pecaBranca);
                if(matriz->vitoria(linha4,3,pecaBranca)){
                    QMessageBox::information(this, "Vitoria de: ", pecaBranca.getNome());
                    ui->centralWidget->setEnabled(false);
                }
                linha4--;
            }
            else
                QMessageBox::information(this, "ERRO", "Coluna cheia");

            QString rodada = "Jogador 1: " + pecaPreta.getNome();
            ui->labelJogador->setText(rodada);
        }
    }catch(QString &erro){
        QMessageBox::information(this, "ERRO", erro);
    }
}

void MainWindow::on_pushButton_5_clicked()
{
    try{
        aux++;

        if(aux%2!=0){
            if(linha5>=0){
                QTableWidgetItem *item = new QTableWidgetItem(pecaPreta.getCor());
                ui->tableWidget->setItem(linha5,4,item);
                matriz->setElemento(linha5,4,pecaPreta);
                if(matriz->vitoria(linha5,4,pecaPreta)){
                    QMessageBox::information(this, "Vitoria de: ", pecaPreta.getNome());
                    ui->centralWidget->setEnabled(false);
                }
                linha5--;
            }
            else
                QMessageBox::information(this, "ERRO", "Coluna cheia");

            QString rodada = "Jogador 2: " + pecaBranca.getNome();
            ui->labelJogador->setText(rodada);
        }
        else{
            if(linha5>=0){
                QTableWidgetItem *item = new QTableWidgetItem(pecaBranca.getCor());
                ui->tableWidget->setItem(linha5,4,item);
                matriz->setElemento(linha5,4,pecaBranca);
                if(matriz->vitoria(linha5,4,pecaBranca)){
                    QMessageBox::information(this, "Vitoria de: ", pecaBranca.getNome());
                    ui->centralWidget->setEnabled(false);
                }
                linha5--;
            }
            else
                QMessageBox::information(this, "ERRO", "Coluna cheia");

            QString rodada = "Jogador 1: " + pecaPreta.getNome();
            ui->labelJogador->setText(rodada);
        }
    }catch(QString &erro){
        QMessageBox::information(this, "ERRO", erro);
    }
}

void MainWindow::on_pushButton_6_clicked()
{
    try{
        aux++;

        if(aux%2!=0){
            if(linha6>=0){
                QTableWidgetItem *item = new QTableWidgetItem(pecaPreta.getCor());
                ui->tableWidget->setItem(linha6,5,item);
                matriz->setElemento(linha6,5,pecaPreta);
                if(matriz->vitoria(linha6,5,pecaPreta)){
                    QMessageBox::information(this, "Vitoria de: ", pecaPreta.getNome());
                    ui->centralWidget->setEnabled(false);
                }
                linha6--;
            }
            else
                QMessageBox::information(this, "ERRO", "Coluna cheia");

            QString rodada = "Jogador 2: " + pecaBranca.getNome();
            ui->labelJogador->setText(rodada);
        }
        else{
            if(linha6>=0){
                QTableWidgetItem *item = new QTableWidgetItem(pecaBranca.getCor());
                ui->tableWidget->setItem(linha6,5,item);
                matriz->setElemento(linha6,5,pecaBranca);
                if(matriz->vitoria(linha6,5,pecaBranca)){
                    QMessageBox::information(this, "Vitoria de: ", pecaBranca.getNome());
                    ui->centralWidget->setEnabled(false);
                }
                linha6--;
            }
            else
                QMessageBox::information(this, "ERRO", "Coluna cheia");

            QString rodada = "Jogador 1: " + pecaPreta.getNome();
            ui->labelJogador->setText(rodada);
        }
    }catch(QString &erro){
        QMessageBox::information(this, "ERRO", erro);
    }
}

void MainWindow::on_pushButton_7_clicked()
{
    try{
        aux++;

        if(aux%2!=0){
            if(linha7>=0){
                QTableWidgetItem *item = new QTableWidgetItem(pecaPreta.getCor());
                ui->tableWidget->setItem(linha7,6,item);
                matriz->setElemento(linha7,6,pecaPreta);
                if(matriz->vitoria(linha7,6,pecaPreta)){
                    QMessageBox::information(this, "Vitoria de: ", pecaPreta.getNome());
                    ui->centralWidget->setEnabled(false);
                }
                linha7--;
            }
            else
                QMessageBox::information(this, "ERRO", "Coluna cheia");

            QString rodada = "Jogador 2: " + pecaBranca.getNome();
            ui->labelJogador->setText(rodada);
        }
        else{
            if(linha7>=0){
                QTableWidgetItem *item = new QTableWidgetItem(pecaBranca.getCor());
                ui->tableWidget->setItem(linha7,6,item);
                matriz->setElemento(linha7,6,pecaBranca);
                if(matriz->vitoria(linha7,6,pecaBranca)){
                    QMessageBox::information(this, "Vitoria de: ", pecaBranca.getNome());
                    ui->centralWidget->setEnabled(false);
                }
                linha7--;
            }
            else
                QMessageBox::information(this, "ERRO", "Coluna cheia");

            QString rodada = "Jogador 1: " + pecaPreta.getNome();
            ui->labelJogador->setText(rodada);
        }
    }catch(QString &erro){
        QMessageBox::information(this, "ERRO", erro);
    }
}
