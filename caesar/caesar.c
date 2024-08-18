#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int validate_key(string key);
void encrypt_text(string text, int key);

int main(int argc, string argv[])
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

    // Solicitar ao usuário uma string de texto simples
    string plaintext = get_string("plaintext: ");

    // Criptografar e imprimir o resultado
    printf("ciphertext: ");
    encrypt_text(plaintext, k);
    printf("\n");

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

// Função para criptografar o texto
void encrypt_text(string text, int key)
{
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isalpha(text[i]))
        {
            char base = isupper(text[i]) ? 'A' : 'a';
            printf("%c", (text[i] - base + key) % 26 + base);
        }
        else
        {
            printf("%c", text[i]);
        }
    }
}
