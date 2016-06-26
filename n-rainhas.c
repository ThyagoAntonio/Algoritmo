/*Aluno: Thyago Antonio Sampaio Valadares
Disciplina: Algoritmos e Estrutura de Dados
Professor: Rodrigo Nonamor Pereira Mariano de Souza
Data: 06/04/2016
EP: 0
Período: 2016.1  */

#include<stdio.h>
#include<math.h>

int tabuleiro[26], cont;

/*Função que serve para imprimir todas as soluções de um tabuleiro
n x n, com n rainhas. Se tiver rainha, aparecerá "R", caso contrário
aparecerá "_".*/

void imprimir(int qtd){

    int i, j, m, n;
    char c, resp[qtd][2];

    printf("\n\nResposta %d:\n", ++cont);

    for(i = 1; i <= qtd; ++i){
        printf("\n\n%d", abs(qtd - i + 1));
        for(j = 1; j <= qtd; ++j){

            if(tabuleiro[i] == j){
                printf("   R");
                resp[j-1][0] = j+96;
                resp[j-1][1] = abs(qtd - i +1 );
            }else{
                printf("   _");
            }
        }
    }
    printf("\n\n");
    for(c = 97; c <= (qtd + 96); ++c){
        printf("   %c", c);
    }
    printf("\n\n");
    for (m = 0; m < qtd; m++){
        for(n = 0; n <= 1; n++){

            if(n == 0){
                printf("%c", resp[m][n]);
            }else if(m == (qtd - 1)){
                printf("%d.", resp[m][n]);
            }else{
                printf("%d, ", resp[m][n]);
            }
        }
    }
    printf("\n");

}

/*Função para verificar se há conflitos nas posições das rainhas. Se nenhum
conflito para a posição desejada retorna 1, caso contrário retorna 0.*/

int conflitos(int linha, int coluna){

    int i;

    for(i = 1; i <= linha - 1; ++i){

        if(tabuleiro[i] == coluna){
            return 0;
        }else if(abs(tabuleiro[i] - coluna) == abs(i - linha)){
                return 0;
        }
    }
    return 1;
}

/*Função para verificar o posicionamento adequado da rainha para não ser atacada
por nenhuma outra rainha.*/

void posicaoRainha(int linha, int qtd){

    int coluna;

    for(coluna = 1; coluna <= qtd; ++coluna){

        if(conflitos(linha, coluna)){
            tabuleiro[linha] = coluna;

            if(linha == qtd){
                imprimir(qtd);
            }else{
                posicaoRainha(linha + 1, qtd);
            }
        }
    }
}

void main(){

    int qtd, i, j;

    void posicaoRainha(int linha, int qtd);

    printf("Digite o numero de rainhas desejadas: ");
    scanf("%d", &qtd);

    posicaoRainha(1, qtd);
}
