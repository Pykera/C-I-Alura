#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
    printf("-----------------------------------\n");
    printf("|Bem vindo ao jogo de adivinhação!|\n");
    printf("-----------------------------------\n");

    int segundos = time(0);
    srand(segundos);

    int numerogrande = rand();

    int numerosecreto = numerogrande % 100;

    printf("numero secreto %d \n", numerosecreto);

    int chute;
    int tentativas = 0;
    double pontos = 1000;

    int acertou;



    int nivel;
    printf("Qual o nível de dificuldade? \n");
    printf("(1) Fácil, (2) Médio (3) Difícil \n\n");
    printf("Escolha: ");
    scanf("%d", &nivel);

    int numerodetentativas;

    if(nivel == 1) {
        numerodetentativas = 20;
    } else if (nivel == 2) {
        numerodetentativas = 15;
    } else {
        numerodetentativas = 6;
    }

    for (int i = 1; i <= numerodetentativas; i++) {

        printf("Tentativa: %d \n", tentativas + 1);


        printf("Qual é o seu chute?: ");
        scanf("%d", &chute);

        if (chute < 0) {
            printf("No negative numbers allowed here ma boi \n");
            continue;
        }


        printf("Seu chute foi %d \n", chute);

        int maior = chute > numerosecreto;
        int acertou = (chute == numerosecreto);



    if (acertou) {
        break;
    }

     if (maior) {
        printf("Seu chute foi maior \n");
        } else {
        printf("Seu chute foi menor que o número secreto \n");
        }
        tentativas = tentativas + 1;
        double pontosperdidos = abs(chute - numerosecreto) / 2.0;

        pontos = pontos - pontosperdidos;

        if (pontos < 0) {
            pontos = 0;
        }

    }
    printf("Cabou \n");

    if (acertou) {
        printf("Acertou! \n");
        printf("Você ganhou em %d tentativas \n", tentativas + 1);
        printf("Pontuação: %.2f \n ", pontos);
    } else {
        printf("Você perdeu");
    }



}
