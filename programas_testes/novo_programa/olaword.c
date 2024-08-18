#include <stdio.h>

int main() {
    char nome[100];

    printf("Digite o seu nome: ");

    scanf("%s", nome);

    printf("Olá, %s! Bem Vinda(o)!\n", nome);

    return 0;
}
