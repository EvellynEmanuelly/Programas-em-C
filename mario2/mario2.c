#include <cs50.h>
#include <stdio.h>

int main()
{
    char nome[100];

    printf("Digite o seu nome: ");
    scanf("%s", nome);
    printf("Olá, %s! Bem Vindo ao jogo!\n", nome);

    int altura;

    // Solicitar altura até que seja fornecido um valor válido
    do
    {
        printf("Digite a altura da pirâmide (entre 1 e 8): ");
        scanf("%d", &altura);

        if (altura < 1 || altura > 8)
        {
            printf("Por favor, insira um número entre 1 e 8.\n");
        }
    }
    while (altura < 1 || altura > 8);

    // Imprimir as pirâmides
    for (int i = 0; i < altura; i++)
    {
        // Imprimir espaços à esquerda na pirâmide da esquerda
        for (int j = 0; j < altura - i - 1; j++)
        {
            printf(" ");
        }

        // Imprimir '#' na pirâmide da esquerda
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }

        // Imprimir espaços entre as pirâmides
        printf("  ");

        // Imprimir '#' na pirâmide da direita
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }

        // Mover para a próxima linha
        printf("\n");
    }

    return 0;
}
