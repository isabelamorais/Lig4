#ifndef PECA_H
#define PECA_H
#include<QString>

namespace TP2{

class Peca
{
private:
    QString nome;
    QString cor;
public:
    Peca();
    QString getNome()const{return nome;}
    void setNome(QString nome){this->nome = nome;}
    QString getCor()const{return cor;}
    void setCor(QString cor){this->cor = cor;}
};

}

#endif // PECA_H
