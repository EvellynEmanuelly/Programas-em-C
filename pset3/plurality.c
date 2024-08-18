#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Define o número máximo de candidatos
#define MAX 9

// Define a estrutura do candidato
typedef struct
{
    string name;
    int votes;
} candidate;

// Declara a matriz global de candidatos
candidate candidates[MAX];

// Declara o número de candidatos na eleição
int candidate_count;

// Protótipos das funções
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Verifica se há um número correto de argumentos
    if (argc < 2)
    {
        printf("Usage: %s candidate1 candidate2 ...\n", argv[0]);
        return 1;
    }

    // Preenche a matriz de candidatos com os nomes fornecidos nos argumentos de linha de comando
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %d\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    // Solicita o número de eleitores
    int voter_count = get_int("Number of voters: ");

    // Registra os votos dos eleitores
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Verifica se o voto é válido e atualiza os votos
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Imprime o(s) vencedor(es) da eleição
    print_winner();
}

// Função para registrar um voto
bool vote(string name)
{
    // Itera sobre os candidatos
    for (int i = 0; i < candidate_count; i++)
    {
        // Verifica se o nome corresponde a um candidato
        if (strcmp(name, candidates[i].name) == 0)
        {
            // Atualiza os votos do candidato e retorna true
            candidates[i].votes++;
            return true;
        }
    }

    // Retorna false se o nome não corresponder a nenhum candidato
    return false;
}

// Função para imprimir o(s) vencedor(es) da eleição
void print_winner(void)
{
    // Inicializa o máximo de votos
    int max_votes = 0;

    // Encontra o número máximo de votos
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > max_votes)
        {
            max_votes = candidates[i].votes;
        }
    }

    // Imprime o(s) vencedor(es)
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == max_votes)
        {
            printf("%s\n", candidates[i].name);
        }
    }
}
