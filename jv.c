
#include <stdio.h>
#include <stdlib.h>

char tabuleiro[3][3];
char jogador_atual;

void inicializar_tabuleiro() {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            tabuleiro[i][j] = ' ';
        }
    }
}

void imprimir_tabuleiro() {
    system("clear"); // Use "cls" se estiver no Windows
    printf("\n--- JOGO DA VELHA ---\n\n");
    printf("  0   1   2\n");
    for(int i = 0; i < 3; i++) {
        printf("%d ", i);
        for(int j = 0; j < 3; j++) {
            printf(" %c ", tabuleiro[i][j]);
            if(j < 2) printf("|");
        }
        printf("\n");
        if(i < 2) printf("  -----------\n");
    }
    printf("\n");
}

int verificar_vitoria() {
    // Linhas e Colunas
    for(int i = 0; i < 3; i++) {
        if(tabuleiro[i][0] == jogador_atual && tabuleiro[i][1] == jogador_atual && tabuleiro[i][2] == jogador_atual) return 1;
        if(tabuleiro[0][i] == jogador_atual && tabuleiro[1][i] == jogador_atual && tabuleiro[2][i] == jogador_atual) return 1;
    }
    // Diagonais
    if(tabuleiro[0][0] == jogador_atual && tabuleiro[1][1] == jogador_atual && tabuleiro[2][2] == jogador_atual) return 1;
    if(tabuleiro[0][2] == jogador_atual && tabuleiro[1][1] == jogador_atual && tabuleiro[2][0] == jogador_atual) return 1;

    return 0;
}

int verificar_empate() {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(tabuleiro[i][j] == ' ') return 0;
        }
    }
    return 1;
}

int main()
{
    int linha, coluna;
    int fim = 0;
    jogador_atual = 'X';

    inicializar_tabuleiro();

    while(!fim)
    {
        imprimir_tabuleiro();
        printf("Vez do jogador %c\n", jogador_atual);
        printf("Digite a linha (0-2): ");
        scanf("%d", &linha);
        printf("Digite a coluna (0-2): ");
        scanf("%d", &coluna);

        if(linha >= 0 && linha < 3 && coluna >= 0 && coluna < 3 && tabuleiro[linha][coluna] == ' ') {
            tabuleiro[linha][coluna] = jogador_atual;

            if(verificar_vitoria()) {
                imprimir_tabuleiro();
                printf("Parabens! O jogador %c venceu!\n", jogador_atual);
                fim = 1;
            } else if(verificar_empate()) {
                imprimir_tabuleiro();
                printf("O jogo terminou em empate!\n");
                fim = 1;
            } else {
                jogador_atual = (jogador_atual == 'X') ? 'O' : 'X';
            }
        } else {
            printf("Jogada invalida! Pressione Enter para tentar novamente.");
            getchar(); getchar();
        }
    }
    return 0;
}

