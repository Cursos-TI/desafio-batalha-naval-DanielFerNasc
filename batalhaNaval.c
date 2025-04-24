#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Aventureiro - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    //Declaração das Variáveis
    int tabuleiro[10][10];
    int linha[10] = {1,2,3,4,5,6,7,8,9,10};
    char coluna[11] = {' ','A','B','C','D','E','F','G','H','I','J'};
    int Pos_navio_H[2] = {2,5}; // Posição Inicial do Navio Horizointal (será acrescido da direita para esquerda)
    int Pos_navio_V[2] = {1,9}; // Posição Inicial do Navio Vertical (será acrescido de cima para baixo)
    int Pos_navio_DP[2] = {2,2}; // Posição Inicial do Navio na Diagonal Principal (será acrescido da direita para esquerda)
    int Pos_navio_DS[2] = {6,4}; // Posição Inicial do Navio na DIagonal Secundária (será acrescido da esquerda para direita)
    int teste = 0;
    int indice = 0;

    //Inicialização do Jogo
    printf("###############################\n");
    printf("#        Batalha Naval        #\n");
    printf("###############################\n");
    printf("\n");

    // Apresentação do Tabuleiro Inicial
    printf("Apresentação do Tabuleiro Inicial\n");
    for (int i = 0; i < 11; i++)
    {
        printf("%c ",coluna[i]); 
    }
    printf("\n");
    
    // Construção do Tabuleiro
    for (int i = 0; i < 10; i++)
    {
        printf("%d ",linha[i]);
        for (int j = 0; j < 10; j++)
        {
            tabuleiro[i][j] = 0;
            printf("%d ",tabuleiro[i][j]); 
        }
        printf("\n");
    }

    /* Analisando se os Navios Estão Sobrepostos
       Monta as Coordenadas dos Navios com Base nas Entradas dos Dados
            Navio Horizointal: Será acrescido da direita para esquerda!
            Navio Vertical: Será acrescido de cima para baixo!
            Navio na Diagonal Principal: Será acrescido da direita para esquerda!
            Navio na Diagonal Secundária: Será acrescido da esquerda para direita! */
    int  Navio_H[3][2] = {{Pos_navio_H[0],Pos_navio_H[1]},{Pos_navio_H[0],(Pos_navio_H[1]+1)},{Pos_navio_H[0],(Pos_navio_H[1]+2)}};
    int  Navio_V[3][2] = {{Pos_navio_V[0],Pos_navio_V[1]},{(Pos_navio_V[0]+1),Pos_navio_V[1]},{(Pos_navio_V[0]+2),Pos_navio_V[1]}};
    int Navio_DP[3][2] = {{Pos_navio_DP[0],Pos_navio_DP[1]},{(Pos_navio_DP[0]+1),(Pos_navio_DP[1]+1)},{(Pos_navio_DP[0]+2),(Pos_navio_DP[1]+2)}};
    int Navio_DS[3][2] = {{Pos_navio_DS[0],Pos_navio_DS[1]},{(Pos_navio_DS[0]+1),(Pos_navio_DS[1]-1)},{(Pos_navio_DS[0]+2),(Pos_navio_DS[1]-2)}};

    for (int  i = 0; i < 3; i++)
    {
        // Comparando as Coordenados do Navio Horizontal com os Demais Navios
        if((Navio_H[i][0] == Navio_V[i][0]) && (Navio_H[i][1] == Navio_V[i][1])){teste++;}
        if((Navio_H[i][0] == Navio_DP[i][0]) && (Navio_H[i][1] == Navio_DP[i][1])){teste++;}
        if((Navio_H[i][0] == Navio_DS[i][0]) && (Navio_H[i][1] == Navio_DS[i][1])){teste++;}

        // Comparando as Coordenados do Navio Vertical com os Demais Navios
        if((Navio_V[i][0] == Navio_DP[i][0]) && (Navio_V[i][1] == Navio_DP[i][1])){teste++;}
        if((Navio_V[i][0] == Navio_DS[i][0]) && (Navio_V[i][1] == Navio_DS[i][1])){teste++;}

        // Comparando as Coordenados entre os Navios das Diagonais
        if((Navio_DP[i][0] == Navio_DS[i][0]) && (Navio_DP[i][1] == Navio_DS[i][1])){teste++;}
    }
    if(teste > 0){indice = 1;teste = 0;}

    //Analisando se os Navios Estão Dentro dos Limtes do Tabuleiro
    if ((Pos_navio_H[0] > 8) || (Pos_navio_V[0] > 8) || (Pos_navio_DP[0] > 8) || (Pos_navio_DS[0] > 8)){
        indice = 2;
    }

    switch (indice)
    {
    case 1:
        printf("\nOs navios estão com coordenadas sobrepostas");
        break;
    case 2:
        printf("\nOs navios estão com posição fora do limite do tabuleiro");
        break;
    case 0:
        // Apresentação do Tabuleiro Preenchido
        printf("\n\nResultado!\n");
        for (int i = 0; i < 11; i++)
        {
            printf("%c ",coluna[i]); 
        }
        printf("\n");

        for (int  i = 0; i < 10; i++)
        {
            printf("%d ",linha[i]);
            for (int j = 0; j < 10; j++)
            {
                // Preenchendo o Navio Horizontal
                if ((i == Navio_H[0][0]-1) && (j == Navio_H[0][1]-1)){ tabuleiro[i][j] = 3;}
                if ((i == Navio_H[1][0]-1) && (j == Navio_H[1][1]-1)){ tabuleiro[i][j] = 3;}
                if ((i == Navio_H[2][0]-1) && (j == Navio_H[2][1]-1)){ tabuleiro[i][j] = 3;}
                
                // Preenchendo o Navio Vertical
                if ((i == Navio_V[0][0]-1) && (j == Navio_V[0][1]-1)){ tabuleiro[i][j] = 3;}
                if ((i == Navio_V[1][0]-1) && (j == Navio_V[1][1]-1)){ tabuleiro[i][j] = 3;}
                if ((i == Navio_V[2][0]-1) && (j == Navio_V[2][1]-1)){ tabuleiro[i][j] = 3;}
                
                // Preenchendo o Navio da Diagonal Principal
                if ((i == Navio_DP[0][0]-1) && (j == Navio_DP[0][1]-1)){ tabuleiro[i][j] = 3;}
                if ((i == Navio_DP[1][0]-1) && (j == Navio_DP[1][1]-1)){ tabuleiro[i][j] = 3;}
                if ((i == Navio_DP[2][0]-1) && (j == Navio_DP[2][1]-1)){ tabuleiro[i][j] = 3;}
                
                // Preenchendo o Navio da Diagonal Secundária
                if ((i == Navio_DS[0][0]-1) && (j == Navio_DS[0][1]-1)){ tabuleiro[i][j] = 3;}
                if ((i == Navio_DS[1][0]-1) && (j == Navio_DS[1][1]-1)){ tabuleiro[i][j] = 3;}
                if ((i == Navio_DS[2][0]-1) && (j == Navio_DS[2][1]-1)){ tabuleiro[i][j] = 3;}
                
                // Apresentando o Tabuleiro
                printf("%d ",tabuleiro[i][j]); 
            }
            printf("\n"); 
        }  
        break;
    default:
        printf("\nErro!\n"); 
        break;
    }


    return 0;
}
