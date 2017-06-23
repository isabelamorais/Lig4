#include "Matriz.h"

namespace TP2{

Matriz::Matriz(int qLinha,int qColuna):
    quantidadeDeLinhas(0),
    quantidadeDeColunas(0),
    matriz(0)
{
    try{
       matriz = new Peca[qLinha*qColuna];
    } catch(std::bad_alloc&){
        throw QString("Memoria insuficiente");
    }

    quantidadeDeLinhas = qLinha;
    quantidadeDeColunas = qColuna;

}

Peca Matriz::getElemento(int linha,int coluna)const{
    if(linha<0||linha>=quantidadeDeLinhas)
        throw QString ("Linha fora do intervalo");
    if(coluna<0||coluna>=quantidadeDeColunas)
        throw QString ("Coluna fora do intervalo");

    int posicao = (linha*quantidadeDeColunas)+coluna;

    return *(matriz+posicao);
}

void Matriz::setElemento(int linha, int coluna, Peca elemento)const{
    if(linha<0||linha>=quantidadeDeLinhas)
        throw QString ("Linha fora do intervalo");
    if(coluna<0||coluna>=quantidadeDeColunas)
        throw QString ("Coluna fora do intervalo");

    int posicao = (linha*quantidadeDeColunas)+coluna;

    *(matriz+posicao) = elemento;
}

bool Matriz::vitoriaHorizontal(int linha, int coluna, Peca elemento)const{
    int aux=1;
    for(int i = 1;aux<=4 && coluna+i<=getColunas()-1 && getElemento(linha,coluna+i).getCor()==elemento.getCor();i++){
        aux ++;
    }
    for(int i = 1;aux<=4 && coluna-i>=0 && getElemento(linha,coluna-i).getCor()==elemento.getCor();i++){
        aux ++;
    }
    if(aux>=4)
        return 1;
    return 0;
}

bool Matriz::vitoriaVertical(int linha, int coluna, Peca elemento)const{
    int aux=1;

    for(int i = 1;aux<=4&&linha+i<=getLinhas()-1&&getElemento(linha+i,coluna).getCor()==elemento.getCor();i++){
        aux++;
    }

    if(aux>=4)
       return 1;
    return 0;
}

bool Matriz::vitoriaDiagonal(int linha, int coluna, Peca elemento)const{
    //aux comeca com 1 porque ja conta a peca que acabou de ser inserida
    int aux = 1;

    //Diagonal principal(esquerda p/ direita)

    /*o for so roda ate a cor do proximo elemento ser diferente da cor da peca inserida.
     * a linha e a coluna diminuindo mostra que o elemento que vai ser
     * comparado ta acima e pra esquerda do elemento anterior.
     * a linha e a coluna aumentando mostra que o elemento que vai ser comparado
     * ta abaixo e a esquerda do elemento anterior.
     * a linha-i tem que ser >= 0 pq 0 e a linha inicial da matriz e linha+i tem que ser getLinhas()-1 pq e a ultima linha da matriz
     * a coluna-i e coluna+i tambem tem que ser assim
     * getElemento(linha-i,coluna-i) e o elemento acima e a esquerda
     * getElemento(linha+i,coluna+i) e o elemento abaixo e a direita
     * o aux so aumenta se todas essas condicoes forem verdadeiras
     * o aux tem que ser no minimo 4 pq ja e considerado vitoria quando aux=4
     * o for para de rodar quando uma das condicoes for falsa
     */

    //de baixo para cima, da direita pra esquerda
    for(int i = 1;aux<=4 && linha-i>=0 && coluna-i>=0 && getElemento(linha-i,coluna-i).getCor()==elemento.getCor();i++)
    {
        aux++;
    }

    //de cima para baixo, da esquerda pra direita
    for(int i = 1;aux<=4 && linha+i<=getLinhas()-1 && coluna+i<=getColunas()-1 && getElemento(linha+i,coluna+i).getCor()==elemento.getCor();i++)
    {
        aux++;
    }

    if(aux>=4)
        return 1;
    //se for verdadeiro o programa para no return

    aux = 1;

    //Diagonal Secundaria(direita p/ esquerda)

    /*o for so roda ate a cor do proximo elemento ser diferente da cor da peca inserida.
     * a linha aumentando e a coluna diminuindo mostra que o elemento que vai ser
     * comparado ta abaixo e a esquerda do elemento anterior.
     * a linha diminuindo e a coluna aumentando mostra que o elemento que vai ser comparado
     * ta acima e a direita do elemento anterior.
     * a linha-i tem que ser >= 0 pq 0 e a linha inicial da matriz e linha+i tem que ser getLinhas()-1 pq e a ultima linha da matriz
     * a coluna-i e coluna+i tambem tem que ser assim
     * getElemento(linha-i,coluna+i) e o elemento acima e a direita
     * getElemento(linha+i,coluna-i) e o elemento abaixo e a esquerda
     * o aux so aumenta se todas essas condicoes forem verdadeiras
     * o aux tem que ser no minimo 4 pq ja e considerado vitoria quando aux=4
     * o for para de rodar quando uma das condicoes for falsa
     */

    //de baixo para cima, da esquerda pra direita
    for(int i = 1;aux<=4 && linha-i>=0 && coluna+i<=getColunas()-1 && getElemento(linha-i,coluna+i).getCor()==elemento.getCor();i++)
    {
        aux++;
    }

    //de cima para baixo, da direita pra esquerda
    for(int i = 1;aux<=4 && linha+i<=getLinhas()-1 && coluna-i>=0 && getElemento(linha+i,coluna-i).getCor()==elemento.getCor();i++)
    {
        aux++;
    }

    if(aux>=4)
        return 1;
    else
        return 0;
}

bool Matriz::vitoria(int linha, int coluna, Peca elemento)const{
    if(vitoriaVertical(linha,coluna,elemento))
        return 1;
    if(vitoriaHorizontal(linha,coluna,elemento))
        return 1;
    if(vitoriaDiagonal(linha,coluna,elemento))
        return 1;
    return 0;
}

}
