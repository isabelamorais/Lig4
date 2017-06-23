#ifndef MATRIZ_H
#define MATRIZ_H
#include <Peca.h>

//posicao = (linha * numero de colunas) + coluna

namespace TP2 {

class Matriz
{
private:
    Peca *matriz;
    int quantidadeDeLinhas;
    int quantidadeDeColunas;
public:
    Matriz(int qLinha, int qColuna);
    ~Matriz(){if(matriz) delete [] matriz;}
    int getLinhas()const{return quantidadeDeLinhas;}
    int getColunas()const{return quantidadeDeColunas;}
    Peca getElemento(int linha, int coluna)const;
    void setElemento(int linha, int coluna, Peca elemento)const;
    bool vitoriaHorizontal(int linha, int coluna, Peca elemento)const;
    bool vitoriaVertical(int linha, int coluna, Peca elemento)const;
    bool vitoriaDiagonal(int linha, int coluna, Peca elemento)const;
    bool vitoria(int linha, int coluna, Peca elemento)const;
};


}
#endif // MATRIZ_H
