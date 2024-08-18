#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int validate_key(string key);
void caesar_cipher(string text, int key, int encrypt);

int main(int argc, string argv[])
{
    while (true)
    {
        // Verificar se a quantidade de argumentos está correta
        if (argc != 2)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }

        // Validar a chave fornecida
        string key = argv[1];
        if (!validate_key(key))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }

        // Converter a chave para um número inteiro
        int k = atoi(key);

        // Solicitar ao usuário escolher criptografar (1) ou descriptografar (0)
        int encrypt = get_int("Encrypt (1) or Decrypt (0)? ");

        // Solicitar ao usuário uma string de texto
        string text = get_string("Text (or 'exit' to finish): ");

        // Verificar se o usuário deseja encerrar o programa
        if (strcmp(text, "exit") == 0)
        {
            printf("Programa encerrado.\n");
            break;
        }

        // Aplicar a cifra de César e imprimir o resultado
        printf("Result: ");
        caesar_cipher(text, k, encrypt);
        printf("\n");
    }

    return 0;
}

// Função para validar a chave
int validate_key(string key)
{
    for (int i = 0; key[i] != '\0'; i++)
    {
        if (!isdigit(key[i]))
        {
            return 0; // A chave contém um caractere não decimal
        }
    }
    return 1;
}

// Função para aplicar a cifra de César
void caesar_cipher(string text, int key, int encrypt)
{
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isalpha(text[i]))
        {
            char base = isupper(text[i]) ? 'A' : 'a';
            int offset = encrypt ? key : -key;
            printf("%c", (text[i] - base + offset + 26) % 26 + base);
        }
        else
        {
            printf("%c", text[i]);
        }
    }
}
