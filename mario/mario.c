#include <stdio.h>

int main()
{
    char nome[100];

    printf("Digite o seu nome: ");
    scanf("%s", nome);
    printf("Olá, %s! Bem Vindo ao jogo!\n", nome);

int height;

    do
    {
        printf("Tamanho: ");
        scanf("%d", &height);

        if (height < 1 || height > 8)
        {
            printf("Por favor, tente novamente e insira um número entre 1 e 8! \n");
        }
    }
    while (height < 1 || height > 8);

    for (int i = 1; i <= height; i++)
    {
        // Imprimir espaços em branco à esquerda
        for (int j = 0; j < height - i; j++)
        {
            printf(" ");
        }

        // Imprimir os #
        for (int k = 0; k < i; k++)
        {
            printf("#");
        }

        // Quebrar a linha após imprimir os #
        printf("\n");
    }

    return 0;
}
